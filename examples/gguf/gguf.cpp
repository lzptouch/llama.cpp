// ============================================================================
// 文件: gguf.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/gguf/gguf.cpp
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

#include "ggml.h"
#include "gguf.h"

#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

#undef MIN
#undef MAX
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

template <typename T>
// 函数: to_string
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: to_string
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static std::string to_string(const T & val) {
    std::stringstream ss;
    ss << val;
    return ss.str();
}

// 函数: gguf_ex_write
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: gguf_ex_write
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool gguf_ex_write(const std::string & fname) {
    // 类: gguf_context
    // 描述: gguf_context类提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 类: gguf_context
    // 描述: gguf_context类提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    struct gguf_context * ctx = gguf_init_empty();

    gguf_set_val_u8  (ctx, "some.parameter.uint8",    0x12);
    gguf_set_val_i8  (ctx, "some.parameter.int8",    -0x13);
    gguf_set_val_u16 (ctx, "some.parameter.uint16",   0x1234);
    gguf_set_val_i16 (ctx, "some.parameter.int16",   -0x1235);
    gguf_set_val_u32 (ctx, "some.parameter.uint32",   0x12345678);
    gguf_set_val_i32 (ctx, "some.parameter.int32",   -0x12345679);
    gguf_set_val_f32 (ctx, "some.parameter.float32",  0.123456789f);
    gguf_set_val_u64 (ctx, "some.parameter.uint64",   0x123456789abcdef0ull);
    gguf_set_val_i64 (ctx, "some.parameter.int64",   -0x123456789abcdef1ll);
    gguf_set_val_f64 (ctx, "some.parameter.float64",  0.1234567890123456789);
    gguf_set_val_bool(ctx, "some.parameter.bool",     true);
    gguf_set_val_str (ctx, "some.parameter.string",   "hello world");

    gguf_set_arr_data(ctx, "some.parameter.arr.i16", GGUF_TYPE_INT16,   std::vector<int16_t>{ 1, 2, 3, 4, }.data(), 4);
    gguf_set_arr_data(ctx, "some.parameter.arr.f32", GGUF_TYPE_FLOAT32, std::vector<float>{ 3.145f, 2.718f, 1.414f, }.data(), 3);
    gguf_set_arr_str (ctx, "some.parameter.arr.str",                    std::vector<const char *>{ "hello", "world", "!" }.data(), 3);

    // 类: ggml_init_params
    // 描述: ggml_init_params类提供相关功能
    // 用途: 用于处理ggml_init_params相关的操作
    // 类: ggml_init_params
    // 描述: ggml_init_params类提供相关功能
    // 用途: 用于处理ggml_init_params相关的操作
    // 结构体: ggml_init_params
    // 描述: ggml_init_params结构体提供相关功能
    // 用途: 用于处理ggml_init_params相关的操作
    // 结构体: ggml_init_params
    // 描述: ggml_init_params结构体提供相关功能
    // 用途: 用于处理ggml_init_params相关的操作
    // 结构体: ggml_init_params
    // 描述: ggml_init_params结构体提供相关功能
    // 用途: 用于处理ggml_init_params相关的操作
    // 结构体: ggml_init_params
    // 描述: ggml_init_params结构体提供相关功能
    // 用途: 用于处理ggml_init_params相关的操作
    struct ggml_init_params params = {
        /*.mem_size   =*/ 128ull*1024ull*1024ull,
        /*.mem_buffer =*/ NULL,
        /*.no_alloc   =*/ false,
    };

    // 类: ggml_context
    // 描述: ggml_context类提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 类: ggml_context
    // 描述: ggml_context类提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    struct ggml_context * ctx_data = ggml_init(params);

    const int n_tensors = 10;

    // tensor infos
    for (int i = 0; i < n_tensors; ++i) {
        const std::string name = "tensor_" + to_string(i);

        int64_t ne[GGML_MAX_DIMS] = { 1 };
        int32_t n_dims = rand() % GGML_MAX_DIMS + 1;

        for (int j = 0; j < n_dims; ++j) {
            ne[j] = rand() % 10 + 1;
        }

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
        struct ggml_tensor * cur = ggml_new_tensor(ctx_data, GGML_TYPE_F32, n_dims, ne);
        ggml_set_name(cur, name.c_str());

        {
            float * data = (float *) cur->data;
            for (int j = 0; j < ggml_nelements(cur); ++j) {
                data[j] = 100 + i;
            }
        }

        gguf_add_tensor(ctx, cur);
    }

    gguf_write_to_file(ctx, fname.c_str(), false);

    printf("%s: wrote file '%s;\n", __func__, fname.c_str());

    ggml_free(ctx_data);
    gguf_free(ctx);

    return true;
}

// just read tensor info
// 函数: gguf_ex_read_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: gguf_ex_read_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool gguf_ex_read_0(const std::string & fname) {
    // 类: gguf_init_params
    // 描述: gguf_init_params类提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 类: gguf_init_params
    // 描述: gguf_init_params类提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 结构体: gguf_init_params
    // 描述: gguf_init_params结构体提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 结构体: gguf_init_params
    // 描述: gguf_init_params结构体提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 结构体: gguf_init_params
    // 描述: gguf_init_params结构体提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 结构体: gguf_init_params
    // 描述: gguf_init_params结构体提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    struct gguf_init_params params = {
        /*.no_alloc = */ false,
        /*.ctx      = */ NULL,
    };

    // 类: gguf_context
    // 描述: gguf_context类提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 类: gguf_context
    // 描述: gguf_context类提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    struct gguf_context * ctx = gguf_init_from_file(fname.c_str(), params);

    if (!ctx) {
        fprintf(stderr, "%s: failed to load '%s'\n", __func__, fname.c_str());
        return false;
    }

    printf("%s: version:      %d\n", __func__, gguf_get_version(ctx));
    printf("%s: alignment:   %zu\n", __func__, gguf_get_alignment(ctx));
    printf("%s: data offset: %zu\n", __func__, gguf_get_data_offset(ctx));

    // kv
    {
        const int n_kv = gguf_get_n_kv(ctx);

        printf("%s: n_kv: %d\n", __func__, n_kv);

        for (int i = 0; i < n_kv; ++i) {
            const char * key = gguf_get_key(ctx, i);

            printf("%s: kv[%d]: key = %s\n", __func__, i, key);
        }
    }

    // find kv string
    {
        const char * findkey = "some.parameter.string";

        const int keyidx = gguf_find_key(ctx, findkey);
        if (keyidx == -1) {
            printf("%s: find key: %s not found.\n", __func__, findkey);
        } else {
            const char * key_value = gguf_get_val_str(ctx, keyidx);
            printf("%s: find key: %s found, kv[%d] value = %s\n", __func__, findkey, keyidx, key_value);
        }
    }

    // tensor info
    {
        const int n_tensors = gguf_get_n_tensors(ctx);

        printf("%s: n_tensors: %d\n", __func__, n_tensors);

        for (int i = 0; i < n_tensors; ++i) {
            const char * name   = gguf_get_tensor_name  (ctx, i);
            const size_t size   = gguf_get_tensor_size  (ctx, i);
            const size_t offset = gguf_get_tensor_offset(ctx, i);

            printf("%s: tensor[%d]: name = %s, size = %zu, offset = %zu\n", __func__, i, name, size, offset);
        }
    }

    gguf_free(ctx);

    return true;
}

// read and create ggml_context containing the tensors and their data
// 函数: gguf_ex_read_1
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: gguf_ex_read_1
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool gguf_ex_read_1(const std::string & fname, bool check_data) {
    // 类: ggml_context
    // 描述: ggml_context类提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 类: ggml_context
    // 描述: ggml_context类提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    struct ggml_context * ctx_data = NULL;

    // 类: gguf_init_params
    // 描述: gguf_init_params类提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 类: gguf_init_params
    // 描述: gguf_init_params类提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 结构体: gguf_init_params
    // 描述: gguf_init_params结构体提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 结构体: gguf_init_params
    // 描述: gguf_init_params结构体提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 结构体: gguf_init_params
    // 描述: gguf_init_params结构体提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    // 结构体: gguf_init_params
    // 描述: gguf_init_params结构体提供相关功能
    // 用途: 用于处理gguf_init_params相关的操作
    struct gguf_init_params params = {
        /*.no_alloc = */ false,
        /*.ctx      = */ &ctx_data,
    };

    // 类: gguf_context
    // 描述: gguf_context类提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 类: gguf_context
    // 描述: gguf_context类提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    struct gguf_context * ctx = gguf_init_from_file(fname.c_str(), params);

    printf("%s: version:      %d\n", __func__, gguf_get_version(ctx));
    printf("%s: alignment:   %zu\n", __func__, gguf_get_alignment(ctx));
    printf("%s: data offset: %zu\n", __func__, gguf_get_data_offset(ctx));

    // kv
    {
        const int n_kv = gguf_get_n_kv(ctx);

        printf("%s: n_kv: %d\n", __func__, n_kv);

        for (int i = 0; i < n_kv; ++i) {
            const char * key = gguf_get_key(ctx, i);

            printf("%s: kv[%d]: key = %s\n", __func__, i, key);
        }
    }

    // tensor info
    {
        const int n_tensors = gguf_get_n_tensors(ctx);

        printf("%s: n_tensors: %d\n", __func__, n_tensors);

        for (int i = 0; i < n_tensors; ++i) {
            const char * name   = gguf_get_tensor_name  (ctx, i);
            const size_t size   = gguf_get_tensor_size  (ctx, i);
            const size_t offset = gguf_get_tensor_offset(ctx, i);
            const auto   type   = gguf_get_tensor_type  (ctx, i);

            const char * type_name  = ggml_type_name(type);
            const size_t type_size  = ggml_type_size(type);
            const size_t n_elements = size / type_size;

            printf("%s: tensor[%d]: name = %s, size = %zu, offset = %zu, type = %s, n_elts = %zu\n", __func__, i, name, size, offset, type_name, n_elements);
        }
    }

    // data
    {
        const int n_tensors = gguf_get_n_tensors(ctx);

        for (int i = 0; i < n_tensors; ++i) {
            printf("%s: reading tensor %d data\n", __func__, i);

            const char * name = gguf_get_tensor_name(ctx, i);

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
            struct ggml_tensor * cur = ggml_get_tensor(ctx_data, name);

            printf("%s: tensor[%d]: n_dims = %d, ne = (%d, %d, %d, %d), name = %s, data = %p\n",
                __func__, i, ggml_n_dims(cur), int(cur->ne[0]), int(cur->ne[1]), int(cur->ne[2]), int(cur->ne[3]), cur->name, cur->data);

            // print first 10 elements
            const float * data = (const float *) cur->data;

            printf("%s data[:10] : ", name);
            for (int j = 0; j < MIN(10, ggml_nelements(cur)); ++j) {
                printf("%f ", data[j]);
            }
            printf("\n\n");

            // check data
            if (check_data) {
                const float * data = (const float *) cur->data;
                for (int j = 0; j < ggml_nelements(cur); ++j) {
                    if (data[j] != 100 + i) {
                        fprintf(stderr, "%s: tensor[%d], data[%d]: found %f, expected %f\n", __func__, i, j, data[j], float(100 + i));
                        gguf_free(ctx);
                        return false;
                    }
                }
            }
        }
    }

    printf("%s: ctx_data size: %zu\n", __func__, ggml_get_mem_size(ctx_data));

    ggml_free(ctx_data);
    gguf_free(ctx);

    return true;
}

// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int main(int argc, char ** argv) {
    if (argc < 3) {
        printf("usage: %s data.gguf r|w [n]\n", argv[0]);
        printf("r: read data.gguf file\n");
        printf("w: write data.gguf file\n");
        printf("n: no check of tensor data\n");
        return -1;
    }
    bool check_data = true;
    if (argc == 4) {
        check_data = false;
    }

    srand(123456);

    const std::string fname(argv[1]);
    const std::string mode (argv[2]);

    GGML_ASSERT((mode == "r" || mode == "w") && "mode must be r or w");

    if (mode == "w") {
        GGML_ASSERT(gguf_ex_write(fname) && "failed to write gguf file");
    } else if (mode == "r") {
        GGML_ASSERT(gguf_ex_read_0(fname) && "failed to read gguf file");
        GGML_ASSERT(gguf_ex_read_1(fname, check_data) && "failed to read gguf file");
    }

    return 0;
}
