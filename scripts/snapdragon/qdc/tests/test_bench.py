// ============================================================================
// 文件: test_bench.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/scripts/snapdragon/qdc/tests/test_bench.py
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

import pytest
import subprocess
import sys

tmp_path='/data/local/tmp'
pkg_path=f'{tmp_path}/llama.cpp'
lib_path=f'{pkg_path}/lib'
bin_path=f'{pkg_path}/bin'

model='../gguf/Llama-3.2-1B-Instruct-Q4_0.gguf'
cli_pref=f'cd {pkg_path} && LD_LIBRARY_PATH={lib_path} ADSP_LIBRARY_PATH={lib_path} {bin_path}'


    # 函数: run_cmd
    # 描述: run_cmd函数提供相关功能
    # 参数: cmd
    # 返回: 有返回值
def run_cmd(cmd):
    p = subprocess.run(cmd, text = True, stdout = subprocess.PIPE, stderr = subprocess.STDOUT)
    sys.stdout.write(p.stdout)
    assert(p.returncode == 0)


@pytest.mark.dependency()
    # 函数: test_install
    # 描述: test_install函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_install():
    run_cmd(['adb', 'push', 'llama.cpp', f'{tmp_path}'])
    run_cmd(['adb', 'shell', f'chmod 755 {bin_path}/*'])


## Basic cli tests
    # 函数: run_llama_cli
    # 描述: run_llama_cli函数提供相关功能
    # 参数: dev, opts
    # 返回: 无返回值
def run_llama_cli(dev, opts):
    prompt='what is the most popular cookie in the world?\nPlease provide a very brief bullet point summary.\nBegin your answer with **BEGIN**.'
    opts = '--batch-size 128 -n 128 -no-cnv --seed 42 ' + opts
    run_cmd(['adb', 'shell', f'{cli_pref}/llama-cli -m {model} --device {dev} -ngl 99 -t 4 {opts} -p "{prompt}"'])


@pytest.mark.dependency(depends=['test_install'])
    # 函数: test_llama_cli_cpu
    # 描述: test_llama_cli_cpu函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_llama_cli_cpu():
    run_llama_cli('none', '-ctk q8_0 -ctv q8_0 -fa on')


@pytest.mark.dependency(depends=['test_install'])
    # 函数: test_llama_cli_gpu
    # 描述: test_llama_cli_gpu函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_llama_cli_gpu():
    run_llama_cli('GPUOpenCL', '-fa on')


@pytest.mark.dependency(depends=['test_install'])
    # 函数: test_llama_cli_npu
    # 描述: test_llama_cli_npu函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_llama_cli_npu():
    run_llama_cli('HTP0', '-ctk q8_0 -ctv q8_0 -fa on')


## Basic bench tests
    # 函数: run_llama_bench
    # 描述: run_llama_bench函数提供相关功能
    # 参数: dev
    # 返回: 无返回值
def run_llama_bench(dev):
    run_cmd(['adb', 'shell', f'{cli_pref}/llama-bench -m {model} --device {dev} -ngl 99 --batch-size 128 -t 4 -p 128 -n 32'])


@pytest.mark.dependency(depends=['test_install'])
    # 函数: test_llama_bench_cpu
    # 描述: test_llama_bench_cpu函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_llama_bench_cpu():
    run_llama_bench('none')


    # 函数: test_llama_bench_gpu
    # 描述: test_llama_bench_gpu函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_llama_bench_gpu():
    run_llama_bench('GPUOpenCL')


    # 函数: test_llama_bench_npu
    # 描述: test_llama_bench_npu函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def test_llama_bench_npu():
    run_llama_bench('HTP0')
