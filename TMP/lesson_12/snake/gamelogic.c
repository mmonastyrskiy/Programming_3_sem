#include "gamelogic.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void MoveUp(char** field,snake* s); /* обрабатывает нажатие на стрелочку вверх для головы*/{
	if(s->y+1 > Y_REZ-1){
		s->y = s->y+2-Y_REZ;
	}
	s->y = s->y+1;
}
void MoveDown(char** field,snake* s); /* обрабатывает нажатие на стрелочку вниз для головы*/
void MoveLeft(char** field, snake* s); /* обрабатывает нажатие на стрелочку влево для головы*/
void MoveRight(char** field, snake* s); /* обрабатывает нажатие на стрелочку вправо для головы*/




void Move(char** field,snake* s); /* Движение такт без нажатия клавиши, и Движение всей остальной змеи*/
{
	int prev_x, prev_y;
	prev_ x = s-> x ;
	prev_y - s -> y;
	s-> x = s-> next ->x;
	s-> y = s -> next -> y;
	field[prev_y][prev_x] = '.';
}

void SnakeMover(char** field,snake* s); /*Общий метод движения змеи*/
{
	snake t;
	t = s;
	while (!(isHead(t)=='0')){
		Move(field, s);
		t = t-> next;
	}
	if(s-> vel_x == 1 ){
		MoveRight(field,t);
	}
	if(s-> vel_x == -1){
		MoveRight(field, t);
	}
	if(s-> vel_y == 1){
		MoveUp(field,t);
	}
	if(s->vel_y == -1){
		MoveDown(field,t);
	}
}

void printfield(char** f)
{
int i,j;
for(i=0;i<Y_REZ;i++){
	for (j = 0; j < X_REZ; j++)
	{
		printf(" %c ",f[i][j]);
	}
	printf("\n");
}
}

void ticker(char ** field, apple* a, snake* s){
	SnakeMover(field,snake);
	system("clear");
	printfield(field);
}




char isEmpty(char** field,int x, int y){
	if((x >= 1 && x < X_REZ) && (y >=1 && y < Y_REZ) &&(field[y][x] == '.')){
		return '0';
	}
	return '1';
}

 void SpawnSnake(char** field,snake* s){
 	int x,y;
 	x = rand()% X_REZ;
 	y = rand()%Y_REZ;
 	if(isEmpty(field,x,y) == '0'){
 		s->x = x;
 		s->y =y;
 		field[x][y] = '>';
 		return;
 	}
 	SpawnSnake(field,s);
 }



 void SpawnApple(char** field,apple* a){
 		int x;
 		int y;
 	x = rand() % X_REZ;
 	y = rand() % Y_REZ;
 	printf("SpawnApple: %d",y);
 	if(isEmpty(field,x,y) == '0'){
 		a->x = x;
 		a->y =y;
		field[y][x] = '0';
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
			field[i][j] = '.';
		}
	}
	SpawnApple(field,a);

	SpawnSnake(field,s);
}
