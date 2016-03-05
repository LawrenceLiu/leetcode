#!/bin/bash

# specify for GNU gdb
#gcc answer.c -DDEBUG -Wall -ggdb -o debug
# nomal
#gcc answer.c -DDEBUG -Wall -g -o debug
# MAC have no gdb :-(
gcc answer.c -DDEBUG -Wall -o debug
if [ $? -eq 0 ]; then
    gcc answer.c -O3 -o release
fi
