#!/usr/bin/env python3
"""
export_single_layer.py - 从 BitNet safetensors 提取单层 BitLinear 导出为 ONNX

策略:
  1. 从 model.safetensors 提取 layer.0.self_attn.q_proj 的 packed uint8 权重
  2. 构建简单 ONNX 图: Input[1, K] INT8 -> MatMul(weight) -> Output[1, M] INT32
  3. 权重以 packed uint8 格式存储为 ONNX initializer
  4. Icraft 解析后通过 BitLinear Pass 替换 MatMul

权重格式:
  safetensors 中 q_proj.weight shape=[640, 2560] uint8
  每个 uint8 包含 4 个 ternary 权重 (2-bit each)
  实际维度: M=2560 (out_features), K=2560 (in_features)
  packed 维度: M=2560, K/4=640 -> 但存储为 [640, 2560] 即 [M/4, K]?

  需要确认 packing 方向! 先检查一下。

用法:
    conda activate icraft_env
    python models/export_single_layer.py
"""
import sys
import numpy as np
from pathlib import Path


def inspect_packing(weight_uint8):
    """分析 packed uint8 权重的 packing 方向"""
    print(f"Weight shape: {weight_uint8.shape}, dtype: {weight_uint8.dtype}")
    print(f"  Total uint8 elements: {weight_uint8.size}")
    print(f"  Total ternary weights: {weight_uint8.size * 4}")

    # 统计各编码值的分布
    for row_idx in [0, 1]:
        row = weight_uint8[row_idx]
        vals = []
        for byte_val in row[:10]:
            for bit_idx in range(4):
                v = (int(byte_val) >> (bit_idx * 2)) & 0x3
                vals.append(v)
        print(f"  Row {row_idx} first 40 ternary values: {vals}")
        counts = {0: 0, 1: 0, 2: 0, 3: 0}
        for byte_val in row:
            for bit_idx in range(4):
                v = (int(byte_val) >> (bit_idx * 2)) & 0x3
                counts[v] += 1
        print(f"  Row {row_idx} distribution: -1(0b00)={counts[0]}, "
              f"0(0b01)={counts[1]}, +1(0b10)={counts[2]}, pad(0b11)={counts[3]}")


def main():
    import torch
    from safetensors import safe_open

    model_dir = Path(__file__).resolve().parent / "microsoftbitnet_b1.58_2B_4T"
    safetensors_path = model_dir / "model.safetensors"

    if not safetensors_path.exists():
        print(f"ERROR: {safetensors_path} not found")
        sys.exit(1)

    print("=== Loading safetensors ===")
    f = safe_open(str(safetensors_path), framework="pt")

    # 提取 q_proj 权重 (最小的 attention 投影之一)
    # q_proj: [640, 2560] uint8 -> M_packed=640, K=2560
    # 但 q_proj 的 out_features=2560 (20 heads * 128 dim)
    # 所以 packing 是在 out_features 维度: M=640*4=2560, K=2560
    weight_key = "model.layers.0.self_attn.q_proj.weight"
    weight_tensor = f.get_tensor(weight_key)
    print(f"Loaded {weight_key}: shape={list(weight_tensor.shape)}, dtype={weight_tensor.dtype}")

    weight_np = weight_tensor.numpy()
    inspect_packing(weight_np)

    # 权重 shape: [640, 2560] uint8
    # packing 在第0维 (out_features): M_packed = M/4 = 640, K = 2560
    # 所以 M = 640 * 4 = 2560, K = 2560
    M_packed, K = weight_np.shape
    M = M_packed * 4  # 解包后的 out_features

    print(f"\n=== Building ONNX graph ===")
    print(f"  Input:  [1, {K}] INT8 (activation)")
    print(f"  Weight: [{M_packed}, {K}] UINT8 (packed ternary)")
    print(f"  Output: [1, {M}] INT32")
    print(f"  Actual: MatMul([1,{K}] x [{M},{K}]^T) = [1,{M}]")

    import onnx
    from onnx import helper, TensorProto, numpy_helper

    # 创建权重 initializer
    weight_initializer = numpy_helper.from_array(
        weight_np, name="weight"
    )

    # 输入: [1, K] INT8
    input_info = helper.make_tensor_value_info(
        "input", TensorProto.INT8, [1, K]
    )

    # 输出: [1, M] INT32
    output_info = helper.make_tensor_value_info(
        "output", TensorProto.INT32, [1, M]
    )

    # MatMul 节点 (Icraft 解析后会被 Pass 替换为 BitLinear)
    matmul_node = helper.make_node(
        "MatMul",
        inputs=["input", "weight"],
        outputs=["output"],
        name="bitlinear_q_proj",
    )

    # 构建 graph
    graph = helper.make_graph(
        [matmul_node],
        "single_bitlinear_layer",
        [input_info],
        [output_info],
        initializer=[weight_initializer],
    )

    # 构建 model
    model = helper.make_model(
        graph,
        opset_imports=[helper.make_opsetid("", 14)],
    )
    model.ir_version = 8

    # 保存
    output_dir = Path(__file__).resolve().parent / "output"
    output_dir.mkdir(exist_ok=True)
    output_path = output_dir / "single_layer_bitlinear.onnx"

    onnx.save(model, str(output_path))
    file_size_kb = output_path.stat().st_size / 1024
    print(f"\n=== ONNX saved ===")
    print(f"  Path: {output_path}")
    print(f"  Size: {file_size_kb:.1f} KB")

    # 验证
    print("\n=== Verifying ONNX ===")
    loaded = onnx.load(str(output_path))
    onnx.checker.check_model(loaded)
    print(f"  IR version:    {loaded.ir_version}")
    print(f"  Opset version: {loaded.opset_import[0].version}")
    print(f"  Nodes:         {len(loaded.graph.node)}")
    print("  [OK] ONNX model is valid!")


if __name__ == "__main__":
    main()
