// ============================================================================
// 文件: README.md
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/passkey/README.md
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

# llama.cpp/example/passkey

A passkey retrieval task is an evaluation method used to measure a language
models ability to recall information from long contexts.

See the following PRs for more info:

- https://github.com/ggml-org/llama.cpp/pull/3856
- https://github.com/ggml-org/llama.cpp/pull/4810

### Usage

```bash
llama-passkey -m ./models/llama-7b-v2/ggml-model-f16.gguf --junk 250
```
