#include <fcntl.h>
#include "gamelogic.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>

int snake_len(snake* head_ptr){
    snake* t;
    int l;
    l = 0;
    t = head_ptr->next;
    while(t != NULL){
        t = t-> prev;
        l++;
}
return l;
}
int last_x(snake* head_ptr){
    snake* t;
    t = head_ptr->next;
    while(t->prev !=NULL){
        t = t->prev;
    }
    return t->prev_x;
}
int last_y(snake* head_ptr){
snake* t;
t = head_ptr->next;
while(t->prev !=NULL){
    t = t->prev;
}
return t->prev_y;
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


void Grow(char** field, snake* head_ptr){
    snake* new;
    new = malloc(sizeof(snake));
    if(new == NULL){
        printf("malloc error");
        exit(1);

    }
    head_ptr->next->score+=1;
    new->next = head_ptr->next;
    new -> prev = head_ptr->next->prev;
    if(head_ptr->next->prev != NULL){
        head_ptr->next->prev->next = new;
    }
    head_ptr->next->prev=new;
    new->repr='=';
    new->vel_y =0;
    new->vel_x = 0;
    new->x =last_x(head_ptr);
    new->y = last_y(head_ptr);
    field[new->y][new->x] = new->repr;
}


void Eat(char** field,snake* head_ptr, apple* a){
    Grow(field,head_ptr);
    SpawnApple(field,a);
    printf("\a");
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
    printf("\033[2J"); /*Очистить экран*/
    printf("СПАСИБО ЗА ИГРУ\n ваш счет:%d",score);
    getc(stdin);
    onCanon();
    exit(0);
}
void offCanon(){

    struct termios orig_termios;
    struct termios raw;
    tcgetattr(STDIN_FILENO,&orig_termios);
    raw = orig_termios;
    raw.c_lflag &=  ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
    fcntl(0,F_SETFL,fcntl(0,F_GETFL,0)|O_NONBLOCK);
}




void MoveUp(char** field,snake* head_ptr,apple* a){
    snake* tail;
      head_ptr->next->prev_x = head_ptr->next->x;
      head_ptr->next->prev_y = head_ptr->next->y;
    field[head_ptr->next->y][head_ptr->next->x] = '.';
    if(head_ptr->next->y+1 >= Y_REZ-1){
        head_ptr->next->y = head_ptr->next->y+2-Y_REZ;
    }
    head_ptr->next->y = head_ptr->next->y+1;
    if((a->x == head_ptr->next->x)&&(a->y == head_ptr->next->y)){
        Eat(field,head_ptr,a);
    }
    if(isTailCRD(field,head_ptr->next->x,head_ptr->next->y)=='0'){
        snake* head;
        head = head_ptr;
        GameOver(head->next->score,0);
    }
    field[head_ptr->next->y][head_ptr->next->x] = '>';


    tail = head_ptr->next->prev;
    if(tail == NULL){return;}
    while(tail != NULL){
        if(tail->next==head_ptr->next){
            tail->prev_x=tail->x;
            tail->prev_y = tail->y;
            field[tail->y][tail->x] = '.';
            tail->x =  head_ptr->next->prev_x;
            tail->y = head_ptr->next->prev_y;
            field[tail->y][tail->x] = tail->repr;
        }
        else{
            tail->prev_x=tail->x;
            tail->prev_y=tail->y;
            field[tail->y][tail->x] = '.';
            tail->x = tail->next->prev_x;
            tail->y=tail->next->prev_y;
            field[tail->y][tail->x] = tail->repr;
        }
        tail = tail->prev;
    }
}

void MoveDown(char** field,snake* head_ptr,apple* a){
     snake* tail;
    
      head_ptr->next->prev_x = head_ptr->next->x;
      head_ptr->next->prev_y = head_ptr->next->y;
  field[head_ptr->next->y][head_ptr->next->x] = '.';
        if(head_ptr->next->y-1 <= 1){
        head_ptr->next->y = head_ptr->next->y-2+Y_REZ;
    }
    head_ptr->next->y = head_ptr->next->y-1;
    if((a->x == head_ptr->next->x)&&(a->y == head_ptr->next->y)){
        Eat(field,head_ptr,a);
    }
    if(isTailCRD(field,head_ptr->next->x,head_ptr->next->y)=='0'){
        GameOver(head_ptr->next->score,0);
    }
    field[head_ptr->next->y][head_ptr->next->x] = '>';


    tail = head_ptr->next->prev;
    if(tail == NULL){return;}
    while(tail != NULL){
        
        if(tail->next==head_ptr->next){
            tail->prev_x=tail->x;
            tail->prev_y = tail->y;
            field[tail->y][tail->x] = '.';
            tail->x =  head_ptr->next->prev_x;
            tail->y = head_ptr->next->prev_y;
            field[tail->y][tail->x] = tail->repr;
        }
        else{
            tail->prev_x=tail->x;
            tail->prev_y=tail->y;
            field[tail->y][tail->x] = '.';
            tail->x = tail->next->prev_x;
            tail->y=tail->next->prev_y;
            field[tail->y][tail->x] = tail->repr;
        }
        tail = tail->prev;
    }
}
void MoveLeft(char** field, snake* head_ptr,apple* a){
    snake* tail;
    head_ptr->next->prev_x = head_ptr->next->x;
    head_ptr->next->prev_y = head_ptr->next->y;
  field[head_ptr->next->y][head_ptr->next->x] = '.';
        if(head_ptr->next->x-1 <= 1){
        head_ptr->next->x = head_ptr->next->x-2+X_REZ;
    }
    head_ptr->next->x = head_ptr->next->x-1;
    if((a->x == head_ptr->next->x)&&(a->y == head_ptr->next->y)){
        Eat(field,head_ptr,a);
    }
    if(isTailCRD(field,head_ptr->next->x,head_ptr->next->y)=='0'){
        snake* head;
        head = head_ptr;
        GameOver(head->next->score,0);
    }
    field[head_ptr->next->y][head_ptr->next->x] = '>';


    tail = head_ptr->next->prev;
    if(tail == NULL){return;}
    while(tail != NULL){
        if(tail->next==head_ptr->next){
            tail->prev_x=tail->x;
            tail->prev_y = tail->y;
            field[tail->y][tail->x] = '.';
            tail->x =  head_ptr->next->prev_x;
            tail->y = head_ptr->next->prev_y;
            field[tail->y][tail->x] = tail->repr;
        }
        else{
            tail->prev_x=tail->x;
            tail->prev_y=tail->y;
            field[tail->y][tail->x] = '.';
            tail->x = tail->next->prev_x;
            tail->y=tail->next->prev_y;
            field[tail->y][tail->x] = tail->repr;
        }
        tail=tail->prev;
    }
} 
void MoveRight(char** field, snake* head_ptr,apple* a){
    snake* tail;
    head_ptr->next->prev_x = head_ptr->next->x;
    head_ptr->next->prev_y = head_ptr->next->y;
    field[head_ptr->next->y][head_ptr->next->x] = '.';
        if(head_ptr->next->x+1 >= X_REZ-1){
        head_ptr->next->x = head_ptr->next->x+2-X_REZ;
    }
    head_ptr->next->x = head_ptr->next->x+1;
    if((a->x == head_ptr->next->x)&&(a->y == head_ptr->next->y)){
        Eat(field,head_ptr,a);
    }
    if(isTailCRD(field,head_ptr->next->x,head_ptr->next->y)=='0'){
        snake* head;
        head = head_ptr;
        GameOver(head->next->score,0);
    }
    field[head_ptr->next->y][head_ptr->next->x] = '>';


    tail = head_ptr->next->prev;
    if(tail == NULL){return;}
    while(tail != NULL){
        if(tail->next==head_ptr->next){
            tail->prev_x=tail->x;
            tail->prev_y = tail->y;
            field[tail->y][tail->x] = '.';
            tail->x = head_ptr->next->prev_x;
            tail->y = head_ptr->next->prev_y;
            field[tail->y][tail->x] = tail->repr;
        }
        else{
            tail->prev_x=tail->x;
            tail->prev_y=tail->y;
            field[tail->y][tail->x] = '.';
            tail->x = tail->next->prev_x;
            tail->y=tail->next->prev_y;
            field[tail->y][tail->x] = tail->repr;
        }
        tail = tail->prev;
    }
}






void SnakeMover(char** field,snake* head_ptr,apple* a)
{

    if(head_ptr->next-> vel_x == 1 ){
        MoveRight(field,head_ptr,a);
    }
    if(head_ptr->next-> vel_x == -1){
        MoveLeft(field, head_ptr,a);
    }
    if(head_ptr->next-> vel_y == 1){
        MoveUp(field,head_ptr,a);
    }
    if(head_ptr->next->vel_y == -1){
        MoveDown(field,head_ptr,a);
    }
}

char isTail(snake* t){
    return (t->repr == '=') ? '0':'1';
}
char isTailCRD(char** f,int x,int y){
    return(f[y][x] == '=') ? '0':'1';
}
void SetVerticalSpeed(snake* head_ptr, int v){

    switch(v){
            case 1:
                if(head_ptr->next->vel_x == 0 && head_ptr->next->vel_y == -1 * v){return;}
                head_ptr->next->vel_x = 0;
                head_ptr->next->vel_y = v;
            case -1:
                if(head_ptr->next->vel_x == 0 && head_ptr->next->vel_y == -1 * v){return;}
                head_ptr->next->vel_x = 0;
                head_ptr->next->vel_y = v;
            default: return;
        }
}
void SetHorizontalSpeed(snake* head_ptr, int v){
        switch(v){
            case 1:
            if(head_ptr->next->vel_y == 0 && head_ptr->next->vel_x == -1 * v){return;}
                head_ptr->next->vel_x = v;
                head_ptr->next->vel_y = 0;
            case -1:
                if(head_ptr->next->vel_y == 0 && head_ptr->next->vel_x == -1 * v){return;}
                head_ptr->next->vel_x = v;
                head_ptr->next->vel_y = 0;
            default: return;
        }
    }




void ticker(char ** field, apple* a, snake* head_ptr){
    char c;
    c=-1;
     c = getc(stdin);
    switch(c){
        case 'w':SetVerticalSpeed(head_ptr,-1);break;
        case 's':SetVerticalSpeed(head_ptr,1);break;
        case 'd':SetHorizontalSpeed(head_ptr,1);break;
        case 'a':SetHorizontalSpeed(head_ptr,-1);break;
        case 'q':onCanon(); GameOver(head_ptr->next->score,1);
    };

    
    SnakeMover(field,head_ptr,a);
    printf("\033[2J"); /*Очистить экран*/
    printfield(field);
}

char isEmpty(char** field,int x, int y){
    if((x >= 1 && x < X_REZ) && (y >=1 && y < Y_REZ) &&(field[y][x] == '.')){
        return '0';
    }
    return '1';
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

 void SpawnSnake(char** field,snake* head_ptr){
    int x,y;
    x = rand()% 10;
    y = rand()%10;
    if(isEmpty(field,x,y) == '0'){
        head_ptr->next->x = x;
        head_ptr->next->y =y;
        field[x][y] = '>';
        return;
    }

    SpawnSnake(field,head_ptr);
 }


void Start(char** field, snake* head_ptr,apple* a) /*Начать игру*/{
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

    SpawnSnake(field,head_ptr);
    offCanon();
}
