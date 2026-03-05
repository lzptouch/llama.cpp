// ============================================================================
// 文件: test_ctx_shift.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tools/server/tests/unit/test_ctx_shift.py
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

import pytest
from utils import *

server = ServerPreset.tinyllama2()


SHORT_TEXT = """
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
""".strip()

LONG_TEXT = """
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
""".strip()

@pytest.fixture(autouse=True)
    # 函数: create_server
    # 描述: create_server函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: create_server
    # 描述: create_server函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def create_server():
    global server
    server = ServerPreset.tinyllama2()
    server.n_ctx = 512
    server.n_slots = 2
    server.n_predict = 128


    # 函数: test_ctx_shift_enabled
    # 描述: test_ctx_shift_enabled函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_ctx_shift_enabled
    # 描述: test_ctx_shift_enabled函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_ctx_shift_enabled():
    # the prompt is 226 tokens
    # the slot context is 512/2 = 256 tokens
    # 96 tokens are generated thanks to shifting the context when it gets full
    global server
    server.enable_ctx_shift = True
    server.start()
    res = server.make_request("POST", "/completion", data={
        "n_predict": 96,
        "prompt": SHORT_TEXT,
    })
    assert res.status_code == 200
    assert res.body["timings"]["prompt_n"] == 226
    assert res.body["timings"]["predicted_n"] == 96
    assert res.body["truncated"] is True


@pytest.mark.parametrize("n_predict,n_token_output,truncated", [
    (64, 64, False),
    (-1, 248, True), # 8 tokens prompt + 248 tokens generated = 256 tokens total
])
    # 函数: test_ctx_shift_disabled_short_prompt
    # 描述: test_ctx_shift_disabled_short_prompt函数提供相关功能
    # 参数: n_predict: int, n_token_output: int, truncated: bool
    # 返回: 无返回值
    # 函数: test_ctx_shift_disabled_short_prompt
    # 描述: test_ctx_shift_disabled_short_prompt函数提供相关功能
    # 参数: n_predict: int, n_token_output: int, truncated: bool
    # 返回: 无返回值
def test_ctx_shift_disabled_short_prompt(n_predict: int, n_token_output: int, truncated: bool):
    global server
    server.n_predict = -1
    server.start()
    res = server.make_request("POST", "/completion", data={
        "n_predict": n_predict,
        "prompt": "Hi how are you",
    })
    assert res.status_code == 200
    assert res.body["timings"]["predicted_n"] == n_token_output
    assert res.body["truncated"] == truncated


    # 函数: test_ctx_shift_disabled_long_prompt
    # 描述: test_ctx_shift_disabled_long_prompt函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_ctx_shift_disabled_long_prompt
    # 描述: test_ctx_shift_disabled_long_prompt函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_ctx_shift_disabled_long_prompt():
    global server
    server.start()
    res = server.make_request("POST", "/completion", data={
        "n_predict": 64,
        "prompt": LONG_TEXT,
    })
    assert res.status_code != 200
    assert "error" in res.body
    assert "exceeds the available context size" in res.body["error"]["message"]

    # 函数: test_ctx_shift_disabled_stream
    # 描述: test_ctx_shift_disabled_stream函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_ctx_shift_disabled_stream
    # 描述: test_ctx_shift_disabled_stream函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_ctx_shift_disabled_stream():
    global server
    server.start()
    res = server.make_stream_request("POST", "/v1/completions", data={
        "n_predict": 256,
        "prompt": "Once",
        "stream": True,
    })
    content = ""
    for data in res:
        choice = data["choices"][0]
        if choice["finish_reason"] == "length":
            assert len(content) > 0
        else:
            assert choice["finish_reason"] is None
            content += choice["text"]
