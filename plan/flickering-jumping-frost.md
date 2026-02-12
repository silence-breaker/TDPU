# BitLinear 自定义算子开发计划

## Context

**问题**: 参加复旦微集创赛（任务二：自定义硬件算子），需要将 BitNet b1.58 模型的核心 `BitLinear` 算子接入 Icraft 工具链，最终在 FMQL30TAI 平台上实现 PS+PL+NPU 异构协同推理。

**当前状态 (已更新)**:
- [x] Phase 1 完成: RTL 升级到 LEN=32, Verilator 仿真 4 Case 全部通过 (延迟 6 拍)
- [x] RTL 优化: 动态位宽(9→14bit)、数据通路去复位、加法树直连PE输出、generate if-else 消除越界
- [x] Phase 2 代码完成: icraft_plugin/ 全部文件已创建
- [x] Phase 2 编译通过: icraft.tdpu.bitlinear.dll + test_bitlinear.exe 均编译成功
- [x] Phase 2 验证通过: test_bitlinear.exe 2/2 PASS (All+1=640, Mixed=0)
- [x] Phase 3 单层 ONNX 导出: single_layer_bitlinear.onnx (q_proj, 1.6KB)
- [x] 权重 packing 方向修正: [M/4, K] (packing 在 M 维度), 全部代码已同步
- [x] Phase 3.5 真实权重验证: PS-PL硬件交互模拟 ✓ PASS (2560/2560 outputs match)
- [ ] Phase 3 端到端: icraft parse + optimize + run 验证

**本次目标**: 升级 RTL 到 LEN=32，并完成 Icraft 自定义算子注册 + HostBackend CPU 仿真，使 `icraft run` 能在 PC 上跑通 BitLinear 计算图。

---

## 当前进展与发现
* icraft parse 命令行工具是为标准图像模型 → Buyi 硬件流程设计的，需要大量预处理参数（pre_method, pre_scale, channel_swap 等），不支持 Host target。对于自定义算子场景，正确的端到端路径是：

1. PC 仿真验证（已完成）：通过 C++ XIR API 手动构建网络 + HostBackend 前向，test_bitlinear.exe 2/2 PASS
2. 真实权重验证（已完成）：扩展 test 加载 safetensors 中的真实 q_proj 权重，test_real_weights.exe PASS
3. 上板部署：在 FMQL30TAI 上注册 BuyiBackend 前向，通过 PL 加速模块执行

* Phase 2 的核心目标——BitLinear 自定义算子注册 + HostBackend CPU 仿真——已经完全达成。Phase 3 的 ONNX 模型接入部分，单层 ONNX 已导出成功，但 icraft parse 命令行不适用于自定义算子。后续上板时需要通过 C++ API 直接构建网络或实现自定义 Parser 接口。

* Phase 3.5 真实权重验证完成：
  - 从 safetensors 成功提取 q_proj 权重 (640×2560 uint8, 1.6MB)
  - 权重分布: -1(25.17%), 0(49.62%), +1(25.21%) - 符合 BitNet 特性
  - PS-PL 硬件交互模拟: 生成随机激活值 → 构建 XIR 网络 → HostBackend 计算 → 验证结果
  - 所有 2560 个输出与参考实现完全匹配 ✓


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

// 算子节点 - 存储属性 (注意: 无 OneResult 模板参数)
class BitLinearNode : public OpNodeBase<BitLinearNode> {
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
#include <icraft-xir/core/reflection.h>
#include <icraft-xir/core/data_type.h>
#include <icraft-xir/core/layout.h>

// 注册和类型推断必须分开写
ICRAFT_REGISTER_OP_NODE(BitLinearNode);

ICRAFT_REGISTER_TINFER(BitLinearNode, HostTarget, [](const BitLinearNode* op) {
    op->validate();
    auto input_type = op->inputs[0].tensorType();
    auto batch = input_type.getDim(0);       // 用 getDim() 而非 shape()
    auto out_features = op->out_features;
    // TensorType 需要 3 参数: (ScalarType, Array<int64_t>, Layout)
    auto output_type = TensorType(
        IntegerType::SInt32(),
        Array<int64_t>{batch, out_features},
        Layout("RC")
    );
    return Array<TensorType>{output_type};
});
```

### Step 2.3 实现 HostBackend 前向

**文件**: `icraft_plugin/src/bitlinear_host_forward.cpp`

核心逻辑 — 用 C++ 模拟 FPGA 的 ternary matmul:

```cpp
// forward 签名: 4 个参数 (含 outputs)
// 注意: inputs 只含运行时张量 (激活值), 权重通过 op.paramsInputs() 获取
auto bitlinear_forward = [](const tdpu::BitLinear& op,
                            const std::vector<Tensor>& inputs,
                            const std::vector<Tensor>& /*outputs*/,
                            HostBackend backend) -> std::vector<Tensor>
{
    auto activation = inputs[0];  // [batch, K] INT8
    // 权重不在 inputs 中! 从 Operation 的 Params 获取
    auto params_list = op.paramsInputs();
    auto* w_ptr = params_list[0].data<uint8_t>().get();

    int64_t K = op->in_features;
    int64_t M = op->out_features;
    int64_t batch = op->inputs[0].tensorType().getDim(0);

    auto output_type = TensorType(IntegerType::SInt32(),
        Array<int64_t>{batch, M}, Layout("RC"));
    auto output = Tensor(output_type).mallocOn(HostDevice::MemRegion());

    auto* act_ptr = reinterpret_cast<const int8_t*>(activation.data().cptr());
    auto* out_ptr = reinterpret_cast<int32_t*>(output.data().cptr());

    // Ternary MatMul (与 RTL 行为一致)
    for (int64_t b = 0; b < batch; b++) {
        for (int64_t m = 0; m < M; m++) {
            int32_t acc = 0;
            for (int64_t k = 0; k < K; k++) {
                int8_t a = act_ptr[b * K + k];
                int byte_idx = (m * K + k) / 4;
                int bit_idx = (m * K + k) % 4;
                int w = unpack_ternary(w_ptr[byte_idx], bit_idx);
                if (w == 1)       acc += a;
                else if (w == -1) acc -= a;
            }
            out_ptr[b * M + m] = acc;
        }
    }
    return {output};
};

ICRAFT_ADD_OP_TO_BACKEND(BitLinear, HostBackend)
    .set_init(bitlinear_init)
    .set_forward(bitlinear_forward);
```

### Step 2.4 手动构建测试网络

**文件**: `icraft_plugin/test/test_bitlinear.cpp`

不依赖 ONNX 解析，直接用 XIR API 构建一个小型测试网络:

```cpp
// 创建网络 (需要 3 参数: name, Framework, version)
auto network = Network(name, Framework::ONNX, "1.0");

// Input: [1, 64] INT8 (TensorType 需要 Layout 参数)
auto input_type = TensorType(IntegerType::SInt8(),
    Array<int64_t>{1, 64}, Layout("RC"));
auto input_op = Input(Array<TensorType>{input_type});
network.addOp(input_op);

// Weight: [32, 16] packed ternary (用 Params 而非 Constant)
auto weight_type = TensorType(IntegerType::UInt8(),
    Array<int64_t>{32, 16}, Layout("RC"));
auto weight_data = std::shared_ptr<uint8_t[]>(new uint8_t[512]);
// ... 填充权重数据 ...
auto weight_param = Params(weight_data, "weight", weight_type);

// BitLinear: [1, 64] x [32, 64]^T → [1, 32]
auto bitlinear = tdpu::BitLinear(input_op[0], weight_param, 64, 32);
network.addOp(bitlinear);

// Output (接受 Array<Value>)
auto output_op = Output(Array<Value>{bitlinear[0]});
network.addOp(output_op);

// 运行
auto session = Session::Create<HostBackend>(network, {HostDevice::Default()});
session.apply();

// 准备输入 Tensor (用 write 写入数据, read 读取结果)
auto input_tensor = Tensor(input_type).mallocOn(HostDevice::MemRegion());
input_tensor.write(0, reinterpret_cast<char*>(data_ptr), byte_size);

auto result = session.forward({input_tensor});
result[0].read(reinterpret_cast<char*>(out_ptr), 0, byte_size);
```

### Step 2.5 CMake 构建配置

**文件**: `icraft_plugin/CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.24)
project(icraft_bitlinear_plugin LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

# MSVC 必须加 /Zc:__cplusplus, 否则 SDK 内部 wise_enum 会编译失败
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>")

# Icraft SDK
set(ICRAFT_SDK_DIR "C:/Icraft/CLI v3.33.1")
list(APPEND CMAKE_PREFIX_PATH "${ICRAFT_SDK_DIR}/cmake")
find_package(Icraft-HostBackend REQUIRED)

add_library(icraft.tdpu.bitlinear SHARED
    src/bitlinear_op.cpp
    src/bitlinear_host_forward.cpp
    src/bitlinear_pass.cpp
)
target_include_directories(icraft.tdpu.bitlinear PRIVATE include)
target_link_libraries(icraft.tdpu.bitlinear PRIVATE Icraft::HostBackend)

# 测试: 直接编译源文件 (DLL 无导出符号, 不生成 .lib)
add_executable(test_bitlinear
    test/test_bitlinear.cpp
    src/bitlinear_op.cpp
    src/bitlinear_host_forward.cpp
)
target_include_directories(test_bitlinear PRIVATE include)
target_link_libraries(test_bitlinear PRIVATE Icraft::HostBackend)
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
        auto matmul_p = IsOp<Matmul>();  // 注意: 类名是 Matmul 不是 MatMul
        network.rewrite(matmul_p, [&](Network& net, const MatchGroup& result) {
            Operation matmul = result.at(matmul_p);  // 返回 Operation 类型
            auto weight = matmul->inputs[1];
            if (!is_ternary_weight(weight)) return;

            auto input = matmul->inputs[0];
            auto weight_ttype = weight.tensorType();
            int64_t M = weight_ttype.getDim(0);       // 用 getDim() 而非 shape()
            int64_t K = weight_ttype.getDim(1) * 4;   // 解包后的实际维度
            auto bitlinear = tdpu::BitLinear(input, weight, K, M);
            net.replaceOpKeepUses(matmul, bitlinear);
        });
        return network;
    };
    return NetworkPass(pass_func, PassInfo("tdpu.ReplaceMatMulWithBitLinear"));
}
// 注册宏直接接受函数名
ICRAFT_REGISTER_PASS(ReplaceMatMulWithBitLinear);
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

## Phase 3.5: 真实权重验证 (PS-PL硬件交互模拟)

### Step 3.5.1 权重提取

**文件**: `TDPU/models/extract_weights.py`（新建）

从 safetensors 中提取 q_proj 权重并保存为二进制文件:

```bash
conda activate icraft_env
python models/extract_weights.py
```

输出: `models/output/q_proj_weights.bin` (1.6MB)

权重分布分析:
- -1 (0b00): 25.17% (稀疏性特征)
- 0 (0b01): 49.62% (高度稀疏)
- +1 (0b10): 25.21% (对称分布)

### Step 3.5.2 PS-PL硬件交互模拟

**文件**: `TDPU/icraft_plugin/test/test_real_weights.cpp`（新建）

完整的端到端验证流程:

1. **PS端**: 加载真实权重 (q_proj, 2560×2560)
2. **请求生成**: 创建随机激活值 [1, 2560] INT8
3. **PL端计算**: 通过 XIR API + HostBackend 执行 BitLinear
4. **结果验证**: 与 C++ 参考实现对比

编译:
```powershell
cd icraft_plugin/build
cmake --build . --config Release
```

运行:
```powershell
cd Release
./test_real_weights.exe "..\..\models\output\q_proj_weights.bin"
```

**测试结果** ✓ PASS:
- 权重加载: 1638400 bytes (640×2560 uint8)
- 激活值生成: [1, 2560] INT8 随机值
- BitLinear计算: 2560 个输出
- 验证: 所有 2560 个输出与参考实现完全匹配

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
| 新建 | `TDPU/icraft_plugin/test/test_real_weights.cpp` | PS-PL硬件交互模拟 (真实权重) |
| 新建 | `TDPU/models/export_single_layer.py` | 单层 ONNX 导出 |
| 新建 | `TDPU/models/extract_weights.py` | 从 safetensors 提取权重 |
| 参考 | `Icraft文档/extensibility/customop.md` | 自定义算子文档 |
| 参考 | `models/microsoftbitnet_b1.58_2B_4T/transfer_safetensors2onnx.py` | 已有导出脚本 |

---

## 验证计划

1. **Phase 1 验证**: `./run_sim.sh` 输出正确 + waveform 时序正确
2. **Phase 2 验证**: `test_bitlinear.exe` 输出与 numpy 手算一致
3. **Phase 3 验证**: `icraft run` 端到端输出与 PyTorch 推理结果对齐（INT32 无损）

## 风险与注意事项

- **编译环境**: Icraft SDK 编译必须在 Windows PowerShell 中进行，WSL 的 arm64 版本不支持编译
- **MSVC 必须加 `/Zc:__cplusplus`**: 否则 SDK 内部 `wise_enum_detail.h` 会因 `__cplusplus` 宏值不正确而编译失败
- **权重编码一致性**: `package_def.sv` 的编码 (W_NEG=2'b00, W_ZERO=2'b01, W_POS=2'b10) 与模型 safetensors 的 packed U8 编码一致，无需转换

## Icraft SDK v3.33.1 API 踩坑记录

以下是实际编译中发现的 API 与文档/猜测不一致之处，供后续开发参考：

| 原始写法 (错误) | 正确写法 | 说明 |
|---|---|---|
| `OpNodeBase<T, OneResult>` | `OpNodeBase<T>` | 无 `OneResult` 模板参数 |
| `#include <icraft-xir/core/op.h>` | `<icraft-xir/core/operation.h>` | 头文件名不同 |
| `ICRAFT_REGISTER_OP_NODE(T).set_tinfer(...)` | 分开写 `ICRAFT_REGISTER_OP_NODE(T);` + `ICRAFT_REGISTER_TINFER(T, Target, lambda);` | 注册和类型推断必须分开 |
| `input_type.shape()[0]` | `input_type.getDim(0)` | `TensorType` 无 `shape()` 方法 |
| `TensorType(dtype, {dims})` | `TensorType(dtype, Array<int64_t>{dims}, Layout("RC"))` | 构造需要 3 参数，必须传 `Layout` |
| `Tensor::Create(dtype, device)` | `Tensor(dtype).mallocOn(HostDevice::MemRegion())` | 无 `Create` 静态方法 |
| `tensor.data<T>()` | `reinterpret_cast<T*>(tensor.data().cptr())` | `data()` 返回 `MemPtr`，需 `.cptr()` 获取 `char*` |
| `(T*)tensor.data()` | `reinterpret_cast<T*>(tensor.data().cptr())` | `MemPtr` 不支持 C-style cast |
| `IsOp<MatMul>()` | `IsOp<Matmul>()` | 类名是 `Matmul` (小写 m) |
| `ICRAFT_REGISTER_PASS("name").set_creator(func)` | `ICRAFT_REGISTER_PASS(FuncName);` | 宏直接接受函数名 |
| `Network::Create(name)` | `Network(name, Framework::ONNX, "1.0")` | 无 `Create` 静态方法，构造需要 3 参数 |
| `Constant(type, data, size)` | `Params(shared_ptr, name, type)` | 无 `Constant` 类，用 `Params` 创建权重 |
| `Input(TensorType)` | `Input(Array<TensorType>{...})` | 接受 `Array<TensorType>` |
| `Output(Value)` | `Output(Array<Value>{...})` | 接受 `Array<Value>` |
| `find_package(Icraft COMPONENTS ...)` | `find_package(Icraft-HostBackend REQUIRED)` | CMake 包名不同 |
| test 链接 DLL | test 直接编译源文件 | DLL 无导出符号不生成 `.lib`，test 需直接编译 |
| forward 3 参数 | forward 4 参数 (含 outputs) | `set_forward` 的 lambda 签名需要 4 个参数 |
| forward 中 `inputs[1]` 取权重 | `op.paramsInputs()[0].data<uint8_t>().get()` | `inputs` 只含运行时张量，Params 权重需从 Operation 获取 |
| 权重 packing 在 K 维度 `[M, K/4]` | 权重 packing 在 M 维度 `[M/4, K]` | safetensors 中 q_proj shape=[640,2560]，M=2560, K=2560 |
| `byte_idx = (m*K+k)/4` | `byte_idx = (m/4)*K + k, bit_idx = m%4` | 寻址方式随 packing 方向改变 |
