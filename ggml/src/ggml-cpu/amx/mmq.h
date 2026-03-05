#pragma once
#include "common.h"

// 函数: ggml_backend_amx_desired_wsize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_desired_wsize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t ggml_backend_amx_desired_wsize(const struct ggml_tensor * dst);

// 函数: ggml_backend_amx_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
size_t ggml_backend_amx_get_alloc_size(const struct ggml_tensor * tensor);

// 函数: ggml_backend_amx_convert_weight
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_convert_weight
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_backend_amx_convert_weight(struct ggml_tensor * tensor, const void * data, size_t offset, size_t size);

// 函数: ggml_backend_amx_mul_mat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_mul_mat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_backend_amx_mul_mat(const struct ggml_compute_params * params, struct ggml_tensor * dst);
