cmake_minimum_required(VERSION 3.25.1)

# need to set this compiler if you want to debug with lldb
# set it before project call
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -g -O0 -fstandalone-debug")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(prototype)

set(SOURCE ${PROJECT_NAME}.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
