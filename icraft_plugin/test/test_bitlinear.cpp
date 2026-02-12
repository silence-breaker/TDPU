/**
 * test_bitlinear.cpp - 手动构建 XIR 网络测试 BitLinear 算子
 *
 * 不依赖 ONNX 解析, 直接用 XIR API 构建小型测试网络:
 *   Input[1,64] INT8 -> BitLinear(K=64, M=32) -> Output[1,32] INT32
 *
 * 在 Windows PowerShell 中编译运行:
 *   cd icraft_plugin/build && cmake --build . --config Release
 *   ./Release/test_bitlinear.exe
 */
#include "bitlinear_op.h"
#include <icraft-xir/core/network.h>
#include <icraft-xir/core/data.h>
#include <icraft-xir/core/data_type.h>
#include <icraft-xir/core/layout.h>
#include <icraft-xrt/core/session.h>
#include <icraft-xrt/core/tensor.h>
#include <icraft-backends/hostbackend/backend.h>
#include <icraft-xrt/dev/host_device.h>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <memory>

using namespace icraft::xir;
using icraft::xrt::Session;
using icraft::xrt::Tensor;
using icraft::xrt::HostBackend;
using icraft::xrt::HostDevice;

// 生成测试权重: 全 +1 (packed uint8)
// 权重布局: [M/4, K], packing 在 M 维度
// 编码: 2'b10 = +1, 每个 byte 存 4 个 M 方向的权重 = 0xAA
static std::vector<uint8_t> generate_all_pos_weights(int64_t M, int64_t K) {
    int64_t packed_size = (M / 4) * K;
    return std::vector<uint8_t>(packed_size, 0xAA);  // 10101010 = 4x(+1)
}

// 生成混合权重: 前半 K 为 +1, 后半 K 为 -1
// 权重布局: [M/4, K], packing 在 M 维度
static std::vector<uint8_t> generate_mixed_weights(int64_t M, int64_t K) {
    int64_t packed_size = (M / 4) * K;
    std::vector<uint8_t> w(packed_size, 0);
    for (int64_t m = 0; m < M; m++) {
        for (int64_t k = 0; k < K; k++) {
            int byte_idx = (m / 4) * K + k;
            int bit_idx  = m % 4;
            uint8_t val = (k < K / 2) ? 0x2 : 0x0;  // +1 or -1
            w[byte_idx] |= (val << (bit_idx * 2));
        }
    }
    return w;
}

// C++ 参考实现: ternary matmul (权重布局 [M/4, K], packing 在 M 维度)
static std::vector<int32_t> reference_ternary_matmul(
    const int8_t* act, const uint8_t* w_packed,
    int64_t batch, int64_t M, int64_t K)
{
    std::vector<int32_t> out(batch * M, 0);
    for (int64_t b = 0; b < batch; b++) {
        for (int64_t m = 0; m < M; m++) {
            int32_t acc = 0;
            for (int64_t k = 0; k < K; k++) {
                int8_t a = act[b * K + k];
                int byte_idx = (m / 4) * K + k;
                int bit_idx  = m % 4;
                int val = (w_packed[byte_idx] >> (bit_idx * 2)) & 0x3;
                int w = (val == 0) ? -1 : (val == 2) ? 1 : 0;
                acc += a * w;
            }
            out[b * M + m] = acc;
        }
    }
    return out;
}

static bool run_test(const char* name,
                     int64_t batch, int64_t K, int64_t M,
                     int8_t input_val,
                     const std::vector<uint8_t>& weights,
                     const std::vector<int32_t>& expected)
{
    std::cout << "[TEST] " << name << " ..." << std::endl;

    // 1. 构建网络
    auto network = Network(name, Framework::ONNX, "1.0");

    // Input: [batch, K] INT8
    auto input_type = TensorType(IntegerType::SInt8(),
        Array<int64_t>{batch, K}, Layout("RC"));
    auto input_op = Input(Array<TensorType>{input_type});
    network.addOp(input_op);

    // Weight: [M/4, K] packed uint8 (packing 在 M 维度, 作为 Params)
    auto weight_type = TensorType(IntegerType::UInt8(),
        Array<int64_t>{M / 4, K}, Layout("RC"));
    auto weight_data = std::shared_ptr<uint8_t[]>(
        new uint8_t[weights.size()]);
    std::memcpy(weight_data.get(), weights.data(), weights.size());
    auto weight_param = Params(weight_data, "weight", weight_type);

    // BitLinear op
    auto bitlinear = tdpu::BitLinear(input_op[0], weight_param, K, M);
    network.addOp(bitlinear);

    // Output
    auto output_op = Output(Array<Value>{bitlinear[0]});
    network.addOp(output_op);

    // 2. 创建 Session
    auto session = Session::Create<HostBackend>(
        network, {HostDevice::Default()});
    session.apply();

    // 3. 准备输入 Tensor
    auto input_tensor = Tensor(input_type).mallocOn(HostDevice::MemRegion());
    {
        std::vector<int8_t> input_data(batch * K, input_val);
        input_tensor.write(0, reinterpret_cast<char*>(input_data.data()),
                           input_data.size() * sizeof(int8_t));
    }

    // 4. 前向
    auto outputs = session.forward({input_tensor});

    // 5. 验证
    bool pass = true;
    std::vector<int32_t> result(batch * M);
    outputs[0].read(reinterpret_cast<char*>(result.data()), 0,
                    result.size() * sizeof(int32_t));

    for (int64_t i = 0; i < batch * M; i++) {
        if (result[i] != expected[i]) {
            std::cout << "  FAIL at [" << i << "]: got "
                      << result[i] << ", expected " << expected[i]
                      << std::endl;
            pass = false;
        }
    }

    if (pass) {
        std::cout << "  PASS (output[0]=" << result[0] << ")" << std::endl;
    }
    return pass;
}

int main() {
    std::cout << "=== BitLinear HostBackend Test ===" << std::endl;

    constexpr int64_t batch = 1, K = 64, M = 32;
    constexpr int8_t test_val = 10;
    int total = 0, passed = 0;

    // Test 1: 全 +1 权重, input=10 -> 每个输出 = 10*64 = 640
    {
        auto w = generate_all_pos_weights(M, K);
        std::vector<int8_t> act(batch * K, test_val);
        auto ref = reference_ternary_matmul(act.data(), w.data(), batch, M, K);
        total++;
        if (run_test("All +1 weights", batch, K, M, test_val, w, ref))
            passed++;
    }

    // Test 2: 混合权重 (前半+1, 后半-1), input=10
    // -> 每个输出 = 10*32 + (-10)*32 = 320 - 320 = 0
    {
        auto w = generate_mixed_weights(M, K);
        std::vector<int8_t> act(batch * K, test_val);
        auto ref = reference_ternary_matmul(act.data(), w.data(), batch, M, K);
        total++;
        if (run_test("Mixed +1/-1 weights", batch, K, M, test_val, w, ref))
            passed++;
    }

    std::cout << "\n=== Results: " << passed << "/" << total
              << " passed ===" << std::endl;
    return (passed == total) ? 0 : 1;
}
