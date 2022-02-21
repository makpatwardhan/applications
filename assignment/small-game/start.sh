#!/bin/bash
rm game.out
g++ -I include --std=c++14 src/player.cpp src/hero.cpp src/orc.cpp src/dragon.cpp src/timer.cpp -o game.out
./game.out
