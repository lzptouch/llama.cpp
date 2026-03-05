// helper functions for ggml-metal that are too difficult to implement in Objective-C

#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

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
struct ggml_tensor;
// 类: ggml_cgraph
// 描述: ggml_cgraph类提供相关功能
// 用途: 用于处理ggml_cgraph相关的操作
// 类: ggml_cgraph
// 描述: ggml_cgraph类提供相关功能
// 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
struct ggml_cgraph;

enum ggml_mem_range_type {
    MEM_RANGE_TYPE_SRC = 0,
    MEM_RANGE_TYPE_DST = 1,
};

// a helper object that can be used for reordering operations to improve concurrency
//
// the fundamental idea is that a set of tasks (either ggml ops, or something else) can run concurrently if they
//   don't write to a memory that is being read by another task or written to by another task in the set
//
// with this structure, we can add tasks to the set, setting memory constraints. we can also check if a new task
//   can be added to the set without violating the constraints (i.e. if it can be executed concurrently with the
//   tasks already in the set)
//
typedef struct ggml_mem_ranges * ggml_mem_ranges_t;

// 函数: ggml_mem_ranges_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
ggml_mem_ranges_t ggml_mem_ranges_init(int debug);
// 函数: ggml_mem_ranges_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void ggml_mem_ranges_free(ggml_mem_ranges_t mrs);

// remove all ranges from the set
// 函数: ggml_mem_ranges_reset
// 描述: 重置: 重置对象或状态到初始值
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_reset
// 描述: 重置: 重置对象或状态到初始值
// 参数: 无参数
// 返回: 无返回值
void ggml_mem_ranges_reset(ggml_mem_ranges_t mrs);

// add src or dst ranges to track
// 函数: ggml_mem_ranges_add
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_add
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_mem_ranges_add(ggml_mem_ranges_t mrs, const struct ggml_tensor * tensor);

// return false if:
// - new src range overlaps with any existing dst range
// - new dst range overlaps with any existing range (src or dst)
// 函数: ggml_mem_ranges_check
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_check
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_mem_ranges_check(ggml_mem_ranges_t mrs, const struct ggml_tensor * tensor);

// reorder the nodes in the graph to improve concurrency, while respecting fusion
//
// note: this implementation is generic and not specific to metal
//       if it proves to work well, we can start using it for other backends in the future
// 函数: ggml_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_graph_optimize(struct ggml_cgraph * gf);

#ifdef __cplusplus
}
#endif
