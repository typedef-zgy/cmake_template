#!/bin/bash
zthread_path="src/thread_lib"

echo "==============================thread_lib compile start========================================="
cd $zthread_path
sh build.sh
echo "==============================thread_lib compile end========================================="


echo "==============================demo start========================================="
cd -
sh build.sh
echo "==============================demo end========================================="
