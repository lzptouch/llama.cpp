#pragma once

#include "server-task.h"

#include <condition_variable>
#include <deque>
#include <mutex>
#include <vector>
#include <unordered_set>

// struct for managing server tasks
// in most cases, use server_response_reader to post new tasks and retrieve results
// 类: server_queue
// 描述: server_queue类提供相关功能
// 用途: 用于处理server_queue相关的操作
// 类: server_queue
// 描述: server_queue类提供相关功能
// 用途: 用于处理server_queue相关的操作
    // 结构体: server_queue
    // 描述: server_queue结构体提供相关功能
    // 用途: 用于处理server_queue相关的操作
    // 结构体: server_queue
    // 描述: server_queue结构体提供相关功能
    // 用途: 用于处理server_queue相关的操作
    // 结构体: server_queue
    // 描述: server_queue结构体提供相关功能
    // 用途: 用于处理server_queue相关的操作
    // 结构体: server_queue
    // 描述: server_queue结构体提供相关功能
    // 用途: 用于处理server_queue相关的操作
    // 结构体: server_queue
    // 描述: server_queue结构体提供相关功能
    // 用途: 用于处理server_queue相关的操作
    // 结构体: server_queue
    // 描述: server_queue结构体提供相关功能
    // 用途: 用于处理server_queue相关的操作
struct server_queue {
private:
    int id = 0;
    bool running  = false;
    bool sleeping = false;
    bool req_stop_sleeping = false;
    int64_t time_last_task = 0;

    // queues
    std::deque<server_task> queue_tasks;
    std::deque<server_task> queue_tasks_deferred;

    std::mutex mutex_tasks;
    std::condition_variable condition_tasks;

    // callback functions
    std::function<void(server_task &&)> callback_new_task;
    std::function<void(void)>           callback_update_slots;
    std::function<void(bool)>           callback_sleeping_state;

public:
    // Add a new task to the end of the queue
    // 函数: post
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: post
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    int post(server_task && task, bool front = false);

    // multi-task version of post()
    // 函数: post
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: post
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    int post(std::vector<server_task> && tasks, bool front = false);

    // Add a new task, but defer until one slot is available
    // 函数: defer
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: defer
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void defer(server_task && task);

    // Get the next id for creating a new task
    // 函数: get_new_id
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_new_id
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    int get_new_id();

    // Call when the state of one slot is changed, it will move one task from deferred to main queue
    // prioritize tasks that use the specified slot (otherwise, pop the first deferred task)
    // 函数: pop_deferred_task
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: pop_deferred_task
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void pop_deferred_task(int id_slot);

    // if sleeping, request exiting sleep state and wait until it is done
    // returns immediately if not sleeping
    // 函数: wait_until_no_sleep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: wait_until_no_sleep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void wait_until_no_sleep();

    // 函数: is_sleeping
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_sleeping
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_sleeping() {
        std::unique_lock<std::mutex> lock(mutex_tasks);
        return sleeping;
    }

    // end the start_loop routine
    // 函数: terminate
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: terminate
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void terminate();

    /**
     * Main loop consists of these steps:
     * - Wait until a new task arrives
     * - Process the task (i.e. maybe copy data into slot)
     * - Check if multitask is finished
     * - Update all slots
     *
     * Sleeping procedure (disabled if idle_sleep_ms < 0):
     * - If there is no task after idle_sleep_ms, enter sleeping state
     * - Call callback_sleeping_state(true)
     * - Wait until req_stop_sleeping is set to true
     * - Call callback_sleeping_state(false)
     * - Exit sleeping state
     */
    // 函数: start_loop
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: start_loop
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void start_loop(int64_t idle_sleep_ms = -1);

    // for metrics
    // 函数: queue_tasks_deferred_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: queue_tasks_deferred_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t queue_tasks_deferred_size() {
        std::unique_lock<std::mutex> lock(mutex_tasks);
        return queue_tasks_deferred.size();
    }

    //
    // Functions below are not thread-safe, must only be used before start_loop() is called
    //

    // Register function to process a new task
    // 函数: on_new_task
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: on_new_task
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void on_new_task(std::function<void(server_task &&)> callback) {
        callback_new_task = std::move(callback);
    }

    // Register the function to be called when all slots data is ready to be processed
    // 函数: on_update_slots
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: on_update_slots
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    void on_update_slots(std::function<void(void)> callback) {
        callback_update_slots = std::move(callback);
    }

    // Register callback for sleeping state change
    // note: when entering sleeping state, the callback is called AFTER sleeping is set to true
    //       when leaving sleeping state, the callback is called BEFORE sleeping is set to false
    // 函数: on_sleeping_state
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: on_sleeping_state
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void on_sleeping_state(std::function<void(bool)> callback) {
        callback_sleeping_state = std::move(callback);
    }

private:
    // 函数: cleanup_pending_task
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: cleanup_pending_task
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void cleanup_pending_task(int id_target);
};

// struct for managing server responses
// in most cases, use server_response_reader to retrieve results
// 类: server_response
// 描述: server_response类提供相关功能
// 用途: 用于处理server_response相关的操作
// 类: server_response
// 描述: server_response类提供相关功能
// 用途: 用于处理server_response相关的操作
    // 结构体: server_response
    // 描述: server_response结构体提供相关功能
    // 用途: 用于处理server_response相关的操作
    // 结构体: server_response
    // 描述: server_response结构体提供相关功能
    // 用途: 用于处理server_response相关的操作
    // 结构体: server_response
    // 描述: server_response结构体提供相关功能
    // 用途: 用于处理server_response相关的操作
    // 结构体: server_response
    // 描述: server_response结构体提供相关功能
    // 用途: 用于处理server_response相关的操作
    // 结构体: server_response
    // 描述: server_response结构体提供相关功能
    // 用途: 用于处理server_response相关的操作
    // 结构体: server_response
    // 描述: server_response结构体提供相关功能
    // 用途: 用于处理server_response相关的操作
struct server_response {
private:
    bool running = true;

    // for keeping track of all tasks waiting for the result
    std::unordered_set<int> waiting_task_ids;

    // the main result queue (using ptr for polymorphism)
    std::vector<server_task_result_ptr> queue_results;

    std::mutex mutex_results;
    std::condition_variable condition_results;

public:
    // add the id_task to the list of tasks waiting for response
    // 函数: add_waiting_task_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_waiting_task_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_waiting_task_id(int id_task);

    // 函数: add_waiting_task_ids
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_waiting_task_ids
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_waiting_task_ids(const std::unordered_set<int> & id_tasks);

    // when the request is finished, we can remove task associated with it
    // 函数: remove_waiting_task_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: remove_waiting_task_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void remove_waiting_task_id(int id_task);

    // remove multiple tasks from waiting list
    // 函数: remove_waiting_task_ids
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: remove_waiting_task_ids
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void remove_waiting_task_ids(const std::unordered_set<int> & id_tasks);

    // This function blocks the thread until there is a response for one of the id_tasks
    // 函数: recv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: recv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    server_task_result_ptr recv(const std::unordered_set<int> & id_tasks);

    // same as recv(), but have timeout in seconds
    // if timeout is reached, nullptr is returned
    // 函数: recv_with_timeout
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: recv_with_timeout
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    server_task_result_ptr recv_with_timeout(const std::unordered_set<int> & id_tasks, int timeout);

    // single-task version of recv()
    // 函数: recv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: recv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    server_task_result_ptr recv(int id_task);

    // Send a new result to a waiting id_task
    // 函数: send
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: send
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void send(server_task_result_ptr && result);

    // terminate the waiting loop
    // 函数: terminate
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: terminate
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void terminate();
};

// utility class to make working with server_queue and server_response easier
// it provides a generator-like API for server responses
// support pooling connection state and aggregating multiple results
// 类: server_response_reader
// 描述: server_response_reader类提供相关功能
// 用途: 用于处理server_response_reader相关的操作
// 类: server_response_reader
// 描述: server_response_reader类提供相关功能
// 用途: 用于处理server_response_reader相关的操作
    // 结构体: server_response_reader
    // 描述: server_response_reader结构体提供相关功能
    // 用途: 用于处理server_response_reader相关的操作
    // 结构体: server_response_reader
    // 描述: server_response_reader结构体提供相关功能
    // 用途: 用于处理server_response_reader相关的操作
    // 结构体: server_response_reader
    // 描述: server_response_reader结构体提供相关功能
    // 用途: 用于处理server_response_reader相关的操作
    // 结构体: server_response_reader
    // 描述: server_response_reader结构体提供相关功能
    // 用途: 用于处理server_response_reader相关的操作
    // 结构体: server_response_reader
    // 描述: server_response_reader结构体提供相关功能
    // 用途: 用于处理server_response_reader相关的操作
    // 结构体: server_response_reader
    // 描述: server_response_reader结构体提供相关功能
    // 用途: 用于处理server_response_reader相关的操作
struct server_response_reader {
    std::unordered_set<int> id_tasks;
    server_queue & queue_tasks;
    server_response & queue_results;
    size_t received_count = 0;
    bool cancelled = false;
    int polling_interval_seconds;

    // tracking generation state and partial tool calls
    // only used by streaming completions
    std::vector<task_result_state> states;

    // should_stop function will be called each polling_interval_seconds
    server_response_reader(server_queue & queue_tasks, server_response & queue_results, int polling_interval_seconds)
        : queue_tasks(queue_tasks), queue_results(queue_results), polling_interval_seconds(polling_interval_seconds) {}
    ~server_response_reader() {
        stop();
    }

    // 函数: get_new_id
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_new_id
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    int get_new_id() {
        return queue_tasks.get_new_id();
    }

    // if front = true, the task will be posted to the front of the queue (high priority)
    // 函数: post_task
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: post_task
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void post_task(server_task && task, bool front = false);
    // 函数: post_tasks
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: post_tasks
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void post_tasks(std::vector<server_task> && tasks, bool front = false);
    // 函数: has_next
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: has_next
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool has_next() const;

    // return nullptr if should_stop() is true before receiving a result
    // note: if one error is received, it will stop further processing and return error result
    // 函数: next
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: next
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    server_task_result_ptr next(const std::function<bool()> & should_stop);

    // 类: batch_response
    // 描述: batch_response类提供相关功能
    // 用途: 用于处理batch_response相关的操作
    // 类: batch_response
    // 描述: batch_response类提供相关功能
    // 用途: 用于处理batch_response相关的操作
    // 结构体: batch_response
    // 描述: batch_response结构体提供相关功能
    // 用途: 用于处理batch_response相关的操作
    // 结构体: batch_response
    // 描述: batch_response结构体提供相关功能
    // 用途: 用于处理batch_response相关的操作
    // 结构体: batch_response
    // 描述: batch_response结构体提供相关功能
    // 用途: 用于处理batch_response相关的操作
    // 结构体: batch_response
    // 描述: batch_response结构体提供相关功能
    // 用途: 用于处理batch_response相关的操作
    // 结构体: batch_response
    // 描述: batch_response结构体提供相关功能
    // 用途: 用于处理batch_response相关的操作
    // 结构体: batch_response
    // 描述: batch_response结构体提供相关功能
    // 用途: 用于处理batch_response相关的操作
    struct batch_response {
        bool is_terminated = false; // if true, indicates that processing was stopped before all results were received
        std::vector<server_task_result_ptr> results;
        server_task_result_ptr error; // nullptr if no error
    };
    // aggregate multiple results
    // 函数: wait_for_all
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: wait_for_all
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    batch_response wait_for_all(const std::function<bool()> & should_stop);

    // 函数: stop
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: stop
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void stop();
};
