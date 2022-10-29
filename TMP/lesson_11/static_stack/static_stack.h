#include <stdio.h>
#include <stdlib.h>

void push(char* head, char new_head_data,int n, int* cur_head);
char pop(char* head_ptr,int* cur_head);
char  top(char* head,int* cur_head);
char IsClean(int cur_head);