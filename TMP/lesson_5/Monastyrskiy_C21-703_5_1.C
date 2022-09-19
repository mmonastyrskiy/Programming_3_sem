#include <stdio.h>
#include <stdlib.h>
#define N 20
int pr3(int *p, int n){
	int i;
	for (i=0;i<n;i++){
		printf("[%d] @[%p]\n",*(p+i),(p+i));
	}
	return n;
}

void arr(int *p, int n){
	int i;
	printf("%p\n",p);
	for (int i = 0; i < n;i++){*p++=rand()%100;}
}
int main(int argc, char *argv[])
{
int* a;
a = (int*)malloc(N*sizeof(int));
if(a==NULL){
	printf("malloc:NULL\n");
	exit(1);

}

arr(a,N);
pr3(a,N);
free(a);
a=NULL;

	return 0;
}