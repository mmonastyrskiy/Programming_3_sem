#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <fcntl.h>
#include <time.h>
#define BUFFER_SIZE 4096
#define N 10
#define INFlags O_RDONLY
#define OFlags O_WRONLY | O_CREAT


typedef struct st1
{
	int i;
	char c[128];
}st1;

void add_new_rd(st1* ptr){
	  int iterator;
	ptr ->i = rand();
  	for(iterator=0;iterator < 127;iterator++){
    ptr -> c[iterator] = (char)(65 +rand()%26);
    ptr -> c[127]='\0';

}
}

size_t dump_to_file(st1* ptr,char* path){
	int fdw;
	int i;
	size_t fw;
	fw =0;
	fdw = open(path,OFlags,0600);
	if(fdw < 0){
		perror("File not opend for writing");
		exit(2);
	}
	for(i=0;i<N;i++){
	fw += write(fdw,&(ptr[i]),sizeof(st1));
}
close(fdw);
return fw;
}
size_t read_from_file(st1* ptr,char* path){
	int fdr;
	int i;
	size_t fr;
	fr = 0;
	fdr = open(path,INFlags);
	if(fdr < 0){
		perror("File not opend for reading");
		exit(3);	
	}


	for(i=0;i<N;i++){
		fr += read(fdr,&(ptr[i]),sizeof(st1));
	}
	close(fdr);
	return fr;
}

void print_out(st1* ptr){
	int i,j;
	for(i=0;i<N;i++){


		printf("%d\n",ptr[i].i);
		for(j=0;j<128;j++){
			printf("%c",ptr[i].c[j]);
		}
		printf("\n");

	}
}

int main(int argc, char const *argv[])
{
	int i;
	st1* array;
	st1* array_copy;
	srand(time(NULL));
	if(argc < 3){
		fprintf(stderr,"Argument error \n");
		exit(1);
	}
	array = malloc(sizeof(st1)*N);
	if (array == NULL){
		perror("malloc fault");
	}

for(i=0;i<N;i++){
	add_new_rd(array + i);
}

dump_to_file(array,argv[1]);


	array_copy = malloc(sizeof(st1)*N);
	if (array_copy == NULL){
		perror("malloc fault");
	}
read_from_file(array_copy,argv[2]);
print_out(array_copy);
	return 0;
}
