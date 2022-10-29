#include "static_stack.h"
void push(char* head, char new_head_data,int n, int* cur_head){
	if(*cur_head +1 > n-1){
		printf("OVERFLOW\n");
		return;
	}

	head[*cur_head+1] = new_head_data;
	*cur_head++;

}
char pop(char* head_ptr,int* cur_head){
	char r;
	r = head_ptr[*cur_head];
	*cur_head--;
	return r;
}
char  top(char* head,int* c){
	return head[*c];
}
char IsClean(int cur_head){
return cur_head ==0 ? '0' : '1';
}