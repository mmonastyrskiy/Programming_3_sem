#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	char i;
	struct Stack* next;
} stack;

void push(stack* head, char new_head_data);
char pop(stack* head_ptr);
char  top(stack* head);
char IsClean(stack* head_ptr);
void clean(stack* head_ptr);
