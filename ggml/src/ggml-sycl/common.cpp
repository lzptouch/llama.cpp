//
// MIT license
// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: MIT
//

//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//

#include "common.hpp"

#include "ggml-backend-impl.h"
#include "ggml-impl.h"

// 函数: get_current_device_id
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
// 函数: get_current_device_id
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
int get_current_device_id() {
  return dpct::dev_mgr::instance().current_device_id();
}

void* ggml_sycl_host_malloc(size_t size) try {
  if (getenv("GGML_SYCL_NO_PINNED") != nullptr) {
    return nullptr;
  }

  void* ptr = nullptr;
  // allow to use dpct::get_in_order_queue() for host malloc
  dpct::err0 err = CHECK_TRY_ERROR(
      ptr = (void*)sycl::malloc_host(size, dpct::get_in_order_queue()));

  if (err != 0) {
    // clear the error
    GGML_LOG_ERROR("WARNING: failed to allocate %.2f MB of pinned memory: %s\n", size / 1024.0 / 1024.0,    "syclGetErrorString is not supported");
    return nullptr;
  }

  return ptr;
} catch (sycl::exception const& exc) {
  std::cerr << exc.what() << "Exception caught at file:" << __FILE__
            << ", line:" << __LINE__ << std::endl;
  std::exit(1);
}

// 函数: ggml_sycl_host_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_sycl_host_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void ggml_sycl_host_free(void* ptr) try {
  // allow to use dpct::get_in_order_queue() for host malloc
  SYCL_CHECK(CHECK_TRY_ERROR(sycl::free(ptr, dpct::get_in_order_queue())));
} catch (sycl::exception const& exc) {
  std::cerr << exc.what() << "Exception caught at file:" << __FILE__
            << ", line:" << __LINE__ << std::endl;
  std::exit(1);
}

// 函数: gpu_has_xmx
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: gpu_has_xmx
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool gpu_has_xmx(sycl::device &dev) {
    return dev.has(sycl::aspect::ext_intel_matrix);
}

// 函数: downsample_sycl_global_range
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
// 函数: downsample_sycl_global_range
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
int64_t downsample_sycl_global_range(int64_t accumulate_block_num, int64_t block_size) {
  const int64_t max_range = std::numeric_limits<int>::max();
  int64_t sycl_down_blk_size = block_size;
  int64_t global_range = accumulate_block_num * sycl_down_blk_size;
  while(global_range > max_range) {
      sycl_down_blk_size /= 2;
      global_range = accumulate_block_num * sycl_down_blk_size;
  }
  return sycl_down_blk_size;
}

// 函数: release_extra_gpu
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: release_extra_gpu
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void release_extra_gpu(ggml_tensor_extra_gpu * extra, std::vector<queue_ptr> streams) {
    for (int i = 0; i < ggml_sycl_info().device_count; ++i) {
        for (int64_t is = 0; is < GGML_SYCL_MAX_STREAMS; ++is) {
            if (extra->events[i][is] != nullptr) {
                SYCL_CHECK(CHECK_TRY_ERROR(dpct::destroy_event(extra->events[i][is])));
            }
        }
        if (extra->data_device[i] != nullptr && streams.size()>0) {
            ggml_sycl_set_device(i);
            SYCL_CHECK(
                CHECK_TRY_ERROR(sycl::free(extra->data_device[i], *(streams[i]))));
        }
    }
    delete extra;
}
