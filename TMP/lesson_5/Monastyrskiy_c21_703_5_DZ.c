#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct st1 {
  int i;
  char* c[128];

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



  void print_out(struct st1* p){
    int idx;
    idx = 0;
    printf("\np[i]= %d\n",p->i);
     while(p->c[idx]!='\0'){
       //printf('%c',p->c[0]);
       printf("%c",p->c[idx]);
       idx++;
     }
     printf("\n");

  }



 int main(int argc, char *argv[]){
      int N;
   srand(time(NULL));
    if(argc > 1  || atoi(argv[1])<= 0){
      N = atoi(argv[1]);
    }
   struct st1* ptr;
   ptr = malloc(N*sizeof(struct st1));
   if(ptr == NULL){
     exit(1);
   }
   int i;
   for(i=0;i < N;i++){
     insert_random(ptr+i);
   }
   for(i=0;i < N;i++){
     printf("struct[%d]\n",i);
     print_out(ptr+i);
   }
   free(ptr);
   ptr = NULL;
   return 0;
 }
