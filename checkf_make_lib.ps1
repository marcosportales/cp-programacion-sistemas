$libName = "checkf"
$libPath = ".\$libName"
gcc -c main.c -o main.o
ar -rv libcheckfile.a main.o
gcc "-static" -o $libPath main.c -I. -L. -lcheckfile
