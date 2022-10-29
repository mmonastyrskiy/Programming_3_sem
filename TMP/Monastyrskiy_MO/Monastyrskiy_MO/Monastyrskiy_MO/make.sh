#!/bin/sh
gcc main.c lists.c -o main.out
gcc -c lists.c -o lists.o

ar crs liblists.a lists.o

gcc -Wall -L . main.c -o main-a.out -llists

gcc -c lists.c -fPIC -o lists-so.o

gcc -shared -o liblists-so.so lists-so.o

gcc -Wall -L . main.c -o main-so -llists-so


export LD_LIBRARY_PATH=$HOME/Monastyrskiy_MO
