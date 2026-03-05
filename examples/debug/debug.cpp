// ============================================================================
// 文件: debug.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/debug/debug.cpp
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

#include "debug.h"
#include "arg.h"
#include "common.h"
#include "log.h"
#include "llama.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <regex>

// 函数: print_usage
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: print_usage
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void print_usage(int /*argc*/, char ** argv) {
    const std::string usage_template = R"(
        example usage:

          Print tensors:

          {prog} -m model.gguf -p "Hello my name is" --verbose

          The tensors to be printed can be filtered with --tensor-filter option.

          Save logits/embeddings:

          {prog} -m model.gguf -p "Hello my name is" --save-logits

          Add --embedding to save embeddings)" "\n";

    // Fix the source code indentation above that is introduced by the raw string literal.
    std::string usage = std::regex_replace(usage_template, std::regex("\\n {8}"), "\n");
    usage = std::regex_replace(usage, std::regex("\\{prog\\}"), argv[0]);
    LOG("%s\n", usage.c_str());
}

// 函数: has_pooling
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: has_pooling
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool has_pooling(llama_context * ctx) {
    switch (llama_pooling_type(ctx)) {
        case LLAMA_POOLING_TYPE_NONE:
        case LLAMA_POOLING_TYPE_UNSPECIFIED:
            return false;
        default:
            return true;
    }
}

// 类: output_data
// 描述: output_data类提供相关功能
// 用途: 用于处理output_data相关的操作
// 类: output_data
// 描述: output_data类提供相关功能
// 用途: 用于处理output_data相关的操作
    // 结构体: output_data
    // 描述: output_data结构体提供相关功能
    // 用途: 用于处理output_data相关的操作
    // 结构体: output_data
    // 描述: output_data结构体提供相关功能
    // 用途: 用于处理output_data相关的操作
    // 结构体: output_data
    // 描述: output_data结构体提供相关功能
    // 用途: 用于处理output_data相关的操作
    // 结构体: output_data
    // 描述: output_data结构体提供相关功能
    // 用途: 用于处理output_data相关的操作
struct output_data {
    float *                  data_ptr    = nullptr;
    int                      data_size   = 0;
    std::string              type_suffix;
    std::vector<float>       embd_norm;
    std::string              prompt;
    std::vector<llama_token> tokens;

    output_data(llama_context * ctx, const llama_model * model, const common_params & params) {
        const llama_vocab * vocab = llama_model_get_vocab(model);
        const bool add_bos = llama_vocab_get_add_bos(vocab);

        tokens = common_tokenize(ctx, params.prompt, add_bos);
        prompt = params.prompt;

        if (params.embedding) {
            const int n_embd       = llama_model_n_embd_out(model);
            const bool pooling     = has_pooling(ctx);
            const int n_embd_count = pooling ? 1 : tokens.size();
            const int n_floats     = n_embd * n_embd_count;

            float * embd_raw = pooling ? llama_get_embeddings_seq(ctx, 0) : llama_get_embeddings(ctx);
            if (embd_raw == nullptr) {
                throw std::runtime_error("failed to get embeddings from the model");
            }

            LOG_DBG("pooling_enabled: %s\n", pooling ? "true" : "false");
            LOG_DBG("n_embd: %d\n", n_embd);
            LOG_DBG("n_floats: %d\n", n_floats);
            LOG_DBG("n_embd_count: %d\n", n_embd_count);

            data_ptr    = embd_raw;
            data_size   = n_floats;
            type_suffix = "-embeddings";

            if (params.embd_normalize >= 0) {
                embd_norm.resize(n_floats);
                for (int i = 0; i < n_embd_count; i++) {
                    common_embd_normalize(embd_raw+i*n_embd, embd_norm.data()+i*n_embd, n_embd, params.embd_normalize);
                }
                data_ptr = embd_norm.data();
            }
        } else {
            const float * logits = llama_get_logits_ith(ctx, tokens.size() - 1);
            const int n_logits = llama_vocab_n_tokens(vocab);

            data_ptr = const_cast<float*>(logits);
            data_size = n_logits;
            type_suffix = "";
        }
    }
};

// 函数: save_output_data
// 描述: 保存: 保存数据到文件或内存
// 参数: 无参数
// 返回: 无返回值
// 函数: save_output_data
// 描述: 保存: 保存数据到文件或内存
// 参数: 无参数
// 返回: 无返回值
static void save_output_data(const output_data & output, const std::string & model_name, const std::string & output_dir) {
    std::filesystem::create_directory(output_dir);
    auto base_path = std::filesystem::path{output_dir} / ("llamacpp-" + model_name + output.type_suffix);

    // Save logits/embeddings to binary file.
    {
        std::filesystem::path filepath{base_path.string() + ".bin"};
        std::ofstream file{filepath, std::ios::binary};
        if (!file) {
            throw std::runtime_error("failed to open binary output file: " + filepath.string());
        }
        file.write(reinterpret_cast<const char*>(output.data_ptr), output.data_size * sizeof(float));
        LOG("Data saved to %s\n", filepath.c_str());
    }

    // Save logits/embeddings to text file.
    {
        std::filesystem::path filepath{base_path.string() + ".txt"};
        std::ofstream file{filepath};
        if (!file) {
            throw std::runtime_error("failed to open text output file: " + filepath.string());
        }
        for (int i = 0; i < output.data_size; i++) {
            file << i << ": " << output.data_ptr[i] << '\n';
        }
        LOG("Data saved to %s\n", filepath.c_str());
    }

    // Save prompt and tokens to text file.
    {
        std::filesystem::path filepath{base_path.string() + "-prompt.txt"};
        std::ofstream file{filepath};
        if (!file) {
            throw std::runtime_error("failed to open prompt output file: " + filepath.string());
        }

        file << "prompt: " << output.prompt << '\n';
        file << "n_tokens: " << output.tokens.size() << '\n';

        file << "token ids: ";
        for (size_t i = 0; i < output.tokens.size(); i++) {
            file << output.tokens[i];
            if (i + 1 < output.tokens.size()) {
                file << ", ";
            }
        }
        file << '\n';
        LOG("Prompt saved to %s\n", filepath.c_str());
    }

    // Save token ids to binary file.
    {
        std::filesystem::path filepath{base_path.string() + "-tokens.bin"};
        std::ofstream file{filepath, std::ios::binary};
        if (!file) {
            throw std::runtime_error("failed to open tokens binary file: " + filepath.string());
        }
        file.write(reinterpret_cast<const char*>(output.tokens.data()), output.tokens.size() * sizeof(llama_token));
        LOG("Tokens saved to %s\n", filepath.c_str());
    }

}

// 函数: print_tokenized_prompt
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: print_tokenized_prompt
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void print_tokenized_prompt(llama_context * ctx, const std::vector<llama_token> & tokens, const std::string & prompt) {
    const llama_model * model = llama_get_model(ctx);
    const llama_vocab * vocab = llama_model_get_vocab(model);

    LOG("Model add_bos: %s\n", llama_vocab_get_add_bos(vocab) ? "true" : "false");
    LOG("Input prompt: \"%s\"\n", prompt.c_str());
    LOG("Token ids (%zu):\n", tokens.size());

    for (auto id : tokens) {
        std::string piece(128, '\0');
        int n = llama_token_to_piece(vocab, id, piece.data(), piece.size(), 0, true);
        if (n < 0) {
            LOG_ERR("failed to convert token %d to piece\n", id);
            continue;
        }
        piece.resize(n);
        LOG("%s(%d) ", piece.c_str(), id);
    }
    LOG("\n");
}

// 函数: run
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: run
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool run(llama_context * ctx, const common_params & params) {
    const llama_model * model = llama_get_model(ctx);
    const llama_vocab * vocab = llama_model_get_vocab(model);

    const bool add_bos = llama_vocab_get_add_bos(vocab);

    std::vector<llama_token> tokens = common_tokenize(ctx, params.prompt, add_bos);

    if (tokens.empty()) {
        LOG_ERR("%s : there are not input tokens to process - (try to provide a prompt with '-p')\n", __func__);
        return false;
    }

    if (llama_decode(ctx, llama_batch_get_one(tokens.data(), tokens.size()))) {
        LOG_ERR("%s : failed to eval\n", __func__);
        return false;
    }

    print_tokenized_prompt(ctx, tokens, params.prompt);

    if (params.save_logits) {
        output_data output {ctx, model, params};
        std::filesystem::path model_path{params.model.path};
        std::string model_name{model_path.stem().string()};
        save_output_data(output, model_name, params.logits_output_dir);
    }

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
    common_params params;

    if (!common_params_parse(argc, argv, params, LLAMA_EXAMPLE_DEBUG, print_usage)) {
        return 1;
    }

    common_init();

    llama_backend_init();
    llama_numa_init(params.numa);

    base_callback_data cb_data(params, params.tensor_filter);

    auto llama_init = common_init_from_params(params);

    auto * model = llama_init->model();
    auto * ctx   = llama_init->context();

    if (model == nullptr || ctx == nullptr) {
        LOG_ERR("%s : failed to init\n", __func__);
        return 1;
    }

    {
        LOG_INF("\n");
        LOG_INF("%s\n", common_params_get_system_info(params).c_str());
        LOG_INF("\n");
    }

    if (!run(ctx, params)) {
        return 1;
    }

    LOG("\n");
    llama_perf_context_print(ctx);

    llama_backend_free();

    return 0;
}
