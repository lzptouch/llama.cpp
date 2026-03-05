// ============================================================================
// 文件: inspect-org-model.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/model-conversion/scripts/utils/inspect-org-model.py
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

#!/usr/bin/env python3

import argparse
import json
import os
import re
import struct
import sys
from pathlib import Path
from typing import Optional
from safetensors import safe_open


MODEL_SAFETENSORS_FILE = "model.safetensors"
MODEL_SAFETENSORS_INDEX = "model.safetensors.index.json"

DTYPE_SIZES = {
    "F64": 8, "I64": 8, "U64": 8,
    "F32": 4, "I32": 4, "U32": 4,
    "F16": 2, "BF16": 2, "I16": 2, "U16": 2,
    "I8": 1, "U8": 1, "BOOL": 1,
    "F8_E4M3": 1, "F8_E5M2": 1,
}

SIZE_UNITS = ['B', 'KB', 'MB', 'GB', 'TB']


    # 函数: get_weight_map
    # 描述: get_weight_map函数提供相关功能
    # 参数: model_path: Path
    # 返回: 无返回值
def get_weight_map(model_path: Path) -> Optional[dict[str, str]]:
    index_file = model_path / MODEL_SAFETENSORS_INDEX

    if index_file.exists():
        with open(index_file, 'r') as f:
            index = json.load(f)
            return index.get("weight_map", {})

    return None


    # 函数: get_all_tensor_names
    # 描述: get_all_tensor_names函数提供相关功能
    # 参数: model_path: Path
    # 返回: 有返回值
def get_all_tensor_names(model_path: Path) -> list[str]:
    weight_map = get_weight_map(model_path)

    if weight_map is not None:
        return list(weight_map.keys())

    single_file = model_path / MODEL_SAFETENSORS_FILE
    if single_file.exists():
        try:
            with safe_open(single_file, framework="pt", device="cpu") as f:
                return list(f.keys())
        except Exception as e:
            print(f"Error reading {single_file}: {e}")
            sys.exit(1)

    print(f"Error: No safetensors files found in {model_path}")
    sys.exit(1)


    # 函数: find_tensor_file
    # 描述: find_tensor_file函数提供相关功能
    # 参数: model_path: Path, tensor_name: str
    # 返回: 有返回值
def find_tensor_file(model_path: Path, tensor_name: str) -> Optional[str]:
    weight_map = get_weight_map(model_path)

    if weight_map is not None:
        return weight_map.get(tensor_name)

    single_file = model_path / MODEL_SAFETENSORS_FILE
    if single_file.exists():
        return single_file.name

    return None


    # 函数: read_safetensors_header
    # 描述: read_safetensors_header函数提供相关功能
    # 参数: file_path: Path
    # 返回: 有返回值
def read_safetensors_header(file_path: Path) -> dict:
    with open(file_path, 'rb') as f:
        header_size = struct.unpack('<Q', f.read(8))[0]
        return json.loads(f.read(header_size))


    # 函数: get_tensor_size_bytes
    # 描述: get_tensor_size_bytes函数提供相关功能
    # 参数: tensor_meta: dict
    # 返回: 有返回值
def get_tensor_size_bytes(tensor_meta: dict) -> int:
    offsets = tensor_meta.get("data_offsets")
    if offsets and len(offsets) == 2:
        return offsets[1] - offsets[0]
    n_elements = 1
    for d in tensor_meta.get("shape", []):
        n_elements *= d
    return n_elements * DTYPE_SIZES.get(tensor_meta.get("dtype", "F32"), 4)


    # 函数: format_size
    # 描述: format_size函数提供相关功能
    # 参数: size_bytes: int
    # 返回: 有返回值
def format_size(size_bytes: int) -> str:
    val = float(size_bytes)
    for unit in SIZE_UNITS[:-1]:
        if val < 1024.0:
            return f"{val:.2f} {unit}"
        val /= 1024.0
    return f"{val:.2f} {SIZE_UNITS[-1]}"


    # 函数: get_all_tensor_metadata
    # 描述: get_all_tensor_metadata函数提供相关功能
    # 参数: model_path: Path
    # 返回: 无返回值
def get_all_tensor_metadata(model_path: Path) -> dict[str, dict]:
    weight_map = get_weight_map(model_path)

    if weight_map is not None:
        file_to_tensors: dict[str, list[str]] = {}
        for tensor_name, file_name in weight_map.items():
            file_to_tensors.setdefault(file_name, []).append(tensor_name)

        all_metadata: dict[str, dict] = {}
        for file_name, tensor_names in file_to_tensors.items():
            try:
                header = read_safetensors_header(model_path / file_name)
                for tensor_name in tensor_names:
                    if tensor_name in header:
                        all_metadata[tensor_name] = header[tensor_name]
            except Exception as e:
                print(f"Warning: Could not read header from {file_name}: {e}", file=sys.stderr)
        return all_metadata

    single_file = model_path / MODEL_SAFETENSORS_FILE
    if single_file.exists():
        try:
            header = read_safetensors_header(single_file)
            return {k: v for k, v in header.items() if k != "__metadata__"}
        except Exception as e:
            print(f"Error reading {single_file}: {e}")
            sys.exit(1)

    print(f"Error: No safetensors files found in {model_path}")
    sys.exit(1)


    # 函数: normalize_tensor_name
    # 描述: normalize_tensor_name函数提供相关功能
    # 参数: tensor_name: str
    # 返回: 有返回值
def normalize_tensor_name(tensor_name: str) -> str:
    normalized = re.sub(r'\.\d+\.', '.#.', tensor_name)
    normalized = re.sub(r'\.\d+$', '.#', normalized)
    return normalized


    # 函数: list_all_tensors
    # 描述: list_all_tensors函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def list_all_tensors(
    model_path: Path,
    short: bool = False,
    show_sizes: bool = False,
):
    tensor_names = get_all_tensor_names(model_path)

    metadata: Optional[dict[str, dict]] = None
    if show_sizes:
        metadata = get_all_tensor_metadata(model_path)

    total_bytes = 0

    if short:
        seen: dict[str, str] = {}
        for tensor_name in sorted(tensor_names):
            normalized = normalize_tensor_name(tensor_name)
            if normalized not in seen:
                seen[normalized] = tensor_name
        display_pairs = list(sorted(seen.items()))
        name_width = max((len(n) for n, _ in display_pairs), default=0)
        for normalized, first_name in display_pairs:
            if metadata and first_name in metadata:
                m = metadata[first_name]
                size = get_tensor_size_bytes(m)
                total_bytes += size
                print(f"{normalized:{name_width}}  {m.get('dtype', '?'):6s}  {str(m.get('shape', '')):30s}  {format_size(size)}")
            else:
                print(normalized)
    else:
        name_width = max((len(n) for n in tensor_names), default=0)
        for tensor_name in sorted(tensor_names):
            if metadata and tensor_name in metadata:
                m = metadata[tensor_name]
                size = get_tensor_size_bytes(m)
                total_bytes += size
                print(f"{tensor_name:{name_width}}  {m.get('dtype', '?'):6s}  {str(m.get('shape', '')):30s}  {format_size(size)}")
            else:
                print(tensor_name)

    if show_sizes:
        print(f"\nTotal: {format_size(total_bytes)}")


    # 函数: print_tensor_info
    # 描述: print_tensor_info函数提供相关功能
    # 参数: model_path: Path, tensor_name: str, num_values: Optional[int] = None
    # 返回: 无返回值
def print_tensor_info(model_path: Path, tensor_name: str, num_values: Optional[int] = None):
    tensor_file = find_tensor_file(model_path, tensor_name)

    if tensor_file is None:
        print(f"Error: Could not find tensor '{tensor_name}' in model index")
        print(f"Model path: {model_path}")
        sys.exit(1)

    file_path = model_path / tensor_file

    try:
        header = read_safetensors_header(file_path)
        tensor_meta = header.get(tensor_name, {})
        dtype_str = tensor_meta.get("dtype")

        with safe_open(file_path, framework="pt", device="cpu") as f:
            if tensor_name in f.keys():
                tensor_slice = f.get_slice(tensor_name)
                shape = tensor_slice.get_shape()
                print(f"Tensor: {tensor_name}")
                print(f"File:   {tensor_file}")
                print(f"Shape:  {shape}")
                if dtype_str:
                    print(f"Dtype:  {dtype_str}")
                if tensor_meta:
                    print(f"Size:   {format_size(get_tensor_size_bytes(tensor_meta))}")
                if num_values is not None:
                    tensor = f.get_tensor(tensor_name)
                    if not dtype_str:
                        print(f"Dtype:  {tensor.dtype}")
                    flat = tensor.flatten()
                    n = min(num_values, flat.numel())
                    print(f"Values: {flat[:n].tolist()}")
            else:
                print(f"Error: Tensor '{tensor_name}' not found in {tensor_file}")
                sys.exit(1)

    except FileNotFoundError:
        print(f"Error: The file '{file_path}' was not found.")
        sys.exit(1)
    except Exception as e:
        print(f"An error occurred: {e}")
        sys.exit(1)


    # 函数: main
    # 描述: main函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def main():
    parser = argparse.ArgumentParser(
        description="Print tensor information from a safetensors model"
    )
    parser.add_argument(
        "tensor_name",
        nargs="?",
        help="Name of the tensor to inspect"
    )
    parser.add_argument(
        "-m", "--model-path",
        type=Path,
        help="Path to the model directory (default: MODEL_PATH environment variable)"
    )
    parser.add_argument(
        "-l", "--list-all-short",
        action="store_true",
        help="List unique tensor patterns (layer numbers replaced with #)"
    )
    parser.add_argument(
        "-la", "--list-all",
        action="store_true",
        help="List all tensor names with actual layer numbers"
    )
    parser.add_argument(
        "-n", "--num-values",
        nargs="?",
        const=10,
        default=None,
        type=int,
        metavar="N",
        help="Print the first N values of the tensor flattened (default: 10 if flag is given without a number)"
    )
    parser.add_argument(
        "-s", "--sizes",
        action="store_true",
        help="Show dtype, shape, and size for each tensor when listing"
    )

    args = parser.parse_args()

    model_path = args.model_path
    if model_path is None:
        model_path_str = os.environ.get("MODEL_PATH")
        if model_path_str is None:
            print("Error: --model-path not provided and MODEL_PATH environment variable not set")
            sys.exit(1)
        model_path = Path(model_path_str)

    if not model_path.exists():
        print(f"Error: Model path does not exist: {model_path}")
        sys.exit(1)

    if not model_path.is_dir():
        print(f"Error: Model path is not a directory: {model_path}")
        sys.exit(1)

    if args.list_all_short or args.list_all:
        list_all_tensors(model_path, short=args.list_all_short, show_sizes=args.sizes)
    else:
        if args.tensor_name is None:
            print("Error: tensor_name is required when not using --list-all-short or --list-all")
            sys.exit(1)
        print_tensor_info(model_path, args.tensor_name, args.num_values)


if __name__ == "__main__":
    main()
