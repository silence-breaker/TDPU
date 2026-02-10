`timescale 1ns / 1ps
`include "package_def.sv"
import package_def::*;
// ============================================================
// vec_multi_core.sv
// 多核向量乘加计算单元 (Vector Multiply-Accumulate Core)
// 支持参数化向量长度和数据位宽
// 较先前版本做了以下改进：
// 1. 整体采用动态位宽，在最后输出才进行位宽固定为32位
// 2. 控制路径复位，数据路径无复位，极大地降低了全局复位信号的扇出，缓解了布线拥塞
// 3. 加法树第0层输入直连 PE 输出，减少寄存器级数，降低延迟
// 4. 消除always块内的if else语句Bug,比如level 0和level>0
// ============================================================
module vec_multi_core #(
    parameter int LEN = 32,
    // Parameter LEN must be power of 2 (e.g., 32, 64)
    parameter int DATA_WIDTH = 8
) (
    input logic clk,
    input logic rst_n,
    input logic i_data_valid,
    input logic i_load_weight,
    input logic signed [LEN-1:0][DATA_WIDTH-1:0] i_data,
    input weight_t [LEN-1:0] i_weight,
    output logic o_data_ready,
    output logic signed [31:0] o_result
);

  // ============================================================
  // 0. 权重寄存器
  // ============================================================
  weight_t [LEN-1:0] weight_reg;
  always_ff @(posedge clk or negedge rst_n) begin : blk_weight
    if (!rst_n) begin
      weight_reg <= '{default: W_ZERO};
    end else if (i_load_weight) begin
      weight_reg <= i_weight;
    end
  end

  // ============================================================
  // 1. PE计算层 (BitLinear Core)
  // ============================================================
  // 优化：DATA_WIDTH(8) -> PROD_WIDTH(9)
  localparam int PROD_WIDTH = DATA_WIDTH + 1;
  logic signed [LEN-1:0][PROD_WIDTH-1:0] product;
  logic product_ready;

  generate
    for (genvar i = 0; i < LEN; i++) begin : gen_PE
      // 数据通路去复位，只保留 Enable
      always_ff @(posedge clk) begin
        if (i_data_valid) begin
          unique case (weight_reg[i])
            W_POS:   product[i] <= PROD_WIDTH'(i_data[i]);
            W_NEG:   product[i] <= -PROD_WIDTH'(i_data[i]);
            W_ZERO:  product[i] <= 'sb0;
            default: product[i] <= 'sb0;
          endcase
        end
      end
    end
  endgenerate

  // 控制信号复位
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) product_ready <= 1'b0;
    else product_ready <= i_data_valid;
  end

  // ============================================================
  // 2. 参数化加法树 (Adder Tree) - 修复版
  // ============================================================
  localparam int TREE_DEPTH = $clog2(LEN);
  logic [TREE_DEPTH-1:0] tree_valid;

  generate
    for (genvar level = 0; level < TREE_DEPTH; level++) begin : gen_tree

      // 计算当前层的位宽和节点数
      localparam int OUT_WIDTH = PROD_WIDTH + level + 1;
      localparam int NUM_NODES = LEN >> (level + 1);

      // 定义当前层的数据寄存器
      logic signed [NUM_NODES-1:0][OUT_WIDTH-1:0] level_data;

      // ==========================================================
      // [修复重点] 使用 if - else 结构，去掉 redundant 的 else if
      // ==========================================================
      if (level == 0) begin : g_level_zero
        // ------------------------------------------------
        // Case A: 第一层 (Level 0)，输入直接来自 product
        // ------------------------------------------------
        for (genvar k = 0; k < NUM_NODES; k++) begin : gen_loop_l0
          always_ff @(posedge clk) begin
            if (product_ready) begin
              // 9bit + 9bit -> 10bit
              level_data[k] <= product[2*k] + product[2*k+1];
            end
          end
        end

      end else begin : g_level_upper
        // ------------------------------------------------
        // Case B: 后续层 (Level >= 1)，输入来自上一级
        // 此时 level-1 绝对安全，不会越界
        // ------------------------------------------------
        for (genvar k = 0; k < NUM_NODES; k++) begin : gen_loop_lx
          always_ff @(posedge clk) begin
            // 引用上一层 gen_tree[level-1]
            if (tree_valid[level-1]) begin
              level_data[k] <= gen_tree[level-1].level_data[2*k] + 
                                   gen_tree[level-1].level_data[2*k+1];
            end
          end
        end
      end
      // ==========================================================

      // Valid 信号流水线
      //如果leverl不分开0级处理，会导致综合工具报错（level-1在0级时会出现负数）
      //if-else内包always不会报错，always内包if-else会报错
      if (level == 0) begin : g_valid_0
        always_ff @(posedge clk or negedge rst_n) begin
          if (!rst_n) begin
            tree_valid[level] <= 1'b0;
          end else begin
            tree_valid[level] <= product_ready;
          end
        end
      end else begin : g_valid_upper
        always_ff @(posedge clk or negedge rst_n) begin
          if (!rst_n) begin
            tree_valid[level] <= 1'b0;
          end else begin
            tree_valid[level] <= tree_valid[level-1];
          end
        end
      end

    end
  endgenerate

  // ============================================================
  // 3. 输出处理
  // ============================================================
  // 符号扩展到 32 位
  assign o_result     = 32'(gen_tree[TREE_DEPTH-1].level_data[0]);
  assign o_data_ready = tree_valid[TREE_DEPTH-1];

endmodule
