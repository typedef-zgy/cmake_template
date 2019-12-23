cmake_minimum_required (VERSION 2.6)

project("ZTHREAD_LIB")

#file(GLOB_RECURSE HELLO_MAIN "main.cpp")
file(GLOB_RECURSE HELLO_SRCS "src/*.cpp")
file(GLOB_RECURSE HELLO_HEADS "includex/*.h")

include_directories(
        ./
        ../
        ./include/
    )

add_library(zthread_lib ${HELLO_SRCS})
#target_link_libraries(zthread_lib pthread)

#add_executable(test_hello ${HELLO_MAIN} ${HELLO_SRCS})

#install(TARGETS test_hello DESTINATION ${PROJECT_DIR}/bin)
