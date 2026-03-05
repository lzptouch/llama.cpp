// ============================================================================
// 文件: test_tokenize.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tools/server/tests/unit/test_tokenize.py
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

import pytest
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


    # 函数: test_tokenize_detokenize
    # 描述: test_tokenize_detokenize函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_tokenize_detokenize
    # 描述: test_tokenize_detokenize函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_tokenize_detokenize():
    global server
    server.start()
    # tokenize
    content = "What is the capital of France ?"
    res_tok = server.make_request("POST", "/tokenize", data={
        "content": content
    })
    assert res_tok.status_code == 200
    assert len(res_tok.body["tokens"]) > 5
    # detokenize
    res_detok = server.make_request("POST", "/detokenize", data={
        "tokens": res_tok.body["tokens"],
    })
    assert res_detok.status_code == 200
    assert res_detok.body["content"].strip() == content


    # 函数: test_tokenize_with_bos
    # 描述: test_tokenize_with_bos函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_tokenize_with_bos
    # 描述: test_tokenize_with_bos函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_tokenize_with_bos():
    global server
    server.start()
    # tokenize
    content = "What is the capital of France ?"
    bosId = 1
    res_tok = server.make_request("POST", "/tokenize", data={
        "content": content,
        "add_special": True,
    })
    assert res_tok.status_code == 200
    assert res_tok.body["tokens"][0] == bosId


    # 函数: test_tokenize_with_pieces
    # 描述: test_tokenize_with_pieces函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_tokenize_with_pieces
    # 描述: test_tokenize_with_pieces函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_tokenize_with_pieces():
    global server
    server.start()
    # tokenize
    content = "This is a test string with unicode 媽 and emoji 🤗"
    res_tok = server.make_request("POST", "/tokenize", data={
        "content": content,
        "with_pieces": True,
    })
    assert res_tok.status_code == 200
    for token in res_tok.body["tokens"]:
        assert "id" in token
        assert token["id"] > 0
        assert "piece" in token
        assert len(token["piece"]) > 0
