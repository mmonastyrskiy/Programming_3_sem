#include "gamelogic.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>


char isSnake(char** f, int x, int y){
    if (f[y][x] == '='){
        return '0';
    }
    return '1';
}

void onCanon(){
    struct termios orig_termios;
    struct termios raw;
    tcgetattr(STDIN_FILENO,&orig_termios);
    raw = orig_termios;
    raw.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
}



void GameOver(int score, int sig){
    system("clear");
    printf("СПАСИБО ЗА ИГРУ\n ваш счет:%d",score);
    getc(stdin);
    onCanon();
    exit(0);
}

void Grow(char** field,snake* s){
    snake* new;
    new = malloc(sizeof(snake));
    if(new == NULL){
        printf("malloc error");
        exit(2);
    }

new -> next = s->next;



}



void Eat(char** field,snake* s, apple* a){
    Grow(field,s);
    SpawnApple(field,a);
}

void offCanon(){
    struct termios orig_termios;
    struct termios raw;
    tcgetattr(STDIN_FILENO,&orig_termios);
    raw = orig_termios;
    raw.c_lflag &=  ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
}




char isTail(snake* t){
    return (t->repr == '=') ? '0':'1';
}

void SetVerticalSpeed(snake* s, int v){
    printf("SetVerticalSpeed");

    switch(v){
            case 1:
                s->next->vel_x = 0;
                s->next->vel_y = v;
            case -1:
                s->next->vel_x = 0;
                s->next->vel_y = v;
            default: return;
        }
}
void SetHorizontalSpeed(snake* s, int v){
    printf("SetHorizontalSpeed");
        switch(v){
            case 1:
                s->next->vel_x = v;
                s->next->vel_y = 0;
            case -1:
                s->next->vel_x = v;
                s->next->vel_y = 0;
            default: return;
        }
    }

void MoveUp(char** field,snake* s,apple* a){ 
    field[s->y][s->x] = '.';
    if(s->y+1 >= Y_REZ){
        s->y = s->y+2-Y_REZ;
    }
    s->y = s->y+1;
    if((a->x == s->x)&&(a->y == s->y)){
        Eat(field,s,a);
    }
    if(isSnake(field,s->x,s->y)=='0'){
        snake* head;
        head = s;
        GameOver(head->score,0);
    }
    field[s->y][s->x] = '>';
}

void MoveDown(char** field,snake* s,apple* a){
  field[s->y][s->x] = '.';
        if(s->y-1 <= 1){
        s->y = s->y-2+Y_REZ;
    }
    s->y = s->y-1;
    if((a->x == s->x)&&(a->y == s->y)){
        Eat(field,s,a);
    }
    if(isSnake(field,s->x,s->y)=='0'){
        snake* head;
        head = s;
        GameOver(head->score,0);
    }
    field[s->y][s->x] = '>';
}
void MoveLeft(char** field, snake* s,apple* a){
  field[s->y][s->x] = '.';
        if(s->x-1 <= 1){
        s->y = s->x-2+Y_REZ;
    }
    s->x = s->x-1;
    if((a->x == s->x)&&(a->y == s->y)){
        Eat(field,s,a);
    }
    if(isSnake(field,s->x,s->y)=='0'){
        snake* head;
        head = s;
        GameOver(head->score,0);
    }
    field[s->y][s->x] = '>';
} 
void MoveRight(char** field, snake* s,apple* a){
    field[s->y][s->x] = '.';
        if(s->x+1 >= X_REZ-1){
        s->x = s->x+2-X_REZ;
    }
    s->x = s->x+1;
    if((a->x == s->x)&&(a->y == s->y)){
        Eat(field,s,a);
    }
    if(isSnake(field,s->x,s->y)=='0'){
        snake* head;
        head = s;
        GameOver(head->score,0);
    }
    field[s->y][s->x] = '>';
}


void Move(char** field, snake* s){
        int prev_x, prev_y;
    prev_x = s-> x ;
    prev_y = s -> y;
    s-> x = s-> next ->x;
    s-> y = s -> next -> y;
    field[prev_y][prev_x] = '.';
}
void SnakeMover(char** field,snake* s,apple* a) /*Общий метод движения змеи*/
{
    snake* t;
    if(s-> vel_x == 1 ){
        MoveRight(field,s->next,a);
    }
    if(s-> vel_x == -1){
        MoveLeft(field, s->next,a);
    }
    if(s-> vel_y == 1){
        MoveUp(field,s->next,a);
    }
    if(s->vel_y == -1){
        MoveDown(field,s->next,a);
    }
    t =s->next;
    while(t!= NULL || isTail(t)=='0'){
        Move(field,t);
        t =t->next;

    }
    printf("head: %d %d\n",t->x, t->y);
    printf("tail: %d %d",s->x, s->y);
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
    char c;
    c=-1;
    c = getc(stdin);
    switch(c){
        case 'w':SetVerticalSpeed(s,-1);break;
        case 's':SetVerticalSpeed(s,1);break;
        case 'd':SetHorizontalSpeed(s,1);break;
        case 'a':SetHorizontalSpeed(s,-1);break;
        case 'q':onCanon(); return;
    };
    SnakeMover(field,s,a);
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
        s->next->x = x;
        s->next->y =y;
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
    offCanon();
}
