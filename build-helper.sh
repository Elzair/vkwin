#!/bin/sh
VKWINROOT=$(dirname $(readlink -f $0))
cd $VKWINROOT
if [ $1 = "full" ]; then
    rm -rf build
    mkdir build
fi
cd build
cmake .. && make
