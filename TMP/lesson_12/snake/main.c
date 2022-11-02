#include "gamelogic.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	int i;
	char** field;
	snake* s;
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
	

s = malloc(sizeof(snake));
if(s == NULL){
	printf("Malloc error\n");
	exit(1);
}
a = malloc(sizeof(apple));
if(a==NULL){
	printf("Malloc error\n");
	exit(1);
}

 Start(field, s, a); /*Начать игру*/
	/*while (1){
		ticker(field, a, s);
		sleep(1);
	}
	*/
	return 0;
} 

