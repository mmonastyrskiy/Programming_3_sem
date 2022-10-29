#include "lists.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	node* ptr = NULL;
	node* ptr2 = NULL;
	int i;
	char* p;
	 const char* path;
	if(argc != 2){
		printf("Error argument\n");
		exit(1);
	}
	path =argv[1];
	p=malloc(sizeof(char)* 128);
	if(p==NULL){
		printf("malloc error\n");
		exit(2);
	}



	srand(time(NULL));
	for(i=0;i<N;i++){
	gen_rand_str(p);
	ptr = add_new_head(ptr,gen_rand_int(),p);
	}
	print_list(ptr);
	dump_to_file(ptr,path);
	ptr2 = ptr;
	read_from_file(ptr2,path);
	print_list(ptr2);
	return 0;
} 
