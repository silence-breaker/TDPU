#!/usr/bin/env python3
"""
quick_test.py - 快速测试脚本: 一键运行PS-PL硬件交互模拟

用法:
    python quick_test.py              # 完整流程: 提取权重 → 编译 → 运行测试
    python quick_test.py --extract    # 仅提取权重
    python quick_test.py --build      # 仅编译
    python quick_test.py --run        # 仅运行测试
"""
import subprocess
import sys
from pathlib import Path

def run_command(cmd, description):
    """执行命令并打印结果"""
    print(f"\n{'='*60}")
    print(f"[{description}]")
    print(f"{'='*60}")
    print(f"Command: {cmd}\n")

    result = subprocess.run(cmd, shell=True)
    if result.returncode != 0:
        print(f"\n✗ {description} FAILED (exit code: {result.returncode})")
        return False
    print(f"\n✓ {description} SUCCESS")
    return True

def main():
    root_dir = Path(__file__).resolve().parent

    # 解析命令行参数
    if len(sys.argv) > 1:
        mode = sys.argv[1]
    else:
        mode = "--all"

    steps = []
    if mode in ["--all", "--extract"]:
        steps.append(("Extract weights",
            f'powershell -Command "cd \'{root_dir}\'; conda activate icraft_env; python models/extract_weights.py"'))

    if mode in ["--all", "--build"]:
        steps.append(("Build test_real_weights",
            f'powershell -Command "cd \'{root_dir}/icraft_plugin/build\'; cmake --build . --config Release"'))

    if mode in ["--all", "--run"]:
        weight_file = root_dir / "models" / "output" / "q_proj_weights.bin"
        steps.append(("Run PS-PL simulation",
            f'"{root_dir}/icraft_plugin/build/Release/test_real_weights.exe" "{weight_file}"'))

    # 执行步骤
    results = []
    for desc, cmd in steps:
        success = run_command(cmd, desc)
        results.append((desc, success))

    # 总结
    print(f"\n{'='*60}")
    print("SUMMARY")
    print(f"{'='*60}")
    for desc, success in results:
        status = "✓ PASS" if success else "✗ FAIL"
        print(f"{status}: {desc}")

    all_pass = all(success for _, success in results)
    return 0 if all_pass else 1

if __name__ == "__main__":
    sys.exit(main())
