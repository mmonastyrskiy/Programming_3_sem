#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct st1 {
  int i;
  char c[128];

};

void insert_random(struct st1* p){
  p ->i = rand();
  int iterator;
  for(iterator=0;iterator < 127;iterator++){
    p -> c[iterator] = (char)(65 +rand()%26);
    //printf("%c",p->c[iterator]);
    p -> c[127]='\0';

  }
}







void arr(int *p, int n){
  inti  i;
  srand(time(NULL));
  for (i=0; i<n; ++i) *p++=rand()%100;
}

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap_struct(struct st1 *a, struct st1 *b) {
  struct st1 tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}


void sort(int *a, int n) {
  int i;
  int j;
  for (i=0; i<n; ++i) {
    for (j=0; j<i; ++j) {
      if (*(a+i) < *(a+j)) {
        swap(a+i, a+j);
      }
    }
  }
}



void sort_struct(struct st1 *a, int n) {
  int i;
  int j;
  for (i=0; i<n; ++i) {
    for (j=0; j<i; ++j) {
      if ((a+i)->i < (a+j)->i) {
        swap_struct(a+i, a+j);
      }
    }
  }
}


int* binpoisk(int *a, int n, int k) {
   int i;
   i = n/2;
   if (i==0) return NULL;
   if (k==*(a+i)) return (a+i);
   if (k>*(a+i)) return binpoisk((a+i), i, k);
   if (k<*(a+i)) return binpoisk(a, i, k);
   return NULL;
}



struct st1* binpoisk_struct(struct st1 *a, int n, int k) {
   int i;
   i = n/2;
   if (i==0) return (struct st1) NULL;
   if (k==((a+i)->i)) return (a+i);
   if (k>*((a+i)->i)) return binpoisk((a+i), i, k);
   if (k<((a+i)->i)) return binpoisk(a, i, k);
   return (struct st1) NULL;
}



int* rev_new(int* a, int n){
  int* p;
  sort(a,n);
    if ((p=malloc(n*sizeof(int))) == NULL){
    printf("malloc: NULL\n");
    exit(1);
  }

int i;
for (i=0;i < n; i++){
  (p+i) =(a+n-1-i);
}
return p;
}

int* rev(int* a, int n){
  sort(a,n);
  int i;
  for(i=0;i<n/2;i++){
    swap((a+i),(a+n-1-i))
  }

}


void out(int*p, int n){
  int i;
  for(i=0;i<n;i++){
    printf("[%d]=%d\n",i,*(p+i));
  }
}

void out_struct(struct st1 *p, int n){
  int i;
  int j;
  for(i=0;i<n;i++){
    printf("[%d]=%d:",i,(p+i)->i);
    for(j=0;j < 127; j++){
      printf("%c",(a+i)->c[j]);
    }
    printf("\n");
  }
}


int main (int argc, char *argv[]) {
  int n;
  int k;
  int *a;
  int *b;
int *b_rev;
  if (argc >= 2) {
    n = atoi(argv[1]);
    k = atoi(argv[2]);
  }
  if ((a=malloc(n*sizeof(int))) == NULL){
    printf("malloc: NULL\n");
    exit(1);
  }
  arr(a,n);
  sort(a,n);
  int i;
  for (i=0; i<n; ++i) printf("%d %p\n", *(a+i), (a+i));
  int* ans = poisk(a,n,k);
  printf("%p   %d\n", ans, (ans-a));
  out(a,n);


 if ((b=malloc(n*sizeof(int))) == NULL){
    printf("malloc: NULL\n");
    exit(1);
  }
arr(b,n);
b_rev = rev_new(b,n);
out(b_rev,n);
rev(b,n);
out(b,n);








  int i;
  struct st1* p;
  p = malloc(n*sizeof(struct st1));
   if(p == NULL){
     exit(1);

  for (i=0;i<n;i++){
    insert_random(p +i);

  }


sort_struct(p,n);
out_struct(p,n);

binpoisk_struct(p,n,k);
}
