// ============================================================================
// 文件: test_security.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tools/server/tests/unit/test_security.py
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

import pytest
from openai import OpenAI
from utils import *

server = ServerPreset.tinyllama2()

TEST_API_KEY = "sk-this-is-the-secret-key"

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
    server.api_key = TEST_API_KEY


@pytest.mark.parametrize("endpoint", ["/health", "/models"])
    # 函数: test_access_public_endpoint
    # 描述: test_access_public_endpoint函数提供相关功能
    # 参数: endpoint: str
    # 返回: 无返回值
    # 函数: test_access_public_endpoint
    # 描述: test_access_public_endpoint函数提供相关功能
    # 参数: endpoint: str
    # 返回: 无返回值
def test_access_public_endpoint(endpoint: str):
    global server
    server.start()
    res = server.make_request("GET", endpoint)
    assert res.status_code == 200
    assert "error" not in res.body


@pytest.mark.parametrize("api_key", [None, "invalid-key"])
    # 函数: test_incorrect_api_key
    # 描述: test_incorrect_api_key函数提供相关功能
    # 参数: api_key: str
    # 返回: 无返回值
    # 函数: test_incorrect_api_key
    # 描述: test_incorrect_api_key函数提供相关功能
    # 参数: api_key: str
    # 返回: 无返回值
def test_incorrect_api_key(api_key: str):
    global server
    server.start()
    res = server.make_request("POST", "/completions", data={
        "prompt": "I believe the meaning of life is",
    }, headers={
        "Authorization": f"Bearer {api_key}" if api_key else None,
    })
    assert res.status_code == 401
    assert "error" in res.body
    assert res.body["error"]["type"] == "authentication_error"


    # 函数: test_correct_api_key
    # 描述: test_correct_api_key函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_correct_api_key
    # 描述: test_correct_api_key函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_correct_api_key():
    global server
    server.start()
    res = server.make_request("POST", "/completions", data={
        "prompt": "I believe the meaning of life is",
    }, headers={
        "Authorization": f"Bearer {TEST_API_KEY}",
    })
    assert res.status_code == 200
    assert "error" not in res.body
    assert "content" in res.body


    # 函数: test_correct_api_key_anthropic_header
    # 描述: test_correct_api_key_anthropic_header函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_correct_api_key_anthropic_header
    # 描述: test_correct_api_key_anthropic_header函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_correct_api_key_anthropic_header():
    global server
    server.start()
    res = server.make_request("POST", "/completions", data={
        "prompt": "I believe the meaning of life is",
    }, headers={
        "X-Api-Key": TEST_API_KEY,
    })
    assert res.status_code == 200
    assert "error" not in res.body
    assert "content" in res.body


    # 函数: test_openai_library_correct_api_key
    # 描述: test_openai_library_correct_api_key函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: test_openai_library_correct_api_key
    # 描述: test_openai_library_correct_api_key函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_openai_library_correct_api_key():
    global server
    server.start()
    client = OpenAI(api_key=TEST_API_KEY, base_url=f"http://{server.server_host}:{server.server_port}")
    res = client.chat.completions.create(
        model="gpt-3.5-turbo",
        messages=[
            {"role": "system", "content": "You are a chatbot."},
            {"role": "user", "content": "What is the meaning of life?"},
        ],
    )
    assert len(res.choices) == 1


@pytest.mark.parametrize("origin,cors_header,cors_header_value", [
    ("localhost", "Access-Control-Allow-Origin", "localhost"),
    ("web.mydomain.fr", "Access-Control-Allow-Origin", "web.mydomain.fr"),
    ("origin", "Access-Control-Allow-Credentials", "true"),
    ("web.mydomain.fr", "Access-Control-Allow-Methods", "GET, POST"),
    ("web.mydomain.fr", "Access-Control-Allow-Headers", "*"),
])
    # 函数: test_cors_options
    # 描述: test_cors_options函数提供相关功能
    # 参数: origin: str, cors_header: str, cors_header_value: str
    # 返回: 无返回值
    # 函数: test_cors_options
    # 描述: test_cors_options函数提供相关功能
    # 参数: origin: str, cors_header: str, cors_header_value: str
    # 返回: 无返回值
def test_cors_options(origin: str, cors_header: str, cors_header_value: str):
    global server
    server.start()
    res = server.make_request("OPTIONS", "/completions", headers={
        "Origin": origin,
        "Access-Control-Request-Method": "POST",
        "Access-Control-Request-Headers": "Authorization",
    })
    assert res.status_code == 200
    assert cors_header in res.headers
    assert res.headers[cors_header] == cors_header_value


@pytest.mark.parametrize(
    "media_path, image_url, success",
    [
        (None,             "file://mtmd/test-1.jpeg",    False), # disabled media path, should fail
        ("../../../tools", "file://mtmd/test-1.jpeg",    True),
        ("../../../tools", "file:////mtmd//test-1.jpeg", True),  # should be the same file as above
        ("../../../tools", "file://mtmd/notfound.jpeg",  False), # non-existent file
        ("../../../tools", "file://../mtmd/test-1.jpeg", False), # no directory traversal
    ]
)
    # 函数: test_local_media_file
    # 描述: test_local_media_file函数提供相关功能
    # 参数: media_path, image_url, success,
    # 返回: 无返回值
    # 函数: test_local_media_file
    # 描述: test_local_media_file函数提供相关功能
    # 参数: media_path, image_url, success,
    # 返回: 无返回值
def test_local_media_file(media_path, image_url, success,):
    server = ServerPreset.tinygemma3()
    server.media_path = media_path
    server.start()
    res = server.make_request("POST", "/chat/completions", data={
        "max_tokens": 1,
        "messages": [
            {"role": "user", "content": [
                {"type": "text", "text": "test"},
                {"type": "image_url", "image_url": {
                    "url": image_url,
                }},
            ]},
        ],
    })
    if success:
        assert res.status_code == 200
    else:
        assert res.status_code == 400
