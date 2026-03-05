#pragma once

#include "ggml.h"
#include "clip-model.h"

#include <cstdint>
#include <vector>
#include <string>

#define MTMD_INTERNAL_HEADER

// 类: mtmd_audio_mel
// 描述: mtmd_audio_mel类提供相关功能
// 用途: 用于处理mtmd_audio_mel相关的操作
// 类: mtmd_audio_mel
// 描述: mtmd_audio_mel类提供相关功能
// 用途: 用于处理mtmd_audio_mel相关的操作
    // 结构体: mtmd_audio_mel
    // 描述: mtmd_audio_mel结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel相关的操作
    // 结构体: mtmd_audio_mel
    // 描述: mtmd_audio_mel结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel相关的操作
    // 结构体: mtmd_audio_mel
    // 描述: mtmd_audio_mel结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel相关的操作
    // 结构体: mtmd_audio_mel
    // 描述: mtmd_audio_mel结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel相关的操作
    // 结构体: mtmd_audio_mel
    // 描述: mtmd_audio_mel结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel相关的操作
    // 结构体: mtmd_audio_mel
    // 描述: mtmd_audio_mel结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel相关的操作
struct mtmd_audio_mel {
    int n_len;
    int n_len_org;
    int n_mel;

    std::vector<float> data;
};

// 类: mtmd_audio_mel_filters
// 描述: mtmd_audio_mel_filters类提供相关功能
// 用途: 用于处理mtmd_audio_mel_filters相关的操作
// 类: mtmd_audio_mel_filters
// 描述: mtmd_audio_mel_filters类提供相关功能
// 用途: 用于处理mtmd_audio_mel_filters相关的操作
    // 结构体: mtmd_audio_mel_filters
    // 描述: mtmd_audio_mel_filters结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel_filters相关的操作
    // 结构体: mtmd_audio_mel_filters
    // 描述: mtmd_audio_mel_filters结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel_filters相关的操作
    // 结构体: mtmd_audio_mel_filters
    // 描述: mtmd_audio_mel_filters结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel_filters相关的操作
    // 结构体: mtmd_audio_mel_filters
    // 描述: mtmd_audio_mel_filters结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel_filters相关的操作
    // 结构体: mtmd_audio_mel_filters
    // 描述: mtmd_audio_mel_filters结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel_filters相关的操作
    // 结构体: mtmd_audio_mel_filters
    // 描述: mtmd_audio_mel_filters结构体提供相关功能
    // 用途: 用于处理mtmd_audio_mel_filters相关的操作
struct mtmd_audio_mel_filters {
    int32_t n_mel;
    int32_t n_fft;

    std::vector<float> data;
};

// cache for audio processing, each processor instance owns its own cache
// 类: mtmd_audio_cache
// 描述: mtmd_audio_cache类提供相关功能
// 用途: 用于处理mtmd_audio_cache相关的操作
// 类: mtmd_audio_cache
// 描述: mtmd_audio_cache类提供相关功能
// 用途: 用于处理mtmd_audio_cache相关的操作
    // 结构体: mtmd_audio_cache
    // 描述: mtmd_audio_cache结构体提供相关功能
    // 用途: 用于处理mtmd_audio_cache相关的操作
    // 结构体: mtmd_audio_cache
    // 描述: mtmd_audio_cache结构体提供相关功能
    // 用途: 用于处理mtmd_audio_cache相关的操作
    // 结构体: mtmd_audio_cache
    // 描述: mtmd_audio_cache结构体提供相关功能
    // 用途: 用于处理mtmd_audio_cache相关的操作
    // 结构体: mtmd_audio_cache
    // 描述: mtmd_audio_cache结构体提供相关功能
    // 用途: 用于处理mtmd_audio_cache相关的操作
    // 结构体: mtmd_audio_cache
    // 描述: mtmd_audio_cache结构体提供相关功能
    // 用途: 用于处理mtmd_audio_cache相关的操作
    // 结构体: mtmd_audio_cache
    // 描述: mtmd_audio_cache结构体提供相关功能
    // 用途: 用于处理mtmd_audio_cache相关的操作
struct mtmd_audio_cache {
    std::vector<float> sin_vals;
    std::vector<float> cos_vals;

    std::vector<float> hann_window;

    mtmd_audio_mel_filters filters;

    // 函数: fill_sin_cos_table
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: fill_sin_cos_table
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void fill_sin_cos_table(int n);

    // 函数: fill_hann_window
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: fill_hann_window
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void fill_hann_window(int length, bool periodic);

    // Build mel filterbank matrix [n_mel × n_fft_bins] at runtime.
    // n_fft_bins must be (N_fft / 2 + 1). Example: if N_fft=512 -> n_fft_bins=257.
    void fill_mel_filterbank_matrix(int   n_mel,
                                    int   n_fft,
                                    int   sample_rate,               // e.g. 16000
                                    float fmin             = 0.0f,   // e.g. 0.0
                                    float fmax             = -1.0f,  // e.g. sr/2; pass -1 for auto
                                    bool  slaney_area_norm = true,
                                    float scale = 1.0f  // optional extra scaling
    );
};

// 类: mtmd_audio_preprocessor
// 描述: mtmd_audio_preprocessor类提供相关功能
// 用途: 用于处理mtmd_audio_preprocessor相关的操作
// 类: mtmd_audio_preprocessor
// 描述: mtmd_audio_preprocessor类提供相关功能
// 用途: 用于处理mtmd_audio_preprocessor相关的操作
    // 结构体: mtmd_audio_preprocessor
    // 描述: mtmd_audio_preprocessor结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor相关的操作
    // 结构体: mtmd_audio_preprocessor
    // 描述: mtmd_audio_preprocessor结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor相关的操作
    // 结构体: mtmd_audio_preprocessor
    // 描述: mtmd_audio_preprocessor结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor相关的操作
    // 结构体: mtmd_audio_preprocessor
    // 描述: mtmd_audio_preprocessor结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor相关的操作
    // 结构体: mtmd_audio_preprocessor
    // 描述: mtmd_audio_preprocessor结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor相关的操作
    // 结构体: mtmd_audio_preprocessor
    // 描述: mtmd_audio_preprocessor结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor相关的操作
struct mtmd_audio_preprocessor {
    const clip_hparams & hparams;

    mtmd_audio_preprocessor(const clip_ctx * ctx): hparams(*clip_get_hparams(ctx)) {}

    virtual ~mtmd_audio_preprocessor() = default;
    // 函数: initialize
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: initialize
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    virtual void initialize() = 0; // NOT thread-safe
    // 函数: preprocess
    // 描述: 处理: 处理输入数据或执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: preprocess
    // 描述: 处理: 处理输入数据或执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    virtual bool preprocess(const float * samples, size_t n_samples, std::vector<mtmd_audio_mel> & output) = 0;
};

// 类: mtmd_audio_preprocessor_whisper
// 描述: mtmd_audio_preprocessor_whisper类提供相关功能
// 用途: 用于处理mtmd_audio_preprocessor_whisper相关的操作
// 类: mtmd_audio_preprocessor_whisper
// 描述: mtmd_audio_preprocessor_whisper类提供相关功能
// 用途: 用于处理mtmd_audio_preprocessor_whisper相关的操作
    // 结构体: mtmd_audio_preprocessor_whisper
    // 描述: mtmd_audio_preprocessor_whisper结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_whisper相关的操作
    // 结构体: mtmd_audio_preprocessor_whisper
    // 描述: mtmd_audio_preprocessor_whisper结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_whisper相关的操作
    // 结构体: mtmd_audio_preprocessor_whisper
    // 描述: mtmd_audio_preprocessor_whisper结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_whisper相关的操作
    // 结构体: mtmd_audio_preprocessor_whisper
    // 描述: mtmd_audio_preprocessor_whisper结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_whisper相关的操作
    // 结构体: mtmd_audio_preprocessor_whisper
    // 描述: mtmd_audio_preprocessor_whisper结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_whisper相关的操作
    // 结构体: mtmd_audio_preprocessor_whisper
    // 描述: mtmd_audio_preprocessor_whisper结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_whisper相关的操作
struct mtmd_audio_preprocessor_whisper : mtmd_audio_preprocessor {
    mtmd_audio_preprocessor_whisper(const clip_ctx * ctx) : mtmd_audio_preprocessor(ctx) {}
    // 函数: initialize
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: initialize
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    void initialize() override;
    // 函数: preprocess
    // 描述: 处理: 处理输入数据或执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: preprocess
    // 描述: 处理: 处理输入数据或执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    bool preprocess(const float * samples, size_t n_samples, std::vector<mtmd_audio_mel> & output) override;

  private:
    mtmd_audio_cache cache;
};

// 类: mtmd_audio_preprocessor_conformer
// 描述: mtmd_audio_preprocessor_conformer类提供相关功能
// 用途: 用于处理mtmd_audio_preprocessor_conformer相关的操作
// 类: mtmd_audio_preprocessor_conformer
// 描述: mtmd_audio_preprocessor_conformer类提供相关功能
// 用途: 用于处理mtmd_audio_preprocessor_conformer相关的操作
    // 结构体: mtmd_audio_preprocessor_conformer
    // 描述: mtmd_audio_preprocessor_conformer结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_conformer相关的操作
    // 结构体: mtmd_audio_preprocessor_conformer
    // 描述: mtmd_audio_preprocessor_conformer结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_conformer相关的操作
    // 结构体: mtmd_audio_preprocessor_conformer
    // 描述: mtmd_audio_preprocessor_conformer结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_conformer相关的操作
    // 结构体: mtmd_audio_preprocessor_conformer
    // 描述: mtmd_audio_preprocessor_conformer结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_conformer相关的操作
    // 结构体: mtmd_audio_preprocessor_conformer
    // 描述: mtmd_audio_preprocessor_conformer结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_conformer相关的操作
    // 结构体: mtmd_audio_preprocessor_conformer
    // 描述: mtmd_audio_preprocessor_conformer结构体提供相关功能
    // 用途: 用于处理mtmd_audio_preprocessor_conformer相关的操作
struct mtmd_audio_preprocessor_conformer : mtmd_audio_preprocessor {
    mtmd_audio_preprocessor_conformer(const clip_ctx * ctx) : mtmd_audio_preprocessor(ctx) {}
    // 函数: initialize
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: initialize
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    void initialize() override;
    // 函数: preprocess
    // 描述: 处理: 处理输入数据或执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: preprocess
    // 描述: 处理: 处理输入数据或执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    bool preprocess(const float * samples, size_t n_samples, std::vector<mtmd_audio_mel> & output) override;

  private:
    mtmd_audio_cache cache;
};

//
// streaming ISTFT - converts spectrogram frames back to audio one frame at a time
//
// 类: mtmd_audio_streaming_istft
// 描述: mtmd_audio_streaming_istft类提供相关功能
// 用途: 用于处理mtmd_audio_streaming_istft相关的操作
// 类: mtmd_audio_streaming_istft
// 描述: mtmd_audio_streaming_istft类提供相关功能
// 用途: 用于处理mtmd_audio_streaming_istft相关的操作
    // 结构体: mtmd_audio_streaming_istft
    // 描述: mtmd_audio_streaming_istft结构体提供相关功能
    // 用途: 用于处理mtmd_audio_streaming_istft相关的操作
    // 结构体: mtmd_audio_streaming_istft
    // 描述: mtmd_audio_streaming_istft结构体提供相关功能
    // 用途: 用于处理mtmd_audio_streaming_istft相关的操作
    // 结构体: mtmd_audio_streaming_istft
    // 描述: mtmd_audio_streaming_istft结构体提供相关功能
    // 用途: 用于处理mtmd_audio_streaming_istft相关的操作
    // 结构体: mtmd_audio_streaming_istft
    // 描述: mtmd_audio_streaming_istft结构体提供相关功能
    // 用途: 用于处理mtmd_audio_streaming_istft相关的操作
    // 结构体: mtmd_audio_streaming_istft
    // 描述: mtmd_audio_streaming_istft结构体提供相关功能
    // 用途: 用于处理mtmd_audio_streaming_istft相关的操作
    // 结构体: mtmd_audio_streaming_istft
    // 描述: mtmd_audio_streaming_istft结构体提供相关功能
    // 用途: 用于处理mtmd_audio_streaming_istft相关的操作
struct mtmd_audio_streaming_istft {
    mtmd_audio_streaming_istft(int n_fft, int hop_length);

    // reset streaming state
    // 函数: reset
    // 描述: 重置: 重置对象或状态到初始值
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: reset
    // 描述: 重置: 重置对象或状态到初始值
    // 参数: 无参数
    // 返回: 无返回值
    void reset();

    // process a single STFT frame (streaming)
    // frame_spectrum: [n_fft_bins x 2] interleaved real/imag
    // returns: up to hop_length samples
    std::vector<float> process_frame(const float * frame_spectrum);

    // flush remaining samples at end of stream
    std::vector<float> flush();

  private:
    int n_fft;
    int hop_length;
    int n_fft_bins;

    // Own cache for output processing
    mtmd_audio_cache cache;

    // Streaming state
    std::vector<float> overlap_buffer;
    std::vector<float> window_sum_buffer;
    int                padding_to_remove;

    // Working buffers for IFFT
    std::vector<float> ifft_in;
    std::vector<float> ifft_out;
};
