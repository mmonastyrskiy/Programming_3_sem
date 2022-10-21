#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20
#define ll long long
int main(int argc, char *argv[]){
int i,s,a[N],j,k;
/* if(argc > 1)
srand(atoi(argv[1])); */
srand(time(NULL));
for(i=0;i<N;i++){
a[i]=rand()%100;
printf("a[%d]=  %d\n",i,a[i]);
}

printf("\n\n");

for (i=0; i < N ; i++){
for (j = 0; j <i ; j++){
if(a[i] > a[j]) {
k=a[i];
a[i] = a[j];
a[j] = k;
}
}
}
for(i=0; i<N; i++){
printf("a[%d] = %d\n",i,a[i]);
}
return 0;
}
