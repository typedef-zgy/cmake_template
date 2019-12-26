cmake_minimum_required (VERSION 2.6)

set(PROJECT_FULL_NAME zthread_lib)
set(PROJECT_SHORT_NAME ztl)
project(zthread_lib)

#set(CMAKE_CXX_FLAGS "-g -pipe -std=c++0x -Wall -Wno-deprecated")
set(CMAKE_CXX_FLAGS "-g -pipe -std=c++0x -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
#file(GLOB_RECURSE HELLO_MAIN "main.cpp")
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE ZTHREAD_SRCS "src/*.cpp")
file(GLOB_RECURSE ZTHREAD_HEADS "includex/*.h")

include_directories(
        ./
        ../
        ./include/
    )

add_library(zthread_lib ${ZTHREAD_SRCS})
target_link_libraries(${PROJECT_FULL_NAME}
    ${ZTHREAD_MODULE_LIB}
    pthread
    )

install(TARGETS zthread_lib DESTINATION ${PROJECT_DIR}/lib)
#target_link_libraries(zthread_lib pthread)

#add_executable(test_hello ${HELLO_MAIN} ${HELLO_SRCS})

#install(TARGETS test_hello DESTINATION ${PROJECT_DIR}/bin)
