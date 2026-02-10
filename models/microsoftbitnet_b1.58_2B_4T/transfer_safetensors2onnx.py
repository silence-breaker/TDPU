#!/usr/bin/env python3
"""
将 BitNet b1.58-2B-4T 模型从 safetensors 格式转换为 ONNX 格式。

目标平台: 复旦微电子 Icraft FPGA 平台
支持的 ONNX 标准: opset version 11/14/17, ir version 8, ONNX version ≤ 1.13.1

模型信息:
  - 架构: BitNetForCausalLM (microsoft/bitnet-b1.58-2B-4T)
  - 权重: 1.58-bit 三值 (packed U8), 编码: 2'b00=-1, 2'b01=0, 2'b10=+1
  - 30 层 Transformer, hidden_size=2560, intermediate_size=6912
  - GQA: 20 attention heads, 5 KV heads
  - 词表: 128256, 最大序列长度: 4096

依赖:
    pip install torch transformers safetensors onnx huggingface_hub

用法:
    python transfer_safetensors2onnx.py
    python transfer_safetensors2onnx.py --opset 14 --seq-len 64 --output model.onnx
    python transfer_safetensors2onnx.py --dtype float16   # 半精度导出，减小 ONNX 体积
"""

import sys
import logging
import argparse
from pathlib import Path

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    datefmt="%H:%M:%S",
)
logger = logging.getLogger(__name__)

# ======================== 配置常量 ========================
MODEL_DIR = Path(__file__).resolve().parent
HF_REPO_ID = "microsoft/bitnet-b1.58-2B-4T"
SUPPORTED_OPSETS = [11, 14, 17]
DEFAULT_OPSET = 14
DEFAULT_SEQ_LEN = 128


def parse_args():
    """解析命令行参数。"""
    parser = argparse.ArgumentParser(
        description="将 BitNet b1.58-2B-4T safetensors 模型转换为 ONNX 格式 (Icraft 兼容)",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "--opset",
        type=int,
        default=DEFAULT_OPSET,
        choices=SUPPORTED_OPSETS,
        help=f"ONNX opset version, Icraft 支持 {SUPPORTED_OPSETS} (默认: {DEFAULT_OPSET})",
    )
    parser.add_argument(
        "--seq-len",
        type=int,
        default=DEFAULT_SEQ_LEN,
        help=f"导出时使用的 dummy 序列长度 (默认: {DEFAULT_SEQ_LEN})",
    )
    parser.add_argument(
        "--output",
        type=str,
        default=None,
        help="输出 ONNX 文件路径 (默认: 同目录下 model.onnx)",
    )
    parser.add_argument(
        "--repo-id",
        type=str,
        default=HF_REPO_ID,
        help=f"HuggingFace 模型仓库 ID, 用于下载自定义代码 (默认: {HF_REPO_ID})",
    )
    parser.add_argument(
        "--dtype",
        type=str,
        default="float32",
        choices=["float32", "float16"],
        help="导出模型的计算精度 (默认: float32)",
    )
    parser.add_argument(
        "--no-verify",
        action="store_true",
        help="跳过 ONNX 模型验证步骤",
    )
    parser.add_argument(
        "--verbose",
        action="store_true",
        help="显示详细日志",
    )
    return parser.parse_args()


# ======================== 工具函数 ========================


def check_dependencies():
    """检查必要的 Python 依赖包。"""
    required = {
        "torch": "torch",
        "transformers": "transformers",
        "safetensors": "safetensors",
        "onnx": "onnx",
        "huggingface_hub": "huggingface_hub",
    }
    missing = []
    for display_name, import_name in required.items():
        try:
            __import__(import_name)
        except ImportError:
            missing.append(display_name)

    if missing:
        logger.error(
            f"缺少依赖包: {', '.join(missing)}\n"
            f"请运行: pip install {' '.join(missing)}"
        )
        sys.exit(1)

    import torch
    logger.info(f"依赖检查通过 (PyTorch {torch.__version__}, "
                f"CUDA {'可用' if torch.cuda.is_available() else '不可用'})")


def ensure_model_code(model_dir: Path, repo_id: str):
    """
    确保自定义模型代码 (modeling_bitnet.py, configuration_bitnet.py) 在本地。
    BitNet 是自定义架构，需要 trust_remote_code=True，模型代码必须在本地目录中。
    """
    required_files = ["modeling_bitnet.py", "configuration_bitnet.py"]
    missing = [f for f in required_files if not (model_dir / f).exists()]

    if not missing:
        logger.info("自定义模型代码已存在于本地目录。")
        return

    logger.info(f"需要从 HuggingFace ({repo_id}) 下载缺失的模型代码: {missing}")
    from huggingface_hub import hf_hub_download

    for filename in missing:
        try:
            hf_hub_download(
                repo_id=repo_id,
                filename=filename,
                local_dir=str(model_dir),
            )
            logger.info(f"  [OK] 已下载: {filename}")
        except Exception as e:
            logger.error(f"  [FAIL] 下载 {filename} 失败: {e}")
            logger.error(
                f"请手动从 https://huggingface.co/{repo_id}/tree/main "
                f"下载 {filename} 到 {model_dir}/"
            )
            sys.exit(1)


def load_model(model_dir: Path, dtype_str: str):
    """
    加载 BitNet 模型。

    关键步骤:
    1. 加载 config 并禁用 KV cache (简化 ONNX 图, 避免导出 past_key_values)
    2. 使用 trust_remote_code=True 加载自定义 BitLinear 层
    3. 设置 eval 模式, 禁用 dropout
    """
    import torch
    from transformers import AutoModelForCausalLM, AutoConfig

    dtype_map = {"float32": torch.float32, "float16": torch.float16}
    dtype = dtype_map[dtype_str]

    logger.info(f"正在加载模型配置: {model_dir / 'config.json'}")
    config = AutoConfig.from_pretrained(str(model_dir), trust_remote_code=True)
    # 禁用 KV cache — ONNX 导出不支持动态 past_key_values 输出
    config.use_cache = False

    logger.info(f"正在加载模型权重 (dtype={dtype_str})...")
    logger.info("  (BitNet 三值权重将从 packed U8 格式加载并由自定义代码处理)")

    model = AutoModelForCausalLM.from_pretrained(
        str(model_dir),
        config=config,
        trust_remote_code=True,
        torch_dtype=dtype,
    )
    model.eval()

    total_params = sum(p.numel() for p in model.parameters())
    logger.info(f"模型加载完成。总参数量: {total_params:,}")
    return model, config


def export_to_onnx(model, config, output_path: Path, opset: int, seq_len: int, dtype_str: str):
    """
    将 CausalLM 模型导出为 ONNX 格式。

    导出策略:
    - 使用 CausalLMWrapper 包装模型, 仅输出 logits (避免 NamedTuple 导出问题)
    - 设置 dynamic_axes 支持可变 batch_size 和 sequence_length
    - 启用 constant_folding 优化
    """
    import torch

    class CausalLMWrapper(torch.nn.Module):
        """包装 CausalLM, 仅返回 logits tensor, 简化 ONNX 导出图。"""

        def __init__(self, model):
            super().__init__()
            self.model = model

        def forward(self, input_ids, attention_mask):
            outputs = self.model(input_ids=input_ids, attention_mask=attention_mask)
            return outputs.logits

    dtype_map = {"float32": torch.float32, "float16": torch.float16}
    dtype = dtype_map[dtype_str]

    logger.info(f"准备 ONNX 导出 (opset={opset}, dummy_seq_len={seq_len}, dtype={dtype_str})")

    wrapper = CausalLMWrapper(model)
    wrapper.eval()

    # 构造 dummy 输入
    batch_size = 1
    input_ids = torch.randint(0, config.vocab_size, (batch_size, seq_len), dtype=torch.long)
    attention_mask = torch.ones(batch_size, seq_len, dtype=torch.long)

    # 动态轴: 允许可变的 batch_size 和 sequence_length
    dynamic_axes = {
        "input_ids": {0: "batch_size", 1: "sequence_length"},
        "attention_mask": {0: "batch_size", 1: "sequence_length"},
        "logits": {0: "batch_size", 1: "sequence_length"},
    }

    logger.info("正在导出 ONNX 模型 (这可能需要数分钟, 取决于硬件)...")

    # 确保输出目录存在
    output_path.parent.mkdir(parents=True, exist_ok=True)

    with torch.no_grad():
        torch.onnx.export(
            wrapper,
            (input_ids, attention_mask),
            str(output_path),
            input_names=["input_ids", "attention_mask"],
            output_names=["logits"],
            dynamic_axes=dynamic_axes,
            opset_version=opset,
            do_constant_folding=True,
            export_params=True,
        )

    file_size_mb = output_path.stat().st_size / (1024 * 1024)
    logger.info(f"ONNX 模型已导出: {output_path}")
    logger.info(f"  文件大小: {file_size_mb:.1f} MB")


def verify_onnx(onnx_path: Path):
    """
    验证导出的 ONNX 模型。
    检查模型结构完整性, 打印 IR version / opset / 输入输出信息。
    """
    import onnx

    logger.info("正在验证 ONNX 模型...")

    try:
        model = onnx.load(str(onnx_path))
        onnx.checker.check_model(model)

        graph = model.graph
        logger.info(f"  IR version:    {model.ir_version}")
        logger.info(f"  Opset version: {model.opset_import[0].version}")
        logger.info(f"  ONNX 节点数:   {len(graph.node)}")

        logger.info(f"  输入 ({len(graph.input)}):")
        for inp in graph.input:
            dims = []
            for d in inp.type.tensor_type.shape.dim:
                dims.append(d.dim_param if d.dim_param else str(d.dim_value))
            logger.info(f"    {inp.name}: [{', '.join(dims)}]")

        logger.info(f"  输出 ({len(graph.output)}):")
        for out in graph.output:
            dims = []
            for d in out.type.tensor_type.shape.dim:
                dims.append(d.dim_param if d.dim_param else str(d.dim_value))
            logger.info(f"    {out.name}: [{', '.join(dims)}]")

        logger.info("  [OK] ONNX 模型验证通过!")
        return True

    except onnx.checker.ValidationError as e:
        logger.warning(f"  [WARN] ONNX 结构验证失败: {e}")
        logger.warning("  模型文件已生成, 但可能存在兼容性问题。")
        return False
    except Exception as e:
        logger.warning(f"  [WARN] ONNX 验证时发生错误: {e}")
        logger.warning("  如果模型文件过大 (>2GB), 可尝试 onnx.load 时设置 load_external_data=False")
        return False


# ======================== 主流程 ========================


def main():
    args = parse_args()

    if args.verbose:
        logging.getLogger().setLevel(logging.DEBUG)

    logger.info("=" * 60)
    logger.info("BitNet b1.58-2B-4T  safetensors → ONNX 转换器")
    logger.info(f"目标平台: Icraft FPGA (opset {args.opset})")
    logger.info("=" * 60)

    # 1. 检查依赖
    check_dependencies()

    # 2. 确定输出路径
    output_path = Path(args.output) if args.output else MODEL_DIR / "model.onnx"

    if output_path.exists():
        logger.warning(f"输出文件已存在, 将被覆盖: {output_path}")

    # 3. 确保自定义模型代码可用
    #    BitNet 使用自定义 modeling_bitnet.py / configuration_bitnet.py
    #    如果本地没有, 需要从 HuggingFace Hub 下载
    ensure_model_code(MODEL_DIR, args.repo_id)

    # 4. 加载模型
    model, config = load_model(MODEL_DIR, args.dtype)

    # 5. 导出 ONNX
    export_to_onnx(model, config, output_path, args.opset, args.seq_len, args.dtype)

    # 6. 验证
    if not args.no_verify:
        verify_onnx(output_path)

    logger.info("=" * 60)
    logger.info("转换完成!")
    logger.info(f"输出文件: {output_path}")
    logger.info(f"后续步骤: 使用 Icraft 工具链导入此 ONNX 模型")
    logger.info("  icraft compile --model model.onnx --target FMQL30TAI")
    logger.info("=" * 60)


if __name__ == "__main__":
    main()
