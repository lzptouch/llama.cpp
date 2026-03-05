#pragma once

#include "ggml-impl.h"

#include <cassert>
#include <cstring>

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

// 类: apir_encoder
// 描述: apir_encoder类提供相关功能
// 用途: 用于处理apir_encoder相关的操作
// 类: apir_encoder
// 描述: apir_encoder类提供相关功能
// 用途: 用于处理apir_encoder相关的操作
    // 结构体: apir_encoder
    // 描述: apir_encoder结构体提供相关功能
    // 用途: 用于处理apir_encoder相关的操作
    // 结构体: apir_encoder
    // 描述: apir_encoder结构体提供相关功能
    // 用途: 用于处理apir_encoder相关的操作
    // 结构体: apir_encoder
    // 描述: apir_encoder结构体提供相关功能
    // 用途: 用于处理apir_encoder相关的操作
    // 结构体: apir_encoder
    // 描述: apir_encoder结构体提供相关功能
    // 用途: 用于处理apir_encoder相关的操作
struct apir_encoder {
    char *       cur;
    const char * start;
    const char * end;
    bool         fatal;
};

// 类: apir_decoder
// 描述: apir_decoder类提供相关功能
// 用途: 用于处理apir_decoder相关的操作
// 类: apir_decoder
// 描述: apir_decoder类提供相关功能
// 用途: 用于处理apir_decoder相关的操作
    // 结构体: apir_decoder
    // 描述: apir_decoder结构体提供相关功能
    // 用途: 用于处理apir_decoder相关的操作
    // 结构体: apir_decoder
    // 描述: apir_decoder结构体提供相关功能
    // 用途: 用于处理apir_decoder相关的操作
    // 结构体: apir_decoder
    // 描述: apir_decoder结构体提供相关功能
    // 用途: 用于处理apir_decoder相关的操作
    // 结构体: apir_decoder
    // 描述: apir_decoder结构体提供相关功能
    // 用途: 用于处理apir_decoder相关的操作
struct apir_decoder {
    const char * cur;
    const char * end;
    bool         fatal;
};

/*
 * new encoder and decoder
 */

// 函数: apir_new_decoder
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_new_decoder
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static apir_decoder apir_new_decoder(const char * ptr, size_t size) {
    apir_decoder dec = {
        .cur   = ptr,
        .end   = ptr + size,
        .fatal = false,
    };

    return dec;
}

// 函数: apir_new_encoder
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_new_encoder
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static apir_encoder apir_new_encoder(char * ptr, size_t size) {
    apir_encoder enc = {
        .cur   = ptr,
        .start = ptr,
        .end   = ptr + size,
        .fatal = false,
    };

    return enc;
}

/*
 * fatal flag handling
 */

// 函数: apir_encoder_reset_fatal
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encoder_reset_fatal
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encoder_reset_fatal(apir_encoder * enc) {
    enc->fatal = false;
}

// 函数: apir_encoder_set_fatal
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encoder_set_fatal
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encoder_set_fatal(apir_encoder * enc) {
    enc->fatal = true;
}

// 函数: apir_encoder_get_fatal
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encoder_get_fatal
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static inline bool apir_encoder_get_fatal(const apir_encoder * enc) {
    return enc->fatal;
}

// 函数: apir_decoder_reset_fatal
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decoder_reset_fatal
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decoder_reset_fatal(apir_decoder * dec) {
    dec->fatal = false;
}

// 函数: apir_decoder_set_fatal
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decoder_set_fatal
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decoder_set_fatal(apir_decoder * dec) {
    dec->fatal = true;
}

// 函数: apir_decoder_get_fatal
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decoder_get_fatal
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static inline bool apir_decoder_get_fatal(const apir_decoder * dec) {
    return dec->fatal;
}

/*
 * encode peek
 */

// 函数: apir_decoder_peek_internal
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decoder_peek_internal
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline bool apir_decoder_peek_internal(apir_decoder * dec, size_t size, void * val, size_t val_size) {
    assert(val_size <= size);

    if (unlikely(size > (size_t) (dec->end - dec->cur))) {
        GGML_LOG_ERROR("%s: reading too much from the decoder ...\n", __func__);
        apir_decoder_set_fatal(dec);
        memset(val, 0, val_size);
        return false;
    }

    /* we should not rely on the compiler to optimize away memcpy... */
    memcpy(val, dec->cur, val_size);
    return true;
}

// 函数: apir_decoder_peek
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decoder_peek
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decoder_peek(apir_decoder * dec, size_t size, void * val, size_t val_size) {
    apir_decoder_peek_internal(dec, size, val, val_size);
}

// 函数: apir_decoder_use_inplace
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decoder_use_inplace
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline const void * apir_decoder_use_inplace(apir_decoder * dec, size_t size) {
    if (unlikely(size > (size_t) (dec->end - dec->cur))) {
        GGML_LOG_ERROR("%s: reading too much from the decoder ...\n", __func__);
        apir_decoder_set_fatal(dec);
        return NULL;
    }
    const void * addr = dec->cur;
    dec->cur += size;

    return addr;
}

/*
 * read/write
 */

// 函数: apir_decoder_read
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decoder_read
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decoder_read(apir_decoder * dec, size_t size, void * val, size_t val_size) {
    if (apir_decoder_peek_internal(dec, size, val, val_size)) {
        dec->cur += size;
    }
}

// 函数: apir_encoder_write
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encoder_write
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline char * apir_encoder_write(apir_encoder * enc, size_t size, const void * val, size_t val_size) {
    assert(val_size <= size);
    assert(size <= ((size_t) (enc->end - enc->cur)));

    char * write_addr = enc->cur;
    /* we should not rely on the compiler to optimize away memcpy... */
    memcpy(write_addr, val, val_size);
    enc->cur += size;

    return write_addr;
}

/*
 * encode/decode
 */

// 函数: apir_decode
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode(apir_decoder * dec, size_t size, void * data, size_t data_size) {
    assert(size % 4 == 0);
    apir_decoder_read(dec, size, data, data_size);
}

// 函数: apir_encode
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode(apir_encoder * enc, size_t size, const void * data, size_t data_size) {
    assert(size % 4 == 0);
    apir_encoder_write(enc, size, data, data_size);
}

/*
 * typed encode/decode
 */

/* uint8_t */

// 函数: apir_encode_uint8_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_uint8_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_uint8_t(apir_encoder * enc, const uint8_t * val) {
    apir_encode(enc, sizeof(int), val, sizeof(*val));
}

// 函数: apir_decode_uint8_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_uint8_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_uint8_t(apir_decoder * dec, uint8_t * val) {
    apir_decode(dec, sizeof(int), val, sizeof(*val));
}

/* uint64_t */

// 函数: apir_encode_uint64_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_uint64_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_uint64_t(apir_encoder * enc, const uint64_t * val) {
    apir_encode(enc, 8, val, sizeof(*val));
}

// 函数: apir_decode_uint64_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_uint64_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_uint64_t(apir_decoder * dec, uint64_t * val) {
    apir_decode(dec, 8, val, sizeof(*val));
}

// 函数: apir_encode_uint64_t_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_uint64_t_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_uint64_t_array(apir_encoder * enc, const uint64_t * val, uint32_t count) {
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    apir_encode(enc, size, val, size);
}

// 函数: apir_decode_uint64_t_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_uint64_t_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_uint64_t_array(apir_decoder * dec, uint64_t * val, uint32_t count) {
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    apir_decode(dec, size, val, size);
}

// 函数: apir_decode_uint64_t_array_inplace
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_uint64_t_array_inplace
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline const uint64_t * apir_decode_uint64_t_array_inplace(apir_decoder * dec, uint32_t count) {
    return (uint64_t *) (uintptr_t) apir_decoder_use_inplace(dec, count * sizeof(uint64_t));
}

/* int32_t */

// 函数: apir_encode_int32_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_int32_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_int32_t(apir_encoder * enc, const int32_t * val) {
    apir_encode(enc, 4, val, sizeof(*val));
}

// 函数: apir_decode_int32_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_int32_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_int32_t(apir_decoder * dec, int32_t * val) {
    apir_decode(dec, 4, val, sizeof(*val));
}

// 函数: apir_encode_int32_t_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_int32_t_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_int32_t_array(apir_encoder * enc, const int32_t * val, uint32_t count) {
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    apir_encode(enc, size, val, size);
}

// 函数: apir_decode_int32_t_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_int32_t_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_int32_t_array(apir_decoder * dec, int32_t * val, uint32_t count) {
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    apir_decode(dec, size, val, size);
}

/* array size (uint64_t) */

// 函数: apir_encode_array_size
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_array_size
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_array_size(apir_encoder * enc, uint64_t size) {
    apir_encode_uint64_t(enc, &size);
}

// 函数: apir_decode_array_size
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_array_size
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline uint64_t apir_decode_array_size(apir_decoder * dec, uint64_t expected_size) {
    uint64_t size;
    apir_decode_uint64_t(dec, &size);
    if (size != expected_size) {
        GGML_LOG_ERROR("%s: Couldn't decode array from the decoder\n", __func__);
        apir_decoder_set_fatal(dec);
        size = 0;
    }
    return size;
}

// 函数: apir_decode_array_size_unchecked
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_array_size_unchecked
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline uint64_t apir_decode_array_size_unchecked(apir_decoder * dec) {
    uint64_t size;
    apir_decode_uint64_t(dec, &size);
    return size;
}

/* non-array pointer */

// 函数: apir_encode_simple_pointer
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_simple_pointer
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline bool apir_encode_simple_pointer(apir_encoder * enc, const void * val) {
    apir_encode_array_size(enc, val ? 1 : 0);
    return val;
}

// 函数: apir_decode_simple_pointer
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_simple_pointer
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline bool apir_decode_simple_pointer(apir_decoder * dec) {
    return apir_decode_array_size_unchecked(dec);
}

/* uint32_t */

// 函数: apir_encode_uint32_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_uint32_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_uint32_t(apir_encoder * enc, const uint32_t * val) {
    apir_encode(enc, 4, val, sizeof(*val));
}

// 函数: apir_decode_uint32_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_uint32_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_uint32_t(apir_decoder * dec, uint32_t * val) {
    apir_decode(dec, 4, val, sizeof(*val));
}

// 函数: apir_encode_uint32_t_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_uint32_t_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_uint32_t_array(apir_encoder * enc, const uint32_t * val, uint32_t count) {
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    apir_encode(enc, size, val, size);
}

// 函数: apir_decode_uint32_t_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_uint32_t_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_uint32_t_array(apir_decoder * dec, uint32_t * val, uint32_t count) {
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    apir_decode(dec, size, val, size);
}

/* size_t */

// 函数: apir_encode_size_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_size_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_size_t(apir_encoder * enc, const size_t * val) {
    const uint64_t tmp = *val;
    apir_encode_uint64_t(enc, &tmp);
}

// 函数: apir_decode_size_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_size_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_size_t(apir_decoder * dec, size_t * val) {
    uint64_t tmp;
    apir_decode_uint64_t(dec, &tmp);
    *val = tmp;
}

// 函数: apir_encode_size_t_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_size_t_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_size_t_array(apir_encoder * enc, const size_t * val, uint32_t count) {
    if (sizeof(size_t) == sizeof(uint64_t)) {
        apir_encode_uint64_t_array(enc, (const uint64_t *) val, count);
    } else {
        for (uint32_t i = 0; i < count; i++) {
            apir_encode_size_t(enc, &val[i]);
        }
    }
}

// 函数: apir_decode_size_t_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_size_t_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_size_t_array(apir_decoder * dec, size_t * val, uint32_t count) {
    if (sizeof(size_t) == sizeof(uint64_t)) {
        apir_decode_uint64_t_array(dec, (uint64_t *) val, count);
    } else {
        for (uint32_t i = 0; i < count; i++) {
            apir_decode_size_t(dec, &val[i]);
        }
    }
}

/* opaque blob */

// 函数: apir_encode_blob_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_blob_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_blob_array(apir_encoder * enc, const void * val, size_t size) {
    apir_encode(enc, (size + 3) & ~3, val, size);
}

// 函数: apir_decode_blob_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_blob_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_blob_array(apir_decoder * dec, void * val, size_t size) {
    apir_decode(dec, (size + 3) & ~3, val, size);
}

/* string */

// 函数: apir_encode_char_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_char_array
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_char_array(apir_encoder * enc, const char * val, size_t size) {
    assert(size && strlen(val) < size);
    apir_encode_blob_array(enc, val, size);
}

// 函数: apir_decode_char_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_char_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_char_array(apir_decoder * dec, char * val, size_t size) {
    apir_decode_blob_array(dec, val, size);
    if (size) {
        val[size - 1] = '\0';
    } else {
        GGML_LOG_ERROR("%s: Couldn't decode the blog array\n", __func__);
        apir_decoder_set_fatal(dec);
    }
}

/* (temp) buffer allocation */

// 函数: apir_decoder_alloc_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decoder_alloc_array
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void * apir_decoder_alloc_array(size_t size, size_t count) {
    size_t alloc_size;
    if (unlikely(__builtin_mul_overflow(size, count, &alloc_size))) {
        GGML_LOG_ERROR("%s: overflow in array allocation of %zu * %zu bytes\n", __func__, size, count);
        return NULL;
    }

    return malloc(alloc_size);
}

/* bool */

// 函数: apir_encode_bool_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_bool_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_bool_t(apir_encoder * enc, const bool * val) {
    apir_encode(enc, sizeof(int), val, sizeof(bool));
}

// 函数: apir_decode_bool_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_bool_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_bool_t(apir_decoder * dec, bool * val) {
    apir_decode(dec, sizeof(int), val, sizeof(bool));
}

/* apir_buffer_type_host_handle_t */

static inline void apir_encode_apir_buffer_type_host_handle_t(apir_encoder *                         enc,
                                                              const apir_buffer_type_host_handle_t * val) {
    apir_encode(enc, sizeof(apir_buffer_type_host_handle_t), val, sizeof(apir_buffer_type_host_handle_t));
}

static inline void apir_decode_apir_buffer_type_host_handle_t(apir_decoder *                   dec,
                                                              apir_buffer_type_host_handle_t * val) {
    apir_decode(dec, sizeof(apir_buffer_type_host_handle_t), val, sizeof(apir_buffer_type_host_handle_t));
}

/* apir_buffer_host_handle_t */

// 函数: apir_encode_apir_buffer_host_handle_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_apir_buffer_host_handle_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_apir_buffer_host_handle_t(apir_encoder * enc, const apir_buffer_host_handle_t * val) {
    apir_encode(enc, sizeof(apir_buffer_host_handle_t), val, sizeof(apir_buffer_host_handle_t));
}

// 函数: apir_decode_apir_buffer_host_handle_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_apir_buffer_host_handle_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_apir_buffer_host_handle_t(apir_decoder * dec, apir_buffer_host_handle_t * val) {
    apir_decode(dec, sizeof(apir_buffer_host_handle_t), val, sizeof(apir_buffer_host_handle_t));
}

/* uintptr_t */

// 函数: apir_encode_uintptr_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_encode_uintptr_t
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
static inline void apir_encode_uintptr_t(apir_encoder * enc, const uintptr_t * val) {
    apir_encode(enc, sizeof(*val), val, sizeof(*val));
}

// 函数: apir_decode_uintptr_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
// 函数: apir_decode_uintptr_t
// 描述: 解码: 解码数据或生成输出结果
// 参数: 无参数
// 返回: 无返回值
static inline void apir_decode_uintptr_t(apir_decoder * dec, uintptr_t * val) {
    apir_decode(dec, sizeof(*val), val, sizeof(*val));
}
