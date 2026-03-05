#pragma once

#include "ggml-backend-impl.h"
#include "ggml-backend.h"
#include "ggml-impl.h"
#include "shared/api_remoting.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

extern ggml_backend_reg_t reg;
extern ggml_backend_dev_t dev;
extern ggml_backend_t     bck;

// 类: virgl_apir_callbacks
// 描述: virgl_apir_callbacks类提供相关功能
// 用途: 用于处理virgl_apir_callbacks相关的操作
// 类: virgl_apir_callbacks
// 描述: virgl_apir_callbacks类提供相关功能
// 用途: 用于处理virgl_apir_callbacks相关的操作
    // 结构体: virgl_apir_callbacks
    // 描述: virgl_apir_callbacks结构体提供相关功能
    // 用途: 用于处理virgl_apir_callbacks相关的操作
    // 结构体: virgl_apir_callbacks
    // 描述: virgl_apir_callbacks结构体提供相关功能
    // 用途: 用于处理virgl_apir_callbacks相关的操作
    // 结构体: virgl_apir_callbacks
    // 描述: virgl_apir_callbacks结构体提供相关功能
    // 用途: 用于处理virgl_apir_callbacks相关的操作
    // 结构体: virgl_apir_callbacks
    // 描述: virgl_apir_callbacks结构体提供相关功能
    // 用途: 用于处理virgl_apir_callbacks相关的操作
struct virgl_apir_callbacks {
    const char * (*get_config)(uint32_t virgl_ctx_id, const char * key);
    void * (*get_shmem_ptr)(uint32_t virgl_ctx_id, uint32_t res_id);
};

extern "C" {
// 函数: apir_backend_initialize
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_backend_initialize
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
ApirLoadLibraryReturnCode apir_backend_initialize(uint32_t virgl_ctx_id, struct virgl_apir_callbacks * virgl_cbs);
// 函数: apir_backend_deinit
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_backend_deinit
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
void                      apir_backend_deinit(uint32_t virgl_ctx_id);
uint32_t                  apir_backend_dispatcher(uint32_t               virgl_ctx_id,
                                                  virgl_apir_callbacks * virgl_cbs,
                                                  uint32_t               cmd_type,
                                                  char *                 dec_cur,
                                                  const char *           dec_end,
                                                  char *                 enc_cur,
                                                  const char *           enc_end,
                                                  char **                enc_cur_after);
}
