#最低版本
cmake_minimum_required (VERSION 2.8)

#项目名称
project(Demo)

set(CMAKE_CXX_FLAGS "-g -pipe -Wall -pthread")
#set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(PROJECT_DIR  ${CMAKE_CURRENT_SOURCE_DIR})
set(ZTHREAD_LIB ${PROJECT_DIR}/src/thread_lib)
set(HELLO_PATH ${PROJECT_DIR}/src/test_hello)

add_subdirectory(${ZTHREAD_LIB})
add_subdirectory(${HELLO_PATH})
