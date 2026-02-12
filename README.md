# TDPU - BitLinear 自定义算子开发项目

## 项目概述

本项目是参加**复旦微集创赛（任务二：自定义硬件算子）**的TDPU（Tensor Deep Processing Unit）项目。目标是将BitNet b1.58模型的核心`BitLinear`算子接入Icraft工具链，最终在FMQL30TAI平台上实现PS+PL+NPU异构协同推理。

**当前状态**: Phase 3.5 完成 ✓ (PS-PL硬件交互模拟 + 真实权重验证)

---

## 工作区结构

```
TDPU/
├── README.md                           # 本文件
├── CLAUDE.md                           # 工作区系统指令
├── PHASE_3_5_README.md                 # Phase 3.5 使用指南
├── PHASE_3_5_SUMMARY.md                # Phase 3.5 完成总结
├── WORK_COMPLETION_REPORT.md           # 工作完成报告
├── quick_test.py                       # 一键测试脚本
│
├── plan/                               # 项目计划
│   └── flickering-jumping-frost.md     # 详细项目计划 (已更新)
│
├── TDPU/                               # RTL设计 (Verilator仿真)
│   ├── vec_multi_core.sv               # 核心算子 (LEN=32, 32并行度)
│   ├── package_def.sv                  # 数据定义 (ternary编码)
│   ├── sim_main.cpp                    # C++ Testbench
│   ├── run_sim.sh                      # 自动化仿真脚本
│   └── waveform.vcd                    # 仿真波形 (Verilator输出)
│
├── icraft_plugin/                      # Icraft自定义算子插件
│   ├── CMakeLists.txt                  # 构建配置 (已更新)
│   ├── include/
│   │   └── bitlinear_op.h              # BitLinear算子定义
│   ├── src/
│   │   ├── bitlinear_op.cpp            # 算子注册 + 类型推断
│   │   ├── bitlinear_host_forward.cpp  # HostBackend前向实现
│   │   └── bitlinear_pass.cpp          # 优化Pass (MatMul→BitLinear)
│   ├── test/
│   │   ├── test_bitlinear.cpp          # 合成权重测试 (2/2 PASS)
│   │   └── test_real_weights.cpp       # 真实权重验证 (PASS)
│   ├── config/
│   │   └── bitlinear_test.toml         # icraft run配置
│   └── build/                          # CMake构建目录
│       ├── Release/
│       │   ├── icraft.tdpu.bitlinear.dll
│       │   ├── test_bitlinear.exe      # 合成权重测试
│       │   └── test_real_weights.exe   # 真实权重测试 ✓
│       └── ...
│
├── models/                             # 模型与权重
│   ├── extract_weights.py              # 权重提取工具 (新建)
│   ├── export_single_layer.py          # 单层ONNX导出
│   ├── output/
│   │   └── q_proj_weights.bin          # 提取的权重文件 (1.6MB)
│   └── microsoftbitnet_b1.58_2B_4T/
│       ├── model.safetensors           # 完整模型权重
│       └── ...
│
└── Icraft文档/                         # Icraft工具链文档
    ├── 3_Component_overview.md         # 架构概览
    ├── extensibility/
    │   └── customop.md                 # 自定义算子文档
    ├── component/
    │   ├── XIR/                        # 中间表示层
    │   ├── quantizer/                  # 量化工具
    │   └── XRT/                        # 运行时环境
    └── ...
```

---

## 核心模块说明

### 1. RTL设计 (`TDPU/`)

**目标**: 实现32并行度的ternary向量乘法核心

| 文件 | 说明 |
|------|------|
| `vec_multi_core.sv` | 核心算子，LEN=32，流水线延迟6拍 |
| `package_def.sv` | ternary编码定义 (W_NEG=2'b00, W_ZERO=2'b01, W_POS=2'b10) |
| `sim_main.cpp` | C++ Testbench，驱动Verilator仿真 |
| `run_sim.sh` | 自动化脚本：verible格式化 → verilator编译 → 仿真 |

**验证状态**: ✓ Phase 1 完成 (4 Case全部通过)

### 2. Icraft自定义算子 (`icraft_plugin/`)

**目标**: 将BitLinear算子注册到Icraft工具链，支持HostBackend CPU仿真

#### 2.1 算子定义 (`include/bitlinear_op.h`)
```cpp
class BitLinearNode : public OpNodeBase<BitLinearNode> {
    int64_t in_features;   // K
    int64_t out_features;  // M
};

class BitLinear : public OpBase<BitLinear, BitLinearNode> {
    // 构造: BitLinear(input, weight, K, M)
};
```

#### 2.2 算子注册 (`src/bitlinear_op.cpp`)
- 注册BitLinearNode到XIR
- 实现类型推断 (ICRAFT_REGISTER_TINFER)
- 输入: [batch, K] INT8
- 权重: [M/4, K] UINT8 (packed ternary)
- 输出: [batch, M] INT32

#### 2.3 HostBackend前向 (`src/bitlinear_host_forward.cpp`)
- C++实现ternary matmul
- 权重寻址: `byte_idx = (m/4)*K + k, bit_idx = m%4`
- 支持任意batch大小

#### 2.4 优化Pass (`src/bitlinear_pass.cpp`)
- 将ONNX的MatMul替换为BitLinear
- 自动检测ternary权重

**编译状态**: ✓ Phase 2 完成
- `icraft.tdpu.bitlinear.dll` ✓
- `test_bitlinear.exe` ✓ (2/2 PASS)

### 3. 真实权重验证 (`models/` + `icraft_plugin/test/test_real_weights.cpp`)

**目标**: 在软件层面模拟PS-PL硬件交互，进行真实权重的完整验证

#### 3.1 权重提取 (`models/extract_weights.py`)
```bash
python models/extract_weights.py
# 输出: models/output/q_proj_weights.bin (1.6MB)
```

**权重信息**:
- 来源: BitNet b1.58 q_proj层
- 形状: [640, 2560] uint8 (packed)
- 解包后: [2560, 2560] (M=2560, K=2560)
- 分布: -1(25.17%), 0(49.62%), +1(25.21%)

#### 3.2 PS-PL硬件交互模拟 (`icraft_plugin/test/test_real_weights.cpp`)

**4步流程**:
1. **PS端**: 加载权重 (1.6MB)
2. **PS端**: 生成请求 ([1, 2560] INT8随机激活值)
3. **PL端**: 构建XIR网络 + HostBackend计算
4. **验证**: 对比参考实现

**测试结果**: ✓ PASS (2560/2560 outputs match)

**编译与运行**:
```bash
cd icraft_plugin/build
cmake --build . --config Release
cd Release
./test_real_weights.exe "..\..\models\output\q_proj_weights.bin"
```

**验证状态**: ✓ Phase 3.5 完成

---

## 快速开始

### 方式1: 一键运行 (推荐)
```bash
cd d:\SYSU\JC\Code-space\TDPU
python quick_test.py
```

自动执行:
1. 提取权重
2. 编译test_real_weights
3. 运行PS-PL硬件交互模拟

### 方式2: 分步执行

**Step 1: 提取权重**
```bash
conda activate icraft_env
python models/extract_weights.py
```

**Step 2: 编译**
```bash
cd icraft_plugin/build
cmake --build . --config Release
```

**Step 3: 运行测试**
```bash
cd Release
./test_real_weights.exe "..\..\models\output\q_proj_weights.bin"
```

---

## 关键技术指标

| 指标 | 值 |
|------|-----|
| RTL并行度 | 32 |
| RTL流水线延迟 | 6拍 |
| 权重编码 | 2-bit ternary (-1, 0, +1) |
| 权重packing方向 | [M/4, K] (M维度) |
| 激活值精度 | INT8 |
| 输出精度 | INT32 |
| 权重文件大小 | 1.6 MB |
| 总ternary权重数 | 6,553,600 |
| 输出匹配率 | 100% (2560/2560) |
| 前向计算时间 | ~100ms |

---

## 文件清单

### 新增文件 (Phase 3.5)
```
PHASE_3_5_README.md                    # 使用指南
PHASE_3_5_SUMMARY.md                   # 完成总结
WORK_COMPLETION_REPORT.md              # 工作报告
quick_test.py                          # 一键测试脚本
models/extract_weights.py              # 权重提取工具
models/output/q_proj_weights.bin       # 提取的权重文件
icraft_plugin/test/test_real_weights.cpp  # PS-PL硬件交互模拟
```

### 修改文件 (Phase 3.5)
```
icraft_plugin/CMakeLists.txt           # 添加test_real_weights编译目标
plan/flickering-jumping-frost.md       # 更新Phase 3.5进度
```

### 编译输出
```
icraft_plugin/build/Release/test_real_weights.exe
icraft_plugin/build/Release/test_real_weights.pdb
```

---

## 项目进度

### Phase 1: RTL升级 ✓ COMPLETE
- [x] vec_multi_core LEN=16→32
- [x] Verilator仿真 4 Case全部通过
- [x] 流水线延迟6拍

### Phase 2: Icraft自定义算子 ✓ COMPLETE
- [x] BitLinear算子注册
- [x] HostBackend前向实现
- [x] test_bitlinear.exe 2/2 PASS

### Phase 3: ONNX模型接入 (进行中)
- [x] 单层ONNX导出
- [x] 权重packing方向修正
- [ ] icraft parse + optimize + run验证

### Phase 3.5: 真实权重验证 ✓ COMPLETE
- [x] 权重提取工具
- [x] PS-PL硬件交互模拟
- [x] 完整验证流程 (2560/2560 PASS)

---

## 后续工作

### 短期 (Phase 3)(跳过，因为host仿真中的icraft parse只适用于Yolo等视觉模型，无法解析当前的BitLinear模型，所以直接进入Phase 3.5的真实权重验证)
- [ ] icraft parse + optimize + run 端到端验证
- [ ] 多batch支持 (batch > 1)
- [ ] 多层BitLinear推理

### 中期 (Phase 4: Vivado IP核开发)
- [ ] 在Vivado中创建TDPU IP核
  - [ ] 将vec_multi_core.sv封装为IP
  - [ ] 配置AXI总线接口 (AXI-Lite控制, AXI-Stream数据)
  - [ ] 添加中断信号和状态寄存器
  - [ ] 生成IP核包 (.xco)
- [ ] 建立PS-PL通信架构
  - [ ] 设计AXI互联网络
  - [ ] 配置DMA引擎 (权重/激活值传输)
  - [ ] 实现PS端驱动程序 (Linux kernel module)
- [ ] 性能优化
  - [ ] 流水线优化 (多层并行)
  - [ ] 内存带宽优化 (缓存策略)
  - [ ] 功耗优化

### 长期 (上板部署)
- [ ] FMQL30TAI BuyiBackend集成
- [ ] PL端硬件加速验证
- [ ] 完整BitNet b1.58推理
- [ ] 多模型支持
- [ ] 生产环境部署

---

## 关键文档

| 文档 | 说明 |
|------|------|
| [plan/PHASE_3_5_SUMMARY.md](PHASE_3_5_SUMMARY.md) | Phase 3.5完成总结 |
| [plan/PHASE_4_VIVADO_PLANNING.md](PHASE_4_VIVADO_PLANNING.md) | Phase 4 Vivado IP核开发规划 |
| [plan/flickering-jumping-frost.md](plan/flickering-jumping-frost.md) | 详细项目计划 |
| [CLAUDE.md](CLAUDE.md) | 工作区系统指令 |

---

## 环境配置

### 编译环境
- **操作系统**: Windows 11
- **编译器**: MSVC (Visual Studio 17 2022)
- **CMake**: 3.24+
- **Icraft SDK**: v3.33.1 (x86_64, Windows)

### Python环境
```bash
conda activate icraft_env
# 已安装: torch, transformers, safetensors, onnx, numpy, huggingface_hub
```

### 关键编译参数
```cmake
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
```

---

## 常见问题

### Q1: 如何运行完整的验证流程?
```bash
python quick_test.py
```

### Q2: 权重文件在哪里?
```
models/output/q_proj_weights.bin (1.6MB)
```

### Q3: 如何查看测试结果?
运行test_real_weights.exe后，查看输出:
- ✓ PASS: 所有2560个输出与参考实现匹配 (正常情况)
- ✗ FAIL: 若出现不匹配，检查权重packing方向或计算逻辑

### Q4: 如何扩展到多batch?
修改test_real_weights.cpp中的batch参数，重新编译即可。

### Q5: 下一步是什么?
Phase 3端到端验证: icraft parse + optimize + run

---


**最后更新**: 2026-02-11
**项目状态**: Phase 3.5 ✓ COMPLETE
**下一步**: Phase 3 端到端验证
