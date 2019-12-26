#!/bin/bash

if [ ! -d "build"  ]; then
echo "Make Folder!"
    mkdir build
else
    echo "Clear Folder!"
    rm -rf ./build/*
fi

CMAKE_BUILD_TYPE=DEBUG
cd build

if [[ $1 = "debug"  ]]; then
    CMAKE_BUILD_TYPE=DEBUG
fi

if [[ $1 = "release"  ]]; then
    CMAKE_BUILD_TYPE=RELEASE
fi

if [[ $1 = ""  ]]; then
    CMAKE_BUILD_TYPE=DEBUG
fi


CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"

echo "CMAKE_FLAGS:${CMAKE_FLAGS}"

cmake ${CMAKE_FLAGS} ..

make install -j8

