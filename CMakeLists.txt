#最低版本
cmake_minimum_required (VERSION 2.8)

#项目名称
project(Demo)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -D_MOCK_TUNNEL_ -Werror -Wno-unused-function -D_MOCK_TOLLGATE_")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

set(PROJECT_DIR  ${CMAKE_CURRENT_SOURCE_DIR})
set(HELLO_PATH ${PROJECT_DIR}/src/test_hello)

add_subdirectory(${HELLO_PATH})
