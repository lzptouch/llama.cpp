// ============================================================================
// 文件: create_ops_docs.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/scripts/create_ops_docs.py
// 作者: 自动注释工具
// 描述: 配置或脚本文件
// ============================================================================

#!/usr/bin/env python3

"""
This script parses docs/ops/*.csv and creates the ops.md, which is a table documenting supported operations on various ggml backends.
"""
import csv
import logging
import sys
from pathlib import Path
from collections import defaultdict


    # 类: DocsGenerator
    # 描述: DocsGenerator类提供相关功能
    # 用途: 用于处理DocsGenerator相关的操作
class DocsGenerator:
    # 函数: __init__
    # 描述: __init__函数提供相关功能
    # 参数: self, ggml_root: str, output_filename: str = "ops.md"
    # 返回: 无返回值
    def __init__(self, ggml_root: str, output_filename: str = "ops.md"):
        self.ggml_root = Path(ggml_root)
        self.ops_dir = self.ggml_root / "docs" / "ops"
        self.output_filename = output_filename
        self.backend_support: dict[str, dict[str, list[bool]]] = defaultdict(
            lambda: defaultdict(list)
        )
        self.all_operations: set[str] = set()
        self.all_backends: set[str] = set()
        self.logger = logging.getLogger(__name__)

    # 函数: parse_support_files
    # 描述: parse_support_files函数提供相关功能
    # 参数: 无参数
    # 返回: 有返回值
    def parse_support_files(self) -> None:
        if not self.ops_dir.exists():
            self.logger.warning(f"ops directory not found: {self.ops_dir}")
            return

        self.logger.info(f"Parsing support files from {self.ops_dir}...")

        for support_file in self.ops_dir.glob("*.csv"):
            self.logger.info(f"  Reading: {support_file.name}")
            self._parse_support_file(support_file)

    # 函数: _parse_support_file
    # 描述: _parse_support_file函数提供相关功能
    # 参数: self, file_path: Path
    # 返回: 无返回值
    def _parse_support_file(self, file_path: Path) -> None:
        try:
            with open(file_path, "r", newline='') as f:
                reader = csv.DictReader(f)

                for row in reader:
                    # Skip rows that don't have support mode
                    if row.get('test_mode') != 'support':
                        continue

                    backend_name = row.get('backend_name', '').strip()
                    operation = row.get('op_name', '').strip()
                    supported_str = row.get('error_message', '').strip()  # "yes" or "no"
                    backend_reg_name = row.get('backend_reg_name', '').strip()

                    # Skip invalid or error operations
                    if not operation or not backend_name or operation in [
                        "CONTEXT_ERROR",
                        "BUILD_ERROR",
                    ]:
                        continue

                    is_supported = supported_str.lower() == "yes"

                    # Use backend_reg_name for grouping, fallback to backend_name
                    backend_key = backend_reg_name if backend_reg_name else backend_name

                    self.all_backends.add(backend_key)
                    self.backend_support[backend_key][operation].append(is_supported)
                    self.all_operations.add(operation)

        except Exception as e:
            self.logger.error(f"    Error parsing {file_path}: {e}")

    # 函数: get_backend_support_status
    # 描述: get_backend_support_status函数提供相关功能
    # 参数: self, backend: str, operation: str
    # 返回: 有返回值
    def get_backend_support_status(self, backend: str, operation: str) -> str:
        support_list = self.backend_support[backend].get(operation, [])

        if not support_list:
            return "unsupported"

        all_supported = all(support_list)
        any_supported = any(support_list)

        if all_supported:
            return "supported"
        elif any_supported:
            return "partially supported"
        else:
            return "unsupported"

    # 函数: get_support_status
    # 描述: get_support_status函数提供相关功能
    # 参数: self, operation: str
    # 返回: 有返回值
    def get_support_status(self, operation: str) -> str:
        if operation not in self.all_operations:
            return "unsupported"

        support_count = 0
        total_backends = len(self.all_backends)

        for backend in self.all_backends:
            if self.backend_support[backend].get(operation, False):
                support_count += 1

        if support_count == 0:
            return "unsupported"
        elif support_count == total_backends:
            return "supported"
        else:
            return "partially supported"

    # 函数: get_support_symbol
    # 描述: get_support_symbol函数提供相关功能
    # 参数: self, status: str
    # 返回: 有返回值
    def get_support_symbol(self, status: str) -> str:
        symbols = {"supported": "✅", "partially supported": "🟡", "unsupported": "❌"}
        return symbols.get(status, "❓")

    # 函数: generate_markdown
    # 描述: generate_markdown函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    def generate_markdown(self) -> str:
        lines = []

        lines.append("# GGML Operations")
        lines.append("")
        lines.append("List of GGML operations and backend support status.")
        lines.append("")
        lines.append("## How to add a backend to this table:")
        lines.append("")
        lines.append("1. Run `test-backend-ops support --output csv` with your backend name and redirect output to a csv file in `docs/ops/` (e.g., `docs/ops/CUDA.csv`)")
        lines.append("2. Regenerate `/docs/ops.md` via `./scripts/create_ops_docs.py`")
        lines.append("")
        lines.append("Legend:")
        lines.append("- ✅ Fully supported by this backend")
        lines.append("- 🟡 Partially supported by this backend")
        lines.append("- ❌ Not supported by this backend")
        lines.append("")

        backends = sorted(self.all_backends)
        header = "| Operation |"
        for backend in backends:
            header += f" {backend} |"

        separator = "|-----------|"
        for _ in backends:
            separator += "------|"

        lines.append(header)
        lines.append(separator)

        sorted_operations = sorted(self.all_operations)

        for operation in sorted_operations:
            row = f"| {operation:>32} |"

            for backend in backends:
                status = self.get_backend_support_status(backend, operation)
                if status == "supported":
                    symbol = "✅"
                elif status == "partially supported":
                    symbol = "🟡"
                else:
                    symbol = "❌"
                row += f" {symbol} |"

            lines.append(row)

        lines.append("")

        return "\n".join(lines)

    # 函数: run
    # 描述: run函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    def run(self) -> None:
        self.logger.info("Parsing GGML operation support files...")
        self.parse_support_files()

        if not self.all_operations:
            self.logger.error(
                "No operations found. Make sure to run test-backend-ops support --output csv > docs/ops/file.csv first."
            )
            return

        self.logger.info(
            f"Found {len(self.all_operations)} operations across {len(self.all_backends)} backends"
        )

        self.logger.info("Generating markdown...")
        markdown_content = self.generate_markdown()

        docs_dir = self.ggml_root / "docs"
        docs_dir.mkdir(exist_ok=True)

        ops_file = docs_dir / self.output_filename
        with open(ops_file, "w") as f:
            f.write(markdown_content)

        self.logger.info(f"Generated: {ops_file}")
        self.logger.info(f"Operations: {len(self.all_operations)}")
        self.logger.info(f"Backends: {len(self.all_backends)}")


    # 函数: main
    # 描述: main函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def main():
    logging.basicConfig(level=logging.INFO)

    if len(sys.argv) > 1:
        output_filename = sys.argv[1]
    else:
        output_filename = "ops.md"

    generator = DocsGenerator(".", output_filename)
    generator.run()


if __name__ == "__main__":
    main()
