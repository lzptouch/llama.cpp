// ============================================================================
// 文件: README.md
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tools/gguf-split/README.md
// 作者: 自动注释工具
// 描述: 工具文件,包含各种实用工具
// ============================================================================

## GGUF split Example

CLI to split / merge GGUF files.

**Command line options:**

- `--split`: split GGUF to multiple GGUF, default operation.
- `--split-max-size`: max size per split in `M` or `G`, f.ex. `500M` or `2G`.
- `--split-max-tensors`: maximum tensors in each split: default(128)
- `--merge`: merge multiple GGUF to a single GGUF.
