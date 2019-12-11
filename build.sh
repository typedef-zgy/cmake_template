#!/bin/bash
CMAKE_BUILD_TYPE=DEBUG
build_flag=0

if [ $# -eq 0 ]; then
    build_flag=1
fi

until [ $# -eq 0   ]
do
    if [[ $1 = "debug" ]]; then
        build_flag=1
        CMAKE_BUILD_TYPE=DEBUG
    elif [[ $1 = "release" ]]; then
        build_flag=1
        CMAKE_BUILD_TYPE=RELEASE
    elif [[ $1 = "clean" ]]; then
        if [ -d "build" ]; then
            rm -rf build/*
            #echo `ls -al build`
            echo "clean success!!!"
        else
            echo "no need clean"
        fi
    else
        echo "UNKNOWN PARAM: $1"
        exit 1
    fi
    shift
done

if [ ${build_flag} -eq 0 ]; then
    exit 0
fi

mkdir -p ./build
cd build

CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
echo "CMAKE_FLAGS: $CMAKE_FLAGS"

cmake $CMAKE_FLAGS ..
make install -j40
