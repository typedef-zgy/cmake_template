#最低版本
cmake_minimum_required (VERSION 2.8)

#项目名称
project(Demo)

set(CMAKE_CXX_FLAGS "-g -pipe -Wall -std=c++0x")
#set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(PROJECT_DIR  ${CMAKE_CURRENT_SOURCE_DIR})
set(HELLO_PATH ${PROJECT_DIR}/src/test_hello)

set(ZTHREAD_MODULE ${PROJECT_DIR}/src/thread_lib)
set(ZTHREAD_MODULE_INCLUDE ${PROJECT_DIR}/src/thread_lib/include)
file(GLOB_RECURSE ZTHREAD_MODULE_LIB "${PROJECT_DIR}/src/thread_lib/lib/*.a")

add_subdirectory(${HELLO_PATH})
