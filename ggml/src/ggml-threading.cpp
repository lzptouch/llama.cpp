// ============================================================================
// 文件: ggml-threading.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-threading.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "ggml-threading.h"
#include <mutex>

std::mutex ggml_critical_section_mutex;

// 函数: ggml_critical_section_start
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_critical_section_start
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_critical_section_start() {
    ggml_critical_section_mutex.lock();
}

// 函数: ggml_critical_section_end
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_critical_section_end
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_critical_section_end(void) {
    ggml_critical_section_mutex.unlock();
}
