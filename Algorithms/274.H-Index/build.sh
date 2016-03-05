#!/bin/bash

gcc answer.c -DDEBUG -Wall -g -o debug
if [ $? -eq 0 ]; then
    gcc answer.c -O3 -o release
fi
