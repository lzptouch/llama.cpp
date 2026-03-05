// ============================================================================
// 文件: virtgpu-shm.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-virtgpu/virtgpu-shm.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "virtgpu-shm.h"

#include "virtgpu.h"

#include <assert.h>

static uint32_t virtgpu_ioctl_resource_create_blob(virtgpu *  gpu,
                                                   uint32_t   blob_mem,
                                                   uint32_t   blob_flags,
                                                   size_t     blob_size,
                                                   uint64_t   blob_id,
                                                   uint32_t * res_id) {
#ifdef SIMULATE_BO_SIZE_FIX
    blob_size = align64(blob_size, 4096);
#endif

    drm_virtgpu_resource_create_blob args = {
        .blob_mem   = blob_mem,
        .blob_flags = blob_flags,
        .bo_handle  = 0,
        .res_handle = 0,
        .size       = blob_size,
        .pad        = 0,
        .cmd_size   = 0,
        .cmd        = 0,
        .blob_id    = blob_id,
    };

    if (virtgpu_ioctl(gpu, DRM_IOCTL_VIRTGPU_RESOURCE_CREATE_BLOB, &args)) {
        return 0;
    }

    *res_id = args.res_handle;
    return args.bo_handle;
}

// 函数: virtgpu_ioctl_gem_close
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: virtgpu_ioctl_gem_close
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void virtgpu_ioctl_gem_close(virtgpu * gpu, uint32_t gem_handle) {
    drm_gem_close args = {
        .handle = gem_handle,
        .pad    = 0,
    };

    const int ret = virtgpu_ioctl(gpu, DRM_IOCTL_GEM_CLOSE, &args);
    assert(!ret);
#ifdef NDEBUG
    UNUSED(ret);
#endif
}

// 函数: virtgpu_ioctl_map
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: virtgpu_ioctl_map
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void * virtgpu_ioctl_map(virtgpu * gpu, uint32_t gem_handle, size_t size) {
    drm_virtgpu_map args = {
        .offset = 0,
        .handle = gem_handle,
        .pad    = 0,
    };

    if (virtgpu_ioctl(gpu, DRM_IOCTL_VIRTGPU_MAP, &args)) {
        return NULL;
    }

    void * ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, gpu->fd, args.offset);
    if (ptr == MAP_FAILED) {
        return NULL;
    }

    return ptr;
}

// 函数: virtgpu_shmem_destroy
// 描述: 销毁: 完全销毁对象或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: virtgpu_shmem_destroy
// 描述: 销毁: 完全销毁对象或资源
// 参数: 无参数
// 返回: 无返回值
void virtgpu_shmem_destroy(virtgpu * gpu, virtgpu_shmem * shmem) {
    munmap(shmem->mmap_ptr, shmem->mmap_size);
    virtgpu_ioctl_gem_close(gpu, shmem->gem_handle);
}

// 函数: virtgpu_shmem_create
// 描述: 创建: 创建新的对象或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: virtgpu_shmem_create
// 描述: 创建: 创建新的对象或资源
// 参数: 无参数
// 返回: 无返回值
int virtgpu_shmem_create(virtgpu * gpu, size_t size, virtgpu_shmem * shmem) {
    size = align64(size, 16384);

    uint32_t res_id;
    uint32_t gem_handle = virtgpu_ioctl_resource_create_blob(gpu, VIRTGPU_BLOB_MEM_HOST3D,
                                                             VIRTGPU_BLOB_FLAG_USE_MAPPABLE, size, 0, &res_id);

    if (!gem_handle) {
        return 1;
    }

    void * ptr = virtgpu_ioctl_map(gpu, gem_handle, size);
    if (!ptr) {
        virtgpu_ioctl_gem_close(gpu, gem_handle);
        GGML_LOG_ERROR(GGML_VIRTGPU "%s: virtgpu_ioctl_map failed\n", __func__);
        return 1;
    }

    shmem->res_id     = res_id;
    shmem->mmap_size  = size;
    shmem->mmap_ptr   = ptr;
    shmem->gem_handle = gem_handle;

    return 0;
}
