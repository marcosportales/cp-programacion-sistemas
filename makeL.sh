#!/usr/bin/bash

sudo gcc -c main.c -o main.o
sudo ar -rv libcheckfile.a main.o
sudo gcc -static -o /usr/checkf main.c -I. -L. -lcheckfile
#sudo /usr/checkf