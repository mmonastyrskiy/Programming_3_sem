#include "gamelogic.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	int i;
	char** field;
	snake* real_head;
	snake* head_ptr;
	apple* a;

srand(time(NULL));
	field = malloc(sizeof(char*)* Y_REZ);
	if(field==NULL){
		printf("Malloc error \n");
		exit(1);
	}
	for (i=0;i<Y_REZ;i++){
		field[i] = malloc(sizeof(char)* X_REZ);
		if(field[i]==NULL){
			printf("Malloc error \n");
			exit(1);
		}

		}
	

real_head = malloc(sizeof(snake));
if(real_head == NULL){
	printf("Malloc error\n");
	exit(1);
}


head_ptr = malloc(sizeof(snake));
if(head_ptr == NULL){
	printf("Malloc error\n");
	exit(1);
}
head_ptr->next = real_head;
real_head->vel_x = 1;
real_head-> vel_y =0;
real_head-> next = NULL;
real_head->prev=NULL;
real_head->score = 0;

a = malloc(sizeof(apple));
if(a==NULL){
	printf("Malloc error\n");
	exit(1);
}

 Start(field,head_ptr, a); /*Начать игру*/
	while (1){
		usleep(300000);
		ticker(field, a, head_ptr);
	}

	return 0;
} 

