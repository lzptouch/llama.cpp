#pragma once
#include "ggml-backend-impl.h"
#include "ggml-cpu-impl.h"
#include "ggml.h"

#ifdef __cplusplus
#    include <vector>
extern "C" {
#endif

// return true if op part of extra "accelerator"
// 函数: ggml_cpu_extra_compute_forward
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_cpu_extra_compute_forward
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
bool ggml_cpu_extra_compute_forward(struct ggml_compute_params * params, struct ggml_tensor * op);
// 函数: ggml_cpu_extra_work_size
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_cpu_extra_work_size
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_cpu_extra_work_size(int n_threads, const struct ggml_tensor * op, size_t * size);

#ifdef __cplusplus
}

namespace ggml::cpu {
// register in tensor->extra
// 类: tensor_traits
// 描述: tensor_traits类提供相关功能
// 用途: 用于处理tensor_traits相关的操作
// 类: tensor_traits
// 描述: tensor_traits类提供相关功能
// 用途: 用于处理tensor_traits相关的操作
class tensor_traits {
  public:
    virtual ~tensor_traits();
    // 函数: work_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: work_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual bool work_size(int n_threads, const struct ggml_tensor * op, size_t & size)        = 0;
    // 函数: compute_forward
    // 描述: 前向传播: 执行神经网络的前向传播
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: compute_forward
    // 描述: 前向传播: 执行神经网络的前向传播
    // 参数: 无参数
    // 返回: 无返回值
    virtual bool compute_forward(struct ggml_compute_params * params, struct ggml_tensor * op) = 0;
};

// 类: extra_buffer_type
// 描述: extra_buffer_type类提供相关功能
// 用途: 用于处理extra_buffer_type相关的操作
// 类: extra_buffer_type
// 描述: extra_buffer_type类提供相关功能
// 用途: 用于处理extra_buffer_type相关的操作
class extra_buffer_type {
  public:
    virtual ~extra_buffer_type();
    // 函数: supports_op
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: supports_op
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual bool            supports_op(ggml_backend_dev_t dev, const struct ggml_tensor * op) = 0;
    // 函数: get_tensor_traits
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_tensor_traits
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    virtual tensor_traits * get_tensor_traits(const struct ggml_tensor * op)                   = 0;
};
}  // namespace ggml::cpu

// implemented in ggml-cpu.cpp.
std::vector<ggml_backend_buffer_type_t> & ggml_backend_cpu_get_extra_buffer_types();

#endif
