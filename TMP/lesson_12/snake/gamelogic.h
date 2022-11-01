#include <stdlib.h>
#include <stdlib.h>
typedef struct Snake{
    int x,y,vel_y,vel_x;
    char* repr;
    struct Snake* next;
}; snake


void MoveUp(snake* s); /* обрабатывает нажатие на стрелочку вверх для головы*/
void MoveDown(snake* s); /* обрабатывает нажатие на стрелочку вниз для головы*/
void MoveLeft(snake* s); /* обрабатывает нажатие на стрелочку влево для головы*/
void MoveRight(snake* s); /* обрабатывает нажатие на стрелочку вправо для головы*/
void Move(snake* s); /* Движение такт без нажатия клавиши, и Движение всей остальной змеи*/
char isSnake(char*** field,int x,int y); /* содержит ли клетка змею? '0' - True '1'*/
char isApple(char*** field,int x, int y); /* содержит ли клетка яблоко ? '0' - True '1'*/
char isHead(snake* s); /* Является ли участок хвостом змеи '0' - True , '1' - False*/
char isEmpty(char*** field, int x, int,y );  /*Является ли клетка пустой '0' - True , '1' - False*/
void Grow(snake* s); /*Увеличить питона*/
void Eat(int* score); /*Кушоц*/
void teleport(snake* s); /*Телепортировать змею, если за краем экрана*/
void clear(); /* Очистить экран */

void ticker(char *** field, apple* a, snake* s)
void Start(); /*Начать игру*/
void GameOver(int score, int code); /*Закончить игру*/


typedef struct Apple {
    int x,y;
}; apple

void SpawnApple(); /*создать яблоко*/
void DelApple(apple* a );/* Удолить яблоко */

