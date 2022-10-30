#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "static_stack.h"




void addition(char* head_ptr,int n, int* cur_head){
    int operator_a;
    int operator_b;
    if(IsClean(*cur_head)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_a = (int)pop(head_ptr,cur_head)-48;
        if(IsClean(*cur_head)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_b =  (int)pop(head_ptr,cur_head)-48;
    printf("%d+%d\n",operator_b,operator_a);
    push(head_ptr,(char) (operator_a + operator_b)+48,n,cur_head);
}
void subtraction (char* head_ptr,int n, int* cur_head){
    int operator_a;
    int operator_b;
    if(IsClean(*cur_head)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_a =  (int)pop(head_ptr,cur_head)-48;
        if(IsClean(*cur_head)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_b =  (int)pop(head_ptr,cur_head)-48;
    printf("%d-%d\n",operator_b,operator_a);
    push(head_ptr,(char) (operator_b - operator_a)+48,n,cur_head);
}

void multiplication (char* head_ptr,int n, int* cur_head){
    int operator_a;
    int operator_b;
    if(IsClean(*cur_head)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_a =  (int)pop(head_ptr,cur_head)-48;
        if(IsClean(*cur_head)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_b =  (int)pop(head_ptr,cur_head)-48;
    printf("%d*%d\n",operator_b,operator_a);
    push(head_ptr,(char) (operator_b * operator_a)+48,n,cur_head);
}

void division (char* head_ptr,int n, int* cur_head){
    int operator_a;
    int operator_b;
    if(IsClean(*cur_head)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_a =  (int)pop(head_ptr,cur_head)-48;
        if(IsClean(*cur_head)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_b =  (int)pop(head_ptr,cur_head)-48;
    if (operator_a == 0)  return;
    printf("%d/%d\n",operator_b,operator_a);
    push(head_ptr,(char) (operator_b / operator_a)+48,n,cur_head);
}

void calc(char* head_ptr, char* equasion,int n,int* cur_head){
    char cur;
    char res;
    int i;
    for (i = 0; equasion[i] != '\0'; i++){
        cur = equasion[i];
        if(isdigit(cur)>0){
            push(head_ptr,cur,n,cur_head);
        }
        else if((cur == '+') ||(cur == '-') || (cur == '*') || (cur == '/'))
        {
            if(cur == '+'){
                addition(head_ptr,n,cur_head);
            }
            else if (cur == '-'){
                subtraction(head_ptr,n,cur_head);

            }
            else if(cur =='*'){
                multiplication(head_ptr,n,cur_head);
            }
            else if (cur == '/'){
                division(head_ptr,n,cur_head);
            }

        }
        else{continue;}

    }
    res = pop(head_ptr,cur_head);
    printf("Result: %d\n",res-48);

}


int main(int argc, const char** argv){
	int n;
	int cur_head;
	char* equasion;
	char* head_ptr;
    equasion = malloc(sizeof(char)*100);
    if(equasion == NULL){
        printf("malloc error\n");
        exit(1);
    }
	cur_head =0;
	scanf("%d\n%s",&n,equasion);
    head_ptr = malloc(sizeof(char)*n);
    if (head_ptr == NULL){
        printf("malloc error\n");
        exit(1);
    }
    printf("----------------STACK TRACEBACK -------------\n");
    calc(head_ptr,equasion,n,&cur_head);
    return 0;

} 