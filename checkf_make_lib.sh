#!/usr/bin/bash

filesPath="/usr/checkf"
libName="checkf"
libPath="$filesPath/$libName"

sudo gcc -c main.c -o main.o
sudo ar -rv libcheckfile.a main.o
sudo gcc -static -o "$libPath" main.c -I. -L. -lcheckfile
