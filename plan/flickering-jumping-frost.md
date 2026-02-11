# BitLinear 自定义算子开发计划

## Context

**问题**: 参加复旦微集创赛（任务二：自定义硬件算子），需要将 BitNet b1.58 模型的核心 `BitLinear` 算子接入 Icraft 工具链，最终在 FMQL30TAI 平台上实现 PS+PL+NPU 异构协同推理。

**当前状态 (已更新)**:
- [x] Phase 1 完成: RTL 升级到 LEN=32, Verilator 仿真 4 Case 全部通过 (延迟 6 拍)
- [x] RTL 优化: 动态位宽(9→14bit)、数据通路去复位、加法树直连PE输出、generate if-else 消除越界
- [x] Phase 2 代码完成: icraft_plugin/ 全部文件已创建
- [ ] Phase 2 验证: 需在 Windows PowerShell 编译并运行 test_bitlinear
- [ ] Phase 3: ONNX 模型接入

**本次目标**: 升级 RTL 到 LEN=32，并完成 Icraft 自定义算子注册 + HostBackend CPU 仿真，使 `icraft run` 能在 PC 上跑通 BitLinear 计算图。

---

## 总体路线 (3 个 Phase)

```
Phase 1: RTL 升级 (WSL Verilator)
   └─ vec_multi_core LEN=16→32, 更新 testbench, 验证通过

Phase 2: Icraft 自定义算子 (Windows Icraft SDK 编译)
   └─ 注册 BitLinear XIR 算子
   └─ 实现 HostBackend 前向 (C++ ternary matmul)
   └─ 手动构建 XIR 测试网络, icraft run 验证

Phase 3: ONNX 模型接入
   └─ 导出单层 BitLinear ONNX
   └─ 通过优化 Pass 替换 MatMul → BitLinear
   └─ 端到端: ONNX → parse → optimize → run
```

---

## Phase 1: RTL 升级到 LEN=32

### Step 1.1 修改 vec_multi_core.sv

**文件**: `TDPU/TDPU/vec_multi_core.sv`

修改内容:
- 第 8 行: `parameter int LEN = 16` → `parameter int LEN = 32`
- 其余代码已参数化，无需改动（TREE_DEPTH 自动变为 5，流水线延迟 1+5=6 拍）

### Step 1.2 更新 sim_main.cpp

**文件**: `TDPU/TDPU/sim_main.cpp`

修改内容:
1. `set_all_inputs` lambda: 外层循环 `k < 4` → `k < 8`（256-bit = 8×uint32_t）
2. `set_all_weights` lambda: 循环 `i < 16` → `i < 32`，类型改为 `uint64_t`（64-bit 权重）
3. 更新期望值注释:
   - Case 1: 全+1, input=10 → 期望 320（10×32）
   - Case 2: 全-1, input=5 → 期望 -160（-5×32）
   - Case 3: Burst -1, inputs 1,2,3 → 期望 -32, -64, -96
4. 增加 Case 4: 混合权重测试（部分+1, 部分-1, 部分0）

### Step 1.3 验证

```bash
cd TDPU/TDPU && ./run_sim.sh
```
检查输出值与期望一致，查看 waveform.vcd 确认时序。

---

## Phase 2: Icraft 自定义算子集成

### Step 2.1 创建项目结构

```
TDPU/icraft_plugin/
├── CMakeLists.txt              # 构建配置
├── include/
│   └── bitlinear_op.h          # BitLinear 算子定义
├── src/
│   ├── bitlinear_op.cpp        # 算子注册 + 类型推断
│   ├── bitlinear_host_forward.cpp  # HostBackend 前向实现
│   └── bitlinear_pass.cpp      # 优化 Pass (MatMul→BitLinear 替换)
├── test/
│   └── test_bitlinear.cpp      # 手动构建 XIR 网络测试
└── config/
    └── bitlinear_test.toml     # icraft run 配置
```

### Step 2.2 注册 BitLinear XIR 算子

**文件**: `icraft_plugin/include/bitlinear_op.h` + `icraft_plugin/src/bitlinear_op.cpp`

```cpp
using namespace icraft::xir;

namespace tdpu {

// 算子节点 - 存储属性
class BitLinearNode : public OpNodeBase<BitLinearNode, OneResult> {
public:
    int64_t in_features;    // 输入特征维度 (K)
    int64_t out_features;   // 输出特征维度 (M)

    ICRAFT_DECLARE_ATTRS(BitLinearNode) {
        ICRAFT_ATTR_FIELD(in_features).set_lower_bound(1);
        ICRAFT_ATTR_FIELD(out_features).set_lower_bound(1);
    }
};

// 算子引用类
class BitLinear : public OpBase<BitLinear, BitLinearNode> {
public:
    BitLinear() = default;

    // 构造: input=[batch, in_features] INT8, weight=[out_features, in_features] ternary
    BitLinear(Value input, Value weight, int64_t in_features, int64_t out_features) {
        auto node = make_object<BitLinearNode>();
        node->in_features = in_features;
        node->out_features = out_features;
        data_ = std::move(node);
        this->setInputs({input, weight});
    }
};

} // namespace tdpu
```

注册 + 类型推断:
```cpp
// bitlinear_op.cpp
ICRAFT_REGISTER_OP_NODE(tdpu::BitLinearNode)
.set_tinfer<tdpu::BitLinearNode, HostTarget>([](const auto* op) {
    op->validate();
    auto input_type = op->inputs[0].tensorType();
    auto batch = input_type.shape()[0];
    auto out_features = op->out_features;
    // 输出: [batch, out_features] INT32
    auto output_type = TensorType(IntegerType::SInt32(), {batch, out_features});
    return Array<TensorType>{output_type};
});
```

### Step 2.3 实现 HostBackend 前向

**文件**: `icraft_plugin/src/bitlinear_host_forward.cpp`

核心逻辑 — 用 C++ 模拟 FPGA 的 ternary matmul:

```cpp
auto bitlinear_forward = [](const tdpu::BitLinear& op,
                            const std::vector<Tensor>& inputs,
                            HostBackend backend) {
    auto activation = inputs[0];  // [batch, K] INT8
    auto weight = inputs[1];      // [M, K] packed ternary (uint8, 4 weights per byte)

    int64_t batch = activation.shape()[0];
    int64_t K = op->in_features;
    int64_t M = op->out_features;

    // 分配输出 [batch, M] INT32
    auto output_type = TensorType(IntegerType::SInt32(), {batch, M});
    auto output = Tensor::Create(output_type, backend);

    auto* act_ptr = activation.data<int8_t>();
    auto* w_packed = weight.data<uint8_t>();
    auto* out_ptr = output.data<int32_t>();

    // 解包权重: uint8 → 4 个 ternary 值 {-1, 0, +1}
    // 编码: 2'b00=-1, 2'b01=0, 2'b10=+1
    auto unpack_weight = [](uint8_t packed, int idx) -> int {
        int val = (packed >> (idx * 2)) & 0x3;
        if (val == 0) return -1;      // 2'b00
        if (val == 2) return  1;      // 2'b10
        return 0;                      // 2'b01 or 2'b11
    };

    // Ternary MatMul: output[b][m] = sum_k(act[b][k] * w_ternary[m][k])
    for (int64_t b = 0; b < batch; b++) {
        for (int64_t m = 0; m < M; m++) {
            int32_t acc = 0;
            for (int64_t k = 0; k < K; k++) {
                int8_t a = act_ptr[b * K + k];
                // 每个 uint8 包含 4 个权重
                int byte_idx = (m * K + k) / 4;
                int bit_idx = (m * K + k) % 4;
                int w = unpack_weight(w_packed[byte_idx], bit_idx);
                // Ternary multiply: 无需 DSP
                if (w == 1)       acc += a;
                else if (w == -1) acc -= a;
                // w == 0: skip
            }
            out_ptr[b * M + m] = acc;
        }
    }

    return std::vector<Tensor>{output};
};

ICRAFT_ADD_OP_TO_BACKEND(tdpu::BitLinear, HostBackend)
    .set_init([](const tdpu::BitLinear& op, HostBackend backend) {})
    .set_forward(bitlinear_forward);
```

### Step 2.4 手动构建测试网络

**文件**: `icraft_plugin/test/test_bitlinear.cpp`

不依赖 ONNX 解析，直接用 XIR API 构建一个小型测试网络:

```cpp
// 创建网络
auto network = Network::Create("bitlinear_test");

// Input: [1, 64] INT8 激活值
auto input_type = TensorType(IntegerType::SInt8(), {1, 64});
auto input_op = Input(input_type);
network.addOp(input_op);

// Weight: [32, 64] packed ternary (常量)
// 32*64/4 = 512 bytes packed
auto weight_data = generate_test_weights(32, 64);  // 生成测试权重
auto weight_op = Constant(weight_type, weight_data);
network.addOp(weight_op);

// BitLinear: [1, 64] x [32, 64]^T → [1, 32]
auto bitlinear = tdpu::BitLinear(input_op[0], weight_op[0], 64, 32);
network.addOp(bitlinear);

// Output
auto output_op = Output(bitlinear[0]);
network.addOp(output_op);

// 序列化
network.dumpJsonToFile("bitlinear_test.json");
network.dumpParamsToFile("bitlinear_test.raw");

// 运行
auto session = Session::Create<HostBackend>(network, {HostDevice::Default()});
session.apply();
auto result = session.forward({test_input_tensor});
// 验证结果与 Python numpy 计算一致
```

### Step 2.5 CMake 构建配置

**文件**: `icraft_plugin/CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.14)
project(icraft_bitlinear_plugin)

# Icraft SDK (Windows 环境下)
find_package(Icraft REQUIRED COMPONENTS xir xrt hostbackend)

add_library(icraft.tdpu.bitlinear SHARED
    src/bitlinear_op.cpp
    src/bitlinear_host_forward.cpp
)
target_include_directories(icraft.tdpu.bitlinear PRIVATE include)
target_link_libraries(icraft.tdpu.bitlinear PRIVATE
    Icraft::XIR Icraft::XRT Icraft::HostBackend
)

# 测试
add_executable(test_bitlinear test/test_bitlinear.cpp)
target_link_libraries(test_bitlinear PRIVATE
    icraft.tdpu.bitlinear Icraft::XIR Icraft::XRT Icraft::HostBackend
)
```

**编译环境**: 在 Windows PowerShell 中执行（Icraft x86_64 已在 PATH）:
```powershell
cd icraft_plugin
mkdir build && cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
```

### Step 2.6 验证

1. 运行 `test_bitlinear.exe`，检查输出与手算/numpy 结果一致
2. 用 `icraft run` 加载序列化的 json/raw:
```powershell
icraft run --json bitlinear_test.json --raw bitlinear_test.raw --backend host
```

---

## Phase 3: ONNX 模型接入

### Step 3.1 导出单层 BitLinear ONNX

**文件**: `TDPU/models/export_single_layer.py`（新建）

从完整模型中提取单个 BitLinear 层导出为 ONNX，用于验证:
- 输入: [1, 2560] float32 (会被量化为 INT8)
- 权重: [2560, 2560] packed ternary
- 输出: [1, 2560] int32

### Step 3.2 实现优化 Pass

**文件**: `icraft_plugin/src/bitlinear_pass.cpp`

在 Icraft 优化阶段，将 ONNX 解析出的 `MatMul` 算子替换为 `BitLinear`:

```cpp
static Pass ReplaceMatMulWithBitLinear() {
    auto pass_func = [](Network network, const PassContext& ctx) {
        auto matmul_p = IsOp<MatMul>();
        network.rewrite(matmul_p, [&](Network& net, const MatchGroup& result) {
            auto matmul = result.at(matmul_p);
            // 检查权重是否为 ternary packed 格式
            auto weight = matmul->inputs[1];
            if (!is_ternary_weight(weight)) return;  // 跳过非 ternary 的 MatMul

            auto input = matmul->inputs[0];
            auto K = get_in_features(weight);
            auto M = get_out_features(weight);
            auto bitlinear = tdpu::BitLinear(input, weight, K, M);
            net.replaceOpKeepUses(matmul, bitlinear);
        });
        return network;
    };
    return NetworkPass(pass_func, PassInfo("tdpu.ReplaceMatMulWithBitLinear"));
}
ICRAFT_REGISTER_PASS("tdpu.ReplaceMatMulWithBitLinear")
    .set_creator(ReplaceMatMulWithBitLinear);
```

### Step 3.3 端到端验证

```powershell
# 1. 解析 ONNX
icraft parse --framework Onnx --network single_layer.onnx --jr_path ./output/

# 2. 优化 (触发 MatMul→BitLinear 替换)
icraft optimize --json ./output/model_parsed.json --raw ./output/model_parsed.raw --jr_path ./output/

# 3. 运行 HostBackend 仿真
icraft run --json ./output/model_optimized.json --raw ./output/model_optimized.raw --backend host
```

---

## 关键文件清单

| 操作 | 文件路径 | 说明 |
|------|---------|------|
| 修改 | `TDPU/TDPU/vec_multi_core.sv` | LEN=16→32 |
| 修改 | `TDPU/TDPU/sim_main.cpp` | 适配 32 并行度 |
| 新建 | `TDPU/icraft_plugin/CMakeLists.txt` | 构建配置 |
| 新建 | `TDPU/icraft_plugin/include/bitlinear_op.h` | 算子定义 |
| 新建 | `TDPU/icraft_plugin/src/bitlinear_op.cpp` | 算子注册 |
| 新建 | `TDPU/icraft_plugin/src/bitlinear_host_forward.cpp` | HostBackend 前向 |
| 新建 | `TDPU/icraft_plugin/src/bitlinear_pass.cpp` | 优化 Pass |
| 新建 | `TDPU/icraft_plugin/test/test_bitlinear.cpp` | 测试程序 |
| 新建 | `TDPU/models/export_single_layer.py` | 单层 ONNX 导出 |
| 参考 | `Icraft文档/extensibility/customop.md` | 自定义算子文档 |
| 参考 | `models/microsoftbitnet_b1.58_2B_4T/transfer_safetensors2onnx.py` | 已有导出脚本 |

---

## 验证计划

1. **Phase 1 验证**: `./run_sim.sh` 输出正确 + waveform 时序正确
2. **Phase 2 验证**: `test_bitlinear.exe` 输出与 numpy 手算一致
3. **Phase 3 验证**: `icraft run` 端到端输出与 PyTorch 推理结果对齐（INT32 无损）

## 风险与注意事项

- **编译环境**: Icraft SDK 编译必须在 Windows PowerShell 中进行，WSL 的 arm64 版本不支持编译
- **权重编码一致性**: `package_def.sv` 的编码 (W_NEG=2'b00, W_ZERO=2'b01, W_POS=2'b10) 与模型 safetensors 的 packed U8 编码一致，无需转换
- **Icraft API 版本**: 具体 API 签名需以实际安装的 Icraft SDK 头文件为准，上述代码为基于文档的参考实现
