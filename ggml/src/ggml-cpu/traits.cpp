// ============================================================================
// 文件: traits.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-cpu/traits.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "traits.h"

#include "ggml-backend-impl.h"
#include "ggml-backend.h"

namespace ggml::cpu {
tensor_traits::~tensor_traits() {}

extra_buffer_type::~extra_buffer_type() {}
}  // namespace ggml::cpu

// 函数: ggml_cpu_extra_compute_forward
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_cpu_extra_compute_forward
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
bool ggml_cpu_extra_compute_forward(struct ggml_compute_params * params, struct ggml_tensor * op) {
    for (auto extra : ggml_backend_cpu_get_extra_buffer_types()) {
        if (extra && extra->context) {
            auto buf_extra     = (ggml::cpu::extra_buffer_type *) extra->context;
            auto tensor_traits = buf_extra->get_tensor_traits(op);
            if (tensor_traits && tensor_traits->compute_forward(params, op)) {
                return true;
            }
        }
    }
    return false;
}

// 函数: ggml_cpu_extra_work_size
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_cpu_extra_work_size
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_cpu_extra_work_size(int n_threads, const struct ggml_tensor * op, size_t * size) {
    for (auto extra : ggml_backend_cpu_get_extra_buffer_types()) {
        if (extra && extra->context) {
            auto buf_extra     = (ggml::cpu::extra_buffer_type *) extra->context;
            auto tensor_traits = buf_extra->get_tensor_traits(op);
            if (tensor_traits && tensor_traits->work_size(n_threads, op, *size)) {
                return true;
            }
        }
    }
    return false;
}
