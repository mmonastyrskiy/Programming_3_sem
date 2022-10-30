#include "stack.h"
#include <ctype.h>
#include <stdlib.h>

void addition(stack* head_ptr){
    int operator_a;
    int operator_b;
    if(IsClean(head_ptr)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_a = (int)pop(head_ptr)-48;
        if(IsClean(head_ptr)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_b =  (int)pop(head_ptr)-48;
    printf("%d+%d\n",operator_b,operator_a);
    push(head_ptr,(char) (operator_a + operator_b)+48);
}
void subtraction (stack* head_ptr){
    int operator_a;
    int operator_b;
    if(IsClean(head_ptr)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_a =  (int)pop(head_ptr)-48;
        if(IsClean(head_ptr)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_b =  (int)pop(head_ptr)-48;
    printf("%d-%d\n",operator_b,operator_a);
    push(head_ptr,(char) (operator_b - operator_a)+48);
}

void multiplication (stack* head_ptr){
    int operator_a;
    int operator_b;
    if(IsClean(head_ptr)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_a =  (int)pop(head_ptr)-48;
        if(IsClean(head_ptr)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_b =  (int)pop(head_ptr)-48;
    printf("%d*%d\n",operator_b,operator_a);
    push(head_ptr,(char) (operator_b * operator_a)+48);
}

void division (stack* head_ptr){
    int operator_a;
    int operator_b;
    if(IsClean(head_ptr)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_a =  (int)pop(head_ptr)-48;
        if(IsClean(head_ptr)=='0'){
        printf("error empty stack found");
        exit(2);
    }
    operator_b =  (int)pop(head_ptr)-48;
    if (operator_a == 0)  return;
    printf("%d/%d\n",operator_b,operator_a);
    push(head_ptr,(char) (operator_b / operator_a)+48);
}


void calc(stack* head_ptr,const char* equasion){
    char cur;
    char res;
    int i;
    for (i = 0; equasion[i] != '\0'; i++){
        cur = equasion[i];
        if(isdigit(cur)>0){
            push(head_ptr,cur);
        }
        else if((cur == '+') ||(cur == '-') || (cur == '*') || (cur == '/'))
        {
            if(cur == '+'){
                addition(head_ptr);
            }
            else if (cur == '-'){
                subtraction(head_ptr);

            }
            else if(cur =='*'){
                multiplication(head_ptr);
            }
            else if (cur == '/'){
                division(head_ptr);
            }

        }
        else{continue;}

    }
    res = pop(head_ptr);
    printf("Result: %d\n",res-48);

}
int main(int argc, const char** argv){
    stack* head_ptr;
    stack* head = NULL;
    if(argc != 2){
        printf("bad argument");
        exit(3);
    }
    head_ptr = malloc(sizeof(stack));
    if(head_ptr == NULL){
        printf("Malloc error\n");
        exit(1);
    }
    head_ptr -> next = head;
    printf("----------------STACK TRACEBACK -------------\n");
    calc(head_ptr,argv[1]);
    return 0;

} 
