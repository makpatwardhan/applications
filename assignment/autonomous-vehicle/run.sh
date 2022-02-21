#!/bin/bash
rm a.out
g++ --std=c++14 -Iinclude  src/*.cpp -lpthread
./a.out
