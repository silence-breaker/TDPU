# BitNet b1.58 2B-4T 模型结构分析

## 模型配置 (config.json)

| 属性 | 值 |
| :--- | :--- |
| 架构 | `BitNetForCausalLM` |
| 隐藏层维度 | 2560 |
| 中间层维度 | 6912 |
| 层数 | 30 |
| 注意力头数 | 20 |
| KV 头数 | 5 |
| 词表大小 | 128256 |
| 最大位置编码 | 4096 |
| 激活函数 | `relu2` |
| 量化方式 | `bitnet` |
| 数据类型 | `bfloat16` |
| tie_word_embeddings | `True` |

> 文件: `model.safetensors`, 大小: **1.10 GB**

## 1. 张量列表 (共 542 个)

<details>
<summary>点击展开完整张量列表</summary>

| 名称 | 形状 | 类型 | 大小 |
| :--- | :--- | :--- | ---: |
| `model.embed_tokens.weight` | `[128256, 2560]` | BF16 | 626.25 MB |
| `model.layers.0.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.0.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.0.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.0.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.0.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.0.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.0.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.0.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.0.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.0.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.0.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.0.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.0.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.0.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.0.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.0.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.0.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.0.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.1.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.1.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.1.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.1.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.1.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.1.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.1.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.1.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.1.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.1.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.1.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.1.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.1.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.1.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.1.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.1.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.1.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.1.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.10.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.10.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.10.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.10.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.10.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.10.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.10.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.10.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.10.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.10.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.10.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.10.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.10.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.10.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.10.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.10.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.10.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.10.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.11.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.11.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.11.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.11.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.11.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.11.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.11.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.11.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.11.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.11.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.11.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.11.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.11.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.11.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.11.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.11.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.11.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.11.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.12.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.12.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.12.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.12.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.12.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.12.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.12.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.12.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.12.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.12.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.12.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.12.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.12.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.12.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.12.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.12.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.12.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.12.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.13.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.13.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.13.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.13.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.13.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.13.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.13.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.13.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.13.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.13.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.13.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.13.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.13.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.13.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.13.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.13.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.13.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.13.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.14.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.14.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.14.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.14.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.14.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.14.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.14.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.14.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.14.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.14.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.14.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.14.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.14.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.14.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.14.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.14.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.14.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.14.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.15.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.15.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.15.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.15.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.15.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.15.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.15.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.15.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.15.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.15.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.15.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.15.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.15.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.15.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.15.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.15.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.15.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.15.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.16.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.16.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.16.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.16.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.16.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.16.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.16.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.16.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.16.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.16.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.16.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.16.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.16.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.16.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.16.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.16.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.16.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.16.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.17.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.17.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.17.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.17.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.17.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.17.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.17.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.17.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.17.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.17.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.17.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.17.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.17.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.17.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.17.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.17.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.17.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.17.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.18.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.18.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.18.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.18.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.18.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.18.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.18.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.18.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.18.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.18.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.18.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.18.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.18.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.18.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.18.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.18.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.18.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.18.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.19.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.19.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.19.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.19.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.19.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.19.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.19.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.19.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.19.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.19.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.19.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.19.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.19.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.19.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.19.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.19.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.19.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.19.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.2.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.2.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.2.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.2.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.2.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.2.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.2.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.2.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.2.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.2.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.2.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.2.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.2.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.2.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.2.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.2.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.2.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.2.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.20.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.20.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.20.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.20.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.20.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.20.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.20.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.20.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.20.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.20.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.20.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.20.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.20.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.20.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.20.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.20.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.20.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.20.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.21.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.21.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.21.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.21.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.21.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.21.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.21.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.21.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.21.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.21.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.21.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.21.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.21.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.21.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.21.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.21.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.21.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.21.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.22.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.22.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.22.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.22.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.22.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.22.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.22.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.22.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.22.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.22.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.22.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.22.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.22.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.22.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.22.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.22.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.22.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.22.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.23.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.23.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.23.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.23.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.23.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.23.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.23.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.23.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.23.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.23.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.23.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.23.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.23.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.23.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.23.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.23.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.23.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.23.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.24.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.24.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.24.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.24.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.24.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.24.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.24.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.24.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.24.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.24.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.24.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.24.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.24.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.24.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.24.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.24.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.24.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.24.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.25.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.25.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.25.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.25.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.25.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.25.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.25.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.25.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.25.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.25.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.25.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.25.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.25.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.25.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.25.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.25.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.25.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.25.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.26.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.26.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.26.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.26.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.26.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.26.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.26.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.26.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.26.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.26.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.26.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.26.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.26.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.26.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.26.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.26.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.26.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.26.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.27.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.27.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.27.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.27.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.27.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.27.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.27.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.27.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.27.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.27.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.27.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.27.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.27.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.27.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.27.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.27.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.27.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.27.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.28.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.28.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.28.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.28.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.28.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.28.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.28.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.28.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.28.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.28.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.28.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.28.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.28.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.28.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.28.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.28.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.28.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.28.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.29.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.29.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.29.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.29.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.29.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.29.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.29.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.29.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.29.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.29.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.29.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.29.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.29.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.29.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.29.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.29.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.29.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.29.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.3.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.3.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.3.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.3.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.3.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.3.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.3.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.3.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.3.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.3.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.3.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.3.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.3.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.3.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.3.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.3.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.3.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.3.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.4.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.4.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.4.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.4.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.4.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.4.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.4.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.4.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.4.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.4.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.4.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.4.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.4.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.4.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.4.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.4.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.4.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.4.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.5.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.5.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.5.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.5.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.5.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.5.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.5.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.5.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.5.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.5.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.5.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.5.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.5.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.5.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.5.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.5.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.5.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.5.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.6.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.6.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.6.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.6.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.6.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.6.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.6.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.6.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.6.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.6.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.6.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.6.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.6.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.6.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.6.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.6.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.6.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.6.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.7.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.7.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.7.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.7.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.7.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.7.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.7.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.7.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.7.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.7.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.7.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.7.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.7.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.7.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.7.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.7.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.7.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.7.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.8.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.8.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.8.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.8.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.8.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.8.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.8.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.8.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.8.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.8.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.8.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.8.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.8.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.8.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.8.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.8.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.8.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.8.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.9.input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.9.mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `model.layers.9.mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.9.mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `model.layers.9.mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.9.mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.9.mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `model.layers.9.mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.9.post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.9.self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `model.layers.9.self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.9.self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.9.self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.9.self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.9.self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `model.layers.9.self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.layers.9.self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `model.layers.9.self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `model.norm.weight` | `[2560]` | BF16 | 5.00 KB |

</details>

## 2. 按类别统计

| 类别 | 张量数 | 参数量 | 存储大小 | 占比 |
| :--- | ---: | ---: | ---: | ---: |
| Embedding | 1 | 328,335,360 | 626.25 MB | 55.72% |
| MLP Down | 60 | 132,710,430 | 126.56 MB | 11.26% |
| MLP Gate | 60 | 132,710,430 | 126.56 MB | 11.26% |
| MLP Up | 60 | 132,710,430 | 126.56 MB | 11.26% |
| Attention O | 60 | 49,152,030 | 46.88 MB | 4.17% |
| Attention Q | 60 | 49,152,030 | 46.88 MB | 4.17% |
| Attention K | 60 | 12,288,030 | 11.72 MB | 1.04% |
| Attention V | 60 | 12,288,030 | 11.72 MB | 1.04% |
| MLP Other | 30 | 207,360 | 405.00 KB | 0.04% |
| Layer Norm | 60 | 153,600 | 300.00 KB | 0.03% |
| Attention Other | 30 | 76,800 | 150.00 KB | 0.01% |
| Final Norm | 1 | 2,560 | 5.00 KB | 0.00% |
| **合计** | **542** | **849,787,090** | **1.10 GB** | **100.00%** |

## 3. Layer 0 详细结构 (其余层结构相同)

| 名称 | 形状 | 类型 | 大小 |
| :--- | :--- | :--- | ---: |
| `input_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `mlp.down_proj.weight` | `[640, 6912]` | U8 | 4.22 MB |
| `mlp.down_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `mlp.ffn_sub_norm.weight` | `[6912]` | BF16 | 13.50 KB |
| `mlp.gate_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `mlp.gate_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `mlp.up_proj.weight` | `[1728, 2560]` | U8 | 4.22 MB |
| `mlp.up_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `post_attention_layernorm.weight` | `[2560]` | BF16 | 5.00 KB |
| `self_attn.attn_sub_norm.weight` | `[2560]` | BF16 | 5.00 KB |
| `self_attn.k_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `self_attn.k_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `self_attn.o_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `self_attn.o_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `self_attn.q_proj.weight` | `[640, 2560]` | U8 | 1.56 MB |
| `self_attn.q_proj.weight_scale` | `[1]` | BF16 | 2 B |
| `self_attn.v_proj.weight` | `[160, 2560]` | U8 | 400.00 KB |
| `self_attn.v_proj.weight_scale` | `[1]` | BF16 | 2 B |

## 4. FPGA 加速相关分析 (BitLinear 层)

每层 Transformer Block 的 Linear 层:

| 名称 | 输入维度 (K) | 输出维度 (M) | 参数量 | 1.58-bit 压缩 |
| :--- | ---: | ---: | ---: | ---: |
| q_proj | 2,560 | 2,560 | 6,553,600 | 1.56 MB |
| k_proj | 2,560 | 640 | 1,638,400 | 400.00 KB |
| v_proj | 2,560 | 640 | 1,638,400 | 400.00 KB |
| o_proj | 2,560 | 2,560 | 6,553,600 | 1.56 MB |
| gate_proj | 2,560 | 6,912 | 17,694,720 | 4.22 MB |
| up_proj | 2,560 | 6,912 | 17,694,720 | 4.22 MB |
| down_proj | 6,912 | 2,560 | 17,694,720 | 4.22 MB |
| **单层合计** | | | **69,468,160** | **16.56 MB** |
| **全部 30 层** | | | **2,084,044,800** | **496.88 MB** |

## 5. 数据类型分布

| 数据类型 | 字节/元素 | 张量数 | 存储大小 |
| :--- | ---: | ---: | ---: |
| bfloat16 | 2B | 332 | 627.09 MB |
| uint8 | 1B | 210 | 496.88 MB |

## 6. 权重值采样分析 (验证三值特性)


> 权重以 U8 打包存储, 每个 uint8 = 4 个 2-bit 三值权重
> 编码: `2'b00=-1, 2'b01=0, 2'b10=+1, 2'b11=0(padding)`

**`model.layers.0.mlp.down_proj.weight`**
- 打包形状: `[640, 6912]` (U8) -> 解包形状: `(2560, 6912)` (ternary)
- 解包后唯一值: `[-1, 0, 1]`
- 三值: +1=30.9%, 0=38.2%, -1=30.9%

**`model.layers.0.mlp.gate_proj.weight`**
- 打包形状: `[1728, 2560]` (U8) -> 解包形状: `(6912, 2560)` (ternary)
- 解包后唯一值: `[-1, 0, 1]`
- 三值: +1=30.6%, 0=39.1%, -1=30.3%

**`model.layers.0.self_attn.q_proj.weight`**
- 打包形状: `[640, 2560]` (U8) -> 解包形状: `(2560, 2560)` (ternary)
- 解包后唯一值: `[-1, 0, 1]`
- 三值: +1=25.2%, 0=49.6%, -1=25.2%

**`model.layers.15.mlp.down_proj.weight`**
- 打包形状: `[640, 6912]` (U8) -> 解包形状: `(2560, 6912)` (ternary)
- 解包后唯一值: `[-1, 0, 1]`
- 三值: +1=30.1%, 0=39.8%, -1=30.1%

**`model.layers.15.mlp.gate_proj.weight`**
- 打包形状: `[1728, 2560]` (U8) -> 解包形状: `(6912, 2560)` (ternary)
- 解包后唯一值: `[-1, 0, 1]`
- 三值: +1=29.2%, 0=41.5%, -1=29.4%

**`model.layers.15.self_attn.q_proj.weight`**
- 打包形状: `[640, 2560]` (U8) -> 解包形状: `(2560, 2560)` (ternary)
- 解包后唯一值: `[-1, 0, 1]`
- 三值: +1=27.2%, 0=45.6%, -1=27.2%


