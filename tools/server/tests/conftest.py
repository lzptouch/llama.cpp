// ============================================================================
// 文件: conftest.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tools/server/tests/conftest.py
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

import pytest
from utils import *


# ref: https://stackoverflow.com/questions/22627659/run-code-before-and-after-each-test-in-py-test
@pytest.fixture(autouse=True)
    # 函数: stop_server_after_each_test
    # 描述: stop_server_after_each_test函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: stop_server_after_each_test
    # 描述: stop_server_after_each_test函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def stop_server_after_each_test():
    # do nothing before each test
    yield
    # stop all servers after each test
    instances = set(
        server_instances
    )  # copy the set to prevent 'Set changed size during iteration'
    for server in instances:
        server.stop()


@pytest.fixture(scope="module", autouse=True)
    # 函数: do_something
    # 描述: do_something函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
    # 函数: do_something
    # 描述: do_something函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def do_something():
    # this will be run once per test session, before any tests
    ServerPreset.load_all()
