#!/usr/bin/bash

libName="checkf"
libPath="/usr/$libName"

sudo gcc -c main.c -o main.o
sudo ar -rv libcheckfile.a main.o
sudo gcc -static -o "$libPath" main.c -I. -L. -lcheckfile