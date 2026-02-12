# Phase 3: 端到端ONNX模型验证与BitLinear算子替换

## 任务概述

**目标**: 导出完整的BitNet b1.58 ONNX模型，通过Icraft工具链进行编译和仿真，最后将MatMul算子替换为自定义BitLinear算子。

**预期成果**:
- 完整ONNX模型导出
- Icraft编译和仿真验证
- MatMul → BitLinear算子替换
- 完整的bug记录和文档

---

## 工作计划

### Step 1: 导出完整ONNX模型
- [ ] 加载BitNet b1.58完整模型
- [ ] 导出为ONNX格式
- [ ] 验证ONNX模型结构
- [ ] 记录模型信息

### Step 2: Icraft编译和仿真
- [ ] 使用icraft parse解析ONNX
- [ ] 使用icraft optimize优化
- [ ] 使用icraft run进行仿真
- [ ] 记录编译过程和错误

### Step 3: MatMul → BitLinear替换
- [ ] 识别所有MatMul算子
- [ ] 应用bitlinear_pass进行替换
- [ ] 验证替换后的模型
- [ ] 性能对比

---

## 文件结构规划

```
TDPU/
├── models/
│   ├── export_single_layer.py          # 单层导出 (已有)
│   ├── export_full_model.py            # 完整模型导出 (新建)
│   ├── output/
│   │   ├── q_proj_weights.bin          # 单层权重 (已有)
│   │   ├── bitnet_b1.58_full.onnx      # 完整ONNX模型 (新建)
│   │   ├── bitnet_b1.58_full.raw       # 权重二进制 (新建)
│   │   └── icraft_output/              # Icraft输出目录 (新建)
│   │       ├── model_parsed.json       # parse输出
│   │       ├── model_parsed.raw
│   │       ├── model_optimized.json    # optimize输出
│   │       ├── model_optimized.raw
│   │       └── logs/                   # 编译日志
│   └── microsoftbitnet_b1.58_2B_4T/
│       ├── model.safetensors           # 原始模型 (已有)
│       └── ...
│
├── phase3_logs/                        # Phase 3工作日志 (新建)
│   ├── export_log.md                   # 导出过程记录
│   ├── icraft_compile_log.md           # 编译过程记录
│   ├── bugs_found.md                   # Bug记录
│   └── performance_report.md           # 性能对比报告
│
└── ...
```

---

## 详细步骤

### Step 1: 导出完整ONNX模型

**创建文件**: `models/export_full_model.py`

功能:
1. 加载BitNet b1.58完整模型
2. 导出为ONNX格式
3. 记录模型信息 (层数、参数量、输入输出形状)
4. 验证ONNX模型

**预期输出**:
- `models/output/bitnet_b1.58_full.onnx` (~500MB)
- 模型信息日志

### Step 2: Icraft编译和仿真

**命令流程**:
```bash
# 1. Parse ONNX
icraft parse --framework Onnx --network bitnet_b1.58_full.onnx --jr_path ./icraft_output/

# 2. Optimize
icraft optimize --json ./icraft_output/model_parsed.json --raw ./icraft_output/model_parsed.raw --jr_path ./icraft_output/

# 3. Run (HostBackend仿真)
icraft run --json ./icraft_output/model_optimized.json --raw ./icraft_output/model_optimized.raw --backend host
```

**预期结果**:
- 编译成功或记录错误
- 仿真输出结果

### Step 3: MatMul → BitLinear替换

**修改**: `icraft_plugin/src/bitlinear_pass.cpp`

功能:
1. 在optimize阶段自动检测MatMul
2. 检查权重是否为ternary编码
3. 替换为BitLinear算子
4. 记录替换信息

---

## Bug记录模板

**文件**: `phase3_logs/bugs_found.md`

```markdown
# Phase 3 Bug记录

## Bug #1: [标题]
- **发现时间**: YYYY-MM-DD HH:MM
- **发现阶段**: [导出/编译/仿真/替换]
- **错误信息**: [完整错误信息]
- **根本原因**: [分析]
- **解决方案**: [修复方法]
- **状态**: [未解决/已解决/待验证]

---
```

---

## 预期问题与解决方案

| 问题 | 可能原因 | 解决方案 |
|------|--------|--------|
| ONNX导出失败 | 模型不兼容 | 检查PyTorch版本、ONNX opset |
| icraft parse失败 | 不支持的算子 | 检查模型中的算子类型 |
| 内存不足 | 模型太大 | 分层导出、量化处理 |
| MatMul替换失败 | 权重格式不匹配 | 检查权重packing方向 |

---

## 时间规划

| 任务 | 预期时间 |
|------|---------|
| 导出ONNX | 30分钟 |
| Icraft编译 | 1小时 |
| 仿真运行 | 30分钟 |
| MatMul替换 | 1小时 |
| 文档记录 | 30分钟 |
| **总计** | **~4小时** |

---

**创建时间**: 2026-02-11
**状态**: 规划中
**下一步**: 开始Step 1 - 导出完整ONNX模型
