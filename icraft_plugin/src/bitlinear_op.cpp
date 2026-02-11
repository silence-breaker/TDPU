/**
 * bitlinear_op.cpp - BitLinear 算子注册 + 类型推断
 */
#include "bitlinear_op.h"
#include <icraft-xir/core/reflection.h>
#include <icraft-xir/core/data_type.h>
#include <icraft-xir/core/layout.h>

namespace tdpu {

// 注册算子节点到 XIR
ICRAFT_REGISTER_OP_NODE(BitLinearNode);

// 注册 HostTarget 上的类型推断
ICRAFT_REGISTER_TINFER(BitLinearNode, HostTarget, [](const BitLinearNode* op) {
    op->validate();

    // 获取输入 activation 的 TensorType: [batch, in_features]
    auto input_type = op->inputs[0].tensorType();
    auto batch = input_type.getDim(0);
    auto out_features = op->out_features;

    // 输出: [batch, out_features] INT32 (ternary 累加无精度损失)
    auto output_type = TensorType(
        IntegerType::SInt32(),
        Array<int64_t>{batch, out_features},
        Layout("RC")
    );
    return Array<TensorType>{output_type};
});

} // namespace tdpu
