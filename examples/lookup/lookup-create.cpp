// ============================================================================
// 文件: lookup-create.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/lookup/lookup-create.cpp
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

#include "arg.h"
#include "common.h"
#include "ngram-cache.h"
#include "llama.h"

#include <string>
#include <vector>

// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int main(int argc, char ** argv){
    common_params params;

    if (!common_params_parse(argc, argv, params, LLAMA_EXAMPLE_LOOKUP)) {
        return 1;
    }

    // init llama.cpp
    llama_backend_init();
    llama_numa_init(params.numa);

    // load the model
    auto llama_init = common_init_from_params(params);

    auto * model = llama_init->model();
    auto * ctx = llama_init->context();

    GGML_ASSERT(model != nullptr);

    // tokenize the prompt
    std::vector<llama_token> inp;
    inp = common_tokenize(ctx, params.prompt, true, true);
    fprintf(stderr, "%s: tokenization done\n", __func__);

    common_ngram_cache ngram_cache;
    common_ngram_cache_update(ngram_cache, LLAMA_NGRAM_STATIC, LLAMA_NGRAM_STATIC, inp, inp.size(), true);
    fprintf(stderr, "%s: hashing done, writing file to %s\n", __func__, params.speculative.lookup_cache_static.c_str());

    common_ngram_cache_save(ngram_cache, params.speculative.lookup_cache_static);

    return 0;
}
