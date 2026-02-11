/**
 * bitlinear_pass.cpp - 优化 Pass: 将 MatMul 替换为 BitLinear
 *
 * 在 Icraft 优化阶段, 匹配 ONNX 解析出的 MatMul 算子,
 * 检查其权重是否为 ternary packed 格式, 若是则替换为 BitLinear。
 */
#include "bitlinear_op.h"
#include <icraft-xir/core/pass.h>
#include <icraft-xir/core/network.h>
#include <icraft-xir/ops/matmul.h>

namespace tdpu {

using namespace icraft::xir;

// 判断权重是否为 ternary packed 格式 (uint8 dtype)
static bool is_ternary_weight(const Value& weight) {
    auto dtype = weight.tensorType().dtype();
    // packed ternary 权重以 uint8 存储
    return dtype == IntegerType::UInt8();
}

static Pass ReplaceMatMulWithBitLinear() {
    auto pass_func = [](Network network, const PassContext& ctx) {
        auto matmul_p = IsOp<MatMul>();

        network.rewrite(matmul_p, [&](Network& net, const MatchGroup& result) {
            auto matmul = result.at(matmul_p);

            // 只替换权重为 ternary packed 的 MatMul
            auto weight = matmul->inputs[1];
            if (!is_ternary_weight(weight)) return;

            auto input = matmul->inputs[0];
            auto weight_shape = weight.tensorType().shape();

            // weight shape: [out_features, in_features/4] (packed)
            int64_t M = weight_shape[0];
            int64_t K = weight_shape[1] * 4;  // 解包后的实际维度

            auto bitlinear = BitLinear(input, weight, K, M);
            net.replaceOpKeepUses(matmul, bitlinear);
        });

        return network;
    };

    return NetworkPass(pass_func, PassInfo("tdpu.ReplaceMatMulWithBitLinear"));
}

// 注册 Pass
ICRAFT_REGISTER_PASS("tdpu.ReplaceMatMulWithBitLinear")
    .set_creator(ReplaceMatMulWithBitLinear);

} // namespace tdpu
