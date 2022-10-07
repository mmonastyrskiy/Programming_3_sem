#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <fcntl.h>
#include <time.h>
#define BUFFER_SIZE 4096
#define N 10
#define INFlags O_RDONLY
#define OFlags O_WRONLY|O_CREAT|O_EXCL


typedef struct st1
{
	int i;
	char[128] c;
}st1;

void add_new_rd(st1* ptr){
	  int iterator;
	srand(time(NULL));
	p ->i = rand();
  	for(iterator=0;iterator < 127;iterator++){
    ptr -> c[iterator] = (char)(65 +rand()%26);
    ptr -> c[127]='\0';

}
}

size_t dump_to_file(st1* ptr){
	int fdw;
	int i;
	size_t fw;
	fw =0
	fdw = open(argv[1],OFlags,0600);
	if(fdw < 0){
		perror("File not opend for writing");
		exit(2);
	}
	for(i=0;i<N;i++){
	fw += write(fdw,ptr[i],sizeof(st1));
}

return fw;
}
size_t read_from_file(st1* ptr, char* path){
	
}
int main(int argc, char const *argv[])
{
	int i;
	if(argc < 3){
		fprintf(stderr,"Argument error \n");
		exit(1);
	}
	st1* array;
	array = malloc(sizeof(st1)*N);
	if (array == NULL){
		perror("malloc fault");
	}

for(i=0;i<N;i++;){
	add_new_rd(array + i);
}





	return 0;
}