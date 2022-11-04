#include <stdlib.h>
#include <termios.h>
#include <stdlib.h>
#define X_REZ 80
#define Y_REZ 24


typedef struct Snake{
    int x,y,vel_y,vel_x,prev_x,prev_y;
    int score;
    char repr;
    struct Snake* next;
    struct Snake* prev;
} snake;


typedef struct Apple {
    int x,y;
    char repr;
} apple;

void MoveUp(char** field,snake* s,apple* a);
void MoveDown(char** field,snake* s,apple* a);
void MoveLeft(char** field, snake* s,apple* a); 
void MoveRight(char** field, snake* s,apple* a); 
void Move(char** field,snake* s); 

void SnakeMover(char** field,snake* s,apple* a); /*Общий метод движения змеи*/
char isSnake(char** field,int x,int y); /* содержит ли клетка змею? '0' - True '1'*/
char isApple(char** field,int x, int y); /* содержит ли клетка яблоко ? '0' - True '1'*/
char isTail(snake* s); /* Является ли участок хвостом змеи '0' - True , '1' - False*/
char isEmpty(char** field, int x, int y );  /*Является ли клетка пустой '0' - True , '1' - False*/
void Grow(char** field,snake* s); /*Увеличить питона*/
void Eat(char** field,snake* s, apple* a); /*Кушоц*/
void clear(); /* Очистить экран */
 void SpawnSnake(char** field,snake* s);
 void ticker(char ** field, apple* a, snake* s);
char isTailCRD(char** f,int x,int y);

void printfield(char** f);

void Start(char ** field,snake* s,apple* a); /*Начать игру*/
void GameOver(int score, int code); /*Закончить игру*/

void SetVerticalSpeed(snake* s, int v);
void SetHorizontalSpeed(snake* s, int v);


void SpawnApple(char** field,apple* a); /*создать яблоко*/
void DelApple(apple* a );/* Удолить яблоко */

