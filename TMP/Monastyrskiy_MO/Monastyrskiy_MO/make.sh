gcc main.c lists.c -o main
gcc -c lists.c
ar crs liblists.a lists.o
gcc -Wall -L $HOME/Monastyrskiy_MO main.c -o main-a -llists

gcc -c lists.c -fPIC -o lists-so.o
gcc -shared -o liblists-so.so lists-so.o
gcc -Wall -L $HOME/Monastyrskiy_MO main.c -o main-so -llists-so
export LD_LIBRARY_PATH=$HOME/Monastyrskiy_MO
