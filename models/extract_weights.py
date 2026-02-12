#!/usr/bin/env python3
"""
extract_weights.py - 从 safetensors 中提取 q_proj 权重并保存为二进制文件

用法:
    conda activate icraft_env
    python models/extract_weights.py
"""
import sys
from pathlib import Path
import numpy as np

def main():
    try:
        from safetensors import safe_open
    except ImportError:
        print("ERROR: safetensors not installed. Run: pip install safetensors")
        sys.exit(1)

    model_dir = Path(__file__).resolve().parent / "microsoftbitnet_b1.58_2B_4T"
    safetensors_path = model_dir / "model.safetensors"

    if not safetensors_path.exists():
        print(f"ERROR: {safetensors_path} not found")
        sys.exit(1)

    print("=== Extracting q_proj weights from safetensors ===")
    print(f"Model path: {safetensors_path}")

    # 打开 safetensors
    f = safe_open(str(safetensors_path), framework="pt")

    # 提取 q_proj 权重
    weight_key = "model.layers.0.self_attn.q_proj.weight"
    print(f"\nLoading {weight_key}...")

    try:
        weight_tensor = f.get_tensor(weight_key)
    except KeyError:
        print(f"ERROR: Key '{weight_key}' not found in safetensors")
        print("\nAvailable keys in layer 0:")
        for k in sorted(f.keys()):
            if "layers.0." in k:
                t = f.get_tensor(k)
                print(f"  {k}: shape={list(t.shape)}, dtype={t.dtype}")
        sys.exit(1)

    weight_np = weight_tensor.numpy()
    print(f"  Shape: {weight_np.shape}")
    print(f"  Dtype: {weight_np.dtype}")
    print(f"  Size: {weight_np.nbytes} bytes")

    # 验证权重格式
    M_packed, K = weight_np.shape
    if weight_np.dtype != np.uint8:
        print(f"ERROR: Expected uint8, got {weight_np.dtype}")
        sys.exit(1)

    M = M_packed * 4  # 解包后的维度
    print(f"\nWeight dimensions:")
    print(f"  Packed shape: [{M_packed}, {K}]")
    print(f"  Unpacked shape: [{M}, {K}]")
    print(f"  Total ternary weights: {M * K}")

    # 分析权重分布
    print(f"\nAnalyzing weight distribution...")
    counts = {0: 0, 1: 0, 2: 0, 3: 0}
    for byte_val in weight_np.flat:
        for bit_idx in range(4):
            v = (int(byte_val) >> (bit_idx * 2)) & 0x3
            counts[v] += 1

    total = sum(counts.values())
    print(f"  -1 (0b00): {counts[0]:8d} ({100.0*counts[0]/total:5.2f}%)")
    print(f"   0 (0b01): {counts[1]:8d} ({100.0*counts[1]/total:5.2f}%)")
    print(f"  +1 (0b10): {counts[2]:8d} ({100.0*counts[2]/total:5.2f}%)")
    print(f"  pad(0b11): {counts[3]:8d} ({100.0*counts[3]/total:5.2f}%)")

    # 保存为二进制文件
    output_dir = Path(__file__).resolve().parent / "output"
    output_dir.mkdir(exist_ok=True)
    output_path = output_dir / "q_proj_weights.bin"

    print(f"\nSaving to binary file...")
    weight_np.tofile(str(output_path))
    print(f"  Path: {output_path}")
    print(f"  Size: {output_path.stat().st_size} bytes")

    print("\n=== Success ===")
    print(f"Binary weights saved to: {output_path}")
    print(f"Use with: ./test_real_weights.exe {output_path}")

if __name__ == "__main__":
    main()
