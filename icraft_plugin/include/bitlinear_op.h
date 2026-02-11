/**
 * bitlinear_op.h - BitLinear 自定义算子定义
 *
 * 语义: output = activation × weight^T
 *   activation: [batch, in_features] INT8
 *   weight:     [out_features, in_features] packed ternary (uint8, 4 weights/byte)
 *   output:     [batch, out_features] INT32
 *
 * 权重编码 (与 package_def.sv 一致):
 *   2'b00 = -1 (W_NEG)
 *   2'b01 =  0 (W_ZERO)
 *   2'b10 = +1 (W_POS)
 *   2'b11 =  0 (Reserved/Padding)
 */
#pragma once

#include <icraft-xir/core/operation.h>
#include <icraft-xir/core/network.h>

namespace tdpu {

using namespace icraft::xir;

// ============================================================
// BitLinearNode: 算子容器类 (存储属性)
// ============================================================
class BitLinearNode : public OpNodeBase<BitLinearNode> {
public:
    int64_t in_features;   // 输入特征维度 K
    int64_t out_features;  // 输出特征维度 M

    ICRAFT_DECLARE_ATTRS(BitLinearNode) {
        ICRAFT_ATTR_FIELD(in_features).set_lower_bound(1);
        ICRAFT_ATTR_FIELD(out_features).set_lower_bound(1);
    }
};

// ============================================================
// BitLinear: 算子引用类 (智能指针)
// ============================================================
class BitLinear : public OpBase<BitLinear, BitLinearNode> {
public:
    BitLinear() = default;

    /**
     * @param input   激活值 [batch, in_features] INT8
     * @param weight  权重   [out_features, in_features/4] packed uint8
     * @param in_features   输入维度 K
     * @param out_features  输出维度 M
     */
    BitLinear(Value input, Value weight,
              int64_t in_features, int64_t out_features) {
        auto node = make_object<BitLinearNode>();
        node->in_features = in_features;
        node->out_features = out_features;
        data_ = std::move(node);
        this->setInputs({input, weight});
    }
};

} // namespace tdpu
