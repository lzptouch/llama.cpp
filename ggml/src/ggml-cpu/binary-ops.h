#pragma once

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

// 函数: ggml_compute_forward_add_non_quantized
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_add_non_quantized
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_add_non_quantized(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_sub
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_sub
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_sub(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_mul
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_mul
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_mul(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_div
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_div
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_div(const struct ggml_compute_params * params, struct ggml_tensor * dst);

#ifdef __cplusplus
}
#endif
