#pragma once

#include "ggml-metal-device.h"

#ifdef __cplusplus
extern "C" {
#endif

//
// backend context
//

typedef struct ggml_metal * ggml_metal_t;

// 函数: ggml_metal_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
ggml_metal_t ggml_metal_init(ggml_metal_device_t dev);
// 函数: ggml_metal_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_free(ggml_metal_t ctx);

// 函数: ggml_metal_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
const char * ggml_metal_get_name(ggml_metal_t ctx);

// 函数: ggml_metal_synchronize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_synchronize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_synchronize(ggml_metal_t ctx);

// 函数: ggml_metal_set_tensor_async
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_set_tensor_async
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_set_tensor_async(ggml_metal_t ctx, struct ggml_tensor * tensor, const void * data, size_t offset, size_t size);
// 函数: ggml_metal_get_tensor_async
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_get_tensor_async
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_get_tensor_async(ggml_metal_t ctx, const struct ggml_tensor * tensor, void * data, size_t offset, size_t size);
// 函数: ggml_metal_cpy_tensor_async
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_cpy_tensor_async
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_metal_cpy_tensor_async(ggml_metal_t ctx_src, ggml_metal_t ctx_dst, const struct ggml_tensor * src, struct ggml_tensor * dst);

enum ggml_status ggml_metal_graph_compute (ggml_metal_t ctx, struct ggml_cgraph * gf);
// 函数: ggml_metal_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void             ggml_metal_graph_optimize(ggml_metal_t ctx, struct ggml_cgraph * gf);

// 函数: ggml_metal_event_record
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_event_record
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_event_record(ggml_metal_t ctx, ggml_metal_event_t ev);
// 函数: ggml_metal_event_wait
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_event_wait
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_event_wait  (ggml_metal_t ctx, ggml_metal_event_t ev);

// 函数: ggml_metal_get_ev_cpy
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_get_ev_cpy
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
ggml_metal_event_t ggml_metal_get_ev_cpy(ggml_metal_t ctx);

// 函数: ggml_metal_set_n_cb
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_set_n_cb
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_set_n_cb            (ggml_metal_t ctx, int n_cb);
// 函数: ggml_metal_set_abort_callback
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_set_abort_callback
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_set_abort_callback  (ggml_metal_t ctx, ggml_abort_callback abort_callback, void * user_data);
// 函数: ggml_metal_supports_family
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_supports_family
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_metal_supports_family     (ggml_metal_t ctx, int family);
// 函数: ggml_metal_capture_next_compute
// 描述: 计算: 执行计算操作
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_capture_next_compute
// 描述: 计算: 执行计算操作
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_capture_next_compute(ggml_metal_t ctx);

#ifdef __cplusplus
}
#endif
