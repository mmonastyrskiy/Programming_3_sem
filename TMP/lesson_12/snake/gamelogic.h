#include <stdlib.h>
#include <stdlib.h>
#define X_REZ 80
#define Y_REZ 24
typedef struct Snake{
    int x,y,vel_y,vel_x;
    char repr;
    struct Snake* next;
} snake;


typedef struct Apple {
    int x,y;
    char repr;
} apple;

void MoveUp(snake* s); /* обрабатывает нажатие на стрелочку вверх для головы*/
void MoveDown(snake* s); /* обрабатывает нажатие на стрелочку вниз для головы*/
void MoveLeft(snake* s); /* обрабатывает нажатие на стрелочку влево для головы*/
void MoveRight(snake* s); /* обрабатывает нажатие на стрелочку вправо для головы*/
void Move(snake* s); /* Движение такт без нажатия клавиши, и Движение всей остальной змеи*/
char isSnake(char** field,int x,int y); /* содержит ли клетка змею? '0' - True '1'*/
char isApple(char** field,int x, int y); /* содержит ли клетка яблоко ? '0' - True '1'*/
char isHead(snake* s); /* Является ли участок хвостом змеи '0' - True , '1' - False*/
char isEmpty(char** field, int x, int y );  /*Является ли клетка пустой '0' - True , '1' - False*/
void Grow(snake* s); /*Увеличить питона*/
void Eat(int* score); /*Кушоц*/
void teleport(snake* s); /*Телепортировать змею, если за краем экрана*/
void clear(); /* Очистить экран */
 void SpawnSnake(char** field,snake* s);
 void ticker(char ** field, apple* a, snake* s);

void printfield(char** f);

void Start(char ** field,snake* s,apple* a); /*Начать игру*/
void GameOver(int score, int code); /*Закончить игру*/




void SpawnApple(char** field,apple* a); /*создать яблоко*/
void DelApple(apple* a );/* Удолить яблоко */

