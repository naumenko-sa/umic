#!/bin/bash
g++ -std=c++11 -o `basename $1 .cpp` $1
