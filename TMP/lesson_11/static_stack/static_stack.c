#include "static_stack.h"

void print(char* head, int* cur_head){
	int i;
	for(i=0;i<=*cur_head;i++){
		printf("%c",head[i]);
	}
	printf("\n");
}
void push(char* head, char new_head_data,int n, int* cur_head){
	if(*cur_head > n-1){
		printf("OVERFLOW\n");
		exit(4);
		return;
	}

	head[*cur_head+1] = new_head_data;
	*cur_head+=1;
	printf("PUSHED %d on idx %d\n", new_head_data-48,*cur_head-1);
}
char pop(char* head_ptr,int* cur_head){
	if(*cur_head ==0){
		printf("Empty stack cannot be POPED");
		exit(3);
	}
	char r;
	r = head_ptr[*cur_head];
	printf("POPED %d on idx %d\n", r-48,*cur_head);
	*cur_head-=1;
	return r;
}
char  top(char* head,int* c){
	return head[*c];
}
char IsClean(int cur_head){
return cur_head ==0 ? '0' : '1';
}
void clean(int* cur_head){
	cur_head =0;
}