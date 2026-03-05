// ============================================================================
// 文件: get-model.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tests/get-model.cpp
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "get-model.h"

// 函数: get_model_or_exit
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
// 函数: get_model_or_exit
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
char * get_model_or_exit(int argc, char *argv[]) {
    char * model_path;
    if (argc > 1) {
        model_path = argv[1];

    } else {
        model_path = getenv("LLAMACPP_TEST_MODELFILE");
        if (!model_path || strlen(model_path) == 0) {
            fprintf(stderr, "\033[33mWARNING: No model file provided. Skipping this test. Set LLAMACPP_TEST_MODELFILE=<gguf_model_path> to silence this warning and run this test.\n\033[0m");
            exit(EXIT_SUCCESS);
        }
    }

    return model_path;
}
