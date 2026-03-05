#pragma once

// clang-format off
#include "ggml.h"
#include "ggml-backend-impl.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
// clang-format on

// ggml_tensor is serialized into apir_rpc_tensor
// 类: apir_rpc_tensor
// 描述: apir_rpc_tensor类提供相关功能
// 用途: 用于处理apir_rpc_tensor相关的操作
// 类: apir_rpc_tensor
// 描述: apir_rpc_tensor类提供相关功能
// 用途: 用于处理apir_rpc_tensor相关的操作
    // 结构体: apir_rpc_tensor
    // 描述: apir_rpc_tensor结构体提供相关功能
    // 用途: 用于处理apir_rpc_tensor相关的操作
    // 结构体: apir_rpc_tensor
    // 描述: apir_rpc_tensor结构体提供相关功能
    // 用途: 用于处理apir_rpc_tensor相关的操作
    // 结构体: apir_rpc_tensor
    // 描述: apir_rpc_tensor结构体提供相关功能
    // 用途: 用于处理apir_rpc_tensor相关的操作
    // 结构体: apir_rpc_tensor
    // 描述: apir_rpc_tensor结构体提供相关功能
    // 用途: 用于处理apir_rpc_tensor相关的操作
struct apir_rpc_tensor {
    uint64_t id;
    uint32_t type;
    uint64_t buffer;
    uint32_t ne[GGML_MAX_DIMS];
    uint32_t nb[GGML_MAX_DIMS];
    uint32_t op;
    int32_t  op_params[GGML_MAX_OP_PARAMS / sizeof(int32_t)];
    int32_t  flags;
    uint64_t src[GGML_MAX_SRC];
    uint64_t view_src;
    uint64_t view_offs;
    uint64_t data;
    char     name[GGML_MAX_NAME];

    char padding[4];
};

/* frontend */

// 函数: apir_serialize_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_serialize_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
apir_rpc_tensor apir_serialize_tensor(const ggml_tensor * tensor);

// 函数: apir_serialize_graph
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_serialize_graph
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void apir_serialize_graph(const ggml_cgraph * cgraph, std::vector<uint8_t> & output);

/* backend */

// 函数: apir_track_backend_buffer
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_track_backend_buffer
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void                                      apir_track_backend_buffer(ggml_backend_buffer_t buffer);
// 函数: apir_untrack_backend_buffer
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_untrack_backend_buffer
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool                                      apir_untrack_backend_buffer(ggml_backend_buffer_t buffer);
std::unordered_set<ggml_backend_buffer_t> apir_get_track_backend_buffers();

void apir_add_tensor(ggml_tensor *                       tensor,
                     std::vector<apir_rpc_tensor> &      tensors,
                     std::unordered_set<ggml_tensor *> & visited);

// 函数: apir_deserialize_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_deserialize_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
ggml_tensor * apir_deserialize_tensor(ggml_context * ctx, const apir_rpc_tensor * tensor);

ggml_tensor * apir_create_node(uint64_t                                                      id,
                               ggml_context *                                                ctx,
                               const std::unordered_map<uint64_t, const apir_rpc_tensor *> & tensor_ptrs,
                               std::unordered_map<uint64_t, ggml_tensor *> &                 tensor_map);

ggml_cgraph * apir_deserialize_graph(uint32_t                n_nodes,
                                     uint32_t                n_tensors,
                                     const apir_rpc_tensor * tensors,
                                     const uint64_t *        nodes);
