#pragma once

#include <atomic>
#include <cassert>
#include <cerrno>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define unlikely(x) __builtin_expect(!!(x), 0)
#define likely(x)   __builtin_expect(!!(x), 1)

#ifndef UNUSED
#    define UNUSED(x) (void) (x)
#endif

/** Checks is a value is a power of two. Does not handle zero. */
#define IS_POT(v) (((v) & ((v) - 1)) == 0)

/** Checks is a value is a power of two. Zero handled. */
#define IS_POT_NONZERO(v) ((v) != 0 && IS_POT(v))

/** Align a value to a power of two */
#define ALIGN_POT(x, pot_align) (((x) + (pot_align) - 1) & ~((pot_align) - 1))

#define p_atomic_read(_v) __atomic_load_n((_v), __ATOMIC_ACQUIRE)

// 函数: util_is_power_of_two_nonzero64
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: util_is_power_of_two_nonzero64
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline bool util_is_power_of_two_nonzero64(uint64_t v) {
    return IS_POT_NONZERO(v);
}

// 函数: align64
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: align64
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline uint64_t align64(uint64_t value, uint64_t alignment) {
    assert(util_is_power_of_two_nonzero64(alignment));
    return ALIGN_POT(value, alignment);
}

// 类: list_head
// 描述: list_head类提供相关功能
// 用途: 用于处理list_head相关的操作
// 类: list_head
// 描述: list_head类提供相关功能
// 用途: 用于处理list_head相关的操作
    // 结构体: list_head
    // 描述: list_head结构体提供相关功能
    // 用途: 用于处理list_head相关的操作
    // 结构体: list_head
    // 描述: list_head结构体提供相关功能
    // 用途: 用于处理list_head相关的操作
    // 结构体: list_head
    // 描述: list_head结构体提供相关功能
    // 用途: 用于处理list_head相关的操作
    // 结构体: list_head
    // 描述: list_head结构体提供相关功能
    // 用途: 用于处理list_head相关的操作
struct list_head {
    list_head * prev;
    list_head * next;
};

// 类: util_sparse_array
// 描述: util_sparse_array类提供相关功能
// 用途: 用于处理util_sparse_array相关的操作
// 类: util_sparse_array
// 描述: util_sparse_array类提供相关功能
// 用途: 用于处理util_sparse_array相关的操作
    // 结构体: util_sparse_array
    // 描述: util_sparse_array结构体提供相关功能
    // 用途: 用于处理util_sparse_array相关的操作
    // 结构体: util_sparse_array
    // 描述: util_sparse_array结构体提供相关功能
    // 用途: 用于处理util_sparse_array相关的操作
    // 结构体: util_sparse_array
    // 描述: util_sparse_array结构体提供相关功能
    // 用途: 用于处理util_sparse_array相关的操作
    // 结构体: util_sparse_array
    // 描述: util_sparse_array结构体提供相关功能
    // 用途: 用于处理util_sparse_array相关的操作
struct util_sparse_array {
    size_t   elem_size;
    unsigned node_size_log2;

    uintptr_t root;
};

// 函数: util_sparse_array_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: util_sparse_array_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void * util_sparse_array_get(util_sparse_array * arr, uint64_t idx);
// 函数: util_sparse_array_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: util_sparse_array_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
void   util_sparse_array_init(util_sparse_array * arr, size_t elem_size, size_t node_size);

// 函数: os_time_sleep
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: os_time_sleep
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
inline void os_time_sleep(int64_t usecs) {
    timespec time;
    time.tv_sec  = usecs / 1000000;
    time.tv_nsec = (usecs % 1000000) * 1000;
    while (clock_nanosleep(CLOCK_MONOTONIC, 0, &time, &time) == EINTR)
        ;
}

// 类: timer_data
// 描述: timer_data类提供相关功能
// 用途: 用于处理timer_data相关的操作
// 类: timer_data
// 描述: timer_data类提供相关功能
// 用途: 用于处理timer_data相关的操作
    // 结构体: timer_data
    // 描述: timer_data结构体提供相关功能
    // 用途: 用于处理timer_data相关的操作
    // 结构体: timer_data
    // 描述: timer_data结构体提供相关功能
    // 用途: 用于处理timer_data相关的操作
    // 结构体: timer_data
    // 描述: timer_data结构体提供相关功能
    // 用途: 用于处理timer_data相关的操作
    // 结构体: timer_data
    // 描述: timer_data结构体提供相关功能
    // 用途: 用于处理timer_data相关的操作
struct timer_data {
    long long start;
    long long total;
    long long count;
};

// 函数: start_timer
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: start_timer
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline void start_timer(timer_data * timer) {
    timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    timer->start = (long long) ts.tv_sec * 1000000000LL + ts.tv_nsec;
}

// returns the duration in ns
static inline long long stop_timer(timer_data * timer) {
    timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    long long timer_end = (long long) ts.tv_sec * 1000000000LL + ts.tv_nsec;

    long long duration = (timer_end - timer->start);
    timer->total += duration;
    timer->count += 1;

    return duration;
}
