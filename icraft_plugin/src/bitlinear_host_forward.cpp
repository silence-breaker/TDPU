/**
 * bitlinear_host_forward.cpp - BitLinear HostBackend 前向实现
 *
 * 用 C++ 模拟 FPGA 的 ternary matmul 行为:
 *   output[b][m] = sum_k( activation[b][k] * ternary_weight[m][k] )
 *
 * 权重编码 (packed uint8, 4 weights per byte, little-endian):
 *   2'b00 = -1, 2'b01 = 0, 2'b10 = +1, 2'b11 = 0 (padding)
 */
#include "bitlinear_op.h"
#include <icraft-backends/hostbackend/backend.h>
#include <icraft-xrt/dev/host_device.h>
#include <icraft-xir/core/layout.h>
#include <icraft-xir/core/data.h>
#include <cstdint>
#include <vector>
#include <iostream>

namespace tdpu {

using namespace icraft::xir;
using icraft::xrt::Tensor;
using icraft::xrt::HostBackend;
using icraft::xrt::HostDevice;

// 解包单个 ternary 权重: 从 packed byte 中提取第 idx 个 2-bit 值
static inline int unpack_ternary(uint8_t packed, int idx) {
    int val = (packed >> (idx * 2)) & 0x3;
    // 2'b00=-1, 2'b10=+1, 其余=0
    if (val == 0) return -1;
    if (val == 2) return  1;
    return 0;
}

// 初始化 (无特殊操作)
static auto bitlinear_init = [](const BitLinear& op, HostBackend backend) {
    // HostBackend 仿真无需硬件初始化
};

// 前向: C++ ternary matmul (精确模拟 FPGA 行为, 整数无损)
static auto bitlinear_forward = [](const BitLinear& op,
                                   const std::vector<Tensor>& inputs,
                                   const std::vector<Tensor>& /*outputs*/,
                                   HostBackend backend)
    -> std::vector<Tensor>
{
    // inputs 只包含运行时张量 (激活值), 权重通过 Params 获取
    auto activation = inputs[0];  // [batch, K] INT8

    int64_t K = op->in_features;
    int64_t M = op->out_features;

    // 从算子的输入 Value 获取 batch 维度
    auto input_ttype = op->inputs[0].tensorType();
    int64_t batch = input_ttype.getDim(0);

    // 从 Operation 的 Params 获取权重数据 (不在 inputs 向量中)
    auto params_list = op.paramsInputs();
    auto w_ptr = params_list[0].data<uint8_t>().get();

    // 分配输出 Tensor [batch, M] INT32
    auto output_type = TensorType(IntegerType::SInt32(),
        Array<int64_t>{batch, M}, Layout("RC"));
    auto output = Tensor(output_type).mallocOn(HostDevice::MemRegion());

    auto* act_ptr = reinterpret_cast<const int8_t*>(activation.data().cptr());
    auto* out_ptr = reinterpret_cast<int32_t*>(output.data().cptr());

    // Ternary MatMul: 逐元素累加, 无 DSP 乘法
    for (int64_t b = 0; b < batch; b++) {
        for (int64_t m = 0; m < M; m++) {
            int32_t acc = 0;
            for (int64_t k = 0; k < K; k++) {
                int8_t a = act_ptr[b * K + k];
                // 每个 uint8 包含 4 个 ternary 权重
                int byte_idx = static_cast<int>((m * K + k) / 4);
                int bit_idx  = static_cast<int>((m * K + k) % 4);
                int w = unpack_ternary(w_ptr[byte_idx], bit_idx);
                // Ternary multiply-accumulate
                if (w == 1)       acc += a;
                else if (w == -1) acc -= a;
                // w == 0: skip (no-op)
            }
            out_ptr[b * M + m] = acc;
        }
    }

    return {output};
};

// 注册到 HostBackend
ICRAFT_ADD_OP_TO_BACKEND(BitLinear, HostBackend)
    .set_init(bitlinear_init)
    .set_forward(bitlinear_forward);

} // namespace tdpu
