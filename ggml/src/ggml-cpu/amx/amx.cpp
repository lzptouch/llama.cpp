// ============================================================================
// 文件: amx.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-cpu/amx/amx.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "amx.h"
#include "common.h"
#include "mmq.h"
#include "ggml-backend-impl.h"
#include "ggml-backend.h"
#include "ggml-impl.h"
#include "ggml-cpu.h"
#include "traits.h"

#if defined(__linux__)
#include <sys/syscall.h>
#include <unistd.h>
#endif

#include <cstdlib>
#include <cstring>
#include <memory>

#if defined(__AMX_INT8__) && defined(__AVX512VNNI__)

// AMX type_trais
namespace ggml::cpu::amx {
// 类: tensor_traits
// 描述: tensor_traits类提供相关功能
// 用途: 用于处理tensor_traits相关的操作
// 类: tensor_traits
// 描述: tensor_traits类提供相关功能
// 用途: 用于处理tensor_traits相关的操作
class tensor_traits : public ggml::cpu::tensor_traits {
    // 函数: work_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: work_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool work_size(int /* n_threads */, const struct ggml_tensor * op, size_t & size) override {
        size = ggml_backend_amx_desired_wsize(op);
        return true;
    }

    // 函数: compute_forward
    // 描述: 前向传播: 执行神经网络的前向传播
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: compute_forward
    // 描述: 前向传播: 执行神经网络的前向传播
    // 参数: 无参数
    // 返回: 无返回值
    bool compute_forward(struct ggml_compute_params * params, struct ggml_tensor * op) override {
        if (op->op == GGML_OP_MUL_MAT) {
            ggml_backend_amx_mul_mat(params, op);
            return true;
        }
        return false;
    }
};

// 函数: get_tensor_traits
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
// 函数: get_tensor_traits
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
static ggml::cpu::tensor_traits * get_tensor_traits(ggml_backend_buffer_t, struct ggml_tensor *) {
    static tensor_traits traits;
    return &traits;
}
}  // namespace ggml::cpu::amx

// AMX buffer interface
// 函数: ggml_backend_amx_buffer_free_buffer
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_free_buffer
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_amx_buffer_free_buffer(ggml_backend_buffer_t buffer) {
    free(buffer->context);
}

// 函数: ggml_backend_amx_buffer_get_base
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_get_base
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void * ggml_backend_amx_buffer_get_base(ggml_backend_buffer_t buffer) {
    return (void *) (buffer->context);
}

static enum ggml_status ggml_backend_amx_buffer_init_tensor(ggml_backend_buffer_t buffer, struct ggml_tensor * tensor) {
    tensor->extra = (void *) ggml::cpu::amx::get_tensor_traits(buffer, tensor);

    GGML_UNUSED(buffer);
    return GGML_STATUS_SUCCESS;
}

static void ggml_backend_amx_buffer_memset_tensor(ggml_backend_buffer_t buffer, struct ggml_tensor * tensor,
                                                  uint8_t value, size_t offset, size_t size) {
    memset((char *) tensor->data + offset, value, size);

    GGML_UNUSED(buffer);
}

static void ggml_backend_amx_buffer_set_tensor(ggml_backend_buffer_t buffer, struct ggml_tensor * tensor,
                                               const void * data, size_t offset, size_t size) {
    if (qtype_has_amx_kernels(tensor->type)) {
        GGML_LOG_DEBUG("%s: amx repack tensor %s of type %s\n", __func__, tensor->name, ggml_type_name(tensor->type));
        ggml_backend_amx_convert_weight(tensor, data, offset, size);
    } else {
        memcpy((char *) tensor->data + offset, data, size);
    }

    GGML_UNUSED(buffer);
}

/*
// need to figure what we need to do with buffer->extra.
// 函数: ggml_backend_amx_buffer_get_tensor
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_get_tensor
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_amx_buffer_get_tensor(ggml_backend_buffer_t buffer, const struct ggml_tensor * tensor, void * data, size_t offset, size_t size) {
    GGML_ASSERT(!qtype_has_amx_kernels(tensor->type));
    memcpy(data, (const char *)tensor->data + offset, size);

    GGML_UNUSED(buffer);
}

// 函数: ggml_backend_amx_buffer_cpy_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_cpy_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_backend_amx_buffer_cpy_tensor(ggml_backend_buffer_t buffer, const struct ggml_tensor * src, struct ggml_tensor * dst) {
    if (ggml_backend_buffer_is_host(src->buffer)) {
        if (qtype_has_amx_kernels(src->type)) {
            ggml_backend_amx_convert_weight(dst, src->data, 0, ggml_nbytes(dst));
        } else {
            memcpy(dst->data, src->data, ggml_nbytes(src));
        }
        return true;
    }
    return false;

    GGML_UNUSED(buffer);
}
*/

// 函数: ggml_backend_amx_buffer_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_amx_buffer_clear(ggml_backend_buffer_t buffer, uint8_t value) {
    memset(buffer->context, value, buffer->size);
}

static ggml_backend_buffer_i ggml_backend_amx_buffer_interface = {
    /* .free_buffer     = */ ggml_backend_amx_buffer_free_buffer,
    /* .get_base        = */ ggml_backend_amx_buffer_get_base,
    /* .init_tensor     = */ ggml_backend_amx_buffer_init_tensor,
    /* .memset_tensor   = */ ggml_backend_amx_buffer_memset_tensor,
    /* .set_tensor      = */ ggml_backend_amx_buffer_set_tensor,
    /* .get_tensor      = */ nullptr,
    /* .cpy_tensor      = */ nullptr,
    /* .clear           = */ ggml_backend_amx_buffer_clear,
    /* .reset           = */ nullptr,
};

// 函数: ggml_backend_amx_buffer_type_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_type_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static const char * ggml_backend_amx_buffer_type_get_name(ggml_backend_buffer_type_t buft) {
    return "AMX";

    GGML_UNUSED(buft);
}

// 函数: ggml_backend_amx_buffer_type_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_type_alloc_buffer
// 描述: 分配: 分配内存或资源
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_buffer_t ggml_backend_amx_buffer_type_alloc_buffer(ggml_backend_buffer_type_t buft, size_t size) {
    void * data = ggml_aligned_malloc(size);
    if (data == NULL) {
        fprintf(stderr, "%s: failed to allocate buffer of size %zu\n", __func__, size);
        return NULL;
    }

    return ggml_backend_buffer_init(buft, ggml_backend_amx_buffer_interface, data, size);
}

// 函数: ggml_backend_amx_buffer_type_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_type_get_alignment
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_amx_buffer_type_get_alignment(ggml_backend_buffer_type_t buft) {
    return TENSOR_ALIGNMENT;

    GGML_UNUSED(buft);
}

namespace ggml::cpu::amx {
// 类: extra_buffer_type
// 描述: extra_buffer_type类提供相关功能
// 用途: 用于处理extra_buffer_type相关的操作
// 类: extra_buffer_type
// 描述: extra_buffer_type类提供相关功能
// 用途: 用于处理extra_buffer_type相关的操作
class extra_buffer_type : ggml::cpu::extra_buffer_type {
    // 函数: supports_op
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: supports_op
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool supports_op(ggml_backend_dev_t, const struct ggml_tensor * op) override {
        if (op->op != GGML_OP_MUL_MAT) {
            return false;
        }
        auto * src0 = op->src[0];
        auto * src1 = op->src[1];

        if (!ggml_is_contiguous(src0) || !ggml_is_contiguous(src1)) {
            return false;
        }
        if (!src0->buffer || src0->buffer->buft != ggml_backend_amx_buffer_type()) {
            return false;
        }
        if (src1->buffer && !ggml_backend_buft_is_host(src1->buffer->buft)) {
            return false;
        }
        if (op->ne[0] % (TILE_N * 2)) {
            return false;
        }
        int alignment;
        switch (src0->type) {
            case GGML_TYPE_Q4_0:
            case GGML_TYPE_Q4_1:
            case GGML_TYPE_Q8_0:
                alignment = TILE_K;
                break;
            case GGML_TYPE_Q4_K:
            case GGML_TYPE_Q5_K:
            case GGML_TYPE_Q6_K:
            case GGML_TYPE_IQ4_XS:
                alignment = 256; // QK_K
                break;
            case GGML_TYPE_F16:
                alignment = 16;
                break;
            default:
                return false;
        }
        if (src0->ne[0] % alignment) {
            return false;
        }
        if (src1->type != GGML_TYPE_F32) {
            return false;
        }
        return true;
    }

    // 函数: get_tensor_traits
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_tensor_traits
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml::cpu::tensor_traits * get_tensor_traits(const struct ggml_tensor * op) override {
        if (op->op == GGML_OP_MUL_MAT && op->src[0]->buffer &&
            op->src[0]->buffer->buft == ggml_backend_amx_buffer_type()) {
            return (ggml::cpu::tensor_traits *) op->src[0]->extra;
        }

        return nullptr;
    }
};
}  // namespace ggml::cpu::amx

// 函数: ggml_backend_amx_buffer_type_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_type_get_alloc_size
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static size_t ggml_backend_amx_buffer_type_get_alloc_size(ggml_backend_buffer_type_t buft, const ggml_tensor * tensor) {
    return ggml_backend_amx_get_alloc_size(tensor);

    GGML_UNUSED(buft);
}

#define ARCH_GET_XCOMP_PERM     0x1022
#define ARCH_REQ_XCOMP_PERM     0x1023
#define XFEATURE_XTILECFG       17
#define XFEATURE_XTILEDATA      18

// 函数: ggml_amx_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_amx_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
static bool ggml_amx_init() {
#if defined(__linux__)
    if (syscall(SYS_arch_prctl, ARCH_REQ_XCOMP_PERM, XFEATURE_XTILEDATA)) {
        fprintf(stderr, "AMX is not ready to be used!\n");
        return false;
    }
    return true;
#elif defined(_WIN32)
    return true;
#else
    return false;
#endif
}

// 函数: ggml_backend_amx_buffer_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_amx_buffer_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
ggml_backend_buffer_type_t ggml_backend_amx_buffer_type() {
    static struct ggml_backend_buffer_type ggml_backend_buffer_type_amx = {
        /* .iface = */ {
                        /* .get_name         = */ ggml_backend_amx_buffer_type_get_name,
                        /* .alloc_buffer     = */ ggml_backend_amx_buffer_type_alloc_buffer,
                        /* .get_alignment    = */ ggml_backend_amx_buffer_type_get_alignment,
                        /* .get_max_size     = */ nullptr,  // defaults to SIZE_MAX
                        /* .get_alloc_size   = */ ggml_backend_amx_buffer_type_get_alloc_size,
                        /* .is_host          = */ nullptr,
                        },
        /* .device  = */ ggml_backend_reg_dev_get(ggml_backend_cpu_reg(), 0),
        /* .context = */ new ggml::cpu::amx::extra_buffer_type(),
    };

    if (!ggml_amx_init()) {
        return nullptr;
    }

    return &ggml_backend_buffer_type_amx;
}

#endif  // defined(__AMX_INT8__) && defined(__AVX512VNNI__)
