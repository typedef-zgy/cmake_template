cmake_minimum_required (VERSION 2.6)

set(PROJECT_FULL_NAME test_hello)
set(PROJECT_SHORT_NAME th)
project(test_hell)

file(GLOB_RECURSE HELLO_MAIN "main.cpp")
file(GLOB_RECURSE HELLO_SRCS "hello/*.cpp")
file(GLOB_RECURSE HELLO_HEADS "hello/*.h")

include_directories(
    ./
    ../
    ${ZTHREAD_MODULE_INCLUDE}
    )
add_executable(${PROJECT_FULL_NAME} ${HELLO_MAIN} ${HELLO_SRCS})
target_link_libraries(${PROJECT_FULL_NAME}
    ${ZTHREAD_MODULE_LIB}
    pthread
    )

install(TARGETS test_hello DESTINATION ${PROJECT_DIR}/bin)
