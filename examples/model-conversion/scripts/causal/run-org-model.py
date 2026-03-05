// ============================================================================
// 文件: run-org-model.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/model-conversion/scripts/causal/run-org-model.py
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

#!/usr/bin/env python3

import argparse
import os
import sys
import importlib
import torch
import numpy as np

from transformers import AutoTokenizer, AutoModelForCausalLM, AutoModelForImageTextToText, AutoConfig

# Add parent directory to path for imports
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from utils.common import debug_hook, save_output_data

    # 函数: parse_arguments
    # 描述: parse_arguments函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: parse_arguments
    # 描述: parse_arguments函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def parse_arguments():
    parser = argparse.ArgumentParser(description="Process model with specified path")
    parser.add_argument("--model-path", "-m", help="Path to the model")
    parser.add_argument("--prompt-file", "-f", help="Optional prompt file", required=False)
    parser.add_argument("--verbose", "-v", action="store_true", help="Enable verbose debug output")
    parser.add_argument("--device", "-d", help="Device to use (cpu, cuda, mps, auto)", default="auto")
    return parser.parse_args()

    # 函数: load_model_and_tokenizer
    # 描述: load_model_and_tokenizer函数提供相关功能
    # 参数: model_path, device="auto"
    # 返回: 无返回值
    # 函数: load_model_and_tokenizer
    # 描述: load_model_and_tokenizer函数提供相关功能
    # 参数: model_path, device="auto"
    # 返回: 无返回值
def load_model_and_tokenizer(model_path, device="auto"):
    print("Loading model and tokenizer using AutoTokenizer:", model_path)
    tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
    config = AutoConfig.from_pretrained(model_path, trust_remote_code=True)
    multimodal = False
    full_config = config

    # Determine device_map based on device argument
    if device == "cpu":
        device_map = {"": "cpu"}
        print("Forcing CPU usage")
    elif device == "auto":
        device_map = "auto"
    else:
        device_map = {"": device}

    print("Model type:       ", config.model_type)
    if "vocab_size" not in config and "text_config" in config:
        config = config.text_config
        multimodal = True

    # 函数: print_if_exists
    # 描述: print_if_exists函数提供相关功能
    # 参数: label, obj, attr, default="N/A"
    # 返回: 无返回值
    # 函数: print_if_exists
    # 描述: print_if_exists函数提供相关功能
    # 参数: label, obj, attr, default="N/A"
    # 返回: 无返回值
    def print_if_exists(label, obj, attr, default="N/A"):
        val = getattr(obj, attr) if hasattr(obj, attr) else default
        print(f"{label}", val)

    print_if_exists("Vocab size:       ", config, "vocab_size")
    print_if_exists("Hidden size:      ", config, "hidden_size")
    print_if_exists("Number of layers: ", config, "num_hidden_layers")
    print_if_exists("BOS token id:     ", config, "bos_token_id")
    print_if_exists("EOS token id:     ", config, "eos_token_id")

    unreleased_model_name = os.getenv("UNRELEASED_MODEL_NAME")
    if unreleased_model_name:
        model_name_lower = unreleased_model_name.lower()
        unreleased_module_path = (
            f"transformers.models.{model_name_lower}.modular_{model_name_lower}"
        )
        class_name = f"{unreleased_model_name}ForCausalLM"
        print(f"Importing unreleased model module: {unreleased_module_path}")

        try:
            model_class = getattr(importlib.import_module(unreleased_module_path), class_name)
            model = model_class.from_pretrained(
                    model_path,
                    device_map=device_map,
                    offload_folder="offload",
                    trust_remote_code=True,
                    config=config
            )
        except (ImportError, AttributeError) as e:
            print(f"Failed to import or load model: {e}")
            exit(1)
    else:
        if multimodal:
            model = AutoModelForImageTextToText.from_pretrained(
                    model_path,
                    device_map=device_map,
                    offload_folder="offload",
                    trust_remote_code=True,
                    config=full_config
            )
        else:
            model = AutoModelForCausalLM.from_pretrained(
                    model_path,
                    device_map=device_map,
                    offload_folder="offload",
                    trust_remote_code=True,
                    config=config
            )

    print(f"Model class: {model.__class__.__name__}")

    return model, tokenizer, config

    # 函数: enable_torch_debugging
    # 描述: enable_torch_debugging函数提供相关功能
    # 参数: model
    # 返回: 无返回值
    # 函数: enable_torch_debugging
    # 描述: enable_torch_debugging函数提供相关功能
    # 参数: model
    # 返回: 无返回值
def enable_torch_debugging(model):
        for name, module in model.named_modules():
            if len(list(module.children())) == 0:  # only leaf modules
                module.register_forward_hook(debug_hook(name))

    # 函数: get_prompt
    # 描述: get_prompt函数提供相关功能
    # 参数: args
    # 返回: 有返回值
    # 函数: get_prompt
    # 描述: get_prompt函数提供相关功能
    # 参数: args
    # 返回: 有返回值
def get_prompt(args):
    if args.prompt_file:
        with open(args.prompt_file, encoding='utf-8') as f:
            return f.read()
    elif os.getenv("MODEL_TESTING_PROMPT"):
        return os.getenv("MODEL_TESTING_PROMPT")
    else:
        return "Hello, my name is"

    # 函数: main
    # 描述: main函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: main
    # 描述: main函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def main():
    args = parse_arguments()
    model_path = os.environ.get("MODEL_PATH", args.model_path)
    if model_path is None:
        print("Error: Model path must be specified either via --model-path argument or MODEL_PATH environment variable")
        sys.exit(1)


    model, tokenizer, config = load_model_and_tokenizer(model_path, args.device)

    if args.verbose:
        enable_torch_debugging(model)

    model_name = os.path.basename(model_path)

    # Iterate over the model parameters (the tensors) and get the first one
    # and use it to get the device the model is on.
    device = next(model.parameters()).device
    prompt = get_prompt(args)
    input_ids = tokenizer(prompt, return_tensors="pt").input_ids.to(device)
    token_ids = input_ids[0].cpu().tolist()

    print(f"Input tokens: {input_ids}")
    print(f"Input text: {repr(prompt)}")
    print(f"Tokenized: {tokenizer.convert_ids_to_tokens(input_ids[0])}")

    batch_size = 512

    with torch.no_grad():
        past = None
        outputs = None
        for i in range(0, input_ids.size(1), batch_size):
            print(f"Processing chunk with tokens {i} to {i + batch_size}")
            chunk = input_ids[:, i:i + batch_size]
            outputs = model(chunk.to(model.device), past_key_values=past, use_cache=True)
            past = outputs.past_key_values

        logits = outputs.logits # type: ignore

        # Extract logits for the last token (next token prediction)
        last_logits = logits[0, -1, :].float().cpu().numpy()

        print(f"Logits shape: {logits.shape}")
        print(f"Last token logits shape: {last_logits.shape}")
        print(f"Vocab size: {len(last_logits)}")

        # Print some sample logits for quick verification
        print(f"First 10 logits: {last_logits[:10]}")
        print(f"Last 10 logits: {last_logits[-10:]}")

        # Show top 5 predicted tokens
        top_indices = np.argsort(last_logits)[-5:][::-1]
        print("Top 5 predictions:")
        for idx in top_indices:
            token = tokenizer.decode([idx])
            print(f"  Token {idx} ({repr(token)}): {last_logits[idx]:.6f}")

        save_output_data(last_logits, token_ids, prompt, model_name)

if __name__ == "__main__":
    main()
