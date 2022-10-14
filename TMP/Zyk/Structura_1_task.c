#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

typedef struct St1{
  int i;
  char c[128];
}st1;

void print_function(st1* masiv){
  int i, j;
  for(i=0; i < N; i++){
    printf("i=%d\n c=", (masiv+i) -> i);
    for(j=0; j < 128; j++){
      printf("%c", (masiv+i) -> c[j]);
    }
    printf("\n");
    }
  }

void zap_function(st1* s){
  int i;
  s->i = rand();
  for(i=0; i < 127; i++){
    s->c[i] = rand()%26+65;
  }
  s->c[127]='\0';
}
/*
          |
          |
          |
       ((( )))
(((((((((:)))))))))
(  )    (  )   (   ) */
int main(int argc, char* argv){
  int i;

  st1* masiv;
  masiv = (st1*)malloc(sizeof (st1) * N);

  if(masiv == NULL){
    exit(1);
  }
  srand(time(NULL));
  for(i=0;i < N; i++){
    zap_function(masiv+i);
  }
  print_function(masiv);
  return 0;
}
