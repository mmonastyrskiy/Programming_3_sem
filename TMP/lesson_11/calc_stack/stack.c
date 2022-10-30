#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void push(stack* head_ptr, char new_head_data){
	stack* new;
		new = malloc(sizeof(stack));
		if(new == NULL){
			printf("Malloc failed\n");
			exit(1);
		}
		
		new -> next = head_ptr->next;
		new -> i = new_head_data;
        head_ptr ->next = new;
        printf("%d PUSHED\n",new_head_data-48);
}
char pop(stack* head_ptr){
	char rm_data;
	stack* rm;
    if(head_ptr->next == NULL){
        return 'N';
    }
	rm = head_ptr->next;
    rm_data = rm->i;
	head_ptr->next = head_ptr->next -> next;
	free(rm);
	rm=NULL;
	printf("%d POPED\n",rm_data-48);
	return rm_data;


}


char top(stack* head_ptr){
    return head_ptr-> next->i;
}
char IsClean(stack* head_ptr){
    return head_ptr->next == NULL ? '0' : '1';
}

void clean(stack* head_ptr){
head_ptr->next = NULL;
}