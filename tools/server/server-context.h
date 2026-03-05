#pragma once

#include "server-http.h"
#include "server-task.h"
#include "server-queue.h"

#include <nlohmann/json_fwd.hpp>

#include <cstddef>
#include <memory>
#include <set>

// 类: server_context_impl
// 描述: server_context_impl类提供相关功能
// 用途: 用于处理server_context_impl相关的操作
// 类: server_context_impl
// 描述: server_context_impl类提供相关功能
// 用途: 用于处理server_context_impl相关的操作
    // 结构体: server_context_impl
    // 描述: server_context_impl结构体提供相关功能
    // 用途: 用于处理server_context_impl相关的操作
    // 结构体: server_context_impl
    // 描述: server_context_impl结构体提供相关功能
    // 用途: 用于处理server_context_impl相关的操作
    // 结构体: server_context_impl
    // 描述: server_context_impl结构体提供相关功能
    // 用途: 用于处理server_context_impl相关的操作
    // 结构体: server_context_impl
    // 描述: server_context_impl结构体提供相关功能
    // 用途: 用于处理server_context_impl相关的操作
    // 结构体: server_context_impl
    // 描述: server_context_impl结构体提供相关功能
    // 用途: 用于处理server_context_impl相关的操作
    // 结构体: server_context_impl
    // 描述: server_context_impl结构体提供相关功能
    // 用途: 用于处理server_context_impl相关的操作
struct server_context_impl; // private implementation

// 类: server_context_meta
// 描述: server_context_meta类提供相关功能
// 用途: 用于处理server_context_meta相关的操作
// 类: server_context_meta
// 描述: server_context_meta类提供相关功能
// 用途: 用于处理server_context_meta相关的操作
    // 结构体: server_context_meta
    // 描述: server_context_meta结构体提供相关功能
    // 用途: 用于处理server_context_meta相关的操作
    // 结构体: server_context_meta
    // 描述: server_context_meta结构体提供相关功能
    // 用途: 用于处理server_context_meta相关的操作
    // 结构体: server_context_meta
    // 描述: server_context_meta结构体提供相关功能
    // 用途: 用于处理server_context_meta相关的操作
    // 结构体: server_context_meta
    // 描述: server_context_meta结构体提供相关功能
    // 用途: 用于处理server_context_meta相关的操作
    // 结构体: server_context_meta
    // 描述: server_context_meta结构体提供相关功能
    // 用途: 用于处理server_context_meta相关的操作
    // 结构体: server_context_meta
    // 描述: server_context_meta结构体提供相关功能
    // 用途: 用于处理server_context_meta相关的操作
struct server_context_meta {
    std::string build_info;
    std::string model_name;
    std::set<std::string> model_aliases;
    std::set<std::string> model_tags;
    std::string model_path;
    bool has_mtmd;
    bool has_inp_image;
    bool has_inp_audio;
    json json_webui_settings;
    int slot_n_ctx;
    enum llama_pooling_type pooling_type;

    // chat params
    server_chat_params & chat_params;
    std::map<std::string, bool> chat_template_caps;

    // tokens
    std::string bos_token_str;
    std::string eos_token_str;
    llama_token fim_pre_token;
    llama_token fim_sub_token;
    llama_token fim_mid_token;
    llama_token fim_pad_token;
    llama_token fim_rep_token;
    llama_token fim_sep_token;

    // model meta
    enum llama_vocab_type model_vocab_type;
    int32_t model_vocab_n_tokens;
    int32_t model_n_ctx_train;
    int32_t model_n_embd_inp;
    uint64_t model_n_params;
    uint64_t model_size;
};

// 类: server_context
// 描述: server_context类提供相关功能
// 用途: 用于处理server_context相关的操作
// 类: server_context
// 描述: server_context类提供相关功能
// 用途: 用于处理server_context相关的操作
    // 结构体: server_context
    // 描述: server_context结构体提供相关功能
    // 用途: 用于处理server_context相关的操作
    // 结构体: server_context
    // 描述: server_context结构体提供相关功能
    // 用途: 用于处理server_context相关的操作
    // 结构体: server_context
    // 描述: server_context结构体提供相关功能
    // 用途: 用于处理server_context相关的操作
    // 结构体: server_context
    // 描述: server_context结构体提供相关功能
    // 用途: 用于处理server_context相关的操作
    // 结构体: server_context
    // 描述: server_context结构体提供相关功能
    // 用途: 用于处理server_context相关的操作
    // 结构体: server_context
    // 描述: server_context结构体提供相关功能
    // 用途: 用于处理server_context相关的操作
struct server_context {
    std::unique_ptr<server_context_impl> impl;

    server_context();
    ~server_context();

    // load the model and initialize llama_context
    // returns true on success
    // 函数: load_model
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_model
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    bool load_model(const common_params & params);

    // this function will block main thread until termination
    // 函数: start_loop
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: start_loop
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void start_loop();

    // terminate main loop (will unblock start_loop)
    // 函数: terminate
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: terminate
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void terminate();

    // get the underlaying llama_context, can return nullptr if sleeping
    // not thread-safe, should only be used from the main thread
    // 函数: get_llama_context
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_llama_context
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_context * get_llama_context() const;

    // get a new response reader, used by CLI application
    // 函数: get_response_reader
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_response_reader
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    server_response_reader get_response_reader();

    // get server metadata (read-only), can only be called after load_model()
    // not thread-safe, should only be used from the main thread
    // 函数: get_meta
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_meta
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    server_context_meta get_meta() const;
};


// forward declarations
// 类: server_res_generator
// 描述: server_res_generator类提供相关功能
// 用途: 用于处理server_res_generator相关的操作
// 类: server_res_generator
// 描述: server_res_generator类提供相关功能
// 用途: 用于处理server_res_generator相关的操作
    // 结构体: server_res_generator
    // 描述: server_res_generator结构体提供相关功能
    // 用途: 用于处理server_res_generator相关的操作
    // 结构体: server_res_generator
    // 描述: server_res_generator结构体提供相关功能
    // 用途: 用于处理server_res_generator相关的操作
    // 结构体: server_res_generator
    // 描述: server_res_generator结构体提供相关功能
    // 用途: 用于处理server_res_generator相关的操作
    // 结构体: server_res_generator
    // 描述: server_res_generator结构体提供相关功能
    // 用途: 用于处理server_res_generator相关的操作
    // 结构体: server_res_generator
    // 描述: server_res_generator结构体提供相关功能
    // 用途: 用于处理server_res_generator相关的操作
    // 结构体: server_res_generator
    // 描述: server_res_generator结构体提供相关功能
    // 用途: 用于处理server_res_generator相关的操作
struct server_res_generator;

// 类: server_routes
// 描述: server_routes类提供相关功能
// 用途: 用于处理server_routes相关的操作
// 类: server_routes
// 描述: server_routes类提供相关功能
// 用途: 用于处理server_routes相关的操作
    // 结构体: server_routes
    // 描述: server_routes结构体提供相关功能
    // 用途: 用于处理server_routes相关的操作
    // 结构体: server_routes
    // 描述: server_routes结构体提供相关功能
    // 用途: 用于处理server_routes相关的操作
    // 结构体: server_routes
    // 描述: server_routes结构体提供相关功能
    // 用途: 用于处理server_routes相关的操作
    // 结构体: server_routes
    // 描述: server_routes结构体提供相关功能
    // 用途: 用于处理server_routes相关的操作
    // 结构体: server_routes
    // 描述: server_routes结构体提供相关功能
    // 用途: 用于处理server_routes相关的操作
    // 结构体: server_routes
    // 描述: server_routes结构体提供相关功能
    // 用途: 用于处理server_routes相关的操作
struct server_routes {
    server_routes(const common_params & params, server_context & ctx_server);

    // 函数: init_routes
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init_routes
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    void init_routes();

    // note: this is not thread-safe and can only when ctx_http.is_ready is false
    // 函数: update_meta
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: update_meta
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    void update_meta(const server_context & ctx_server) {
        this->meta = std::make_unique<server_context_meta>(ctx_server.get_meta());
    }

    // handlers using lambda function, so that they can capture `this` without `std::bind`
    // they won't be called until ctx_http.is_ready is set to true
    server_http_context::handler_t get_health;
    server_http_context::handler_t get_metrics;
    server_http_context::handler_t get_slots;
    server_http_context::handler_t post_slots;
    server_http_context::handler_t get_props;
    server_http_context::handler_t post_props;
    server_http_context::handler_t get_api_show;
    server_http_context::handler_t post_infill;
    server_http_context::handler_t post_completions;
    server_http_context::handler_t post_completions_oai;
    server_http_context::handler_t post_chat_completions;
    server_http_context::handler_t post_responses_oai;
    server_http_context::handler_t post_anthropic_messages;
    server_http_context::handler_t post_anthropic_count_tokens;
    server_http_context::handler_t post_apply_template;
    server_http_context::handler_t get_models;
    server_http_context::handler_t post_tokenize;
    server_http_context::handler_t post_detokenize;
    server_http_context::handler_t post_embeddings;
    server_http_context::handler_t post_embeddings_oai;
    server_http_context::handler_t post_rerank;
    server_http_context::handler_t get_lora_adapters;
    server_http_context::handler_t post_lora_adapters;
private:
    std::unique_ptr<server_res_generator> handle_completions_impl(
            const server_http_req & req,
            server_task_type type,
            const json & data,
            const std::vector<raw_buffer> & files,
            task_response_type res_type);
    std::unique_ptr<server_res_generator> handle_slots_save(const server_http_req & req, int id_slot);
    std::unique_ptr<server_res_generator> handle_slots_restore(const server_http_req & req, int id_slot);
    std::unique_ptr<server_res_generator> handle_slots_erase(const server_http_req &, int id_slot);
    std::unique_ptr<server_res_generator> handle_embeddings_impl(const server_http_req & req, task_response_type res_type);

    // using unique_ptr to allow late initialization of const
    std::unique_ptr<const server_context_meta> meta;

    const common_params & params;
    const server_context_impl & ctx_server;

    server_queue & queue_tasks;
    server_response & queue_results;
    std::unique_ptr<server_res_generator> create_response(bool bypass_sleep = false);
};
