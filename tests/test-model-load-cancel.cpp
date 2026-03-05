// ============================================================================
// 文件: test-model-load-cancel.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tests/test-model-load-cancel.cpp
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

#include "llama.h"
#include "get-model.h"

#include <cstdlib>

// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int main(int argc, char *argv[] ) {
    auto * model_path = get_model_or_exit(argc, argv);
    auto * file = fopen(model_path, "r");
    if (file == nullptr) {
        fprintf(stderr, "no model at '%s' found\n", model_path);
        return EXIT_FAILURE;
    }

    fprintf(stderr, "using '%s'\n", model_path);
    fclose(file);

    llama_backend_init();
    auto params = llama_model_params{};
    params.use_mmap = false;
    params.progress_callback = [](float progress, void * ctx){
        (void) ctx;
        return progress > 0.50;
    };
    auto * model = llama_model_load_from_file(model_path, params);
    llama_backend_free();
    return model == nullptr ? EXIT_SUCCESS : EXIT_FAILURE;
}
