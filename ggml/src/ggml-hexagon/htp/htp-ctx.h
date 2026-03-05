#ifndef HTP_CTX_H
#define HTP_CTX_H

#include "hex-dma.h"
#include "worker-pool.h"

#include <assert.h>
#include <dspqueue.h>
#include <stdatomic.h>
#include <stdint.h>

#define HTP_MAX_NTHREADS 10

// Main context for htp DSP backend
// 类: htp_context
// 描述: htp_context类提供相关功能
// 用途: 用于处理htp_context相关的操作
// 类: htp_context
// 描述: htp_context类提供相关功能
// 用途: 用于处理htp_context相关的操作
    // 结构体: htp_context
    // 描述: htp_context结构体提供相关功能
    // 用途: 用于处理htp_context相关的操作
    // 结构体: htp_context
    // 描述: htp_context结构体提供相关功能
    // 用途: 用于处理htp_context相关的操作
    // 结构体: htp_context
    // 描述: htp_context结构体提供相关功能
    // 用途: 用于处理htp_context相关的操作
    // 结构体: htp_context
    // 描述: htp_context结构体提供相关功能
    // 用途: 用于处理htp_context相关的操作
struct htp_context {
    dspqueue_t            queue;
    dma_queue *           dma[HTP_MAX_NTHREADS];
    worker_pool_context_t worker_pool;
    uint32_t              n_threads;

    int thread_id;
    int thread_prio;

    uint8_t * vtcm_base;
    size_t    vtcm_size;
    uint32_t  vtcm_rctx;

    atomic_bool vtcm_valid;
    atomic_bool vtcm_inuse;
    atomic_bool vtcm_needs_release;

    uint32_t opmask;
};

#endif /* HTP_CTX_H */
