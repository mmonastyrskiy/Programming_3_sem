#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void insert(int* a, int n){
	int i;
	for(i=0;i<n;i++){
		*(a+i) = rand()%100;
	}
}
void sort(int* array, int n){
	int i,j,t;
	int* ptr;
	ptr = array;
	i = 0;
	j = 0;
	for (i = 0; i < n; i++) {

			for (j = i + 1; j < n; j++) {

					if (*(ptr + j) < *(ptr + i)) {

							t = *(ptr + i);
							*(ptr + i) = *(ptr + j);
							*(ptr + j) = t;
					}
			}
	}


}
int main(int argc, char  *argv[])
{
	srand(time(NULL));
	int n;
	int* a;
	if (argc > 1){
		n = atoi(argv[1]);
	}
	a = (int*)malloc(n*sizeof(int));
	if(a ==NULL){
		exit(1);
	}
	insert(a,n);
	int i;
	i =0;
	for(i;i<n;i++){
		printf("a[%d]= %d\n",i,*(a+i));
	}
	sort(a,n);
	for(i;i<n;i++){
		printf("a[%d]= %d\n",i,*(a+i));
	}
	return 0;
}