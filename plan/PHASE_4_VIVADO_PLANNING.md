# Phase 4: Vivado IP核开发规划

## 概述

Phase 4的目标是将RTL设计的vec_multi_core.sv封装为Vivado IP核，并在FMQL30TAI平台上建立完整的PS-PL通信架构。

**预期成果**:
- TDPU IP核 (AXI接口)
- PS-PL通信驱动
- 完整的硬件加速系统

---

## Phase 4.1: IP核封装

### 目标
将vec_multi_core.sv转换为标准Vivado IP核，支持AXI总线接口。

### 工作内容

#### 4.1.1 IP核架构设计
```
┌─────────────────────────────────────────┐
│         TDPU IP Core                    │
├─────────────────────────────────────────┤
│                                         │
│  ┌──────────────────────────────────┐  │
│  │   AXI-Lite Control Interface     │  │
│  │  (寄存器读写, 中断控制)           │  │
│  └──────────────────────────────────┘  │
│                                         │
│  ┌──────────────────────────────────┐  │
│  │   AXI-Stream Data Interface      │  │
│  │  (激活值输入, 权重输入, 结果输出) │  │
│  └──────────────────────────────────┘  │
│                                         │
│  ┌──────────────────────────────────┐  │
│  │   vec_multi_core (RTL核心)       │  │
│  │  (32并行度, 6拍流水线)            │  │
│  └──────────────────────────────────┘  │
│                                         │
└─────────────────────────────────────────┘
```

#### 4.1.2 寄存器定义

| 地址 | 寄存器名 | 功能 | 说明 |
|------|---------|------|------|
| 0x00 | CTRL | 控制寄存器 | [0]=启动, [1]=复位, [2]=中断使能 |
| 0x04 | STATUS | 状态寄存器 | [0]=就绪, [1]=忙, [2]=完成, [3]=错误 |
| 0x08 | CONFIG | 配置寄存器 | [15:0]=K, [31:16]=M |
| 0x0C | INTR_STATUS | 中断状态 | [0]=完成中断, [1]=错误中断 |
| 0x10 | INTR_MASK | 中断掩码 | 中断使能控制 |

#### 4.1.3 AXI-Stream接口

**输入流** (激活值):
- 数据宽度: 256-bit (32×INT8)
- 有效信号: tvalid
- 就绪信号: tready
- 最后信号: tlast (表示一个batch完成)

**输入流** (权重):
- 数据宽度: 256-bit (64×2-bit ternary)
- 有效信号: tvalid
- 就绪信号: tready

**输出流** (结果):
- 数据宽度: 256-bit (8×INT32)
- 有效信号: tvalid
- 就绪信号: tready
- 最后信号: tlast

#### 4.1.4 文件结构

```
vivado_project/
├── TDPU_IP/
│   ├── hdl/
│   │   ├── vec_multi_core.sv           # 核心算子 (已有)
│   │   ├── package_def.sv              # 数据定义 (已有)
│   │   ├── tdpu_axi_wrapper.sv         # AXI包装层 (新建)
│   │   └── tdpu_top.sv                 # 顶层模块 (新建)
│   ├── ip_catalog/
│   │   └── TDPU_v1_0.xgui              # IP定制化GUI
│   └── component.xml                   # IP元数据
├── constraints/
│   └── tdpu.xdc                        # 时序约束
└── sim/
    └── tb_tdpu.sv                      # 仿真testbench
```

### 关键代码框架

**tdpu_axi_wrapper.sv** (AXI-Lite控制接口):
```verilog
module tdpu_axi_wrapper (
    input clk, rst_n,

    // AXI-Lite 控制接口
    input [31:0] awaddr, wdata,
    input awvalid, wvalid,
    output awready, wready,

    output [31:0] rdata,
    input araddr, arvalid,
    output arready, rvalid,

    // 中断信号
    output intr,

    // 核心接口
    output [255:0] act_data,
    output [255:0] weight_data,
    output valid,
    input ready,
    input [255:0] result_data,
    input result_valid
);
    // 寄存器组
    reg [31:0] ctrl_reg, status_reg, config_reg;

    // 读写逻辑
    // ...
endmodule
```

**tdpu_top.sv** (顶层):
```verilog
module tdpu_top (
    input clk, rst_n,

    // AXI-Lite
    input [31:0] s_axi_awaddr, s_axi_wdata,
    input s_axi_awvalid, s_axi_wvalid,
    output s_axi_awready, s_axi_wready,

    // AXI-Stream (激活值)
    input [255:0] s_axis_act_tdata,
    input s_axis_act_tvalid,
    output s_axis_act_tready,
    input s_axis_act_tlast,

    // AXI-Stream (权重)
    input [255:0] s_axis_weight_tdata,
    input s_axis_weight_tvalid,
    output s_axis_weight_tready,

    // AXI-Stream (结果)
    output [255:0] m_axis_result_tdata,
    output m_axis_result_tvalid,
    input m_axis_result_tready,
    output m_axis_result_tlast,

    // 中断
    output intr
);
    // 实例化核心模块
    vec_multi_core core_inst (
        .clk(clk),
        .rst_n(rst_n),
        .i_data(s_axis_act_tdata),
        .i_weight(s_axis_weight_tdata),
        .o_result(m_axis_result_tdata),
        .o_valid(m_axis_result_tvalid)
    );
endmodule
```

### 验证计划

- [ ] 功能仿真 (ModelSim/VCS)
- [ ] 时序仿真 (Post-Place & Route)
- [ ] IP核打包 (Vivado IP Packager)
- [ ] 集成测试 (在Block Design中)

---

## Phase 4.2: PS-PL通信架构

### 目标
建立完整的PS-PL通信系统，包括DMA、中断、驱动程序。

### 工作内容

#### 4.2.1 Block Design架构

```
┌─────────────────────────────────────────────────────┐
│              Zynq PS (ARM Cortex-A9)                │
│  ┌──────────────────────────────────────────────┐  │
│  │  Linux Kernel + TDPU Driver                  │  │
│  │  (用户空间应用)                               │  │
│  └──────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────┘
                        │
                   AXI互联网络
                        │
        ┌───────────────┼───────────────┐
        │               │               │
    ┌───▼────┐    ┌────▼────┐    ┌────▼────┐
    │ TDPU   │    │   DMA   │    │ Memory  │
    │  IP    │    │ Engine  │    │ (DDR3)  │
    │ Core   │    │         │    │         │
    └────────┘    └─────────┘    └─────────┘
```

#### 4.2.2 DMA配置

**用途**: 高效传输权重和激活值

| 参数 | 值 | 说明 |
|------|-----|------|
| 数据宽度 | 256-bit | 匹配IP核接口 |
| 突发长度 | 16 | 优化带宽利用 |
| 优先级 | 高 | 实时性要求 |

#### 4.2.3 中断处理

- **完成中断**: 计算完成时触发
- **错误中断**: 检测到错误时触发
- **中断优先级**: 设置为高优先级

#### 4.2.4 Linux驱动程序

**文件结构**:
```
linux_driver/
├── tdpu_driver.c          # 主驱动程序
├── tdpu_ioctl.h           # IOCTL命令定义
├── tdpu_dma.c             # DMA管理
├── tdpu_intr.c            # 中断处理
└── Makefile               # 编译配置
```

**关键功能**:
```c
// IOCTL命令
#define TDPU_IOCTL_SET_CONFIG    _IOW('T', 1, struct tdpu_config)
#define TDPU_IOCTL_START         _IO('T', 2)
#define TDPU_IOCTL_WAIT          _IO('T', 3)
#define TDPU_IOCTL_GET_RESULT    _IOR('T', 4, struct tdpu_result)

// 驱动接口
int tdpu_open(struct inode *inode, struct file *filp);
int tdpu_release(struct inode *inode, struct file *filp);
long tdpu_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);
int tdpu_mmap(struct file *filp, struct vm_area_struct *vma);
```

### 验证计划

- [ ] Block Design功能验证
- [ ] 硬件仿真 (Vivado Simulator)
- [ ] 驱动程序编译和加载
- [ ] 端到端集成测试

---

## Phase 4.3: 性能优化

### 目标
优化FPGA资源利用率和推理延迟。

### 工作内容

#### 4.3.1 资源优化

| 资源 | 当前 | 目标 | 优化方法 |
|------|------|------|---------|
| LUT | ~40% | <50% | 逻辑优化、资源共享 |
| DSP | ~30% | <40% | 乘法器复用 |
| BRAM | ~20% | <30% | 缓存优化 |
| 功耗 | TBD | <10W | 时钟门控、电压调整 |

#### 4.3.2 延迟优化

- 流水线深度调整 (当前6拍)
- 多核并行 (多个vec_multi_core实例)
- 缓存策略 (权重预加载)

#### 4.3.3 带宽优化

- DMA突发长度优化
- 内存访问模式优化
- 缓存一致性管理

### 验证计划

- [ ] 资源使用率报告
- [ ] 时序分析 (Timing Report)
- [ ] 功耗分析 (Power Report)
- [ ] 性能基准测试

---

## 时间规划

| Phase | 任务 | 预期工作量 | 依赖 |
|-------|------|----------|------|
| 4.1 | IP核封装 | 2-3周 | Phase 3.5完成 |
| 4.2 | PS-PL通信 | 3-4周 | 4.1完成 |
| 4.3 | 性能优化 | 2-3周 | 4.2完成 |
| 集成 | 端到端验证 | 1-2周 | 全部完成 |

---

## 关键里程碑

- [ ] IP核功能仿真通过
- [ ] Block Design集成成功
- [ ] 驱动程序加载成功
- [ ] 端到端推理验证通过
- [ ] 性能指标达成

---

## 参考资源

- Vivado IP Packager文档
- Zynq PS-PL通信指南
- Linux内核驱动开发指南
- FMQL30TAI硬件参考手册

---

**创建时间**: 2026-02-11
**状态**: 规划中
**下一步**: Phase 4.1 IP核封装
