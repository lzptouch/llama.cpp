// ============================================================================
// 文件: ggml-backend.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-virtgpu/ggml-backend.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "../../include/ggml-virtgpu.h"
#include "ggml-remoting.h"

// 函数: ggml_backend_remoting_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_remoting_get_name
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static const char * ggml_backend_remoting_get_name(ggml_backend_t backend) {
    UNUSED(backend);

    return "API Remoting backend";
}

// 函数: ggml_backend_remoting_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_remoting_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_remoting_free(ggml_backend_t backend) {
    delete backend;
}

// 函数: ggml_backend_remoting_graph_compute
// 描述: 计算: 执行计算操作
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_remoting_graph_compute
// 描述: 计算: 执行计算操作
// 参数: 无参数
// 返回: 无返回值
static ggml_status ggml_backend_remoting_graph_compute(ggml_backend_t backend, ggml_cgraph * cgraph) {
    virtgpu * gpu = DEV_TO_GPU(backend->device);

    return apir_backend_graph_compute(gpu, cgraph);
}

// 函数: ggml_backend_remoting_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_remoting_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void ggml_backend_remoting_graph_optimize(ggml_backend_t backend, ggml_cgraph * cgraph) {
    virtgpu * gpu = DEV_TO_GPU(backend->device);
#if true
    UNUSED(gpu);
    UNUSED(cgraph);
#else
    // not working yet

    apir_backend_graph_optimize(gpu, cgraph);
#endif
}

static ggml_backend_i ggml_backend_remoting_interface = {
    /* .get_name                = */ ggml_backend_remoting_get_name,
    /* .free                    = */ ggml_backend_remoting_free,
    /* .set_tensor_async        = */ NULL,  // ggml_backend_remoting_set_tensor_async,
    /* .get_tensor_async        = */ NULL,  // ggml_backend_remoting_get_tensor_async,
    /* .cpy_tensor_async        = */ NULL,  // ggml_backend_remoting_cpy_tensor_async,
    /* .synchronize             = */ NULL,  // ggml_backend_remoting_synchronize,
    /* .graph_plan_create       = */ NULL,
    /* .graph_plan_free         = */ NULL,
    /* .graph_plan_update       = */ NULL,
    /* .graph_plan_compute      = */ NULL,
    /* .graph_compute           = */ ggml_backend_remoting_graph_compute,
    /* .event_record            = */ NULL,
    /* .event_wait              = */ NULL,
    /* .graph_optimize          = */ ggml_backend_remoting_graph_optimize,
};

// 函数: ggml_backend_remoting_guid
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_remoting_guid
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_guid_t ggml_backend_remoting_guid() {
    static ggml_guid guid = { 0xb8, 0xf7, 0x4f, 0x86, 0x14, 0x03, 0x86, 0x02,
                              0x91, 0xc8, 0xdd, 0xe9, 0x02, 0x3f, 0xc0, 0x2b };

    return &guid;
}

// 函数: ggml_backend_remoting_device_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_remoting_device_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
ggml_backend_t ggml_backend_remoting_device_init(ggml_backend_dev_t dev, const char * params) {
    UNUSED(params);

    ggml_backend_remoting_device_context * ctx = (ggml_backend_remoting_device_context *) dev->context;

    ggml_backend_t remoting_backend = new ggml_backend{
        /* .guid      = */ ggml_backend_remoting_guid(),
        /* .interface = */ ggml_backend_remoting_interface,
        /* .device    = */ ggml_backend_reg_dev_get(ggml_backend_virtgpu_reg(), ctx->device),
        /* .context   = */ ctx,
    };

    return remoting_backend;
}
