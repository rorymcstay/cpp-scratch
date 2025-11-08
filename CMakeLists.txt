cmake_minimum_required(VERSION 3.28)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cpp_scratch)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)
