// ============================================================================
// 文件: backend-convert.h
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-virtgpu/backend/backend-convert.h
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "shared/apir_backend.h"

#define BUFFER_TO_HOST_HANDLE(name) ggml_buffer_to_apir_handle(name)

// 函数: ggml_buffer_to_apir_handle
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_buffer_to_apir_handle
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline apir_buffer_host_handle_t ggml_buffer_to_apir_handle(ggml_backend_buffer_t buffer) {
    // in the backend, the buffer handle is the buffer pointer
    return (apir_buffer_host_handle_t) buffer;
}

// 函数: ggml_buffer_type_to_apir_handle
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_buffer_type_to_apir_handle
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline apir_buffer_type_host_handle_t ggml_buffer_type_to_apir_handle(ggml_backend_buffer_type_t buft) {
    // in the backend, the buffer handle is the buffer pointer
    return (apir_buffer_type_host_handle_t) buft;
}
