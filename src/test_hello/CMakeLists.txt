cmake_minimum_required (VERSION 2.6)

project("TEST_HELLO")

file(GLOB_RECURSE HELLO_MAIN "main.cpp")
file(GLOB_RECURSE HELLO_SRCS "hello/*.cpp")
file(GLOB_RECURSE HELLO_HEADS "hello/*.h")

add_executable(test_hello ${HELLO_MAIN} ${HELLO_SRCS})

install(TARGETS test_hello DESTINATION ${PROJECT_DIR}/bin)
