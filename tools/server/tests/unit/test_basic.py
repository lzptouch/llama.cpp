// ============================================================================
// 文件: test_basic.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tools/server/tests/unit/test_basic.py
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

import pytest
import requests
from utils import *

server = ServerPreset.tinyllama2()


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


    # 函数: test_server_start_simple
    # 描述: test_server_start_simple函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_server_start_simple
    # 描述: test_server_start_simple函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_server_start_simple():
    global server
    server.start()
    res = server.make_request("GET", "/health")
    assert res.status_code == 200


    # 函数: test_server_props
    # 描述: test_server_props函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_server_props
    # 描述: test_server_props函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_server_props():
    global server
    server.start()
    res = server.make_request("GET", "/props")
    assert res.status_code == 200
    assert ".gguf" in res.body["model_path"]
    assert res.body["total_slots"] == server.n_slots
    default_val = res.body["default_generation_settings"]
    assert server.n_ctx is not None and server.n_slots is not None
    assert default_val["n_ctx"] == server.n_ctx / server.n_slots
    assert default_val["params"]["seed"] == server.seed


    # 函数: test_server_models
    # 描述: test_server_models函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_server_models
    # 描述: test_server_models函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_server_models():
    global server
    server.start()
    res = server.make_request("GET", "/models")
    assert res.status_code == 200
    assert len(res.body["data"]) == 1
    assert res.body["data"][0]["id"] == server.model_alias


    # 函数: test_server_slots
    # 描述: test_server_slots函数提供相关功能
    # 参数: 无参数
    # 返回: 有返回值
    # 函数: test_server_slots
    # 描述: test_server_slots函数提供相关功能
    # 参数: 无参数
    # 返回: 有返回值
def test_server_slots():
    global server

    # without slots endpoint enabled, this should return error
    server.server_slots = False
    server.start()
    res = server.make_request("GET", "/slots")
    assert res.status_code == 501 # ERROR_TYPE_NOT_SUPPORTED
    assert "error" in res.body
    server.stop()

    # with slots endpoint enabled, this should return slots info
    server.server_slots = True
    server.n_slots = 2
    server.start()
    res = server.make_request("GET", "/slots")
    assert res.status_code == 200
    assert len(res.body) == server.n_slots
    assert server.n_ctx is not None and server.n_slots is not None
    assert res.body[0]["n_ctx"] == server.n_ctx / server.n_slots
    assert "params" not in res.body[0]


    # 函数: test_load_split_model
    # 描述: test_load_split_model函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_load_split_model
    # 描述: test_load_split_model函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_load_split_model():
    global server
    server.offline = False
    server.model_hf_repo = "ggml-org/models"
    server.model_hf_file = "tinyllamas/split/stories15M-q8_0-00001-of-00003.gguf"
    server.model_alias = "tinyllama-split"
    server.start()
    res = server.make_request("POST", "/completion", data={
        "n_predict": 16,
        "prompt": "Hello",
        "temperature": 0.0,
    })
    assert res.status_code == 200
    assert match_regex("(little|girl)+", res.body["content"])


    # 函数: test_no_webui
    # 描述: test_no_webui函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_no_webui
    # 描述: test_no_webui函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_no_webui():
    global server
    # default: webui enabled
    server.start()
    url = f"http://{server.server_host}:{server.server_port}"
    res = requests.get(url)
    assert res.status_code == 200
    assert "<!doctype html>" in res.text
    server.stop()

    # with --no-webui
    server.no_webui = True
    server.start()
    res = requests.get(url)
    assert res.status_code == 404


    # 函数: test_server_model_aliases_and_tags
    # 描述: test_server_model_aliases_and_tags函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_server_model_aliases_and_tags
    # 描述: test_server_model_aliases_and_tags函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_server_model_aliases_and_tags():
    global server
    server.model_alias = "tinyllama-2,fim,code"
    server.model_tags = "chat,fim,small"
    server.start()
    res = server.make_request("GET", "/models")
    assert res.status_code == 200
    assert len(res.body["data"]) == 1
    model = res.body["data"][0]
    # aliases field must contain all aliases
    assert set(model["aliases"]) == {"tinyllama-2", "fim", "code"}
    # tags field must contain all tags
    assert set(model["tags"]) == {"chat", "fim", "small"}
    # id is derived from first alias (alphabetical order from std::set)
    assert model["id"] == "code"
