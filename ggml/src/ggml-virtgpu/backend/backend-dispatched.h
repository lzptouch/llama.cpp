#pragma once

// clang-format off
#include <cstdint>
#include <cstddef>

#include <ggml-backend.h>

#include "backend-convert.h"
#include "backend-virgl-apir.h"
#include "shared/apir_backend.h"
#include "shared/apir_cs.h"
#include "shared/apir_cs_ggml.h"
// clang-format on

#define GGML_VIRTGPU_BCK "ggml-virtgpu-backend: "

// 类: virgl_apir_context
// 描述: virgl_apir_context类提供相关功能
// 用途: 用于处理virgl_apir_context相关的操作
// 类: virgl_apir_context
// 描述: virgl_apir_context类提供相关功能
// 用途: 用于处理virgl_apir_context相关的操作
    // 结构体: virgl_apir_context
    // 描述: virgl_apir_context结构体提供相关功能
    // 用途: 用于处理virgl_apir_context相关的操作
    // 结构体: virgl_apir_context
    // 描述: virgl_apir_context结构体提供相关功能
    // 用途: 用于处理virgl_apir_context相关的操作
    // 结构体: virgl_apir_context
    // 描述: virgl_apir_context结构体提供相关功能
    // 用途: 用于处理virgl_apir_context相关的操作
    // 结构体: virgl_apir_context
    // 描述: virgl_apir_context结构体提供相关功能
    // 用途: 用于处理virgl_apir_context相关的操作
struct virgl_apir_context {
    uint32_t               ctx_id;
    virgl_apir_callbacks * iface;
};

// 函数: uint32_t
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: uint32_t
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
typedef uint32_t (*backend_dispatch_t)(apir_encoder * enc, apir_decoder * dec, virgl_apir_context * ctx);

#include "backend-dispatched.gen.h"

// 函数: backend_dispatch_initialize
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_dispatch_initialize
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
uint32_t backend_dispatch_initialize(void * ggml_backend_reg_fct_p);
