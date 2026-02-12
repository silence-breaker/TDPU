"""临时脚本: 查看 safetensors 中第0层的权重结构"""
from safetensors import safe_open

f = safe_open(
    "d:/SYSU/JC/Code-space/TDPU/models/microsoftbitnet_b1.58_2B_4T/model.safetensors",
    framework="pt",
)
keys = sorted(f.keys())

print("=== Layer 0 weights ===")
for k in keys:
    if "layers.0." in k:
        t = f.get_tensor(k)
        print(f"  {k}: shape={list(t.shape)}, dtype={t.dtype}")

print("\n=== Global weights ===")
for k in keys:
    if not k.startswith("model.layers."):
        t = f.get_tensor(k)
        print(f"  {k}: shape={list(t.shape)}, dtype={t.dtype}")

print(f"\nTotal keys: {len(keys)}")
