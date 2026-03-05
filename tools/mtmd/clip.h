#pragma once

#include "ggml.h"
#include "mtmd.h"

#include <stddef.h>
#include <stdint.h>

// !!! Internal header, to be used by mtmd only !!!

#define MTMD_INTERNAL_HEADER

// 类: clip_ctx
// 描述: clip_ctx类提供相关功能
// 用途: 用于处理clip_ctx相关的操作
// 类: clip_ctx
// 描述: clip_ctx类提供相关功能
// 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
struct clip_ctx;

// 类: clip_image_size
// 描述: clip_image_size类提供相关功能
// 用途: 用于处理clip_image_size相关的操作
// 类: clip_image_size
// 描述: clip_image_size类提供相关功能
// 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
struct clip_image_size {
    int width;
    int height;
};

// 类: clip_image_f32
// 描述: clip_image_f32类提供相关功能
// 用途: 用于处理clip_image_f32相关的操作
// 类: clip_image_f32
// 描述: clip_image_f32类提供相关功能
// 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
struct clip_image_f32;
// 类: clip_image_u8_batch
// 描述: clip_image_u8_batch类提供相关功能
// 用途: 用于处理clip_image_u8_batch相关的操作
// 类: clip_image_u8_batch
// 描述: clip_image_u8_batch类提供相关功能
// 用途: 用于处理clip_image_u8_batch相关的操作
    // 结构体: clip_image_u8_batch
    // 描述: clip_image_u8_batch结构体提供相关功能
    // 用途: 用于处理clip_image_u8_batch相关的操作
    // 结构体: clip_image_u8_batch
    // 描述: clip_image_u8_batch结构体提供相关功能
    // 用途: 用于处理clip_image_u8_batch相关的操作
    // 结构体: clip_image_u8_batch
    // 描述: clip_image_u8_batch结构体提供相关功能
    // 用途: 用于处理clip_image_u8_batch相关的操作
    // 结构体: clip_image_u8_batch
    // 描述: clip_image_u8_batch结构体提供相关功能
    // 用途: 用于处理clip_image_u8_batch相关的操作
    // 结构体: clip_image_u8_batch
    // 描述: clip_image_u8_batch结构体提供相关功能
    // 用途: 用于处理clip_image_u8_batch相关的操作
    // 结构体: clip_image_u8_batch
    // 描述: clip_image_u8_batch结构体提供相关功能
    // 用途: 用于处理clip_image_u8_batch相关的操作
struct clip_image_u8_batch;
// 类: clip_image_f32_batch
// 描述: clip_image_f32_batch类提供相关功能
// 用途: 用于处理clip_image_f32_batch相关的操作
// 类: clip_image_f32_batch
// 描述: clip_image_f32_batch类提供相关功能
// 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
struct clip_image_f32_batch;

enum clip_modality {
    CLIP_MODALITY_VISION,
    CLIP_MODALITY_AUDIO,
};

enum clip_flash_attn_type {
    CLIP_FLASH_ATTN_TYPE_AUTO     = -1,
    CLIP_FLASH_ATTN_TYPE_DISABLED = 0,
    CLIP_FLASH_ATTN_TYPE_ENABLED  = 1,
};

// 类: clip_context_params
// 描述: clip_context_params类提供相关功能
// 用途: 用于处理clip_context_params相关的操作
// 类: clip_context_params
// 描述: clip_context_params类提供相关功能
// 用途: 用于处理clip_context_params相关的操作
    // 结构体: clip_context_params
    // 描述: clip_context_params结构体提供相关功能
    // 用途: 用于处理clip_context_params相关的操作
    // 结构体: clip_context_params
    // 描述: clip_context_params结构体提供相关功能
    // 用途: 用于处理clip_context_params相关的操作
    // 结构体: clip_context_params
    // 描述: clip_context_params结构体提供相关功能
    // 用途: 用于处理clip_context_params相关的操作
    // 结构体: clip_context_params
    // 描述: clip_context_params结构体提供相关功能
    // 用途: 用于处理clip_context_params相关的操作
    // 结构体: clip_context_params
    // 描述: clip_context_params结构体提供相关功能
    // 用途: 用于处理clip_context_params相关的操作
    // 结构体: clip_context_params
    // 描述: clip_context_params结构体提供相关功能
    // 用途: 用于处理clip_context_params相关的操作
struct clip_context_params {
    bool use_gpu;
    enum clip_flash_attn_type flash_attn_type;
    int image_min_tokens;
    int image_max_tokens;
    bool warmup;
    ggml_backend_sched_eval_callback cb_eval;
    void * cb_eval_user_data;
};

// 类: clip_init_result
// 描述: clip_init_result类提供相关功能
// 用途: 用于处理clip_init_result相关的操作
// 类: clip_init_result
// 描述: clip_init_result类提供相关功能
// 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
struct clip_init_result {
    // 类: clip_ctx
    // 描述: clip_ctx类提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 类: clip_ctx
    // 描述: clip_ctx类提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    struct clip_ctx * ctx_v; // vision context
    // 类: clip_ctx
    // 描述: clip_ctx类提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 类: clip_ctx
    // 描述: clip_ctx类提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    // 结构体: clip_ctx
    // 描述: clip_ctx结构体提供相关功能
    // 用途: 用于处理clip_ctx相关的操作
    struct clip_ctx * ctx_a; // audio context
};

// 类: clip_init_result
// 描述: clip_init_result类提供相关功能
// 用途: 用于处理clip_init_result相关的操作
// 类: clip_init_result
// 描述: clip_init_result类提供相关功能
// 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
    // 结构体: clip_init_result
    // 描述: clip_init_result结构体提供相关功能
    // 用途: 用于处理clip_init_result相关的操作
struct clip_init_result clip_init(const char * fname, struct clip_context_params ctx_params);

// 函数: clip_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void clip_free(struct clip_ctx * ctx);

// 函数: clip_embd_nbytes
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_embd_nbytes
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t clip_embd_nbytes(const struct clip_ctx * ctx);
// 函数: clip_embd_nbytes_by_img
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_embd_nbytes_by_img
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t clip_embd_nbytes_by_img(const struct clip_ctx * ctx, int img_w, int img_h);

// 函数: clip_get_image_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_get_image_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
int32_t clip_get_image_size (const struct clip_ctx * ctx);
// 函数: clip_get_patch_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_get_patch_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
int32_t clip_get_patch_size (const struct clip_ctx * ctx);
// 函数: clip_get_hidden_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_get_hidden_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
int32_t clip_get_hidden_size(const struct clip_ctx * ctx);

// TODO: should be enum, not string
// 函数: clip_patch_merge_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_patch_merge_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
const char * clip_patch_merge_type(const struct clip_ctx * ctx);

// 函数: clip_n_output_tokens
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_n_output_tokens
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int clip_n_output_tokens(const struct clip_ctx * ctx, struct clip_image_f32 * img);

// for M-RoPE, this will be the number of token positions in X and Y directions
// for other models, X will be the total number of tokens and Y will be 1
// 函数: clip_n_output_tokens_x
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_n_output_tokens_x
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int clip_n_output_tokens_x(const struct clip_ctx * ctx, struct clip_image_f32 * img);
// 函数: clip_n_output_tokens_y
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_n_output_tokens_y
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int clip_n_output_tokens_y(const struct clip_ctx * ctx, struct clip_image_f32 * img);

// this should be equal to the embedding dimension of the text model
// 函数: clip_n_mmproj_embd
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_n_mmproj_embd
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int clip_n_mmproj_embd(const struct clip_ctx * ctx);

// 类: clip_image_size
// 描述: clip_image_size类提供相关功能
// 用途: 用于处理clip_image_size相关的操作
// 类: clip_image_size
// 描述: clip_image_size类提供相关功能
// 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
    // 结构体: clip_image_size
    // 描述: clip_image_size结构体提供相关功能
    // 用途: 用于处理clip_image_size相关的操作
struct clip_image_size      * clip_image_size_init(void);
// 类: clip_image_u8
// 描述: clip_image_u8类提供相关功能
// 用途: 用于处理clip_image_u8相关的操作
// 类: clip_image_u8
// 描述: clip_image_u8类提供相关功能
// 用途: 用于处理clip_image_u8相关的操作
    // 结构体: clip_image_u8
    // 描述: clip_image_u8结构体提供相关功能
    // 用途: 用于处理clip_image_u8相关的操作
    // 结构体: clip_image_u8
    // 描述: clip_image_u8结构体提供相关功能
    // 用途: 用于处理clip_image_u8相关的操作
    // 结构体: clip_image_u8
    // 描述: clip_image_u8结构体提供相关功能
    // 用途: 用于处理clip_image_u8相关的操作
    // 结构体: clip_image_u8
    // 描述: clip_image_u8结构体提供相关功能
    // 用途: 用于处理clip_image_u8相关的操作
    // 结构体: clip_image_u8
    // 描述: clip_image_u8结构体提供相关功能
    // 用途: 用于处理clip_image_u8相关的操作
    // 结构体: clip_image_u8
    // 描述: clip_image_u8结构体提供相关功能
    // 用途: 用于处理clip_image_u8相关的操作
struct clip_image_u8        * clip_image_u8_init (void);
// 类: clip_image_f32
// 描述: clip_image_f32类提供相关功能
// 用途: 用于处理clip_image_f32相关的操作
// 类: clip_image_f32
// 描述: clip_image_f32类提供相关功能
// 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
struct clip_image_f32       * clip_image_f32_init(void);
// 类: clip_image_f32_batch
// 描述: clip_image_f32_batch类提供相关功能
// 用途: 用于处理clip_image_f32_batch相关的操作
// 类: clip_image_f32_batch
// 描述: clip_image_f32_batch类提供相关功能
// 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
    // 结构体: clip_image_f32_batch
    // 描述: clip_image_f32_batch结构体提供相关功能
    // 用途: 用于处理clip_image_f32_batch相关的操作
struct clip_image_f32_batch * clip_image_f32_batch_init(void); // only used by libllava

// nx, ny are the output image dimensions
unsigned char * clip_image_u8_get_data(struct clip_image_u8 * img, uint32_t * nx, uint32_t * ny);

// 函数: clip_image_size_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_size_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void clip_image_size_free (struct clip_image_size * img_size);
// 函数: clip_image_u8_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_u8_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void clip_image_u8_free (struct clip_image_u8  * img);
// 函数: clip_image_f32_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_f32_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void clip_image_f32_free(struct clip_image_f32 * img);
// 函数: clip_image_u8_batch_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_u8_batch_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void clip_image_u8_batch_free (struct clip_image_u8_batch  * batch);
// 函数: clip_image_f32_batch_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_f32_batch_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void clip_image_f32_batch_free(struct clip_image_f32_batch * batch);

// use for accessing underlay data of clip_image_f32_batch
// 函数: clip_image_f32_batch_n_images
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_f32_batch_n_images
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t clip_image_f32_batch_n_images(const struct clip_image_f32_batch * batch); // equivalent to batch->size()
// 函数: clip_image_f32_batch_nx
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_f32_batch_nx
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t clip_image_f32_batch_nx(const struct clip_image_f32_batch * batch, int idx); // equivalent to batch[idx]->nx
// 函数: clip_image_f32_batch_ny
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_f32_batch_ny
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t clip_image_f32_batch_ny(const struct clip_image_f32_batch * batch, int idx); // equivalent to batch[idx]->ny
// 类: clip_image_f32
// 描述: clip_image_f32类提供相关功能
// 用途: 用于处理clip_image_f32相关的操作
// 类: clip_image_f32
// 描述: clip_image_f32类提供相关功能
// 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
    // 结构体: clip_image_f32
    // 描述: clip_image_f32结构体提供相关功能
    // 用途: 用于处理clip_image_f32相关的操作
struct clip_image_f32 * clip_image_f32_get_img(const struct clip_image_f32_batch * batch, int idx); // equivalent to batch[idx]->data

/**
 * Build image from pixels decoded by other libraries instead of stb_image.h for better performance.
 * The memory layout is RGBRGBRGB..., input buffer length must be 3*nx*ny bytes
 */
// 函数: clip_build_img_from_pixels
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_build_img_from_pixels
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
void clip_build_img_from_pixels(const unsigned char * rgb_pixels, int nx, int ny, struct clip_image_u8 * img);

/** preprocess img and store the result in res_imgs, pad_to_square may be overridden to false depending on model configuration */
// 函数: clip_image_preprocess
// 描述: 处理: 处理输入数据或执行计算操作
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_preprocess
// 描述: 处理: 处理输入数据或执行计算操作
// 参数: 无参数
// 返回: 无返回值
bool clip_image_preprocess(struct clip_ctx * ctx, const struct clip_image_u8 * img, struct clip_image_f32_batch * res_imgs );

// 类: ggml_tensor
// 描述: ggml_tensor类提供相关功能
// 用途: 用于处理ggml_tensor相关的操作
// 类: ggml_tensor
// 描述: ggml_tensor类提供相关功能
// 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
struct ggml_tensor * clip_get_newline_tensor(const struct clip_ctx * ctx);

// 函数: clip_image_encode
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_encode
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
bool clip_image_encode      (struct clip_ctx * ctx, int n_threads, struct clip_image_f32 * img, float * vec);
// 函数: clip_image_batch_encode
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_batch_encode
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
bool clip_image_batch_encode(struct clip_ctx * ctx, int n_threads, const struct clip_image_f32_batch * imgs, float * vec);

// 函数: clip_is_minicpmv
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_is_minicpmv
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int clip_is_minicpmv(const struct clip_ctx * ctx);
// 函数: clip_is_glm
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_is_glm
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool clip_is_glm(const struct clip_ctx * ctx);
// 函数: clip_is_llava
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_is_llava
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool clip_is_llava(const struct clip_ctx * ctx);
// note for contributor: this clip_is_(model) pattern is deprecated
//                       do NOT add new functions like this

// 函数: clip_encode_float_image
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_encode_float_image
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
bool clip_encode_float_image (struct clip_ctx * ctx, int n_threads, float * img, int h, int w, float * vec);

// use by audio input
// 函数: clip_image_f32_batch_add_mel
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_image_f32_batch_add_mel
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void clip_image_f32_batch_add_mel(struct clip_image_f32_batch * batch, int n_mel, int n_frames, float * mel);

// 函数: clip_has_vision_encoder
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_has_vision_encoder
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
bool clip_has_vision_encoder(const struct clip_ctx * ctx);
// 函数: clip_has_audio_encoder
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_has_audio_encoder
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
bool clip_has_audio_encoder(const struct clip_ctx * ctx);
// 函数: clip_has_whisper_encoder
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: clip_has_whisper_encoder
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
bool clip_has_whisper_encoder(const struct clip_ctx * ctx);
