#!/bin/bash

set -x
g++ -std=c++11 $* -o a.out && ./a.out
