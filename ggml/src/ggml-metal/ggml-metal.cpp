// ============================================================================
// 文件: ggml-metal.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-metal/ggml-metal.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "ggml-metal.h"

#include "ggml-impl.h"
#include "ggml-backend-impl.h"

#include "ggml-metal-device.h"
#include "ggml-metal-context.h"
#include "ggml-metal-ops.h"

#include <mutex>
#include <string>

#define GGML_METAL_NAME "MTL"
#define GGML_METAL_MAX_DEVICES 16

// number of Metal devices
// note: can be overriden with GGML_METAL_DEVICES env to simulate virtual devices
static int g_devices = 1;

////////////////////////////////////////////////////////////////////////////////
// backend interface
////////////////////////////////////////////////////////////////////////////////

// shared buffer

// 函数: ggml_backend_metal_buffer_shared_free_buffer
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_shared_free_buffer
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_shared_free_buffer(ggml_backend_buffer_t buffer) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_free(ctx);
}

// 函数: ggml_backend_metal_buffer_shared_get_base
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_shared_get_base
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void * ggml_backend_metal_buffer_shared_get_base(ggml_backend_buffer_t buffer) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(ggml_metal_buffer_is_shared(ctx));

    return ggml_metal_buffer_get_base(ctx);
}

// 函数: ggml_backend_metal_buffer_shared_memset_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_shared_memset_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_shared_memset_tensor(ggml_backend_buffer_t buffer, ggml_tensor * tensor, uint8_t value, size_t offset, size_t size) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_memset_tensor(ctx, tensor, value, offset, size);
}

// 函数: ggml_backend_metal_buffer_shared_set_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_shared_set_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_shared_set_tensor(ggml_backend_buffer_t buffer, ggml_tensor * tensor, const void * data, size_t offset, size_t size) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_set_tensor(ctx, tensor, data, offset, size);
}

// 函数: ggml_backend_metal_buffer_shared_get_tensor
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_shared_get_tensor
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_shared_get_tensor(ggml_backend_buffer_t buffer, const ggml_tensor * tensor, void * data, size_t offset, size_t size) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_get_tensor(ctx, tensor, data, offset, size);
}

// 函数: ggml_backend_metal_buffer_shared_cpy_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_shared_cpy_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_metal_buffer_shared_cpy_tensor(ggml_backend_buffer_t buffer, const ggml_tensor * src, ggml_tensor * dst) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(ggml_metal_buffer_is_shared(ctx));

    GGML_UNUSED(buffer);
    GGML_UNUSED(src);
    GGML_UNUSED(dst);

    return false;
}

// 函数: ggml_backend_metal_buffer_shared_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_shared_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_shared_clear(ggml_backend_buffer_t buffer, uint8_t value) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_clear(ctx, value);
}

static ggml_backend_buffer_i ggml_backend_metal_buffer_shared_i = {
    /* .free_buffer     = */ ggml_backend_metal_buffer_shared_free_buffer,
    /* .get_base        = */ ggml_backend_metal_buffer_shared_get_base,
    /* .init_tensor     = */ NULL,
    /* .memset_tensor   = */ ggml_backend_metal_buffer_shared_memset_tensor,
    /* .set_tensor      = */ ggml_backend_metal_buffer_shared_set_tensor,
    /* .get_tensor      = */ ggml_backend_metal_buffer_shared_get_tensor,
    /* .cpy_tensor      = */ ggml_backend_metal_buffer_shared_cpy_tensor,
    /* .clear           = */ ggml_backend_metal_buffer_shared_clear,
    /* .reset           = */ NULL,
};

// private buffer

// 函数: ggml_backend_metal_buffer_private_free_buffer
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_private_free_buffer
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_private_free_buffer(ggml_backend_buffer_t buffer) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(!ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_free(ctx);
}

// 函数: ggml_backend_metal_buffer_private_get_base
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_private_get_base
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void * ggml_backend_metal_buffer_private_get_base(ggml_backend_buffer_t buffer) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(!ggml_metal_buffer_is_shared(ctx));

    return ggml_metal_buffer_get_base(ctx);
}

// 函数: ggml_backend_metal_buffer_private_memset_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_private_memset_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_private_memset_tensor(ggml_backend_buffer_t buffer, ggml_tensor * tensor, uint8_t value, size_t offset, size_t size) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(!ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_memset_tensor(ctx, tensor, value, offset, size);
}

// 函数: ggml_backend_metal_buffer_private_set_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_private_set_tensor
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_private_set_tensor(ggml_backend_buffer_t buffer, ggml_tensor * tensor, const void * data, size_t offset, size_t size) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(!ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_set_tensor(ctx, tensor, data, offset, size);
}

// 函数: ggml_backend_metal_buffer_private_get_tensor
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_private_get_tensor
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_private_get_tensor(ggml_backend_buffer_t buffer, const ggml_tensor * tensor, void * data, size_t offset, size_t size) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(!ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_get_tensor(ctx, tensor, data, offset, size);
}

// 函数: ggml_backend_metal_buffer_private_cpy_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_private_cpy_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_metal_buffer_private_cpy_tensor(ggml_backend_buffer_t buffer, const ggml_tensor * src, ggml_tensor * dst) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(!ggml_metal_buffer_is_shared(ctx));

    GGML_UNUSED(buffer);
    GGML_UNUSED(src);
    GGML_UNUSED(dst);

    return false;
}

// 函数: ggml_backend_metal_buffer_private_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_private_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_buffer_private_clear(ggml_backend_buffer_t buffer, uint8_t value) {
    ggml_metal_buffer_t ctx = (ggml_metal_buffer_t)buffer->context;

    GGML_ASSERT(!ggml_metal_buffer_is_shared(ctx));

    ggml_metal_buffer_clear(ctx, value);
}

static ggml_backend_buffer_i ggml_backend_metal_buffer_private_i = {
    /* .free_buffer     = */ ggml_backend_metal_buffer_private_free_buffer,
    /* .get_base        = */ ggml_backend_metal_buffer_private_get_base,
    /* .init_tensor     = */ NULL,
    /* .memset_tensor   = */ ggml_backend_metal_buffer_private_memset_tensor,
    /* .set_tensor      = */ ggml_backend_metal_buffer_private_set_tensor,
    /* .get_tensor      = */ ggml_backend_metal_buffer_private_get_tensor,
    /* .cpy_tensor      = */ ggml_backend_metal_buffer_private_cpy_tensor,
    /* .clear           = */ ggml_backend_metal_buffer_private_clear,
    /* .reset           = */ NULL,
};

// 函数: ggml_backend_buffer_is_metal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_buffer_is_metal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_buffer_is_metal(ggml_backend_buffer_t buffer) {
    return buffer->iface.free_buffer == ggml_backend_metal_buffer_shared_free_buffer ||
           buffer->iface.free_buffer == ggml_backend_metal_buffer_private_free_buffer;
}

//
// buffer types
//

// 类: ggml_backend_metal_buffer_type
// 描述: ggml_backend_metal_buffer_type类提供相关功能
// 用途: 用于处理ggml_backend_metal_buffer_type相关的操作
// 类: ggml_backend_metal_buffer_type
// 描述: ggml_backend_metal_buffer_type类提供相关功能
// 用途: 用于处理ggml_backend_metal_buffer_type相关的操作
    // 结构体: ggml_backend_metal_buffer_type
    // 描述: ggml_backend_metal_buffer_type结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_buffer_type相关的操作
    // 结构体: ggml_backend_metal_buffer_type
    // 描述: ggml_backend_metal_buffer_type结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_buffer_type相关的操作
    // 结构体: ggml_backend_metal_buffer_type
    // 描述: ggml_backend_metal_buffer_type结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_buffer_type相关的操作
    // 结构体: ggml_backend_metal_buffer_type
    // 描述: ggml_backend_metal_buffer_type结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_buffer_type相关的操作
struct ggml_backend_metal_buffer_type {
    int device;
    std::string name;
};

// 类: ggml_backend_metal_buffer_type_deleter
// 描述: ggml_backend_metal_buffer_type_deleter类提供相关功能
// 用途: 用于处理ggml_backend_metal_buffer_type_deleter相关的操作
// 类: ggml_backend_metal_buffer_type_deleter
// 描述: ggml_backend_metal_buffer_type_deleter类提供相关功能
// 用途: 用于处理ggml_backend_metal_buffer_type_deleter相关的操作
    // 结构体: ggml_backend_metal_buffer_type_deleter
    // 描述: ggml_backend_metal_buffer_type_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_buffer_type_deleter相关的操作
    // 结构体: ggml_backend_metal_buffer_type_deleter
    // 描述: ggml_backend_metal_buffer_type_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_buffer_type_deleter相关的操作
    // 结构体: ggml_backend_metal_buffer_type_deleter
    // 描述: ggml_backend_metal_buffer_type_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_buffer_type_deleter相关的操作
    // 结构体: ggml_backend_metal_buffer_type_deleter
    // 描述: ggml_backend_metal_buffer_type_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_buffer_type_deleter相关的操作
struct ggml_backend_metal_buffer_type_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(ggml_backend_metal_buffer_type * ctx) const {
        delete ctx;
    }
};

typedef std::unique_ptr<ggml_backend_metal_buffer_type, ggml_backend_metal_buffer_type_deleter> ggml_backend_metal_buffer_type_ptr;

// common method for allocating shread or private Metal buffers
// 函数: ggml_backend_metal_buffer_type_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_t ggml_backend_metal_buffer_type_alloc_buffer(ggml_backend_buffer_type_t buft, size_t size, bool shared) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)buft->device->context;
    ggml_metal_buffer_t res = ggml_metal_buffer_init(ctx_dev, size, shared);

    ggml_backend_buffer_i buf_i = ggml_metal_buffer_is_shared(res)
        ? ggml_backend_metal_buffer_shared_i
        : ggml_backend_metal_buffer_private_i;

    return ggml_backend_buffer_init(buft, buf_i, res, size);
}

// 函数: ggml_backend_metal_buffer_type_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_get_alloc_size(ggml_backend_buffer_type_t buft, const ggml_tensor * tensor) {
    size_t res = ggml_nbytes(tensor);

    // some operations require additional memory for fleeting data:
    switch (tensor->op) {
        case GGML_OP_MUL_MAT_ID:
            {
                res += ggml_metal_op_mul_mat_id_extra_tpe(tensor);
                res += ggml_metal_op_mul_mat_id_extra_ids(tensor);
            } break;
        case GGML_OP_FLASH_ATTN_EXT:
            {
                res += ggml_metal_op_flash_attn_ext_extra_pad(tensor);
                res += ggml_metal_op_flash_attn_ext_extra_blk(tensor);
                res += ggml_metal_op_flash_attn_ext_extra_tmp(tensor);
            } break;
        case GGML_OP_CUMSUM:
        case GGML_OP_ARGSORT:
            {
                res *= 2;
            } break;
        case GGML_OP_TOP_K:
            {
                res = 2*sizeof(int32_t)*ggml_nelements(tensor->src[0]);
            } break;
        default:
            break;
    }

    return res;

    GGML_UNUSED(buft);
}

// default (shared) buffer type

// 函数: ggml_backend_metal_buffer_type_shared_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_shared_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static const char * ggml_backend_metal_buffer_type_shared_get_name(ggml_backend_buffer_type_t buft) {
    ggml_backend_metal_buffer_type * ctx = (ggml_backend_metal_buffer_type *)buft->context;

    return ctx->name.c_str();
}

// 函数: ggml_backend_metal_buffer_type_shared_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_shared_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_t ggml_backend_metal_buffer_type_shared_alloc_buffer(ggml_backend_buffer_type_t buft, size_t size) {
    return ggml_backend_metal_buffer_type_alloc_buffer(buft, size, true);
}

// 函数: ggml_backend_metal_buffer_type_shared_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_shared_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_shared_get_alignment(ggml_backend_buffer_type_t buft) {
    return 32;

    GGML_UNUSED(buft);
}

// 函数: ggml_backend_metal_buffer_type_shared_get_max_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_shared_get_max_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_shared_get_max_size(ggml_backend_buffer_type_t buft) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)buft->device->context;

    return ggml_metal_device_get_props(ctx_dev)->max_buffer_size;
}

// 函数: ggml_backend_metal_buffer_type_shared_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_shared_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_shared_get_alloc_size(ggml_backend_buffer_type_t buft, const ggml_tensor * tensor) {
    return ggml_backend_metal_buffer_type_get_alloc_size(buft, tensor);
}

// 函数: ggml_backend_metal_buffer_type_shared_is_host
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_shared_is_host
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_metal_buffer_type_shared_is_host(ggml_backend_buffer_type_t buft) {
    return false;

    GGML_UNUSED(buft);
}

// 函数: ggml_backend_metal_buffer_type_shared
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_shared
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_type_t ggml_backend_metal_buffer_type_shared(int device) {
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);

    static std::vector<ggml_backend_buffer_type> bufts;
    static std::vector<ggml_backend_metal_buffer_type_ptr> ctxs;

    static bool initialized = false;
    if (!initialized) {
        bufts.reserve(g_devices);
        ctxs.reserve(g_devices);

        for (int i = 0; i < g_devices; ++i) {
            ggml_backend_metal_buffer_type * raw_ctx =
                new ggml_backend_metal_buffer_type {
                    /* .device = */ i,
                    /* .name   = */ GGML_METAL_NAME + std::to_string(i),
                };
            ctxs.emplace_back(raw_ctx);

            ggml_backend_buffer_type buft = {
                /* .iface = */ {
                    /* .get_name         = */ ggml_backend_metal_buffer_type_shared_get_name,
                    /* .alloc_buffer     = */ ggml_backend_metal_buffer_type_shared_alloc_buffer,
                    /* .get_alignment    = */ ggml_backend_metal_buffer_type_shared_get_alignment,
                    /* .get_max_size     = */ ggml_backend_metal_buffer_type_shared_get_max_size,
                    /* .get_alloc_size   = */ ggml_backend_metal_buffer_type_shared_get_alloc_size,
                    /* .is_host          = */ ggml_backend_metal_buffer_type_shared_is_host,
                },
                /* .device  = */ ggml_backend_reg_dev_get(ggml_backend_metal_reg(), i),
                /* .context = */ raw_ctx,
            };

            bufts.emplace_back(buft);
        }

        initialized = true;
    }

    return &bufts[device];
}

// default (private) buffer type

// 函数: ggml_backend_metal_buffer_type_private_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_private_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static const char * ggml_backend_metal_buffer_type_private_get_name(ggml_backend_buffer_type_t buft) {
    ggml_backend_metal_buffer_type * ctx = (ggml_backend_metal_buffer_type *)buft->context;

    return ctx->name.c_str();
}

// 函数: ggml_backend_metal_buffer_type_private_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_private_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_t ggml_backend_metal_buffer_type_private_alloc_buffer(ggml_backend_buffer_type_t buft, size_t size) {
    return ggml_backend_metal_buffer_type_alloc_buffer(buft, size, false);
}

// 函数: ggml_backend_metal_buffer_type_private_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_private_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_private_get_alignment(ggml_backend_buffer_type_t buft) {
    return 32;

    GGML_UNUSED(buft);
}

// 函数: ggml_backend_metal_buffer_type_private_get_max_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_private_get_max_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_private_get_max_size(ggml_backend_buffer_type_t buft) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)buft->device->context;

    return ggml_metal_device_get_props(ctx_dev)->max_buffer_size;
}

// 函数: ggml_backend_metal_buffer_type_private_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_private_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_private_get_alloc_size(ggml_backend_buffer_type_t buft, const ggml_tensor * tensor) {
    return ggml_backend_metal_buffer_type_get_alloc_size(buft, tensor);
}

// 函数: ggml_backend_metal_buffer_type_private_is_host
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_private_is_host
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_metal_buffer_type_private_is_host(ggml_backend_buffer_type_t buft) {
    return false;

    GGML_UNUSED(buft);
}

// 函数: ggml_backend_metal_buffer_type_private
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_private
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_type_t ggml_backend_metal_buffer_type_private(int device) {
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);

    static std::vector<ggml_backend_buffer_type> bufts;
    static std::vector<ggml_backend_metal_buffer_type_ptr> ctxs;

    static bool initialized = false;
    if (!initialized) {
        bufts.reserve(g_devices);
        ctxs.reserve(g_devices);

        for (int i = 0; i < g_devices; ++i) {
            ggml_backend_metal_buffer_type * raw_ctx = new ggml_backend_metal_buffer_type{
                /* .device = */ i,
                /* .name   = */ GGML_METAL_NAME + std::to_string(i) + "_Private"
            };
            ctxs.emplace_back(raw_ctx);

            ggml_backend_buffer_type buft = {
                /* .iface = */ {
                    /* .get_name         = */ ggml_backend_metal_buffer_type_private_get_name,
                    /* .alloc_buffer     = */ ggml_backend_metal_buffer_type_private_alloc_buffer,
                    /* .get_alignment    = */ ggml_backend_metal_buffer_type_private_get_alignment,
                    /* .get_max_size     = */ ggml_backend_metal_buffer_type_private_get_max_size,
                    /* .get_alloc_size   = */ ggml_backend_metal_buffer_type_private_get_alloc_size,
                    /* .is_host          = */ ggml_backend_metal_buffer_type_private_is_host,
                },
                /* .device  = */ ggml_backend_reg_dev_get(ggml_backend_metal_reg(), i),
                /* .context = */ raw_ctx,
            };

            bufts.emplace_back(buft);
        }

        initialized = true;
    }

    return &bufts[device];
}

// mapped buffer type

// 函数: ggml_backend_metal_buffer_type_mapped_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_mapped_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static const char * ggml_backend_metal_buffer_type_mapped_get_name(ggml_backend_buffer_type_t buft) {
    ggml_backend_metal_buffer_type * ctx = (ggml_backend_metal_buffer_type *)buft->context;

    return ctx->name.c_str();
}

// 函数: ggml_backend_metal_buffer_type_mapped_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_mapped_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_t ggml_backend_metal_buffer_type_mapped_alloc_buffer(ggml_backend_buffer_type_t buft, size_t size) {
    // for mapped buffers, prefer shared memory
    return ggml_backend_metal_buffer_type_alloc_buffer(buft, size, true);
}

// 函数: ggml_backend_metal_buffer_type_mapped_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_mapped_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_mapped_get_alignment(ggml_backend_buffer_type_t buft) {
    return 32;

    GGML_UNUSED(buft);
}

// 函数: ggml_backend_metal_buffer_type_mapped_get_max_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_mapped_get_max_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_mapped_get_max_size(ggml_backend_buffer_type_t buft) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)buft->device->context;

    return ggml_metal_device_get_props(ctx_dev)->max_buffer_size;
}

// 函数: ggml_backend_metal_buffer_type_mapped_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_mapped_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_buffer_type_mapped_get_alloc_size(ggml_backend_buffer_type_t buft, const ggml_tensor * tensor) {
    return ggml_backend_metal_buffer_type_get_alloc_size(buft, tensor);
}

// 函数: ggml_backend_metal_buffer_type_mapped_is_host
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_mapped_is_host
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_metal_buffer_type_mapped_is_host(ggml_backend_buffer_type_t buft) {
    return false;

    GGML_UNUSED(buft);
}

// 函数: ggml_backend_metal_buffer_type_mapped
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_buffer_type_mapped
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_type_t ggml_backend_metal_buffer_type_mapped(int device) {
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);

    static std::vector<ggml_backend_buffer_type> bufts;
    static std::vector<ggml_backend_metal_buffer_type_ptr> ctxs;

    static bool initialized = false;
    if (!initialized) {
        bufts.reserve(g_devices);
        ctxs.reserve(g_devices);

        for (int i = 0; i < g_devices; ++i) {
            ggml_backend_metal_buffer_type * raw_ctx = new ggml_backend_metal_buffer_type{
                /* .device = */ i,
                /* .name   = */ GGML_METAL_NAME + std::to_string(i) + "_Mapped"
            };
            ctxs.emplace_back(raw_ctx);

            // note: not obvious, but this buffer type still needs to implement .alloc_buffer:
            //       https://github.com/ggml-org/llama.cpp/pull/15832#discussion_r2333177099
            ggml_backend_buffer_type buft = {
                /* .iface = */ {
                    /* .get_name         = */ ggml_backend_metal_buffer_type_mapped_get_name,
                    /* .alloc_buffer     = */ ggml_backend_metal_buffer_type_mapped_alloc_buffer,
                    /* .get_alignment    = */ ggml_backend_metal_buffer_type_mapped_get_alignment,
                    /* .get_max_size     = */ ggml_backend_metal_buffer_type_mapped_get_max_size,
                    /* .get_alloc_size   = */ ggml_backend_metal_buffer_type_mapped_get_alloc_size,
                    /* .is_host          = */ ggml_backend_metal_buffer_type_mapped_is_host,
                },
                /* .device  = */ ggml_backend_reg_dev_get(ggml_backend_metal_reg(), i),
                /* .context = */ raw_ctx,
            };

            bufts.emplace_back(buft);
        }

        initialized = true;
    }

    return &bufts[device];
}

// backend

// 函数: ggml_backend_metal_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static const char * ggml_backend_metal_name(ggml_backend_t backend) {
    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    return ggml_metal_get_name(ctx);
}

// 函数: ggml_backend_metal_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_free(ggml_backend_t backend) {
    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    // wait for any ongoing async operations to finish
    ggml_metal_synchronize(ctx);

    ggml_metal_free(ctx);

    free(backend);
}

// 函数: ggml_backend_metal_synchronize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_synchronize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_synchronize(ggml_backend_t backend) {
    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    ggml_metal_synchronize(ctx);
}

// 函数: ggml_backend_metal_set_tensor_async
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_set_tensor_async
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_set_tensor_async(ggml_backend_t backend, ggml_tensor * tensor, const void * data, size_t offset, size_t size) {
    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    ggml_metal_set_tensor_async(ctx, tensor, data, offset, size);
}

// 函数: ggml_backend_metal_get_tensor_async
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_get_tensor_async
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_get_tensor_async(ggml_backend_t backend, const ggml_tensor * tensor, void * data, size_t offset, size_t size) {
    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    ggml_metal_get_tensor_async(ctx, tensor, data, offset, size);
}

// 函数: ggml_backend_metal_cpy_tensor_async
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_cpy_tensor_async
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_metal_cpy_tensor_async(ggml_backend_t backend_src, ggml_backend_t backend_dst, const ggml_tensor * src, ggml_tensor * dst) {
    if (!ggml_backend_is_metal(backend_src) || !ggml_backend_is_metal(backend_dst)) {
        return false;
    }

    if (!ggml_backend_buffer_is_metal(src->buffer) || !ggml_backend_buffer_is_metal(dst->buffer)) {
        return false;
    }

    ggml_metal_t ctx_src = (ggml_metal_t)backend_src->context;
    ggml_metal_t ctx_dst = (ggml_metal_t)backend_dst->context;

    //ggml_backend_buffer_t buf_src = src->view_src ? src->view_src->buffer : src->buffer;
    //ggml_backend_buffer_t buf_dst = dst->view_src ? dst->view_src->buffer : dst->buffer;

    //ggml_metal_buffer_t buf_ctx_src = (ggml_metal_buffer_t)buf_src->context;
    //ggml_metal_buffer_t buf_ctx_dst = (ggml_metal_buffer_t)buf_dst->context;

    return ggml_metal_cpy_tensor_async(ctx_src, ctx_dst, src, dst);
}

static enum ggml_status ggml_backend_metal_graph_compute(ggml_backend_t backend, ggml_cgraph * cgraph) {
    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    // 函数: ggml_metal_graph_compute
    // 描述: 计算: 执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ggml_metal_graph_compute
    // 描述: 计算: 执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    return ggml_metal_graph_compute(ctx, cgraph);
}

// 函数: ggml_backend_metal_event_record
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_event_record
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_event_record(ggml_backend_t backend, ggml_backend_event_t event) {
    ggml_metal_t ctx = (ggml_metal_t)backend->context;
    ggml_metal_event_t ev = (ggml_metal_event_t)event->context;

    ggml_metal_event_record(ctx, ev);
}

// 函数: ggml_backend_metal_event_wait
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_event_wait
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_event_wait(ggml_backend_t backend, ggml_backend_event_t event) {
    ggml_metal_t ctx = (ggml_metal_t)backend->context;
    ggml_metal_event_t ev = (ggml_metal_event_t)event->context;

    ggml_metal_event_wait(ctx, ev);
}

// 函数: ggml_backend_metal_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_graph_optimize(ggml_backend_t backend, ggml_cgraph * cgraph) {
    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    ggml_metal_graph_optimize(ctx, cgraph);
}

// 函数: ggml_backend_metal_set_n_cb
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_set_n_cb
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_set_n_cb(ggml_backend_t backend, int n_cb) {
    GGML_ASSERT(ggml_backend_is_metal(backend));

    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    ggml_metal_set_n_cb(ctx, n_cb);
}

static ggml_backend_i ggml_backend_metal_i = {
    /* .get_name                = */ ggml_backend_metal_name,
    /* .free                    = */ ggml_backend_metal_free,
    /* .set_tensor_async        = */ ggml_backend_metal_set_tensor_async,
    /* .get_tensor_async        = */ ggml_backend_metal_get_tensor_async,
    /* .cpy_tensor_async        = */ ggml_backend_metal_cpy_tensor_async, // only needed for multi-GPU setups
    /* .synchronize             = */ ggml_backend_metal_synchronize,
    /* .graph_plan_create       = */ NULL,
    /* .graph_plan_free         = */ NULL,
    /* .graph_plan_update       = */ NULL,
    /* .graph_plan_compute      = */ NULL,
    /* .graph_compute           = */ ggml_backend_metal_graph_compute,
    /* .event_record            = */ ggml_backend_metal_event_record,
    /* .event_wait              = */ ggml_backend_metal_event_wait,
    /* .graph_optimize          = */ ggml_backend_metal_graph_optimize,
};

// 函数: ggml_backend_metal_guid
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_guid
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_guid_t ggml_backend_metal_guid(void) {
    static ggml_guid guid = { 0x81, 0xa1, 0x8b, 0x1e, 0x71, 0xec, 0x79, 0xed, 0x2b, 0x85, 0xdc, 0x8a, 0x61, 0x98, 0x30, 0xe6 };
    return &guid;
}

// 函数: ggml_backend_metal_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
ggml_backend_t ggml_backend_metal_init(void) {
    ggml_backend_dev_t dev = ggml_backend_reg_dev_get(ggml_backend_metal_reg(), 0);
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    ggml_metal_t ctx = ggml_metal_init(ctx_dev);
    if (ctx == NULL) {
        GGML_LOG_ERROR("%s: error: failed to allocate context\n", __func__);
        return NULL;
    }

    ggml_backend_t backend = (ggml_backend_t) malloc(sizeof(ggml_backend));

    *backend = {
        /* .guid      = */ ggml_backend_metal_guid(),
        /* .interface = */ ggml_backend_metal_i,
        /* .device    = */ dev,
        /* .context   = */ ctx,
    };

    ggml_backend_metal_set_n_cb(backend, 1);

    return backend;
}

// 函数: ggml_backend_is_metal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_is_metal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_backend_is_metal(ggml_backend_t backend) {
    return backend != NULL && ggml_guid_matches(backend->guid, ggml_backend_metal_guid());
}

// 函数: ggml_backend_metal_set_abort_callback
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_set_abort_callback
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void ggml_backend_metal_set_abort_callback(ggml_backend_t backend, ggml_abort_callback abort_callback, void * user_data) {
    GGML_ASSERT(ggml_backend_is_metal(backend));

    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    ggml_metal_set_abort_callback(ctx, abort_callback, user_data);
}

// 函数: ggml_backend_metal_supports_family
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_supports_family
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_backend_metal_supports_family(ggml_backend_t backend, int family) {
    GGML_ASSERT(ggml_backend_is_metal(backend));

    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    return ggml_metal_supports_family(ctx, family);
}

// 函数: ggml_backend_metal_capture_next_compute
// 描述: 计算: 执行计算操作
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_capture_next_compute
// 描述: 计算: 执行计算操作
// 参数: 无参数
// 返回: 无返回值
void ggml_backend_metal_capture_next_compute(ggml_backend_t backend) {
    GGML_ASSERT(ggml_backend_is_metal(backend));

    ggml_metal_t ctx = (ggml_metal_t)backend->context;

    ggml_metal_capture_next_compute(ctx);
}

// backend device

// 函数: ggml_backend_metal_device_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static const char * ggml_backend_metal_device_get_name(ggml_backend_dev_t dev) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    const ggml_metal_device_props * props_dev = ggml_metal_device_get_props(ctx_dev);

    return props_dev->name;
}

// 函数: ggml_backend_metal_device_get_description
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_get_description
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static const char * ggml_backend_metal_device_get_description(ggml_backend_dev_t dev) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    return ggml_metal_device_get_props(ctx_dev)->desc;
}

// 函数: ggml_backend_metal_device_get_memory
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_get_memory
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_device_get_memory(ggml_backend_dev_t dev, size_t * free, size_t * total) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    ggml_metal_device_get_memory(ctx_dev, free, total);
}

static enum ggml_backend_dev_type ggml_backend_metal_device_get_type(ggml_backend_dev_t dev) {
    return GGML_BACKEND_DEVICE_TYPE_GPU;

    GGML_UNUSED(dev);
}

// 函数: ggml_backend_metal_device_get_props
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_get_props
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_device_get_props(ggml_backend_dev_t dev, ggml_backend_dev_props * props) {
    props->name        = ggml_backend_metal_device_get_name(dev);
    props->description = ggml_backend_metal_device_get_description(dev);
    props->type        = ggml_backend_metal_device_get_type(dev);

    ggml_backend_metal_device_get_memory(dev, &props->memory_free, &props->memory_total);

    props->caps = {
        /* .async                = */ true,
        /* .host_buffer          = */ false,
        /* .buffer_from_host_ptr = */ true,
        /* .events               = */ true,
    };
}

// 函数: ggml_backend_metal_device_init_backend
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_init_backend
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_t ggml_backend_metal_device_init_backend(ggml_backend_dev_t dev, const char * params) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    ggml_metal_t ctx = ggml_metal_init(ctx_dev);
    if (ctx == NULL) {
        GGML_LOG_ERROR("%s: error: failed to allocate context\n", __func__);
        return NULL;
    }

    ggml_backend_t backend = (ggml_backend_t) malloc(sizeof(ggml_backend));

    *backend = {
        /* .guid      = */ ggml_backend_metal_guid(),
        /* .interface = */ ggml_backend_metal_i,
        /* .device    = */ dev,
        /* .context   = */ ctx,
    };

    ggml_backend_metal_set_n_cb(backend, 1);

    return backend;

    GGML_UNUSED(params);
}

// 函数: ggml_backend_metal_device_get_buffer_type
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_get_buffer_type
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_type_t ggml_backend_metal_device_get_buffer_type(ggml_backend_dev_t dev) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    const ggml_metal_device_props * props_dev = ggml_metal_device_get_props(ctx_dev);

    return props_dev->use_shared_buffers ? ggml_backend_metal_buffer_type_shared(props_dev->device) : ggml_backend_metal_buffer_type_private(props_dev->device);
}

// 函数: ggml_backend_metal_device_buffer_mapped
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_buffer_mapped
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_t ggml_backend_metal_device_buffer_mapped(ggml_backend_dev_t dev, void * ptr, size_t size, size_t max_tensor_size) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    ggml_metal_buffer_t res = ggml_metal_buffer_map(ctx_dev, ptr, size, max_tensor_size);

    const ggml_metal_device_props * props_dev = ggml_metal_device_get_props(ctx_dev);

    return ggml_backend_buffer_init(ggml_backend_metal_buffer_type_mapped(props_dev->device), ggml_backend_metal_buffer_shared_i, res, size);
}

// 函数: ggml_backend_metal_device_supports_op
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_supports_op
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_metal_device_supports_op(ggml_backend_dev_t dev, const ggml_tensor * op) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    return ggml_metal_device_supports_op(ctx_dev, op);
}

// 函数: ggml_backend_metal_device_supports_buft
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_supports_buft
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_metal_device_supports_buft(ggml_backend_dev_t dev, ggml_backend_buffer_type_t buft) {
    return
        buft->device == dev && (
        buft->iface.get_name == ggml_backend_metal_buffer_type_shared_get_name ||
        buft->iface.get_name == ggml_backend_metal_buffer_type_private_get_name ||
        buft->iface.get_name == ggml_backend_metal_buffer_type_mapped_get_name);

    GGML_UNUSED(dev);
}

// 函数: get_op_batch_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
// 函数: get_op_batch_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
static int64_t get_op_batch_size(const ggml_tensor * op) {
    switch (op->op) {
        case GGML_OP_MUL_MAT:
            return op->ne[1];
        case GGML_OP_MUL_MAT_ID:
            return op->ne[2];
        default:
            return ggml_nrows(op);
    }
}

// 函数: ggml_backend_metal_device_offload_op
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_offload_op
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_metal_device_offload_op(ggml_backend_dev_t dev, const ggml_tensor * op) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    return (op->op == GGML_OP_MUL_MAT ||
            op->op == GGML_OP_MUL_MAT_ID) &&
            get_op_batch_size(op) >= ggml_metal_device_get_props(ctx_dev)->op_offload_min_batch_size;
}

// 函数: ggml_backend_metal_device_event_new
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_event_new
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_event_t ggml_backend_metal_device_event_new(ggml_backend_dev_t dev) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    ggml_metal_event_t event = ggml_metal_device_event_init(ctx_dev);
    GGML_ASSERT(event);

    ggml_backend_event_t ev = new ggml_backend_event {
        /* .device  = */ dev,
        /* .context = */ event,
    };

    return ev;
}

// 函数: ggml_backend_metal_device_event_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_event_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_device_event_free(ggml_backend_dev_t dev, ggml_backend_event_t event) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    ggml_metal_event_t ev = (ggml_metal_event_t)event->context;

    ggml_metal_device_event_free(ctx_dev, ev);

    delete event;
}

// 函数: ggml_backend_metal_device_event_synchronize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_event_synchronize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_device_event_synchronize(ggml_backend_dev_t dev, ggml_backend_event_t event) {
    ggml_metal_device_t ctx_dev = (ggml_metal_device_t)dev->context;

    ggml_metal_event_t evt = (ggml_metal_event_t)event->context;

    ggml_metal_device_event_synchronize(ctx_dev, evt);
}

static ggml_backend_device_i ggml_backend_metal_device_i = {
    /* .get_name             = */ ggml_backend_metal_device_get_name,
    /* .get_description      = */ ggml_backend_metal_device_get_description,
    /* .get_memory           = */ ggml_backend_metal_device_get_memory,
    /* .get_type             = */ ggml_backend_metal_device_get_type,
    /* .get_props            = */ ggml_backend_metal_device_get_props,
    /* .init_backend         = */ ggml_backend_metal_device_init_backend,
    /* .get_buffer_type      = */ ggml_backend_metal_device_get_buffer_type,
    /* .get_host_buffer_type = */ NULL,
    /* .buffer_from_host_ptr = */ ggml_backend_metal_device_buffer_mapped,
    /* .supports_op          = */ ggml_backend_metal_device_supports_op,
    /* .supports_buft        = */ ggml_backend_metal_device_supports_buft,
    /* .offload_op           = */ ggml_backend_metal_device_offload_op,
    /* .event_new            = */ ggml_backend_metal_device_event_new,
    /* .event_free           = */ ggml_backend_metal_device_event_free,
    /* .event_synchronize    = */ ggml_backend_metal_device_event_synchronize,
};

// backend registry

// 类: ggml_backend_metal_reg
// 描述: ggml_backend_metal_reg类提供相关功能
// 用途: 用于处理ggml_backend_metal_reg相关的操作
// 类: ggml_backend_metal_reg
// 描述: ggml_backend_metal_reg类提供相关功能
// 用途: 用于处理ggml_backend_metal_reg相关的操作
    // 结构体: ggml_backend_metal_reg
    // 描述: ggml_backend_metal_reg结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_reg相关的操作
    // 结构体: ggml_backend_metal_reg
    // 描述: ggml_backend_metal_reg结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_reg相关的操作
    // 结构体: ggml_backend_metal_reg
    // 描述: ggml_backend_metal_reg结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_reg相关的操作
    // 结构体: ggml_backend_metal_reg
    // 描述: ggml_backend_metal_reg结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_reg相关的操作
struct ggml_backend_metal_reg {
    std::vector<ggml_backend_dev_t> devices;
};

typedef struct ggml_backend_metal_reg * ggml_backend_metal_reg_t;

// 函数: ggml_backend_metal_reg_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_reg_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_metal_reg_t ggml_backend_metal_reg_init(void) {
    ggml_backend_metal_reg_t ctx = new struct ggml_backend_metal_reg;

    return ctx;
}

// 函数: ggml_backend_metal_reg_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_reg_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_reg_free(ggml_backend_metal_reg_t ctx) {
    delete ctx;
}

// 类: ggml_backend_metal_reg_deleter
// 描述: ggml_backend_metal_reg_deleter类提供相关功能
// 用途: 用于处理ggml_backend_metal_reg_deleter相关的操作
// 类: ggml_backend_metal_reg_deleter
// 描述: ggml_backend_metal_reg_deleter类提供相关功能
// 用途: 用于处理ggml_backend_metal_reg_deleter相关的操作
    // 结构体: ggml_backend_metal_reg_deleter
    // 描述: ggml_backend_metal_reg_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_reg_deleter相关的操作
    // 结构体: ggml_backend_metal_reg_deleter
    // 描述: ggml_backend_metal_reg_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_reg_deleter相关的操作
    // 结构体: ggml_backend_metal_reg_deleter
    // 描述: ggml_backend_metal_reg_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_reg_deleter相关的操作
    // 结构体: ggml_backend_metal_reg_deleter
    // 描述: ggml_backend_metal_reg_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_metal_reg_deleter相关的操作
struct ggml_backend_metal_reg_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(ggml_backend_metal_reg_t ctx) {
        ggml_backend_metal_reg_free(ctx);
    }
};

typedef std::unique_ptr<struct ggml_backend_metal_reg, ggml_backend_metal_reg_deleter> ggml_backend_metal_reg_ptr;

// 函数: ggml_backend_metal_reg_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_reg_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static const char * ggml_backend_metal_reg_get_name(ggml_backend_reg_t reg) {
    return GGML_METAL_NAME;

    GGML_UNUSED(reg);
}

// 函数: ggml_backend_metal_reg_device_count
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_reg_device_count
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_metal_reg_device_count(ggml_backend_reg_t reg) {
    ggml_backend_metal_reg_t ctx = (ggml_backend_metal_reg_t)reg->context;
    return ctx->devices.size();
}

// 函数: ggml_backend_metal_reg_device_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_reg_device_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_dev_t ggml_backend_metal_reg_device_get(ggml_backend_reg_t reg, size_t index) {
    ggml_backend_metal_reg_t ctx = (ggml_backend_metal_reg_t)reg->context;
    GGML_ASSERT(index < ctx->devices.size());
    return ctx->devices[index];
}

static ggml_backend_feature g_ggml_backend_metal_features[] = {
#if defined(GGML_METAL_EMBED_LIBRARY)
    { "EMBED_LIBRARY", "1" },
#endif
    { NULL, NULL },
};

// 函数: ggml_backend_metal_get_features
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_get_features
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_feature * ggml_backend_metal_get_features(ggml_backend_reg_t reg) {
    return g_ggml_backend_metal_features;

    GGML_UNUSED(reg);
}

// 函数: ggml_backend_metal_get_proc_address
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_get_proc_address
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void * ggml_backend_metal_get_proc_address(ggml_backend_reg_t reg, const char * name) {
    if (strcmp(name, "ggml_backend_get_features") == 0) {
        return (void *)ggml_backend_metal_get_features;
    }

    return NULL;

    GGML_UNUSED(reg);
}

static ggml_backend_reg_i ggml_backend_metal_reg_i = {
    /* .get_name         = */ ggml_backend_metal_reg_get_name,
    /* .get_device_count = */ ggml_backend_metal_reg_device_count,
    /* .get_device       = */ ggml_backend_metal_reg_device_get,
    /* .get_proc_address = */ ggml_backend_metal_get_proc_address,
};

// 函数: ggml_backend_metal_device_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_dev_t ggml_backend_metal_device_init(ggml_backend_reg_t reg, int device) {
    return new ggml_backend_device {
        /* .iface   = */ ggml_backend_metal_device_i,
        /* .reg     = */ reg,
        /* .context = */ ggml_metal_device_get(device),
    };
}

// 函数: ggml_backend_metal_device_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_device_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_metal_device_free(ggml_backend_dev_t dev) {
    delete dev;
}

// 类: ggml_backend_device_deleter
// 描述: ggml_backend_device_deleter类提供相关功能
// 用途: 用于处理ggml_backend_device_deleter相关的操作
// 类: ggml_backend_device_deleter
// 描述: ggml_backend_device_deleter类提供相关功能
// 用途: 用于处理ggml_backend_device_deleter相关的操作
    // 结构体: ggml_backend_device_deleter
    // 描述: ggml_backend_device_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_device_deleter相关的操作
    // 结构体: ggml_backend_device_deleter
    // 描述: ggml_backend_device_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_device_deleter相关的操作
    // 结构体: ggml_backend_device_deleter
    // 描述: ggml_backend_device_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_device_deleter相关的操作
    // 结构体: ggml_backend_device_deleter
    // 描述: ggml_backend_device_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_device_deleter相关的操作
struct ggml_backend_device_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(ggml_backend_dev_t ctx) {
        ggml_backend_metal_device_free(ctx);
    }
};

typedef std::unique_ptr<ggml_backend_device, ggml_backend_device_deleter> ggml_backend_device_ptr;

// 函数: ggml_backend_metal_reg
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_metal_reg
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
ggml_backend_reg_t ggml_backend_metal_reg(void) {
    static ggml_backend_reg reg;
    static bool initialized = false;

    {
        static std::mutex mutex;
        std::lock_guard<std::mutex> lock(mutex);

        const char * env = getenv("GGML_METAL_DEVICES");
        if (env) {
            g_devices = atoi(env);
        }

        static std::vector<ggml_backend_device_ptr> devs;

        if (!initialized) {
            static ggml_backend_metal_reg_ptr reg_ctx(ggml_backend_metal_reg_init());

            for (int i = 0; i < g_devices; ++i) {
                auto * dev = ggml_backend_metal_device_init(&reg, i);
                devs.emplace_back(dev);

                reg_ctx->devices.push_back(dev);
            }

            reg = {
                /* .api_version = */ GGML_BACKEND_API_VERSION,
                /* .iface       = */ ggml_backend_metal_reg_i,
                /* .context     = */ reg_ctx.get(),
            };
        }

        initialized = true;
    }

    return &reg;
}

GGML_BACKEND_DL_IMPL(ggml_backend_metal_reg)
