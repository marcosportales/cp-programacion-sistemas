#!/usr/bin/bash

gcc -c main.c -o main.o
ar -rv libcheckfile.a main.o
gcc -static -o checkf main.c -I. -L. -libcheckfile
./checkf