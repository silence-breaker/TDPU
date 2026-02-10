"""分析 BitNet b1.58 2B-4T 模型的 safetensors 文件结构。

输出内容:
1. 所有张量的名称、形状、数据类型
2. 按层分组统计
3. 各类参数的内存占用
4. 权重值分布分析 (验证 1.58-bit 三值特性)
"""

import json
import struct
from collections import defaultdict
from pathlib import Path

MODEL_DIR = Path(__file__).parent
SAFETENSORS_PATH = MODEL_DIR / "model.safetensors"
CONFIG_PATH = MODEL_DIR / "config.json"

# safetensors 数据类型 -> (名称, 字节数)
DTYPE_INFO = {
    "F64": ("float64", 8),
    "F32": ("float32", 4),
    "F16": ("float16", 2),
    "BF16": ("bfloat16", 2),
    "I64": ("int64", 8),
    "I32": ("int32", 4),
    "I16": ("int16", 2),
    "I8": ("int8", 1),
    "U8": ("uint8", 1),
    "BOOL": ("bool", 1),
}


def parse_safetensors_header(filepath: Path) -> dict:
    """解析 safetensors 文件头，返回元数据字典。"""
    with open(filepath, "rb") as f:
        # 前 8 字节是 header 长度 (little-endian uint64)
        header_len = struct.unpack("<Q", f.read(8))[0]
        header_bytes = f.read(header_len)
    metadata = json.loads(header_bytes)
    # 移除 __metadata__ 键 (如果存在)
    metadata.pop("__metadata__", None)
    return metadata


def analyze_tensors(metadata: dict) -> list[dict]:
    """将元数据解析为结构化的张量信息列表。"""
    tensors = []
    for name, info in sorted(metadata.items()):
        dtype_str = info["dtype"]
        shape = info["shape"]
        offsets = info["data_offsets"]  # [start, end]
        num_elements = 1
        for dim in shape:
            num_elements *= dim
        _, bytes_per_elem = DTYPE_INFO.get(dtype_str, (dtype_str, 0))
        size_bytes = num_elements * bytes_per_elem
        tensors.append({
            "name": name,
            "shape": shape,
            "dtype": dtype_str,
            "num_elements": num_elements,
            "size_bytes": size_bytes,
            "offset_start": offsets[0],
            "offset_end": offsets[1],
        })
    return tensors


def classify_tensor(name: str) -> str:
    """根据张量名称分类。"""
    if "embed_tokens" in name:
        return "Embedding"
    if "lm_head" in name:
        return "LM Head"
    if "norm" in name and "layers" not in name:
        return "Final Norm"
    if "self_attn" in name:
        if "q_proj" in name:
            return "Attention Q"
        if "k_proj" in name:
            return "Attention K"
        if "v_proj" in name:
            return "Attention V"
        if "o_proj" in name:
            return "Attention O"
        return "Attention Other"
    if "mlp" in name:
        if "gate_proj" in name:
            return "MLP Gate"
        if "up_proj" in name:
            return "MLP Up"
        if "down_proj" in name:
            return "MLP Down"
        return "MLP Other"
    if "input_layernorm" in name or "post_attention_layernorm" in name:
        return "Layer Norm"
    return "Other"


def extract_layer_idx(name: str) -> int | None:
    """从张量名称中提取层号。"""
    parts = name.split(".")
    for i, part in enumerate(parts):
        if part == "layers" and i + 1 < len(parts):
            try:
                return int(parts[i + 1])
            except ValueError:
                pass
    return None


def format_size(size_bytes: int) -> str:
    """格式化字节数为可读字符串。"""
    if size_bytes >= 1024 ** 3:
        return f"{size_bytes / 1024**3:.2f} GB"
    if size_bytes >= 1024 ** 2:
        return f"{size_bytes / 1024**2:.2f} MB"
    if size_bytes >= 1024:
        return f"{size_bytes / 1024:.2f} KB"
    return f"{size_bytes} B"


def main():
    # 加载 config
    with open(CONFIG_PATH) as f:
        config = json.load(f)

    p = print  # shorthand

    p("# BitNet b1.58 2B-4T 模型结构分析\n")

    p("## 模型配置 (config.json)\n")
    p("| 属性 | 值 |")
    p("| :--- | :--- |")
    p(f"| 架构 | `{config['architectures'][0]}` |")
    p(f"| 隐藏层维度 | {config['hidden_size']} |")
    p(f"| 中间层维度 | {config['intermediate_size']} |")
    p(f"| 层数 | {config['num_hidden_layers']} |")
    p(f"| 注意力头数 | {config['num_attention_heads']} |")
    p(f"| KV 头数 | {config['num_key_value_heads']} |")
    p(f"| 词表大小 | {config['vocab_size']} |")
    p(f"| 最大位置编码 | {config['max_position_embeddings']} |")
    p(f"| 激活函数 | `{config['hidden_act']}` |")
    p(f"| 量化方式 | `{config['quantization_config']['quant_method']}` |")
    p(f"| 数据类型 | `{config['torch_dtype']}` |")
    p(f"| tie_word_embeddings | `{config['tie_word_embeddings']}` |")

    # 解析 safetensors
    p(f"\n> 文件: `{SAFETENSORS_PATH.name}`, 大小: **{format_size(SAFETENSORS_PATH.stat().st_size)}**\n")

    metadata = parse_safetensors_header(SAFETENSORS_PATH)
    tensors = analyze_tensors(metadata)

    # ── 1. 张量列表 ──
    p(f"## 1. 张量列表 (共 {len(tensors)} 个)\n")
    p("<details>")
    p("<summary>点击展开完整张量列表</summary>\n")
    p("| 名称 | 形状 | 类型 | 大小 |")
    p("| :--- | :--- | :--- | ---: |")
    for t in tensors:
        p(f"| `{t['name']}` | `{t['shape']}` | {t['dtype']} | {format_size(t['size_bytes'])} |")
    p("\n</details>\n")

    # ── 2. 按类别统计 ──
    p("## 2. 按类别统计\n")
    category_stats = defaultdict(lambda: {"count": 0, "elements": 0, "bytes": 0})
    for t in tensors:
        cat = classify_tensor(t["name"])
        category_stats[cat]["count"] += 1
        category_stats[cat]["elements"] += t["num_elements"]
        category_stats[cat]["bytes"] += t["size_bytes"]

    total_bytes = sum(s["bytes"] for s in category_stats.values())
    total_elements = sum(s["elements"] for s in category_stats.values())

    p("| 类别 | 张量数 | 参数量 | 存储大小 | 占比 |")
    p("| :--- | ---: | ---: | ---: | ---: |")
    for cat in sorted(category_stats, key=lambda c: category_stats[c]["bytes"], reverse=True):
        s = category_stats[cat]
        pct = s["bytes"] / total_bytes * 100
        p(f"| {cat} | {s['count']} | {s['elements']:,} | {format_size(s['bytes'])} | {pct:.2f}% |")
    p(f"| **合计** | **{len(tensors)}** | **{total_elements:,}** | **{format_size(total_bytes)}** | **100.00%** |")

    # ── 3. Layer 0 详细结构 ──
    p(f"\n## 3. Layer 0 详细结构 (其余层结构相同)\n")
    p("| 名称 | 形状 | 类型 | 大小 |")
    p("| :--- | :--- | :--- | ---: |")
    for t in tensors:
        if extract_layer_idx(t["name"]) == 0:
            short_name = t["name"].split("model.layers.0.")[-1]
            p(f"| `{short_name}` | `{t['shape']}` | {t['dtype']} | {format_size(t['size_bytes'])} |")

    # ── 4. FPGA 加速相关分析 ──
    p(f"\n## 4. FPGA 加速相关分析 (BitLinear 层)\n")

    hidden = config["hidden_size"]
    inter = config["intermediate_size"]
    n_heads = config["num_attention_heads"]
    n_kv_heads = config["num_key_value_heads"]
    head_dim = hidden // n_heads
    n_layers = config["num_hidden_layers"]

    linear_layers = [
        ("q_proj", hidden, hidden),
        ("k_proj", hidden, n_kv_heads * head_dim),
        ("v_proj", hidden, n_kv_heads * head_dim),
        ("o_proj", hidden, hidden),
        ("gate_proj", hidden, inter),
        ("up_proj", hidden, inter),
        ("down_proj", inter, hidden),
    ]

    p("每层 Transformer Block 的 Linear 层:\n")
    p("| 名称 | 输入维度 (K) | 输出维度 (M) | 参数量 | 1.58-bit 压缩 |")
    p("| :--- | ---: | ---: | ---: | ---: |")
    layer_total_params = 0
    layer_total_compressed = 0
    for name, k, m in linear_layers:
        params = k * m
        compressed = params * 2 // 8
        layer_total_params += params
        layer_total_compressed += compressed
        p(f"| {name} | {k:,} | {m:,} | {params:,} | {format_size(compressed)} |")
    p(f"| **单层合计** | | | **{layer_total_params:,}** | **{format_size(layer_total_compressed)}** |")
    p(f"| **全部 {n_layers} 层** | | | **{layer_total_params * n_layers:,}** | **{format_size(layer_total_compressed * n_layers)}** |")

    # ── 5. 数据类型分布 ──
    p(f"\n## 5. 数据类型分布\n")
    dtype_stats = defaultdict(lambda: {"count": 0, "bytes": 0})
    for t in tensors:
        dtype_stats[t["dtype"]]["count"] += 1
        dtype_stats[t["dtype"]]["bytes"] += t["size_bytes"]

    p("| 数据类型 | 字节/元素 | 张量数 | 存储大小 |")
    p("| :--- | ---: | ---: | ---: |")
    for dtype, s in sorted(dtype_stats.items(), key=lambda x: x[1]["bytes"], reverse=True):
        friendly, bpe = DTYPE_INFO.get(dtype, (dtype, 0))
        p(f"| {friendly} | {bpe}B | {s['count']} | {format_size(s['bytes'])} |")

    # ── 6. 权重值采样分析 ──
    p(f"\n## 6. 权重值采样分析 (验证三值特性)\n")
    try:
        analyze_weight_values(tensors)
    except Exception as e:
        p(f"跳过 (需要安装 safetensors 库): {e}")
        p(f"```\npip install safetensors\n```")

    p()


def unpack_ternary_u8(packed: "numpy.ndarray") -> "numpy.ndarray":
    """将 U8 打包的 2-bit 三值权重解包为 {-1, 0, +1}。

    每个 uint8 包含 4 个 2-bit 权重 (LSB first):
      2'b00 -> -1, 2'b01 -> 0, 2'b10 -> +1, 2'b11 -> 0 (padding)
    """
    import numpy as np
    flat = packed.flatten().astype(np.uint8)
    # 提取 4 个 2-bit 字段
    w0 = flat & 0x03
    w1 = (flat >> 2) & 0x03
    w2 = (flat >> 4) & 0x03
    w3 = (flat >> 6) & 0x03
    # 交错合并: [w0_0, w1_0, w2_0, w3_0, w0_1, ...]
    codes = np.stack([w0, w1, w2, w3], axis=-1).reshape(-1)
    # 映射: 0b00->-1, 0b01->0, 0b10->+1, 0b11->0
    mapping = np.array([-1, 0, 1, 0], dtype=np.int8)
    return mapping[codes]


def analyze_weight_values(tensors: list[dict]):
    """采样分析权重值，验证是否为 {-1, 0, +1} 三值 (U8 打包格式)。"""
    try:
        from safetensors import safe_open
        import numpy as np
    except ImportError:
        print("  需要 safetensors + numpy 库: pip install safetensors numpy")
        return

    # 只选取 U8 类型的 weight 张量 (打包的三值权重)
    sample_tensors = [
        t for t in tensors
        if t["dtype"] == "U8"
        and ("layers.0." in t["name"] or "layers.15." in t["name"])
        and any(p in t["name"] for p in ["q_proj.weight", "gate_proj.weight", "down_proj.weight"])
        and "scale" not in t["name"]
    ]

    if not sample_tensors:
        sample_tensors = [t for t in tensors if t["dtype"] == "U8" and "scale" not in t["name"]][:3]

    print(f"\n> 权重以 U8 打包存储, 每个 uint8 = 4 个 2-bit 三值权重")
    print(f"> 编码: `2'b00=-1, 2'b01=0, 2'b10=+1, 2'b11=0(padding)`\n")

    with safe_open(str(SAFETENSORS_PATH), framework="numpy") as f:
        for t in sample_tensors:
            name = t["name"]
            packed = f.get_tensor(name)
            unpacked = unpack_ternary_u8(packed)
            total = len(unpacked)

            n_pos = int((unpacked == 1).sum())
            n_neg = int((unpacked == -1).sum())
            n_zero = int((unpacked == 0).sum())
            unique_vals = set(unpacked.tolist()[:1000])

            # 实际逻辑维度 (打包前)
            real_shape = (t["shape"][0] * 4, t["shape"][1]) if len(t["shape"]) == 2 else t["shape"]

            is_ternary = unique_vals.issubset({-1, 0, 1})
            status = "三值" if is_ternary else "非三值"
            dist = f"+1={n_pos/total*100:.1f}%, 0={n_zero/total*100:.1f}%, -1={n_neg/total*100:.1f}%"

            print(f"**`{name}`**")
            print(f"- 打包形状: `{t['shape']}` (U8) -> 解包形状: `{real_shape}` (ternary)")
            print(f"- 解包后唯一值: `{sorted(unique_vals)}`")
            if is_ternary:
                print(f"- {status}: {dist}\n")
            else:
                print(f"- 非三值权重 (共 {len(unique_vals)} 个唯一值)\n")


if __name__ == "__main__":
    import io
    import contextlib

    # 同时输出到终端和文件
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf):
        main()

    output = buf.getvalue()
    # 打印到终端
    print(output, end="")
    # 保存到同目录下的 analysis_report.txt
    report_path = MODEL_DIR / "analysis_report.md"
    with open(report_path, "w", encoding="utf-8") as f:
        f.write(output)
    print(f"分析报告已保存至: {report_path}")
