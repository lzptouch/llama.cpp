// ============================================================================
// 文件: test-mtmd-c-api.c
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tests/test-mtmd-c-api.c
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

#include <stdio.h>
#include <assert.h>

#include "mtmd.h"

// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int main(void) {
    printf("\n\nTesting libmtmd C API...\n");
    printf("--------\n\n");

    // 类: mtmd_context_params
    // 描述: mtmd_context_params类提供相关功能
    // 用途: 用于处理mtmd_context_params相关的操作
    // 类: mtmd_context_params
    // 描述: mtmd_context_params类提供相关功能
    // 用途: 用于处理mtmd_context_params相关的操作
    // 结构体: mtmd_context_params
    // 描述: mtmd_context_params结构体提供相关功能
    // 用途: 用于处理mtmd_context_params相关的操作
    // 结构体: mtmd_context_params
    // 描述: mtmd_context_params结构体提供相关功能
    // 用途: 用于处理mtmd_context_params相关的操作
    // 结构体: mtmd_context_params
    // 描述: mtmd_context_params结构体提供相关功能
    // 用途: 用于处理mtmd_context_params相关的操作
    // 结构体: mtmd_context_params
    // 描述: mtmd_context_params结构体提供相关功能
    // 用途: 用于处理mtmd_context_params相关的操作
    // 结构体: mtmd_context_params
    // 描述: mtmd_context_params结构体提供相关功能
    // 用途: 用于处理mtmd_context_params相关的操作
    // 结构体: mtmd_context_params
    // 描述: mtmd_context_params结构体提供相关功能
    // 用途: 用于处理mtmd_context_params相关的操作
    struct mtmd_context_params params = mtmd_context_params_default();
    printf("Default image marker: %s\n", params.image_marker);

    mtmd_input_chunks * chunks = mtmd_test_create_input_chunks();

    if (!chunks) {
        fprintf(stderr, "Failed to create input chunks\n");
        return 1;
    }

    size_t n_chunks = mtmd_input_chunks_size(chunks);
    printf("Number of chunks: %zu\n", n_chunks);
    assert(n_chunks > 0);

    for (size_t i = 0; i < n_chunks; i++) {
        const mtmd_input_chunk * chunk = mtmd_input_chunks_get(chunks, i);
        assert(chunk != NULL);
        enum mtmd_input_chunk_type type = mtmd_input_chunk_get_type(chunk);
        printf("Chunk %zu type: %d\n", i, type);

        if (type == MTMD_INPUT_CHUNK_TYPE_TEXT) {
            size_t n_tokens;
            const llama_token * tokens = mtmd_input_chunk_get_tokens_text(chunk, &n_tokens);
            printf("    Text chunk with %zu tokens\n", n_tokens);
            assert(tokens != NULL);
            assert(n_tokens > 0);
            for (size_t j = 0; j < n_tokens; j++) {
                assert(tokens[j] >= 0);
                printf("    > Token %zu: %d\n", j, tokens[j]);
            }

        } else if (type == MTMD_INPUT_CHUNK_TYPE_IMAGE) {
            const mtmd_image_tokens * image_tokens = mtmd_input_chunk_get_tokens_image(chunk);
            size_t n_tokens = mtmd_image_tokens_get_n_tokens(image_tokens);
            size_t nx = mtmd_image_tokens_get_nx(image_tokens);
            size_t ny = mtmd_image_tokens_get_ny(image_tokens);
            const char * id = mtmd_image_tokens_get_id(image_tokens);
            assert(n_tokens > 0);
            assert(nx > 0);
            assert(ny > 0);
            assert(id != NULL);
            printf("    Image chunk with %zu tokens\n", n_tokens);
            printf("    Image size: %zu x %zu\n", nx, ny);
            printf("    Image ID: %s\n", id);
        }
    }

    // Free the chunks
    mtmd_input_chunks_free(chunks);

    printf("\n\nDONE: test libmtmd C API...\n");

    return 0;
}
