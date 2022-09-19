#define N 10
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
double bubble(int *array){
	int i,j,tmp;
	int* ptr;
	ptr = array;
	i = 0;
	j = 0;
	clock_t begin=clock();
	for(i;i < N; i++){
		for(j;j<N;j++){
			if (ptr+i < ptr+j){
				tmp = *(ptr+i);
				*(ptr+j) =*(ptr+i);
				*(ptr+i) = tmp;

			}
		}
	}
	clock_t end = clock();
	return (double)(end-begin);

}


double quick(int *array){
	int pivot,gc,lc,i;
	i =0;
	pivot = *array;
	int gr[N];
	int lt[N];
	clock_t begin = clock();
	for(i;i<N;i++){
		if(*(array+i) > pivot){
			*(gr+gc) = *(array+i);
			gc++;
		}
		*(lt+lc) = *(array+i);
		lc++;
	}
	i = 0;
	for(i;i<lc;i++){
		*(array+i) = *(lt+i);
	}
	*(array+lc) = pivot;


		i = 0;
	for(i;i<gc;i++){
		*(array+i+1+lc) = *(gr+i);
	}
	clock_t end = clock();
	return (double)(end-begin);


}


int main(int argc, char *argv){
	int a[N] = {0,9,2,1,4,7,6,3,5,8};
	int b[N];
	int* ptrb = b;
	int* ptra = a;
	memcpy(ptrb,ptra,N*sizeof(int));



	int i = 0;

	for(i; i<N;i++){
		printf("%d ",b[i]);
	}
	double bubble_time;
	double q_time;
bubble_time = bubble(a);
q_time = quick(b);


printf("\n\n\n");
	i = 0;

	for(i; i<N;i++){
		printf("%d ",a[i]);
}

i = 0;
printf("\n\n\n");
for(i; i<N;i++){
	printf("%d ",b[i]);
}
printf("\n");
printf("Bubble: %lf\nQuick: %lf",bubble_time,q_time );
}
