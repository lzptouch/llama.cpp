/*
 * Copyright (c) 2023-2026 The ggml authors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef CANN_COMMON_H
#define CANN_COMMON_H

#include "../ggml-impl.h"
#include "../include/ggml-cann.h"
#include "../include/ggml.h"

#include <acl/acl.h>
#include <unistd.h>

#include <atomic>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <thread>
#include <vector>

#define MATRIX_ROW_PADDING    512
#define GGML_CANN_MAX_STREAMS 8

/**
 * @brief Handles CANN-related errors by printing an error message and
 *        terminating the program.
 * @param stmt The statement that caused the error.
 * @param func The function in which the error occurred.
 * @param file The file in which the error occurred.
 * @param line The line number at which the error occurred.
 * @param msg The error message.
 */
[[noreturn]] void ggml_cann_error(const char * stmt, const char * func, const char * file, int line, const char * msg);

/**
 * @brief Checks the result of a CANN function call and invokes the error
 *        handler if the call fails.
 * @param stmt The CANN function call to check.
 * @param success The success code that indicates the call was successful.
 * @param error_fn The function to call to retrieve the error message.
 */
#define ACL_CHECK_GEN(stmt, success, error_fn)                                \
    do {                                                                      \
        int err_code = (stmt);                                                \
        if (err_code != (success)) {                                          \
            ggml_cann_error(#stmt, __func__, __FILE__, __LINE__, error_fn()); \
        }                                                                     \
    } while (0);

#define ACL_CHECK(stmt) ACL_CHECK_GEN(stmt, 0, aclGetRecentErrMsg)

/**
 * @brief Contains information about CANN devices.
 */
// 类: ggml_cann_device_info
// 描述: ggml_cann_device_info类提供相关功能
// 用途: 用于处理ggml_cann_device_info相关的操作
// 类: ggml_cann_device_info
// 描述: ggml_cann_device_info类提供相关功能
// 用途: 用于处理ggml_cann_device_info相关的操作
    // 结构体: ggml_cann_device_info
    // 描述: ggml_cann_device_info结构体提供相关功能
    // 用途: 用于处理ggml_cann_device_info相关的操作
    // 结构体: ggml_cann_device_info
    // 描述: ggml_cann_device_info结构体提供相关功能
    // 用途: 用于处理ggml_cann_device_info相关的操作
    // 结构体: ggml_cann_device_info
    // 描述: ggml_cann_device_info结构体提供相关功能
    // 用途: 用于处理ggml_cann_device_info相关的操作
    // 结构体: ggml_cann_device_info
    // 描述: ggml_cann_device_info结构体提供相关功能
    // 用途: 用于处理ggml_cann_device_info相关的操作
struct ggml_cann_device_info {
    /**
     * @brief Number of CANN devices available.
     */
    int32_t device_count;

    /**
     * @brief Information about a single CANN device.
     */
    // 类: cann_device_info
    // 描述: cann_device_info类提供相关功能
    // 用途: 用于处理cann_device_info相关的操作
    // 类: cann_device_info
    // 描述: cann_device_info类提供相关功能
    // 用途: 用于处理cann_device_info相关的操作
    // 结构体: cann_device_info
    // 描述: cann_device_info结构体提供相关功能
    // 用途: 用于处理cann_device_info相关的操作
    // 结构体: cann_device_info
    // 描述: cann_device_info结构体提供相关功能
    // 用途: 用于处理cann_device_info相关的操作
    // 结构体: cann_device_info
    // 描述: cann_device_info结构体提供相关功能
    // 用途: 用于处理cann_device_info相关的操作
    // 结构体: cann_device_info
    // 描述: cann_device_info结构体提供相关功能
    // 用途: 用于处理cann_device_info相关的操作
    struct cann_device_info {
        int    cc;              /**< Compute capability.                   */
        size_t smpb;            /**< Maximum shared memory per block.      */
        bool   vmm;             /**< Virtual memory support.               */
        size_t vmm_granularity; /**< Granularity of virtual memory.        */
        size_t total_vram;      /**< Total video RAM available on the device. */
    };

    cann_device_info devices[GGML_CANN_MAX_DEVICES] = {}; /**< Array of CANN device information. */
};

const ggml_cann_device_info & ggml_cann_info();

// 函数: ggml_cann_set_device
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_cann_set_device
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void    ggml_cann_set_device(int32_t device);

std::optional<std::string> get_env_as_lowercase(const std::string & name);
// 函数: parse_bool
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: parse_bool
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool                       parse_bool(const std::string & value);
// 函数: parse_integer
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: parse_integer
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int                        parse_integer(const std::string & value);

/**
 * @brief Abstract base class for memory pools used by CANN.
 */
// 类: ggml_cann_pool
// 描述: ggml_cann_pool类提供相关功能
// 用途: 用于处理ggml_cann_pool相关的操作
// 类: ggml_cann_pool
// 描述: ggml_cann_pool类提供相关功能
// 用途: 用于处理ggml_cann_pool相关的操作
    // 结构体: ggml_cann_pool
    // 描述: ggml_cann_pool结构体提供相关功能
    // 用途: 用于处理ggml_cann_pool相关的操作
    // 结构体: ggml_cann_pool
    // 描述: ggml_cann_pool结构体提供相关功能
    // 用途: 用于处理ggml_cann_pool相关的操作
    // 结构体: ggml_cann_pool
    // 描述: ggml_cann_pool结构体提供相关功能
    // 用途: 用于处理ggml_cann_pool相关的操作
    // 结构体: ggml_cann_pool
    // 描述: ggml_cann_pool结构体提供相关功能
    // 用途: 用于处理ggml_cann_pool相关的操作
struct ggml_cann_pool {
    /**
     * @brief Virtual destructor for the memory pool.
     */
    virtual ~ggml_cann_pool() = default;

    /**
     * @brief Allocates memory from the pool.
     *
     * @param size         The size of the memory block to allocate.
     * @param actual_size  Pointer to a variable where the actual allocated size
     *                     will be stored.
     * @return             Pointer to the allocated memory block.
     */
    // 函数: alloc
    // 描述: 分配: 分配内存或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: alloc
    // 描述: 分配: 分配内存或资源
    // 参数: 无参数
    // 返回: 无返回值
    virtual void * alloc(size_t size, size_t * actual_size) = 0;

    /**
     * @brief Frees a previously allocated memory block.
     *
     * @param ptr   Pointer to the memory block to free.
     * @param size  Size of the memory block to free.
     * @note Note that all CANN opertors are running async. Make sure memory is
     *       still avaiable before this operator finished.
     */
    // 函数: free
    // 描述: 释放: 释放资源或销毁对象
    // 参数: 要释放的对象或资源
    // 返回: 无返回值
    // 函数: free
    // 描述: 释放: 释放资源或销毁对象
    // 参数: 要释放的对象或资源
    // 返回: 无返回值
    virtual void free(void * ptr, size_t size) = 0;
};

/**
 * @brief RAII wrapper for managing memory allocations from a CANN memory pool.
 */
// 类: ggml_cann_pool_alloc
// 描述: ggml_cann_pool_alloc类提供相关功能
// 用途: 用于处理ggml_cann_pool_alloc相关的操作
// 类: ggml_cann_pool_alloc
// 描述: ggml_cann_pool_alloc类提供相关功能
// 用途: 用于处理ggml_cann_pool_alloc相关的操作
    // 结构体: ggml_cann_pool_alloc
    // 描述: ggml_cann_pool_alloc结构体提供相关功能
    // 用途: 用于处理ggml_cann_pool_alloc相关的操作
    // 结构体: ggml_cann_pool_alloc
    // 描述: ggml_cann_pool_alloc结构体提供相关功能
    // 用途: 用于处理ggml_cann_pool_alloc相关的操作
    // 结构体: ggml_cann_pool_alloc
    // 描述: ggml_cann_pool_alloc结构体提供相关功能
    // 用途: 用于处理ggml_cann_pool_alloc相关的操作
    // 结构体: ggml_cann_pool_alloc
    // 描述: ggml_cann_pool_alloc结构体提供相关功能
    // 用途: 用于处理ggml_cann_pool_alloc相关的操作
struct ggml_cann_pool_alloc {
    ggml_cann_pool * pool        = nullptr; /**< Pointer to the memory pool. */
    void *           ptr         = nullptr; /**< Pointer to the allocated memory block. */
    size_t           actual_size = 0;       /**< Actual size of the allocated memory block. */

    /**
     * @brief Default constructor.
     */
    ggml_cann_pool_alloc() = default;

    /**
     * @brief Constructor that initializes the memory pool.
     * @param pool Reference to the memory pool.
     */
    // 函数: ggml_cann_pool_alloc
    // 描述: 分配: 分配内存或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ggml_cann_pool_alloc
    // 描述: 分配: 分配内存或资源
    // 参数: 无参数
    // 返回: 无返回值
    explicit ggml_cann_pool_alloc(ggml_cann_pool & pool) : pool(&pool) {}

    /**
     * @brief Constructor that initializes the memory pool and allocates memory.
     * @param pool Reference to the memory pool.
     * @param size Size of the memory block to allocate.
     */
    ggml_cann_pool_alloc(ggml_cann_pool & pool, size_t size) : pool(&pool) { alloc(size); }

    /**
     * @brief Destructor that frees the allocated memory block.
     */
    ~ggml_cann_pool_alloc() {
        if (ptr != nullptr) {
            pool->free(ptr, actual_size);
        }
    }

    /**
     * @brief Allocates memory from the pool.
     * @param size Size of the memory block to allocate.
     * @return Pointer to the allocated memory block.
     */
    // 函数: alloc
    // 描述: 分配: 分配内存或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: alloc
    // 描述: 分配: 分配内存或资源
    // 参数: 无参数
    // 返回: 无返回值
    void * alloc(size_t size) {
        GGML_ASSERT(pool != nullptr);
        GGML_ASSERT(ptr == nullptr);
        ptr = pool->alloc(size, &this->actual_size);
        return ptr;
    }

    /**
     * @brief Allocates memory from a specific memory pool.
     * @param pool Reference to the memory pool.
     * @param size Size of the memory block to allocate.
     * @return Pointer to the allocated memory block.
     */
    // 函数: alloc
    // 描述: 分配: 分配内存或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: alloc
    // 描述: 分配: 分配内存或资源
    // 参数: 无参数
    // 返回: 无返回值
    void * alloc(ggml_cann_pool & pool, size_t size) {
        this->pool = &pool;
        return alloc(size);
    }

    /**
     * @brief Gets the pointer to the allocated memory block.
     * @return Pointer to the allocated memory block.
     */
    // 函数: get
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: get
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void * get() { return ptr; }

    // Deleted copy constructor
    ggml_cann_pool_alloc(const ggml_cann_pool_alloc &) = delete;

    // Deleted move constructor
    ggml_cann_pool_alloc(ggml_cann_pool_alloc &&) = delete;

    // Deleted copy assignment operator
    ggml_cann_pool_alloc & operator=(const ggml_cann_pool_alloc &) = delete;

    // Deleted move assignment operator
    ggml_cann_pool_alloc & operator=(ggml_cann_pool_alloc &&) = delete;
};

#ifdef USE_ACL_GRAPH
// 类: ggml_graph_node_properties
// 描述: ggml_graph_node_properties类提供相关功能
// 用途: 用于处理ggml_graph_node_properties相关的操作
// 类: ggml_graph_node_properties
// 描述: ggml_graph_node_properties类提供相关功能
// 用途: 用于处理ggml_graph_node_properties相关的操作
    // 结构体: ggml_graph_node_properties
    // 描述: ggml_graph_node_properties结构体提供相关功能
    // 用途: 用于处理ggml_graph_node_properties相关的操作
    // 结构体: ggml_graph_node_properties
    // 描述: ggml_graph_node_properties结构体提供相关功能
    // 用途: 用于处理ggml_graph_node_properties相关的操作
    // 结构体: ggml_graph_node_properties
    // 描述: ggml_graph_node_properties结构体提供相关功能
    // 用途: 用于处理ggml_graph_node_properties相关的操作
    // 结构体: ggml_graph_node_properties
    // 描述: ggml_graph_node_properties结构体提供相关功能
    // 用途: 用于处理ggml_graph_node_properties相关的操作
struct ggml_graph_node_properties {
    // dst tensor
    void *  node_address;
    int64_t ne[GGML_MAX_DIMS];
    size_t  nb[GGML_MAX_DIMS];

    // src tensor
    void *  src_address[GGML_MAX_SRC];
    int64_t src_ne[GGML_MAX_SRC][GGML_MAX_DIMS];
    size_t  src_nb[GGML_MAX_SRC][GGML_MAX_DIMS];

    // op
    ggml_op node_op;
    int32_t op_params[GGML_MAX_OP_PARAMS / sizeof(int32_t)];

    /**
     * @brief Check if a ggml tensor node matches this property set.
     *
     * This function compares all relevant fields (address, op type, shape, source inputs, op params)
     * to determine whether the current node matches these previously recorded properties.
     *
     * @param node The current ggml tensor node.
     * @return true if all fields match (excluding GGML_OP_VIEW); false otherwise.
     */
    // 函数: has_matching_properties
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: has_matching_properties
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool has_matching_properties(ggml_tensor * node) {
        if (node->data != this->node_address && node->op != GGML_OP_VIEW) {
            return false;
        }

        if (node->op != this->node_op) {
            return false;
        }

        for (int i = 0; i < GGML_MAX_DIMS; i++) {
            if (node->ne[i] != this->ne[i]) {
                return false;
            }
            if (node->nb[i] != this->nb[i]) {
                return false;
            }
        }

        for (int i = 0; i < GGML_MAX_SRC; i++) {
            if (node->src[i]) {
                if (node->src[i]->data != this->src_address[i] && node->op != GGML_OP_VIEW) {
                    return false;
                }

                for (int d = 0; d < GGML_MAX_DIMS; d++) {
                    if (node->src[i]->ne[d] != this->src_ne[i][d]) {
                        return false;
                    }
                    if (node->src[i]->nb[d] != this->src_nb[i][d]) {
                        return false;
                    }
                }
            } else {
                if (this->src_address[i] != nullptr) {
                    return false;
                }
            }
        }

        if (node->op == GGML_OP_SCALE || node->op == GGML_OP_UNARY || node->op == GGML_OP_GLU) {
            return memcmp(this->op_params, node->op_params, GGML_MAX_OP_PARAMS) == 0;
        }
        return true;
    }
};

// 类: ggml_cann_graph
// 描述: ggml_cann_graph类提供相关功能
// 用途: 用于处理ggml_cann_graph相关的操作
// 类: ggml_cann_graph
// 描述: ggml_cann_graph类提供相关功能
// 用途: 用于处理ggml_cann_graph相关的操作
    // 结构体: ggml_cann_graph
    // 描述: ggml_cann_graph结构体提供相关功能
    // 用途: 用于处理ggml_cann_graph相关的操作
    // 结构体: ggml_cann_graph
    // 描述: ggml_cann_graph结构体提供相关功能
    // 用途: 用于处理ggml_cann_graph相关的操作
    // 结构体: ggml_cann_graph
    // 描述: ggml_cann_graph结构体提供相关功能
    // 用途: 用于处理ggml_cann_graph相关的操作
    // 结构体: ggml_cann_graph
    // 描述: ggml_cann_graph结构体提供相关功能
    // 用途: 用于处理ggml_cann_graph相关的操作
struct ggml_cann_graph {
    ~ggml_cann_graph() {
        if (graph != nullptr) {
            ACL_CHECK(aclmdlRIDestroy(graph));
        }
    }

    aclmdlRI graph = nullptr;

    std::vector<ggml_graph_node_properties> ggml_graph_properties;

    /**
     * @brief Create a new CANN graph from a ggml computation graph.
     *
     * This function creates a new ggml_cann_graph object and fills its node properties
     * (operation type, dimensions, strides, input sources, and operation parameters)
     * based on the current ggml computation graph.
     *
     * Each node in the ggml graph is mapped to a property entry in the new CANN graph:
     * - node address
     * - operation type
     * - shape (ne) and strides (nb)
     * - source tensor addresses
     * - operation parameters
     *
     * @param cgraph The current ggml computation graph.
     * @return Pointer to the newly created ggml_cann_graph object.
     */
    // 函数: create_from_cgraph
    // 描述: 创建: 创建新的对象或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: create_from_cgraph
    // 描述: 创建: 创建新的对象或资源
    // 参数: 无参数
    // 返回: 无返回值
    static ggml_cann_graph * create_from_cgraph(ggml_cgraph * cgraph) {
        ggml_cann_graph * new_graph = new ggml_cann_graph();
        new_graph->ggml_graph_properties.resize(cgraph->n_nodes);

        for (int node_idx = 0; node_idx < cgraph->n_nodes; ++node_idx) {
            ggml_tensor * node = cgraph->nodes[node_idx];
            auto &        prop = new_graph->ggml_graph_properties[node_idx];

            prop.node_address = node->data;
            prop.node_op      = node->op;

            std::copy_n(node->ne, GGML_MAX_DIMS, prop.ne);
            std::copy_n(node->nb, GGML_MAX_DIMS, prop.nb);

            for (int src = 0; src < GGML_MAX_SRC; ++src) {
                if (node->src[src]) {
                    prop.src_address[src] = node->src[src]->data;
                    std::copy_n(node->src[src]->ne, GGML_MAX_DIMS, prop.src_ne[src]);
                    std::copy_n(node->src[src]->nb, GGML_MAX_DIMS, prop.src_nb[src]);
                } else {
                    prop.src_address[src] = nullptr;
                    std::fill_n(prop.src_ne[src], GGML_MAX_DIMS, 0);
                    std::fill_n(prop.src_nb[src], GGML_MAX_DIMS, 0);
                }
            }

            memcpy(prop.op_params, node->op_params, GGML_MAX_OP_PARAMS);
        }

        return new_graph;
    }

    /**
     * @brief Check whether this CANN graph matches the given ggml computation graph.
     *
     * This function compares the number of nodes and each node's properties
     * (operation type, dimensions, strides, inputs, and operation parameters)
     * to determine whether this CANN graph matches the given ggml graph.
     *
     * @param cgraph The current ggml computation graph.
     * @return true if this CANN graph matches the ggml graph; false otherwise.
     */
    // 函数: matches_cgraph
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: matches_cgraph
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool matches_cgraph(ggml_cgraph * cgraph) {
        if (this->ggml_graph_properties.size() != static_cast<size_t>(cgraph->n_nodes)) {
            return false;
        }

        for (int i = 0; i < cgraph->n_nodes; ++i) {
            if (!this->ggml_graph_properties[i].has_matching_properties(cgraph->nodes[i])) {
                return false;
            }
        }

        return true;
    }
};

/**
 * @brief LRU cache for managing ggml_cann_graph objects.
 *
 * This class maintains a list of shared_ptr to ggml_cann_graph objects
 * and enforces a maximum capacity. It provides methods to push new graphs,
 * move existing graphs to the front (most recently used), and clear the cache.
 */
// 类: ggml_cann_graph_lru_cache
// 描述: ggml_cann_graph_lru_cache类提供相关功能
// 用途: 用于处理ggml_cann_graph_lru_cache相关的操作
// 类: ggml_cann_graph_lru_cache
// 描述: ggml_cann_graph_lru_cache类提供相关功能
// 用途: 用于处理ggml_cann_graph_lru_cache相关的操作
    // 结构体: ggml_cann_graph_lru_cache
    // 描述: ggml_cann_graph_lru_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_graph_lru_cache相关的操作
    // 结构体: ggml_cann_graph_lru_cache
    // 描述: ggml_cann_graph_lru_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_graph_lru_cache相关的操作
    // 结构体: ggml_cann_graph_lru_cache
    // 描述: ggml_cann_graph_lru_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_graph_lru_cache相关的操作
    // 结构体: ggml_cann_graph_lru_cache
    // 描述: ggml_cann_graph_lru_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_graph_lru_cache相关的操作
struct ggml_cann_graph_lru_cache {
    size_t capacity;                         /**< Maximum number of graphs in the cache. */

    std::list<ggml_cann_graph *> cache_list; /**< List storing cached graphs as raw pointers. */

    ggml_cann_graph_lru_cache() { capacity = parse_integer(get_env_as_lowercase("GGML_CANN_GRAPH_CACHE_CAPACITY").value_or("12")); }

    /**
     * @brief Push a new graph to the front of the cache.
     * If the cache exceeds capacity, the least recently used graph is deleted.
     * @param new_node Pointer to the new ggml_cann_graph to cache.
     *        Ownership is transferred to the cache (cache will delete it).
     */
    // 函数: push
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: push
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void push(ggml_cann_graph * new_node) {
        if (cache_list.size() >= capacity) {
            ggml_cann_graph * old = cache_list.back();
            cache_list.pop_back();
            delete old;  // free the old graph
        }
        cache_list.push_front(new_node);
    }

    /**
     * @brief Clear all graphs from the cache (also frees memory).
     */
    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    void clear() {
        for (auto ptr : cache_list) {
            delete ptr;
        }
        cache_list.clear();
    }

    /**
     * @brief Destructor that clears the cache and frees all cached graphs.
     */
    ~ggml_cann_graph_lru_cache() { clear(); }

    /**
     * @brief Find a cached CANN graph that matches the given ggml graph and move it to front.
     *
     * This function iterates through the cached CANN graphs stored in the LRU cache and
     * compares them against the given ggml computation graph. If a matching graph is found,
     * it is promoted to the front of the LRU cache and returned. Otherwise, the function
     * returns nullptr.
     *
     * @param cgraph The current ggml computation graph.
     * @return true if found; false otherwise.
     */
    // 函数: find_and_move_to_front
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: find_and_move_to_front
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool find_and_move_to_front(ggml_cgraph * cgraph) {
        for (auto & graph_ptr : this->cache_list) {
            if (graph_ptr->matches_cgraph(cgraph)) {
                cache_list.remove(graph_ptr);
                cache_list.push_front(graph_ptr);
                return true;
            }
        }
        return false;
    }
};
#endif  // USE_ACL_GRAPH

// 类: ggml_cann_rope_cache
// 描述: ggml_cann_rope_cache类提供相关功能
// 用途: 用于处理ggml_cann_rope_cache相关的操作
// 类: ggml_cann_rope_cache
// 描述: ggml_cann_rope_cache类提供相关功能
// 用途: 用于处理ggml_cann_rope_cache相关的操作
    // 结构体: ggml_cann_rope_cache
    // 描述: ggml_cann_rope_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_rope_cache相关的操作
    // 结构体: ggml_cann_rope_cache
    // 描述: ggml_cann_rope_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_rope_cache相关的操作
    // 结构体: ggml_cann_rope_cache
    // 描述: ggml_cann_rope_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_rope_cache相关的操作
    // 结构体: ggml_cann_rope_cache
    // 描述: ggml_cann_rope_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_rope_cache相关的操作
struct ggml_cann_rope_cache {
    ~ggml_cann_rope_cache() {
        if (theta_scale_cache) {
            ACL_CHECK(aclrtFree(theta_scale_cache));
        }
        if (sin_cache) {
            ACL_CHECK(aclrtFree(sin_cache));
        }
        if (cos_cache) {
            ACL_CHECK(aclrtFree(cos_cache));
        }
        if (position_select_index) {
            ACL_CHECK(aclrtFree(position_select_index));
        }
        if (theta_scale_exp_host) {
            free(theta_scale_exp_host);
        }
        if (position_select_index_host) {
            free(position_select_index_host);
        }
        if (yarn_ramp_cache) {
            ACL_CHECK(aclrtFree(yarn_ramp_cache));
        }
    }

    bool equal(int64_t theta_scale_length,
               int64_t position_length,
               float   ext_factor,
               float   theta_scale,
               float   freq_scale,
               float   attn_factor,
               bool    is_neox,
               bool    indep_sects,
               bool    mrope_used,
               bool    is_imrope,
               int     sections[4]) {
        return this->theta_scale_length == theta_scale_length && this->position_length == position_length &&
               this->ext_factor == ext_factor && this->theta_scale == theta_scale && this->freq_scale == freq_scale &&
               this->attn_factor == attn_factor && this->is_neox == is_neox && this->indep_sects == indep_sects &&
               this->mrope_used == mrope_used && this->is_imrope == is_imrope && this->sections[0] == sections[0] &&
               this->sections[1] == sections[1] && this->sections[2] == sections[2] && this->sections[3] == sections[3];
    }

    void set(int64_t theta_scale_length,
             int64_t position_length,
             float   ext_factor,
             float   theta_scale,
             float   freq_scale,
             float   attn_factor,
             bool    is_neox,
             bool    indep_sects,
             bool    mrope_used,
             bool    is_imrope,
             int     sections[4]) {
        this->theta_scale_length = theta_scale_length;
        this->position_length    = position_length;
        this->ext_factor         = ext_factor;
        this->theta_scale        = theta_scale;
        this->freq_scale         = freq_scale;
        this->attn_factor        = attn_factor;
        this->is_neox            = is_neox;
        this->indep_sects        = indep_sects;
        this->mrope_used         = mrope_used;
        this->is_imrope          = is_imrope;
        this->sections[0]        = sections[0];
        this->sections[1]        = sections[1];
        this->sections[2]        = sections[2];
        this->sections[3]        = sections[3];
    }

    // memory cache, prepare before inferencing.
    void *  theta_scale_cache          = nullptr;
    float * theta_scale_exp_host       = nullptr;
    int *   position_select_index_host = nullptr;
    void *  position_select_index      = nullptr;
    void *  yarn_ramp_cache            = nullptr;
    // sin/cos cache, used only to accelerate first layer on each device
    void *  sin_cache                  = nullptr;
    void *  cos_cache                  = nullptr;
    // Properties to check before reusing the sincos cache
    int64_t theta_scale_length         = 0;
    int64_t position_length            = 0;
    bool    cached                     = false;
    float   ext_factor                 = 0.0f;
    float   theta_scale                = 0.0f;
    float   freq_scale                 = 0.0f;
    float   attn_factor                = 0.0f;
    bool    is_neox                    = false;
    bool    indep_sects                = false;
    bool    mrope_used                 = false;
    int     sections[4]                = { 0, 0, 0, 0 };
    bool    is_imrope                  = false;
};

// 类: ggml_cann_tensor_cache
// 描述: ggml_cann_tensor_cache类提供相关功能
// 用途: 用于处理ggml_cann_tensor_cache相关的操作
// 类: ggml_cann_tensor_cache
// 描述: ggml_cann_tensor_cache类提供相关功能
// 用途: 用于处理ggml_cann_tensor_cache相关的操作
    // 结构体: ggml_cann_tensor_cache
    // 描述: ggml_cann_tensor_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_tensor_cache相关的操作
    // 结构体: ggml_cann_tensor_cache
    // 描述: ggml_cann_tensor_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_tensor_cache相关的操作
    // 结构体: ggml_cann_tensor_cache
    // 描述: ggml_cann_tensor_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_tensor_cache相关的操作
    // 结构体: ggml_cann_tensor_cache
    // 描述: ggml_cann_tensor_cache结构体提供相关功能
    // 用途: 用于处理ggml_cann_tensor_cache相关的操作
struct ggml_cann_tensor_cache {
    ~ggml_cann_tensor_cache() {
        if (cache != nullptr) {
            ACL_CHECK(aclrtFree(cache));
        }
    }

    void *  cache = nullptr;
    int64_t size  = 0;
};

/**
 * @brief Context for managing CANN backend operations.
 */
// 类: ggml_backend_cann_context
// 描述: ggml_backend_cann_context类提供相关功能
// 用途: 用于处理ggml_backend_cann_context相关的操作
// 类: ggml_backend_cann_context
// 描述: ggml_backend_cann_context类提供相关功能
// 用途: 用于处理ggml_backend_cann_context相关的操作
    // 结构体: ggml_backend_cann_context
    // 描述: ggml_backend_cann_context结构体提供相关功能
    // 用途: 用于处理ggml_backend_cann_context相关的操作
    // 结构体: ggml_backend_cann_context
    // 描述: ggml_backend_cann_context结构体提供相关功能
    // 用途: 用于处理ggml_backend_cann_context相关的操作
    // 结构体: ggml_backend_cann_context
    // 描述: ggml_backend_cann_context结构体提供相关功能
    // 用途: 用于处理ggml_backend_cann_context相关的操作
    // 结构体: ggml_backend_cann_context
    // 描述: ggml_backend_cann_context结构体提供相关功能
    // 用途: 用于处理ggml_backend_cann_context相关的操作
struct ggml_backend_cann_context {
    int32_t     device;               /**< Device ID. */
    std::string name;                 /**< Name of the device. */
    std::string description;          /**< Description of the device. */
    aclrtEvent  copy_event = nullptr; /**< Event for managing copy operations. */
#ifdef USE_ACL_GRAPH
    /// Cached CANN ACL graph used for executing the current ggml computation graph.
    ggml_cann_graph_lru_cache graph_lru_cache;
    bool                      acl_graph_mode = true;
#endif
    bool                   async_mode;
    // Rope Cache
    ggml_cann_rope_cache   rope_cache;
    // Constant Pool
    ggml_cann_tensor_cache rms_norm_one_tensor_cache;
    ggml_cann_tensor_cache rms_norm_zero_tensor_cache;

    aclrtStream streams[GGML_CANN_MAX_STREAMS] = { nullptr }; /**< Array of streams for the device. */

    /**
     * @brief Constructor for initializing the context with a given device.
     * @param device Device ID.
     */
    // 函数: ggml_backend_cann_context
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ggml_backend_cann_context
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit ggml_backend_cann_context(int device) : device(device), name("CANN" + std::to_string(device)) {
        ggml_cann_set_device(device);
        description = aclrtGetSocName();

#ifdef USE_ACL_GRAPH
        acl_graph_mode = parse_bool(get_env_as_lowercase("GGML_CANN_ACL_GRAPH").value_or("on"));
        GGML_LOG_INFO("%s: device %d execution mode is %s (%s)\n", __func__, device, acl_graph_mode ? "GRAPH" : "EAGER",
                      acl_graph_mode ? "acl graph enabled" : "acl graph disabled");
#endif
    }

    /**
     * @brief Destructor for cleaning up resources.
     */
    ~ggml_backend_cann_context() {
        ggml_cann_set_device(device);
        if (copy_event != nullptr) {
            ACL_CHECK(aclrtDestroyEvent(copy_event));
        }
        for (int i = 0; i < GGML_CANN_MAX_STREAMS; ++i) {
            if (streams[i] != nullptr) {
                ACL_CHECK(aclrtDestroyStream(streams[i]));
            }
        }
    }

    /**
     * @brief Get or create a stream for a given index.
     * @param stream Index of the stream.
     * @return The stream corresponding to the given index.
     */
    // 函数: stream
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: stream
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    aclrtStream stream(int stream) {
        if (streams[stream] == nullptr) {
            // If the device is not set here, destroying the stream later may cause a mismatch
            // between the thread contexts where the stream was created and destroyed.
            // However, I printed the device_id, thread_id, and stream, and they are all consistent.
            ACL_CHECK(aclrtSetDevice(device));
            ACL_CHECK(aclrtCreateStream(&streams[stream]));
        }
        return streams[stream];
    }

    /**
     * @brief Get or create the default stream (index 0).
     * @return The default stream.
     */
    // 函数: stream
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: stream
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    aclrtStream stream() { return stream(0); }

    // TODO: each stream should have a memory pool.
    std::unique_ptr<ggml_cann_pool> mem_pool; /**< Memory pool for the device. */

    /**
     * @brief Create a new memory pool for a given device.
     * @param device Device ID.
     * @return A unique pointer to the new memory pool.
     */
    static std::unique_ptr<ggml_cann_pool> new_pool_for_device(int device);

    /**
     * @brief Get or create the memory pool for the context.
     * @return Reference to the memory pool.
     */
    ggml_cann_pool & pool() {
        if (mem_pool == nullptr) {
            mem_pool = new_pool_for_device(device);
        }
        return *mem_pool;
    }
};

#endif  // CANN_COMMON_H
