#include "gamelogic.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
void printfield(char** f)
{
int i,j;
for(i=0;i<Y_REZ;i++){
	for (int j = 0; j < X_REZ; j++)
	{
		printf(" %c ",f[i][j]);
	}
	printf("\n");
}
}

void ticker(char ** field, apple* a, snake* s){
	/*system("clear");
	printfield(field);*/
}




char isEmpty(char** field,int x, int y){
	if(field[x][y] == ' '){
		return '0';
	}
	return '1';
}

 void SpawnSnake(char** field,snake* s){
 	int x,y;
 	x = rand()%X_REZ;
 	y = rand()% Y_REZ;
 	if(isEmpty(field,x,y) == '0'){
 		s->x = x;
 		s->y =y;
 		s->repr = '>';
 		return;
 	}
 	SpawnSnake(field,s);
 }



 void SpawnApple(char** field,apple* a){
 		int x,y;
 	srand(time(NULL));
 	x = (int)rand()%X_REZ;
 	y = (int)rand()% Y_REZ;
 	printf("%x %x",x,y);
 	if(isEmpty(field,x,y) == '0'){
 		a->x = x;
 		a->y =y;
 		a->repr = '0';
 		return;
 	}
 	SpawnApple(field,a);
 }
void Start(char** field, snake* s,apple* a) /*Начать игру*/{
	int i,j;

	for(i=0;i<Y_REZ;i++){
		field[i][0] = '-';
		field[i][X_REZ] = '-';

	}


	for(i=0;i<X_REZ-1;i++){
	field[0][i] = '|';
	field[Y_REZ-1][i] = '|';
	}
	for(i=1;i<Y_REZ-1;i++){
		for(j=1;j<X_REZ-1;j++){
			field[i][j] = ' ';
		}
	}
	SpawnApple(field,a);
	field[a->x][a->y] = a->repr;
	/*
	SpawnSnake(field,s);
	field[s->x][s->y] = s->repr;
	*/
}
