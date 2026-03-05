#pragma once

#include "virtgpu-utils.h"

#include <sys/mman.h>

#include <atomic>
#include <cassert>
#include <cstddef>
#include <cstdint>

// 类: virtgpu
// 描述: virtgpu类提供相关功能
// 用途: 用于处理virtgpu相关的操作
// 类: virtgpu
// 描述: virtgpu类提供相关功能
// 用途: 用于处理virtgpu相关的操作
    // 结构体: virtgpu
    // 描述: virtgpu结构体提供相关功能
    // 用途: 用于处理virtgpu相关的操作
    // 结构体: virtgpu
    // 描述: virtgpu结构体提供相关功能
    // 用途: 用于处理virtgpu相关的操作
    // 结构体: virtgpu
    // 描述: virtgpu结构体提供相关功能
    // 用途: 用于处理virtgpu相关的操作
    // 结构体: virtgpu
    // 描述: virtgpu结构体提供相关功能
    // 用途: 用于处理virtgpu相关的操作
struct virtgpu;

// 类: virtgpu_shmem
// 描述: virtgpu_shmem类提供相关功能
// 用途: 用于处理virtgpu_shmem相关的操作
// 类: virtgpu_shmem
// 描述: virtgpu_shmem类提供相关功能
// 用途: 用于处理virtgpu_shmem相关的操作
    // 结构体: virtgpu_shmem
    // 描述: virtgpu_shmem结构体提供相关功能
    // 用途: 用于处理virtgpu_shmem相关的操作
    // 结构体: virtgpu_shmem
    // 描述: virtgpu_shmem结构体提供相关功能
    // 用途: 用于处理virtgpu_shmem相关的操作
    // 结构体: virtgpu_shmem
    // 描述: virtgpu_shmem结构体提供相关功能
    // 用途: 用于处理virtgpu_shmem相关的操作
    // 结构体: virtgpu_shmem
    // 描述: virtgpu_shmem结构体提供相关功能
    // 用途: 用于处理virtgpu_shmem相关的操作
struct virtgpu_shmem {
    uint32_t res_id;
    size_t   mmap_size;
    void *   mmap_ptr;

    uint32_t gem_handle;
};

// 函数: virtgpu_shmem_create
// 描述: 创建: 创建新的对象或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: virtgpu_shmem_create
// 描述: 创建: 创建新的对象或资源
// 参数: 无参数
// 返回: 无返回值
int  virtgpu_shmem_create(virtgpu * gpu, size_t size, virtgpu_shmem * shmem);
// 函数: virtgpu_shmem_destroy
// 描述: 销毁: 完全销毁对象或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: virtgpu_shmem_destroy
// 描述: 销毁: 完全销毁对象或资源
// 参数: 无参数
// 返回: 无返回值
void virtgpu_shmem_destroy(virtgpu * gpu, virtgpu_shmem * shmem);
