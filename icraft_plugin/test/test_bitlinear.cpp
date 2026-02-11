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
#include <icraft-xir/core/tensor.h>
#include <icraft-xir/core/type.h>
#include <icraft-xir/ops/input.h>
#include <icraft-xir/ops/output.h>
#include <icraft-xir/ops/constant.h>
#include <icraft-xrt/core/session.h>
#include <icraft-backends/hostbackend/backend.h>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <cmath>

using namespace icraft::xir;

// 生成测试权重: 全 +1 (packed uint8)
// 编码: 2'b10 = +1, 每个 byte 存 4 个权重 = 0xAA
static std::vector<uint8_t> generate_all_pos_weights(int64_t M, int64_t K) {
    int64_t packed_size = (M * K + 3) / 4;
    return std::vector<uint8_t>(packed_size, 0xAA);  // 10101010 = 4x(+1)
}

// 生成混合权重: 前半 +1, 后半 -1
// +1 = 2'b10 = 0xAA per byte, -1 = 2'b00 = 0x00 per byte
static std::vector<uint8_t> generate_mixed_weights(int64_t M, int64_t K) {
    int64_t packed_size = (M * K + 3) / 4;
    std::vector<uint8_t> w(packed_size, 0);
    // 每行前 K/2 个权重为 +1, 后 K/2 个为 -1
    for (int64_t m = 0; m < M; m++) {
        for (int64_t k = 0; k < K; k++) {
            int64_t flat = m * K + k;
            int byte_idx = flat / 4;
            int bit_idx  = flat % 4;
            uint8_t val = (k < K / 2) ? 0x2 : 0x0;  // +1 or -1
            w[byte_idx] |= (val << (bit_idx * 2));
        }
    }
    return w;
}

// C++ 参考实现: ternary matmul
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
                int byte_idx = (m * K + k) / 4;
                int bit_idx  = (m * K + k) % 4;
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
    auto network = Network::Create(name);

    auto input_type = TensorType(IntegerType::SInt8(), {batch, K});
    auto input_op = Input(input_type);
    network.addOp(input_op);

    auto weight_type = TensorType(IntegerType::UInt8(),
                                  {M, K / 4});
    auto weight_op = Constant(weight_type, weights.data(), weights.size());
    network.addOp(weight_op);

    auto bitlinear = tdpu::BitLinear(input_op[0], weight_op[0], K, M);
    network.addOp(bitlinear);

    auto output_op = Output(bitlinear[0]);
    network.addOp(output_op);

    // 2. 创建 Session
    auto session = Session::Create<HostBackend>(
        network, {HostDevice::Default()});
    session.apply();

    // 3. 准备输入
    auto input_tensor = Tensor::Create(input_type, HostDevice::Default());
    auto* in_ptr = input_tensor.data<int8_t>();
    for (int64_t i = 0; i < batch * K; i++) {
        in_ptr[i] = input_val;
    }

    // 4. 前向
    auto outputs = session.forward({input_tensor});
    auto* out_ptr = outputs[0].data<int32_t>();

    // 5. 验证
    bool pass = true;
    for (int64_t i = 0; i < batch * M; i++) {
        if (out_ptr[i] != expected[i]) {
            std::cout << "  FAIL at [" << i << "]: got "
                      << out_ptr[i] << ", expected " << expected[i]
                      << std::endl;
            pass = false;
        }
    }

    if (pass) {
        std::cout << "  PASS (output[0]=" << out_ptr[0] << ")" << std::endl;
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
