#!/bin/bash
zthread_path="src/thread_lib"

flag=""
if [ $# -gt 1 ]; then
    echo "args too much"
    exit 0
fi

if [ $# -eq 1 ]; then
    echo "param:$1"
    flag=$1
fi

echo "param:$flag"

echo "==============================thread_lib compile start========================================="
cd $zthread_path
echo "sh build.sh $flag"
sh build.sh $flag
echo "==============================thread_lib compile end========================================="


echo "==============================demo start========================================="
cd -
echo "sh build.sh $flag"
sh build.sh $flag
echo "==============================demo end========================================="
