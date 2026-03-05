#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <cstdio>

// 类: llama_file
// 描述: llama_file类提供相关功能
// 用途: 用于处理llama_file相关的操作
// 类: llama_file
// 描述: llama_file类提供相关功能
// 用途: 用于处理llama_file相关的操作
    // 结构体: llama_file
    // 描述: llama_file结构体提供相关功能
    // 用途: 用于处理llama_file相关的操作
    // 结构体: llama_file
    // 描述: llama_file结构体提供相关功能
    // 用途: 用于处理llama_file相关的操作
    // 结构体: llama_file
    // 描述: llama_file结构体提供相关功能
    // 用途: 用于处理llama_file相关的操作
    // 结构体: llama_file
    // 描述: llama_file结构体提供相关功能
    // 用途: 用于处理llama_file相关的操作
struct llama_file;
// 类: llama_mmap
// 描述: llama_mmap类提供相关功能
// 用途: 用于处理llama_mmap相关的操作
// 类: llama_mmap
// 描述: llama_mmap类提供相关功能
// 用途: 用于处理llama_mmap相关的操作
    // 结构体: llama_mmap
    // 描述: llama_mmap结构体提供相关功能
    // 用途: 用于处理llama_mmap相关的操作
    // 结构体: llama_mmap
    // 描述: llama_mmap结构体提供相关功能
    // 用途: 用于处理llama_mmap相关的操作
    // 结构体: llama_mmap
    // 描述: llama_mmap结构体提供相关功能
    // 用途: 用于处理llama_mmap相关的操作
    // 结构体: llama_mmap
    // 描述: llama_mmap结构体提供相关功能
    // 用途: 用于处理llama_mmap相关的操作
struct llama_mmap;
// 类: llama_mlock
// 描述: llama_mlock类提供相关功能
// 用途: 用于处理llama_mlock相关的操作
// 类: llama_mlock
// 描述: llama_mlock类提供相关功能
// 用途: 用于处理llama_mlock相关的操作
    // 结构体: llama_mlock
    // 描述: llama_mlock结构体提供相关功能
    // 用途: 用于处理llama_mlock相关的操作
    // 结构体: llama_mlock
    // 描述: llama_mlock结构体提供相关功能
    // 用途: 用于处理llama_mlock相关的操作
    // 结构体: llama_mlock
    // 描述: llama_mlock结构体提供相关功能
    // 用途: 用于处理llama_mlock相关的操作
    // 结构体: llama_mlock
    // 描述: llama_mlock结构体提供相关功能
    // 用途: 用于处理llama_mlock相关的操作
struct llama_mlock;

using llama_files  = std::vector<std::unique_ptr<llama_file>>;
using llama_mmaps  = std::vector<std::unique_ptr<llama_mmap>>;
using llama_mlocks = std::vector<std::unique_ptr<llama_mlock>>;

// 类: llama_file
// 描述: llama_file类提供相关功能
// 用途: 用于处理llama_file相关的操作
// 类: llama_file
// 描述: llama_file类提供相关功能
// 用途: 用于处理llama_file相关的操作
    // 结构体: llama_file
    // 描述: llama_file结构体提供相关功能
    // 用途: 用于处理llama_file相关的操作
    // 结构体: llama_file
    // 描述: llama_file结构体提供相关功能
    // 用途: 用于处理llama_file相关的操作
    // 结构体: llama_file
    // 描述: llama_file结构体提供相关功能
    // 用途: 用于处理llama_file相关的操作
    // 结构体: llama_file
    // 描述: llama_file结构体提供相关功能
    // 用途: 用于处理llama_file相关的操作
struct llama_file {
    llama_file(const char * fname, const char * mode, bool use_direct_io = false);
    ~llama_file();

    // 函数: tell
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tell
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t tell() const;
    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size() const;

    // 函数: file_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: file_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    int file_id() const; // fileno overload

    // 函数: seek
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seek
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void seek(size_t offset, int whence) const;

    // 函数: read_raw
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: read_raw
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void read_raw(void * ptr, size_t len);
    // 函数: read_raw_unsafe
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: read_raw_unsafe
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void read_raw_unsafe(void * ptr, size_t len);
    // 函数: read_aligned_chunk
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: read_aligned_chunk
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void read_aligned_chunk(void * dest, size_t size);
    // 函数: read_u32
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: read_u32
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t read_u32();

    // 函数: write_raw
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: write_raw
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void write_raw(const void * ptr, size_t len) const;
    // 函数: write_u32
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: write_u32
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void write_u32(uint32_t val) const;

    // 函数: read_alignment
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: read_alignment
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t read_alignment() const;
    // 函数: has_direct_io
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: has_direct_io
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool has_direct_io() const;
private:
    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    struct impl;
    std::unique_ptr<impl> pimpl;
};

// 类: llama_mmap
// 描述: llama_mmap类提供相关功能
// 用途: 用于处理llama_mmap相关的操作
// 类: llama_mmap
// 描述: llama_mmap类提供相关功能
// 用途: 用于处理llama_mmap相关的操作
    // 结构体: llama_mmap
    // 描述: llama_mmap结构体提供相关功能
    // 用途: 用于处理llama_mmap相关的操作
    // 结构体: llama_mmap
    // 描述: llama_mmap结构体提供相关功能
    // 用途: 用于处理llama_mmap相关的操作
    // 结构体: llama_mmap
    // 描述: llama_mmap结构体提供相关功能
    // 用途: 用于处理llama_mmap相关的操作
    // 结构体: llama_mmap
    // 描述: llama_mmap结构体提供相关功能
    // 用途: 用于处理llama_mmap相关的操作
struct llama_mmap {
    llama_mmap(const llama_mmap &) = delete;
    llama_mmap(struct llama_file * file, size_t prefetch = (size_t) -1, bool numa = false);
    ~llama_mmap();

    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size() const;
    // 函数: addr
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: addr
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void * addr() const;

    // 函数: unmap_fragment
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: unmap_fragment
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void unmap_fragment(size_t first, size_t last);

    static const bool SUPPORTED;

private:
    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    struct impl;
    std::unique_ptr<impl> pimpl;
};

// 类: llama_mlock
// 描述: llama_mlock类提供相关功能
// 用途: 用于处理llama_mlock相关的操作
// 类: llama_mlock
// 描述: llama_mlock类提供相关功能
// 用途: 用于处理llama_mlock相关的操作
    // 结构体: llama_mlock
    // 描述: llama_mlock结构体提供相关功能
    // 用途: 用于处理llama_mlock相关的操作
    // 结构体: llama_mlock
    // 描述: llama_mlock结构体提供相关功能
    // 用途: 用于处理llama_mlock相关的操作
    // 结构体: llama_mlock
    // 描述: llama_mlock结构体提供相关功能
    // 用途: 用于处理llama_mlock相关的操作
    // 结构体: llama_mlock
    // 描述: llama_mlock结构体提供相关功能
    // 用途: 用于处理llama_mlock相关的操作
struct llama_mlock {
    llama_mlock();
    ~llama_mlock();

    // 函数: init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    void init(void * ptr);
    // 函数: grow_to
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: grow_to
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void grow_to(size_t target_size);

    static const bool SUPPORTED;

private:
    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    struct impl;
    std::unique_ptr<impl> pimpl;
};

// 函数: llama_path_max
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llama_path_max
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t llama_path_max();
