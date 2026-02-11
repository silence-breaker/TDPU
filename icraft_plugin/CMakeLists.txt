cmake_minimum_required(VERSION 3.14)
project(icraft_bitlinear_plugin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Icraft SDK (Windows 环境, 已在 PATH 中)
find_package(Icraft REQUIRED COMPONENTS xir xrt hostbackend)

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
    Icraft::XIR
    Icraft::XRT
    Icraft::HostBackend
)

# ============================================================
# 测试程序: 手动构建 XIR 网络验证
# ============================================================
add_executable(test_bitlinear test/test_bitlinear.cpp)
target_include_directories(test_bitlinear PRIVATE include)
target_link_libraries(test_bitlinear PRIVATE
    icraft.tdpu.bitlinear
    Icraft::XIR
    Icraft::XRT
    Icraft::HostBackend
)
