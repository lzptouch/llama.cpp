// ============================================================================
// 文件: log.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/common/log.cpp
// 作者: 自动注释工具
// 描述: 通用工具文件,包含常用功能和辅助类
// ============================================================================

#include "common.h"
#include "log.h"

#include <chrono>
#include <condition_variable>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <sstream>
#include <thread>
#include <vector>

#if defined(_WIN32)
#    include <io.h>
#    include <windows.h>
#    define isatty _isatty
#    define fileno _fileno
#else
#    include <unistd.h>
#endif // defined(_WIN32)

int common_log_verbosity_thold = LOG_DEFAULT_LLAMA;

// 函数: common_log_set_verbosity_thold
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_set_verbosity_thold
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void common_log_set_verbosity_thold(int verbosity) {
    common_log_verbosity_thold = verbosity;
}

// 函数: t_us
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: t_us
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static int64_t t_us() {
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

// colors
enum common_log_col : int {
    COMMON_LOG_COL_DEFAULT = 0,
    COMMON_LOG_COL_BOLD,
    COMMON_LOG_COL_RED,
    COMMON_LOG_COL_GREEN,
    COMMON_LOG_COL_YELLOW,
    COMMON_LOG_COL_BLUE,
    COMMON_LOG_COL_MAGENTA,
    COMMON_LOG_COL_CYAN,
    COMMON_LOG_COL_WHITE,
};

// disable colors by default
static std::vector<const char *> g_col = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

// 类: common_log_entry
// 描述: common_log_entry类提供相关功能
// 用途: 用于处理common_log_entry相关的操作
// 类: common_log_entry
// 描述: common_log_entry类提供相关功能
// 用途: 用于处理common_log_entry相关的操作
    // 结构体: common_log_entry
    // 描述: common_log_entry结构体提供相关功能
    // 用途: 用于处理common_log_entry相关的操作
    // 结构体: common_log_entry
    // 描述: common_log_entry结构体提供相关功能
    // 用途: 用于处理common_log_entry相关的操作
    // 结构体: common_log_entry
    // 描述: common_log_entry结构体提供相关功能
    // 用途: 用于处理common_log_entry相关的操作
    // 结构体: common_log_entry
    // 描述: common_log_entry结构体提供相关功能
    // 用途: 用于处理common_log_entry相关的操作
struct common_log_entry {
    enum ggml_log_level level;

    bool prefix;

    int64_t timestamp;

    std::vector<char> msg;

    // signals the worker thread to stop
    bool is_end;

    // 函数: print
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: print
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void print(FILE * file = nullptr) const {
        FILE * fcur = file;
        if (!fcur) {
            // stderr displays DBG messages only when their verbosity level is not higher than the threshold
            // these messages will still be logged to a file
            if (level == GGML_LOG_LEVEL_DEBUG && common_log_verbosity_thold < LOG_DEFAULT_DEBUG) {
                return;
            }

            fcur = stdout;

            if (level != GGML_LOG_LEVEL_NONE) {
                fcur = stderr;
            }
        }

        if (level != GGML_LOG_LEVEL_NONE && level != GGML_LOG_LEVEL_CONT && prefix) {
            if (timestamp) {
                // [M.s.ms.us]
                fprintf(fcur, "%s%d.%02d.%03d.%03d%s ",
                        g_col[COMMON_LOG_COL_BLUE],
                        (int) (timestamp / 1000000 / 60),
                        (int) (timestamp / 1000000 % 60),
                        (int) (timestamp / 1000 % 1000),
                        (int) (timestamp % 1000),
                        g_col[COMMON_LOG_COL_DEFAULT]);
            }

            switch (level) {
                case GGML_LOG_LEVEL_INFO:  fprintf(fcur, "%sI %s", g_col[COMMON_LOG_COL_GREEN],   g_col[COMMON_LOG_COL_DEFAULT]); break;
                case GGML_LOG_LEVEL_WARN:  fprintf(fcur, "%sW %s", g_col[COMMON_LOG_COL_MAGENTA], ""                        ); break;
                case GGML_LOG_LEVEL_ERROR: fprintf(fcur, "%sE %s", g_col[COMMON_LOG_COL_RED],     ""                        ); break;
                case GGML_LOG_LEVEL_DEBUG: fprintf(fcur, "%sD %s", g_col[COMMON_LOG_COL_YELLOW],  ""                        ); break;
                default:
                    break;
            }
        }

        fprintf(fcur, "%s", msg.data());

        if (level == GGML_LOG_LEVEL_WARN || level == GGML_LOG_LEVEL_ERROR || level == GGML_LOG_LEVEL_DEBUG) {
            fprintf(fcur, "%s", g_col[COMMON_LOG_COL_DEFAULT]);
        }

        fflush(fcur);
    }
};

// 类: common_log
// 描述: common_log类提供相关功能
// 用途: 用于处理common_log相关的操作
// 类: common_log
// 描述: common_log类提供相关功能
// 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
struct common_log {
    // default capacity - will be expanded if needed
    common_log() : common_log(256) {}

    common_log(size_t capacity) {
        file = nullptr;
        prefix = false;
        timestamps = false;
        running = false;
        t_start = t_us();

        // initial message size - will be expanded if longer messages arrive
        entries.resize(capacity);
        for (auto & entry : entries) {
            entry.msg.resize(256);
        }

        head = 0;
        tail = 0;

        resume();
    }

    ~common_log() {
        pause();
        if (file) {
            fclose(file);
        }
    }

private:
    std::mutex mtx;
    std::thread thrd;
    std::condition_variable cv;

    FILE * file;

    bool prefix;
    bool timestamps;
    bool running;

    int64_t t_start;

    // ring buffer of entries
    std::vector<common_log_entry> entries;
    size_t head;
    size_t tail;

    // worker thread copies into this
    common_log_entry cur;

public:
    // 函数: add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add(enum ggml_log_level level, const char * fmt, va_list args) {
        std::lock_guard<std::mutex> lock(mtx);

        if (!running) {
            // discard messages while the worker thread is paused
            return;
        }

        auto & entry = entries[tail];

        {
            // cannot use args twice, so make a copy in case we need to expand the buffer
            va_list args_copy;
            va_copy(args_copy, args);

#if 1
            const size_t n = vsnprintf(entry.msg.data(), entry.msg.size(), fmt, args);
            if (n >= entry.msg.size()) {
                entry.msg.resize(n + 1);
                vsnprintf(entry.msg.data(), entry.msg.size(), fmt, args_copy);
            }
#else
            // hack for bolding arguments

            std::stringstream ss;
            for (int i = 0; fmt[i] != 0; i++) {
                if (fmt[i] == '%') {
                    ss << LOG_COL_BOLD;
                    while (fmt[i] != ' ' && fmt[i] != ')' && fmt[i] != ']' && fmt[i] != 0) ss << fmt[i++];
                    ss << LOG_COL_DEFAULT;
                    if (fmt[i] == 0) break;
                }
                ss << fmt[i];
            }
            const size_t n = vsnprintf(entry.msg.data(), entry.msg.size(), ss.str().c_str(), args);
            if (n >= entry.msg.size()) {
                entry.msg.resize(n + 1);
                vsnprintf(entry.msg.data(), entry.msg.size(), ss.str().c_str(), args_copy);
            }
#endif
            va_end(args_copy);
        }

        entry.level = level;
        entry.prefix = prefix;
        entry.timestamp = 0;
        if (timestamps) {
            entry.timestamp = t_us() - t_start;
        }
        entry.is_end = false;

        tail = (tail + 1) % entries.size();
        if (tail == head) {
            // expand the buffer
            std::vector<common_log_entry> new_entries(2*entries.size());

            size_t new_tail = 0;

            do {
                new_entries[new_tail] = std::move(entries[head]);

                head     = (head     + 1) % entries.size();
                new_tail = (new_tail + 1);
            } while (head != tail);

            head = 0;
            tail = new_tail;

            for (size_t i = tail; i < new_entries.size(); i++) {
                new_entries[i].msg.resize(256);
            }

            entries = std::move(new_entries);
        }

        cv.notify_one();
    }

    // 函数: resume
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: resume
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void resume() {
        std::lock_guard<std::mutex> lock(mtx);

        if (running) {
            return;
        }

        running = true;

        thrd = std::thread([this]() {
            while (true) {
                {
                    std::unique_lock<std::mutex> lock(mtx);
                    cv.wait(lock, [this]() { return head != tail; });

                    cur = entries[head];

                    head = (head + 1) % entries.size();
                }

                if (cur.is_end) {
                    break;
                }

                cur.print(); // stdout and stderr

                if (file) {
                    cur.print(file);
                }
            }
        });
    }

    // 函数: pause
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: pause
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void pause() {
        {
            std::lock_guard<std::mutex> lock(mtx);

            if (!running) {
                return;
            }

            running = false;

            // push an entry to signal the worker thread to stop
            {
                auto & entry = entries[tail];
                entry.is_end = true;

                tail = (tail + 1) % entries.size();
            }

            cv.notify_one();
        }

        thrd.join();
    }

    // 函数: set_file
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_file
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_file(const char * path) {
        pause();

        if (file) {
            fclose(file);
        }

        if (path) {
            file = fopen(path, "w");
        } else {
            file = nullptr;
        }

        resume();
    }

    // 函数: set_colors
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_colors
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_colors(bool colors) {
        pause();

        if (colors) {
            g_col[COMMON_LOG_COL_DEFAULT] = LOG_COL_DEFAULT;
            g_col[COMMON_LOG_COL_BOLD]    = LOG_COL_BOLD;
            g_col[COMMON_LOG_COL_RED]     = LOG_COL_RED;
            g_col[COMMON_LOG_COL_GREEN]   = LOG_COL_GREEN;
            g_col[COMMON_LOG_COL_YELLOW]  = LOG_COL_YELLOW;
            g_col[COMMON_LOG_COL_BLUE]    = LOG_COL_BLUE;
            g_col[COMMON_LOG_COL_MAGENTA] = LOG_COL_MAGENTA;
            g_col[COMMON_LOG_COL_CYAN]    = LOG_COL_CYAN;
            g_col[COMMON_LOG_COL_WHITE]   = LOG_COL_WHITE;
        } else {
            for (size_t i = 0; i < g_col.size(); i++) {
                g_col[i] = "";
            }
        }

        resume();
    }

    // 函数: set_prefix
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_prefix
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_prefix(bool prefix) {
        std::lock_guard<std::mutex> lock(mtx);

        this->prefix = prefix;
    }

    // 函数: set_timestamps
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_timestamps
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_timestamps(bool timestamps) {
        std::lock_guard<std::mutex> lock(mtx);

        this->timestamps = timestamps;
    }
};

//
// public API
//

// 类: common_log
// 描述: common_log类提供相关功能
// 用途: 用于处理common_log相关的操作
// 类: common_log
// 描述: common_log类提供相关功能
// 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
struct common_log * common_log_init() {
    return new common_log;
}

// 类: common_log
// 描述: common_log类提供相关功能
// 用途: 用于处理common_log相关的操作
// 类: common_log
// 描述: common_log类提供相关功能
// 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
    // 结构体: common_log
    // 描述: common_log结构体提供相关功能
    // 用途: 用于处理common_log相关的操作
struct common_log * common_log_main() {
    static struct common_log log;
    static std::once_flag    init_flag;
    std::call_once(init_flag, [&]() {
        // Set default to auto-detect colors
        log.set_colors(tty_can_use_colors());
    });

    return &log;
}

// 函数: common_log_pause
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_pause
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void common_log_pause(struct common_log * log) {
    log->pause();
}

// 函数: common_log_resume
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_resume
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void common_log_resume(struct common_log * log) {
    log->resume();
}

// 函数: common_log_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void common_log_free(struct common_log * log) {
    delete log;
}

// 函数: common_log_add
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_add
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void common_log_add(struct common_log * log, enum ggml_log_level level, const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log->add(level, fmt, args);
    va_end(args);
}

// 函数: common_log_set_file
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_set_file
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void common_log_set_file(struct common_log * log, const char * file) {
    log->set_file(file);
}

// 函数: common_log_set_colors
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_set_colors
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void common_log_set_colors(struct common_log * log, log_colors colors) {
    if (colors == LOG_COLORS_AUTO) {
        log->set_colors(tty_can_use_colors());
        return;
    }

    if (colors == LOG_COLORS_DISABLED) {
        log->set_colors(false);
        return;
    }

    GGML_ASSERT(colors == LOG_COLORS_ENABLED);
    log->set_colors(true);
}

// 函数: common_log_set_prefix
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_set_prefix
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void common_log_set_prefix(struct common_log * log, bool prefix) {
    log->set_prefix(prefix);
}

// 函数: common_log_set_timestamps
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_set_timestamps
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void common_log_set_timestamps(struct common_log * log, bool timestamps) {
    log->set_timestamps(timestamps);
}

// 函数: common_log_flush
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_flush
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void common_log_flush(struct common_log * log) {
    log->pause();
    log->resume();
}

// 函数: common_get_verbosity
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: common_get_verbosity
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static int common_get_verbosity(enum ggml_log_level level) {
    switch (level) {
        case GGML_LOG_LEVEL_DEBUG: return LOG_LEVEL_DEBUG;
        case GGML_LOG_LEVEL_INFO:  return LOG_LEVEL_INFO;
        case GGML_LOG_LEVEL_WARN:  return LOG_LEVEL_WARN;
        case GGML_LOG_LEVEL_ERROR: return LOG_LEVEL_ERROR;
        case GGML_LOG_LEVEL_CONT:  return LOG_LEVEL_INFO; // same as INFO
        case GGML_LOG_LEVEL_NONE:
        default:
            return LOG_LEVEL_OUTPUT;
    }
}

// 函数: common_log_default_callback
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_log_default_callback
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void common_log_default_callback(enum ggml_log_level level, const char * text, void * /*user_data*/) {
    auto verbosity = common_get_verbosity(level);
    if (verbosity <= common_log_verbosity_thold) {
        common_log_add(common_log_main(), level, "%s", text);
    }
}
