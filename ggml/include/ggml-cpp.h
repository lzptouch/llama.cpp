#pragma once

#ifndef __cplusplus
#error "This header is for C++ only"
#endif

#include "ggml.h"
#include "ggml-alloc.h"
#include "ggml-backend.h"
#include "gguf.h"
#include <memory>

// Smart pointers for ggml types

// ggml

// 类: ggml_context_deleter
// 描述: ggml_context_deleter类提供相关功能
// 用途: 用于处理ggml_context_deleter相关的操作
// 类: ggml_context_deleter
// 描述: ggml_context_deleter类提供相关功能
// 用途: 用于处理ggml_context_deleter相关的操作
    // 结构体: ggml_context_deleter
    // 描述: ggml_context_deleter结构体提供相关功能
    // 用途: 用于处理ggml_context_deleter相关的操作
    // 结构体: ggml_context_deleter
    // 描述: ggml_context_deleter结构体提供相关功能
    // 用途: 用于处理ggml_context_deleter相关的操作
    // 结构体: ggml_context_deleter
    // 描述: ggml_context_deleter结构体提供相关功能
    // 用途: 用于处理ggml_context_deleter相关的操作
    // 结构体: ggml_context_deleter
    // 描述: ggml_context_deleter结构体提供相关功能
    // 用途: 用于处理ggml_context_deleter相关的操作
struct ggml_context_deleter { void operator()(ggml_context * ctx) { ggml_free(ctx); } };
// 类: gguf_context_deleter
// 描述: gguf_context_deleter类提供相关功能
// 用途: 用于处理gguf_context_deleter相关的操作
// 类: gguf_context_deleter
// 描述: gguf_context_deleter类提供相关功能
// 用途: 用于处理gguf_context_deleter相关的操作
    // 结构体: gguf_context_deleter
    // 描述: gguf_context_deleter结构体提供相关功能
    // 用途: 用于处理gguf_context_deleter相关的操作
    // 结构体: gguf_context_deleter
    // 描述: gguf_context_deleter结构体提供相关功能
    // 用途: 用于处理gguf_context_deleter相关的操作
    // 结构体: gguf_context_deleter
    // 描述: gguf_context_deleter结构体提供相关功能
    // 用途: 用于处理gguf_context_deleter相关的操作
    // 结构体: gguf_context_deleter
    // 描述: gguf_context_deleter结构体提供相关功能
    // 用途: 用于处理gguf_context_deleter相关的操作
struct gguf_context_deleter { void operator()(gguf_context * ctx) { gguf_free(ctx); } };

typedef std::unique_ptr<ggml_context, ggml_context_deleter> ggml_context_ptr;
typedef std::unique_ptr<gguf_context, gguf_context_deleter> gguf_context_ptr;

// ggml-alloc

// 类: ggml_gallocr_deleter
// 描述: ggml_gallocr_deleter类提供相关功能
// 用途: 用于处理ggml_gallocr_deleter相关的操作
// 类: ggml_gallocr_deleter
// 描述: ggml_gallocr_deleter类提供相关功能
// 用途: 用于处理ggml_gallocr_deleter相关的操作
    // 结构体: ggml_gallocr_deleter
    // 描述: ggml_gallocr_deleter结构体提供相关功能
    // 用途: 用于处理ggml_gallocr_deleter相关的操作
    // 结构体: ggml_gallocr_deleter
    // 描述: ggml_gallocr_deleter结构体提供相关功能
    // 用途: 用于处理ggml_gallocr_deleter相关的操作
    // 结构体: ggml_gallocr_deleter
    // 描述: ggml_gallocr_deleter结构体提供相关功能
    // 用途: 用于处理ggml_gallocr_deleter相关的操作
    // 结构体: ggml_gallocr_deleter
    // 描述: ggml_gallocr_deleter结构体提供相关功能
    // 用途: 用于处理ggml_gallocr_deleter相关的操作
struct ggml_gallocr_deleter { void operator()(ggml_gallocr_t galloc) { ggml_gallocr_free(galloc); } };

typedef std::unique_ptr<ggml_gallocr, ggml_gallocr_deleter> ggml_gallocr_ptr;

// ggml-backend

// 类: ggml_backend_deleter
// 描述: ggml_backend_deleter类提供相关功能
// 用途: 用于处理ggml_backend_deleter相关的操作
// 类: ggml_backend_deleter
// 描述: ggml_backend_deleter类提供相关功能
// 用途: 用于处理ggml_backend_deleter相关的操作
    // 结构体: ggml_backend_deleter
    // 描述: ggml_backend_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_deleter相关的操作
    // 结构体: ggml_backend_deleter
    // 描述: ggml_backend_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_deleter相关的操作
    // 结构体: ggml_backend_deleter
    // 描述: ggml_backend_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_deleter相关的操作
    // 结构体: ggml_backend_deleter
    // 描述: ggml_backend_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_deleter相关的操作
struct ggml_backend_deleter        { void operator()(ggml_backend_t backend)       { ggml_backend_free(backend); } };
// 类: ggml_backend_buffer_deleter
// 描述: ggml_backend_buffer_deleter类提供相关功能
// 用途: 用于处理ggml_backend_buffer_deleter相关的操作
// 类: ggml_backend_buffer_deleter
// 描述: ggml_backend_buffer_deleter类提供相关功能
// 用途: 用于处理ggml_backend_buffer_deleter相关的操作
    // 结构体: ggml_backend_buffer_deleter
    // 描述: ggml_backend_buffer_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_buffer_deleter相关的操作
    // 结构体: ggml_backend_buffer_deleter
    // 描述: ggml_backend_buffer_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_buffer_deleter相关的操作
    // 结构体: ggml_backend_buffer_deleter
    // 描述: ggml_backend_buffer_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_buffer_deleter相关的操作
    // 结构体: ggml_backend_buffer_deleter
    // 描述: ggml_backend_buffer_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_buffer_deleter相关的操作
struct ggml_backend_buffer_deleter { void operator()(ggml_backend_buffer_t buffer) { ggml_backend_buffer_free(buffer); } };
// 类: ggml_backend_event_deleter
// 描述: ggml_backend_event_deleter类提供相关功能
// 用途: 用于处理ggml_backend_event_deleter相关的操作
// 类: ggml_backend_event_deleter
// 描述: ggml_backend_event_deleter类提供相关功能
// 用途: 用于处理ggml_backend_event_deleter相关的操作
    // 结构体: ggml_backend_event_deleter
    // 描述: ggml_backend_event_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_event_deleter相关的操作
    // 结构体: ggml_backend_event_deleter
    // 描述: ggml_backend_event_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_event_deleter相关的操作
    // 结构体: ggml_backend_event_deleter
    // 描述: ggml_backend_event_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_event_deleter相关的操作
    // 结构体: ggml_backend_event_deleter
    // 描述: ggml_backend_event_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_event_deleter相关的操作
struct ggml_backend_event_deleter  { void operator()(ggml_backend_event_t event)   { ggml_backend_event_free(event); } };
// 类: ggml_backend_sched_deleter
// 描述: ggml_backend_sched_deleter类提供相关功能
// 用途: 用于处理ggml_backend_sched_deleter相关的操作
// 类: ggml_backend_sched_deleter
// 描述: ggml_backend_sched_deleter类提供相关功能
// 用途: 用于处理ggml_backend_sched_deleter相关的操作
    // 结构体: ggml_backend_sched_deleter
    // 描述: ggml_backend_sched_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_sched_deleter相关的操作
    // 结构体: ggml_backend_sched_deleter
    // 描述: ggml_backend_sched_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_sched_deleter相关的操作
    // 结构体: ggml_backend_sched_deleter
    // 描述: ggml_backend_sched_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_sched_deleter相关的操作
    // 结构体: ggml_backend_sched_deleter
    // 描述: ggml_backend_sched_deleter结构体提供相关功能
    // 用途: 用于处理ggml_backend_sched_deleter相关的操作
struct ggml_backend_sched_deleter  { void operator()(ggml_backend_sched_t sched)   { ggml_backend_sched_free(sched); } };

typedef std::unique_ptr<ggml_backend,        ggml_backend_deleter>        ggml_backend_ptr;
typedef std::unique_ptr<ggml_backend_buffer, ggml_backend_buffer_deleter> ggml_backend_buffer_ptr;
typedef std::unique_ptr<ggml_backend_event,  ggml_backend_event_deleter>  ggml_backend_event_ptr;
typedef std::unique_ptr<ggml_backend_sched,  ggml_backend_sched_deleter>  ggml_backend_sched_ptr;
