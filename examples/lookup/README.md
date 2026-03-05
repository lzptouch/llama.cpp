// ============================================================================
// 文件: README.md
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/lookup/README.md
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

# llama.cpp/examples/lookup

Demonstration of Prompt Lookup Decoding

https://github.com/apoorvumang/prompt-lookup-decoding

The key parameters for lookup decoding are `ngram_min`, `ngram_max` and `n_draft`. The first two determine the size of the ngrams to search for in the prompt for a match. The latter specifies how many subsequent tokens to draft if a match is found.

More info:

https://github.com/ggml-org/llama.cpp/pull/4484
https://github.com/ggml-org/llama.cpp/issues/4226
