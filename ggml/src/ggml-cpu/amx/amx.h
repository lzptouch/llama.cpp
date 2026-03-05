// ============================================================================
// 文件: amx.h
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-cpu/amx/amx.h
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "ggml-backend.h"
#include "ggml-cpu-impl.h"

// GGML internal header

#if defined(__AMX_INT8__) && defined(__AVX512VNNI__)
// 函数: ggml_backend_amx_buffer_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
ggml_backend_buffer_type_t ggml_backend_amx_buffer_type(void);
#endif
