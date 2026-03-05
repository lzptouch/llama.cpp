#pragma once

/* device */
// 函数: backend_device_get_device_count
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_get_device_count
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_get_device_count(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_device_get_count
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_get_count
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_get_count(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_device_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_get_name(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_device_get_description
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_get_description
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_get_description(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_device_get_type
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_get_type
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_get_type(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_device_get_memory
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_get_memory
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_get_memory(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_device_supports_op
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_supports_op
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_supports_op(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_device_get_buffer_type
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_get_buffer_type
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_get_buffer_type(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_device_get_props
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_get_props
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_get_props(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_device_buffer_from_ptr
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_device_buffer_from_ptr
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_device_buffer_from_ptr(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);

/* buffer-type */
// 函数: backend_buffer_type_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_type_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_type_get_name(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_buffer_type_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_type_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_type_get_alignment(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_buffer_type_get_max_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_type_get_max_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_type_get_max_size(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
/* APIR_COMMAND_TYPE_BUFFER_TYPE_IS_HOST is deprecated. Keeping the handler for backward compatibility. */
// 函数: backend_buffer_type_is_host
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_type_is_host
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_type_is_host(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_buffer_type_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_type_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_type_alloc_buffer(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_buffer_type_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_type_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_type_get_alloc_size(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);

/* buffer */
// 函数: backend_buffer_get_base
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_get_base
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_get_base(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_buffer_set_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_set_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_set_tensor(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_buffer_get_tensor
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_get_tensor
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_get_tensor(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_buffer_cpy_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_cpy_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_cpy_tensor(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_buffer_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_clear(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);
// 函数: backend_buffer_free_buffer
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_buffer_free_buffer
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_buffer_free_buffer(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);

/* backend */
// 函数: backend_backend_graph_compute
// 描述: 计算: 执行计算操作
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_backend_graph_compute
// 描述: 计算: 执行计算操作
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_backend_graph_compute(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);

extern "C" {
static const backend_dispatch_t apir_backend_dispatch_table[APIR_BACKEND_DISPATCH_TABLE_COUNT] = {

    /* device */

    /* APIR_COMMAND_TYPE_DEVICE_GET_DEVICE_COUNT  = */ backend_device_get_device_count,
    /* APIR_COMMAND_TYPE_DEVICE_GET_COUNT  = */ backend_device_get_count,
    /* APIR_COMMAND_TYPE_DEVICE_GET_NAME  = */ backend_device_get_name,
    /* APIR_COMMAND_TYPE_DEVICE_GET_DESCRIPTION  = */ backend_device_get_description,
    /* APIR_COMMAND_TYPE_DEVICE_GET_TYPE  = */ backend_device_get_type,
    /* APIR_COMMAND_TYPE_DEVICE_GET_MEMORY  = */ backend_device_get_memory,
    /* APIR_COMMAND_TYPE_DEVICE_SUPPORTS_OP  = */ backend_device_supports_op,
    /* APIR_COMMAND_TYPE_DEVICE_GET_BUFFER_TYPE  = */ backend_device_get_buffer_type,
    /* APIR_COMMAND_TYPE_DEVICE_GET_PROPS  = */ backend_device_get_props,
    /* APIR_COMMAND_TYPE_DEVICE_BUFFER_FROM_PTR  = */ backend_device_buffer_from_ptr,

    /* buffer-type */

    /* APIR_COMMAND_TYPE_BUFFER_TYPE_GET_NAME  = */ backend_buffer_type_get_name,
    /* APIR_COMMAND_TYPE_BUFFER_TYPE_GET_ALIGNMENT  = */ backend_buffer_type_get_alignment,
    /* APIR_COMMAND_TYPE_BUFFER_TYPE_GET_MAX_SIZE  = */ backend_buffer_type_get_max_size,
    /* APIR_COMMAND_TYPE_BUFFER_TYPE_IS_HOST  = */ backend_buffer_type_is_host /* DEPRECATED */,
    /* APIR_COMMAND_TYPE_BUFFER_TYPE_ALLOC_BUFFER  = */ backend_buffer_type_alloc_buffer,
    /* APIR_COMMAND_TYPE_BUFFER_TYPE_GET_ALLOC_SIZE  = */ backend_buffer_type_get_alloc_size,

    /* buffer */

    /* APIR_COMMAND_TYPE_BUFFER_GET_BASE  = */ backend_buffer_get_base,
    /* APIR_COMMAND_TYPE_BUFFER_SET_TENSOR  = */ backend_buffer_set_tensor,
    /* APIR_COMMAND_TYPE_BUFFER_GET_TENSOR  = */ backend_buffer_get_tensor,
    /* APIR_COMMAND_TYPE_BUFFER_CPY_TENSOR  = */ backend_buffer_cpy_tensor,
    /* APIR_COMMAND_TYPE_BUFFER_CLEAR  = */ backend_buffer_clear,
    /* APIR_COMMAND_TYPE_BUFFER_FREE_BUFFER  = */ backend_buffer_free_buffer,

    /* backend */

    /* APIR_COMMAND_TYPE_BACKEND_GRAPH_COMPUTE  = */ backend_backend_graph_compute,
};
}
