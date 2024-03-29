#!/usr/bin/bash

filesPath="/usr/checkf"
libName="checkf"
libPath="$filesPath/$libName"

configPath="/etc/sec-info"

sudo mkdir "$configPath/"
sudo touch "$configPath/file.conf"
sudo touch "$configPath/log.txt"
sudo chmod 777 "$configPath/log.txt"

sudo gcc -c main.c -o main.o
sudo ar -rv libcheckfile.a main.o
sudo gcc -static -o $libPath main.c -I. -L. -lcheckfile