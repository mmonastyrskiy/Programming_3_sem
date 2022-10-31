#include <stdio.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>

struct termios orig_termios;

void offCanon(){
    struct termios raw;
    tcgetattr(STDIN_FILENO,&orig_termios);
    raw = orig_termios;
    raw.c_lflag &=  ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
}


void onCanon(){
    struct termios raw;
    tcgetattr(STDIN_FILENO,&orig_termios);
    raw = orig_termios;
    raw.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
}

int main(int argc, char* argv[]){
int i;
char c,k =-1;
offCanon();
while((c=getc(stdin)) != EOF){
    switch(c){
        case 'Q':onCanon(); return 2;
        case 'a' ... 'z' : printf("%c[%d]\n",c,i++);break;
        case 0x1b: ++k;break;
        case 0x5b: k==0?++k:(0);break;
        case 0x41:k>0?printf("^\n"):(0);k=-1;break;
        case 0x42:k>0?printf("!\n"):(0);k=-1;break;
        case 0x43:k>0?printf(">\n"):(0);k=-1;break;
        case 0x44:k>0?printf("<\n"):(0);k=-1;break;
        default: printf("[%x]\n",c);
    }
}
}


// res = 80x24