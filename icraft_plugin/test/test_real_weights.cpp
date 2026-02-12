/**
 * test_real_weights.cpp - PS-PL硬件交互模拟: 真实权重端到端验证
 *
 * 场景: 在软件层面模拟FMQL30TAI板卡的PS端和PL端交互:
 *   1. PS端: 加载safetensors中的真实q_proj权重, 准备输入激活值
 *   2. 请求: PS端通过XIR API构建网络, 发送计算请求到PL端(模拟)
 *   3. PL端: HostBackend执行BitLinear计算(模拟FPGA加速)
 *   4. 返回: PL端返回计算结果到PS端
 *   5. 验证: 与PyTorch参考实现对比
 *
 * 编译: 在 icraft_plugin/build 目录下
 *   cmake .. -G "Visual Studio 17 2022"
 *   cmake --build . --config Release
 *   ./Release/test_real_weights.exe
 *
 * 依赖: torch, safetensors, numpy (Python环境)
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
#include <fstream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>

using namespace icraft::xir;
using icraft::xrt::Session;
using icraft::xrt::Tensor;
using icraft::xrt::HostBackend;
using icraft::xrt::HostDevice;

// ============================================================================
// Part 1: 权重加载与验证
// ============================================================================

/**
 * 从二进制文件加载权重数据
 * 格式: 原始uint8数组, 无头部信息
 */
static std::vector<uint8_t> load_weights_from_file(const char* filepath) {
    std::ifstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "ERROR: Cannot open weight file: " << filepath << std::endl;
        return {};
    }

    file.seekg(0, std::ios::end);
    size_t file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<uint8_t> weights(file_size);
    file.read(reinterpret_cast<char*>(weights.data()), file_size);
    file.close();

    std::cout << "[LOAD] Loaded " << file_size << " bytes from " << filepath << std::endl;
    return weights;
}

/**
 * 统计权重中各编码值的分布
 * 编码: 2'b00=-1, 2'b01=0, 2'b10=+1, 2'b11=0(padding)
 */
static void analyze_weights(const std::vector<uint8_t>& weights, int64_t sample_size = 1000) {
    int64_t counts[4] = {0, 0, 0, 0};
    int64_t total_ternary = static_cast<int64_t>(weights.size()) * 4;
    int64_t sample_count = std::min(sample_size, total_ternary);

    for (int64_t i = 0; i < sample_count; i++) {
        int byte_idx = i / 4;
        int bit_idx = i % 4;
        uint8_t val = (weights[byte_idx] >> (bit_idx * 2)) & 0x3;
        counts[val]++;
    }

    std::cout << "[ANALYZE] Weight distribution (first " << sample_count << " ternary values):" << std::endl;
    std::cout << "  -1 (0b00): " << counts[0] << " (" << (100.0*counts[0]/sample_count) << "%)" << std::endl;
    std::cout << "   0 (0b01): " << counts[1] << " (" << (100.0*counts[1]/sample_count) << "%)" << std::endl;
    std::cout << "  +1 (0b10): " << counts[2] << " (" << (100.0*counts[2]/sample_count) << "%)" << std::endl;
    std::cout << "  pad(0b11): " << counts[3] << " (" << (100.0*counts[3]/sample_count) << "%)" << std::endl;
}

// ============================================================================
// Part 2: PS端请求生成 (模拟)
// ============================================================================

/**
 * PS端请求结构: 包含输入激活值和请求元数据
 */
struct PSRequest {
    int64_t batch;
    int64_t K;  // in_features
    int64_t M;  // out_features
    std::vector<int8_t> activation;  // [batch, K] INT8

    PSRequest(int64_t b, int64_t k, int64_t m)
        : batch(b), K(k), M(m), activation(b * k) {}

    void fill_random(int seed = 42) {
        srand(seed);
        for (auto& val : activation) {
            val = static_cast<int8_t>((rand() % 256) - 128);
        }
    }

    void fill_constant(int8_t val) {
        std::fill(activation.begin(), activation.end(), val);
    }
};

/**
 * PS端: 生成计算请求
 */
static PSRequest generate_ps_request(int64_t batch, int64_t K, int64_t M) {
    PSRequest req(batch, K, M);
    req.fill_random(42);  // 固定seed保证可重复

    std::cout << "[PS] Generated request:" << std::endl;
    std::cout << "  Batch: " << batch << ", K: " << K << ", M: " << M << std::endl;
    std::cout << "  Activation shape: [" << batch << ", " << K << "] INT8" << std::endl;
    std::cout << "  Sample activation[0]: ";
    for (int i = 0; i < std::min(10LL, K); i++) {
        std::cout << (int)req.activation[i] << " ";
    }
    std::cout << "..." << std::endl;

    return req;
}

// ============================================================================
// Part 3: PL端计算 (模拟)
// ============================================================================

/**
 * PL端响应结构: 包含计算结果
 */
struct PLResponse {
    int64_t batch;
    int64_t M;
    std::vector<int32_t> output;  // [batch, M] INT32

    PLResponse(int64_t b, int64_t m)
        : batch(b), M(m), output(b * m, 0) {}
};

/**
 * PL端: 执行BitLinear计算 (通过HostBackend模拟FPGA)
 */
static PLResponse execute_pl_computation(
    const PSRequest& req,
    const std::vector<uint8_t>& weights,
    int64_t M_packed)
{
    std::cout << "[PL] Starting BitLinear computation..." << std::endl;

    // 1. 构建XIR网络
    auto network = Network("bitlinear_real_weights", Framework::ONNX, "1.0");

    // Input: [batch, K] INT8
    auto input_type = TensorType(IntegerType::SInt8(),
        Array<int64_t>{req.batch, req.K}, Layout("RC"));
    auto input_op = Input(Array<TensorType>{input_type});
    network.addOp(input_op);

    // Weight: [M/4, K] packed uint8
    auto weight_type = TensorType(IntegerType::UInt8(),
        Array<int64_t>{M_packed, req.K}, Layout("RC"));
    auto weight_data = std::shared_ptr<uint8_t[]>(
        new uint8_t[weights.size()]);
    std::memcpy(weight_data.get(), weights.data(), weights.size());
    auto weight_param = Params(weight_data, "weight", weight_type);

    // BitLinear op
    auto bitlinear = tdpu::BitLinear(input_op[0], weight_param, req.K, req.M);
    network.addOp(bitlinear);

    // Output
    auto output_op = Output(Array<Value>{bitlinear[0]});
    network.addOp(output_op);

    // 2. 创建Session (模拟PL端)
    auto session = Session::Create<HostBackend>(
        network, {HostDevice::Default()});
    session.apply();

    std::cout << "[PL] XIR network built and session created" << std::endl;

    // 3. 准备输入Tensor
    auto input_tensor = Tensor(input_type).mallocOn(HostDevice::MemRegion());
    input_tensor.write(0, reinterpret_cast<char*>(
        const_cast<int8_t*>(req.activation.data())),
        req.activation.size() * sizeof(int8_t));

    std::cout << "[PL] Input tensor prepared" << std::endl;

    // 4. 执行前向计算
    auto outputs = session.forward({input_tensor});

    std::cout << "[PL] Forward computation completed" << std::endl;

    // 5. 读取输出
    PLResponse resp(req.batch, req.M);
    outputs[0].read(reinterpret_cast<char*>(resp.output.data()), 0,
                    resp.output.size() * sizeof(int32_t));

    std::cout << "[PL] Output tensor read" << std::endl;
    std::cout << "  Output shape: [" << req.batch << ", " << req.M << "] INT32" << std::endl;
    std::cout << "  Sample output[0]: ";
    for (int i = 0; i < std::min(10LL, req.M); i++) {
        std::cout << resp.output[i] << " ";
    }
    std::cout << "..." << std::endl;

    return resp;
}

// ============================================================================
// Part 4: 参考实现与验证
// ============================================================================

/**
 * 参考实现: C++ ternary matmul (用于验证)
 */
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
                int bit_idx = m % 4;
                int val = (w_packed[byte_idx] >> (bit_idx * 2)) & 0x3;
                int w = (val == 0) ? -1 : (val == 2) ? 1 : 0;
                acc += a * w;
            }
            out[b * M + m] = acc;
        }
    }
    return out;
}

/**
 * 验证PL端输出与参考实现的一致性
 */
static bool verify_pl_response(
    const PSRequest& req,
    const PLResponse& resp,
    const std::vector<uint8_t>& weights,
    int64_t M_packed)
{
    std::cout << "[VERIFY] Comparing PL output with reference implementation..." << std::endl;

    auto ref_output = reference_ternary_matmul(
        req.activation.data(), weights.data(),
        req.batch, req.M, req.K);

    bool pass = true;
    int error_count = 0;
    const int max_errors = 10;

    for (int64_t i = 0; i < req.batch * req.M; i++) {
        if (resp.output[i] != ref_output[i]) {
            if (error_count < max_errors) {
                std::cout << "  MISMATCH at [" << i << "]: got "
                          << resp.output[i] << ", expected " << ref_output[i]
                          << std::endl;
            }
            error_count++;
            pass = false;
        }
    }

    if (pass) {
        std::cout << "[VERIFY] PASS - All " << (req.batch * req.M)
                  << " outputs match reference!" << std::endl;
    } else {
        std::cout << "[VERIFY] FAIL - " << error_count << " mismatches found" << std::endl;
    }

    return pass;
}

// ============================================================================
// Part 5: 主测试流程
// ============================================================================

int main(int argc, char* argv[]) {
    std::cout << "=== BitLinear PS-PL Hardware Interaction Simulation ===" << std::endl;
    std::cout << std::endl;

    // 配置参数
    const char* weight_file = argc > 1 ? argv[1] : "q_proj_weights.bin";
    int64_t batch = 1;
    int64_t K = 2560;      // in_features
    int64_t M = 2560;      // out_features
    int64_t M_packed = M / 4;  // [M/4, K] packing

    std::cout << "[CONFIG] Parameters:" << std::endl;
    std::cout << "  Weight file: " << weight_file << std::endl;
    std::cout << "  Batch: " << batch << ", K: " << K << ", M: " << M << std::endl;
    std::cout << "  Weight shape: [" << M_packed << ", " << K << "] UINT8" << std::endl;
    std::cout << std::endl;

    // ========== Step 1: PS端加载权重 ==========
    std::cout << "[STEP 1] PS端: 加载权重" << std::endl;
    auto weights = load_weights_from_file(weight_file);
    if (weights.empty()) {
        std::cerr << "ERROR: Failed to load weights" << std::endl;
        return 1;
    }

    // 验证权重大小
    size_t expected_size = M_packed * K;
    if (weights.size() != expected_size) {
        std::cerr << "ERROR: Weight size mismatch. Expected " << expected_size
                  << ", got " << weights.size() << std::endl;
        return 1;
    }

    analyze_weights(weights, 10000);
    std::cout << std::endl;

    // ========== Step 2: PS端生成请求 ==========
    std::cout << "[STEP 2] PS端: 生成计算请求" << std::endl;
    auto ps_req = generate_ps_request(batch, K, M);
    std::cout << std::endl;

    // ========== Step 3: PL端执行计算 ==========
    std::cout << "[STEP 3] PL端: 执行BitLinear计算" << std::endl;
    auto pl_resp = execute_pl_computation(ps_req, weights, M_packed);
    std::cout << std::endl;

    // ========== Step 4: 验证结果 ==========
    std::cout << "[STEP 4] 验证: 对比参考实现" << std::endl;
    bool verify_pass = verify_pl_response(ps_req, pl_resp, weights, M_packed);
    std::cout << std::endl;

    // ========== 总结 ==========
    std::cout << "=== Test Summary ===" << std::endl;
    if (verify_pass) {
        std::cout << "✓ PS-PL Hardware Interaction Simulation: PASS" << std::endl;
        std::cout << "✓ Real weight verification: PASS" << std::endl;
        return 0;
    } else {
        std::cout << "✗ PS-PL Hardware Interaction Simulation: FAIL" << std::endl;
        return 1;
    }
}
