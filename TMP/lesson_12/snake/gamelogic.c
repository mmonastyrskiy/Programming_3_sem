#include "gamelogic.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>




void Grow(char** field,snake* s){
    snake* new;
    snake* head;
    head = s;
    while(!(isHead(head)=='0')){
        head = head-> next;
    }
    new = malloc(sizeof(snake));
    if(new == NULL){
        printf("malloc error");
        exit(2);
    }
head->score +=1;
new -> next = s;
new-> repr = '=';
new -> vel_x =0;
new -> vel_y = 0;
new -> x = s->x - head->vel_x;
new -> y = s->y - head->vel_y;
field[new->y][new->x] = new->repr;

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


void onCanon(){
    struct termios orig_termios;
    struct termios raw;
    tcgetattr(STDIN_FILENO,&orig_termios);
    raw = orig_termios;
    raw.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
}


char isHead(snake* t){
    return (t->next == NULL) ? '0':'1';
}

void SetVerticalSpeed(snake* s, int v){
    printf("SetVerticalSpeed");
    snake* t;
    t = s;
    while(isHead(t)!= '0'){
        t = t-> next;
    }

    switch(v){
            case 1:
                s->vel_x = 0;
                s->vel_y = v;
            case -1:
                s->vel_x = 0;
                s->vel_y = v;
            default: return;
        }
}
void SetHorizontalSpeed(snake* s, int v){
    printf("SetHorizontalSpeed");
    snake* t;
    t = s;
    if(isHead(t)=='0'){
        switch(v){
            case 1:
                s->vel_x = v;
                s->vel_y = 0;
            case -1:
                s->vel_x = v;
                s->vel_y = 0;
            default: return;
        }
    }
    t = t-> next;
    SetHorizontalSpeed(t,v);
    return;
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
    t = s;
    while (!(isHead(t)=='0')){
        Move(field, s);
        t = t-> next;
    }
    if(s-> vel_x == 1 ){
        MoveRight(field,t,a);
    }
    if(s-> vel_x == -1){
        MoveLeft(field, t,a);
    }
    if(s-> vel_y == 1){
        MoveUp(field,t,a);
    }
    if(s->vel_y == -1){
        MoveDown(field,t,a);
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
