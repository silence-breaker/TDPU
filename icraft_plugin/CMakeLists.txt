cmake_minimum_required(VERSION 3.24)
project(icraft_bitlinear_plugin LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# MSVC 编译参数 (与 Icraft 官方示例一致)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/Zi>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/permissive->")
add_link_options("$<$<CXX_COMPILER_ID:MSVC>:/INCREMENTAL:NO>")
add_link_options("$<$<CXX_COMPILER_ID:MSVC>:/DEBUG>")
add_link_options("$<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Release>>:/OPT:REF>")
add_link_options("$<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Release>>:/OPT:ICF>")

# ============================================================
# Icraft SDK 路径 (Windows 安装目录)
# 可通过 -DICRAFT_SDK_DIR=... 覆盖
# ============================================================
if(NOT DEFINED ICRAFT_SDK_DIR)
    set(ICRAFT_SDK_DIR "C:/Icraft/CLI v3.33.1")
endif()
list(APPEND CMAKE_PREFIX_PATH "${ICRAFT_SDK_DIR}/cmake")

# 查找 Icraft 依赖库 (按组件查找, HostBackend 会自动拉取 XRT → XIR → Utils)
find_package(Icraft-HostBackend REQUIRED)

# ============================================================
# 共享库: BitLinear 算子插件
# ============================================================
add_library(icraft.tdpu.bitlinear SHARED
    src/bitlinear_op.cpp
    src/bitlinear_host_forward.cpp
    src/bitlinear_pass.cpp
)
target_include_directories(icraft.tdpu.bitlinear PRIVATE include)
target_link_libraries(icraft.tdpu.bitlinear PRIVATE
    Icraft::HostBackend
)

# ============================================================
# 测试程序: 手动构建 XIR 网络验证
# 直接编译插件源文件 (DLL 无导出符号, 不生成 .lib)
# ============================================================
add_executable(test_bitlinear
    test/test_bitlinear.cpp
    src/bitlinear_op.cpp
    src/bitlinear_host_forward.cpp
)
target_include_directories(test_bitlinear PRIVATE include)
target_link_libraries(test_bitlinear PRIVATE
    Icraft::HostBackend
)
