/**
 * bitlinear_op.cpp - BitLinear 算子注册 + 类型推断
 */
#include "bitlinear_op.h"
#include <icraft-xir/core/type.h>

namespace tdpu {

// 注册算子到 XIR，并提供类型推断
ICRAFT_REGISTER_OP_NODE(BitLinearNode)
.set_tinfer<BitLinearNode, HostTarget>([](const auto* op) {
    op->validate();

    // 获取输入 activation 的 shape: [batch, in_features]
    auto input_type = op->inputs[0].tensorType();
    auto batch = input_type.shape()[0];
    auto out_features = op->out_features;

    // 输出: [batch, out_features] INT32 (ternary 累加无精度损失)
    auto output_type = TensorType(
        IntegerType::SInt32(),
        {batch, out_features}
    );
    return Array<TensorType>{output_type};
});

} // namespace tdpu
