#include <stdio.h>
#include <stdlib.h>

typedef struct NodeFull
{
	int data;
	struct NodeFull* next;
	struct NodeFull* prev;
} node;

void print_list(node* head){
	if (head -> next != NULL){
		printf("%d\n",head -> data);
		print_list(head -> next);
	}
	else{
		printf("%d\n",head -> data);
	}
	printf("\n");
}




node* add_new_head(node* head, int new_head_data){
	node* new;
		new = malloc(sizeof(node));
		if(new == NULL){
			printf("Malloc failed\n");
			exit(1);
		}
		
		new -> next = head;
		new -> data = new_head_data;
		new -> prev = NULL;
		if (head == NULL){
			return new;
		}
		head -> prev = new;
		return new;

}

node* tail_seek(node* head){
	node* t;
	t = head;
	while (t -> next != NULL){
	t = t->next;
	}
	return t;
}

node* add_new_tail(node* head, int new_tail_data){
node* tail;
node* new;

new = (node*)malloc(sizeof(node));
if(new == NULL){
printf("malloc error\n");
 exit(1);
}
new -> data = new_tail_data;
tail = tail_seek(head);
tail -> next = new;
new-> next = NULL;
new -> prev = tail;


return head;


}
node* rm_head(node* head){
	node* rm;
	rm = head;
	head = head -> next;
	free(rm);
	return head;


}
node* rm_tail(node* head){
node* t;
t = head;
while (t -> next->next != NULL){
t = t-> next;
}
free(t-> next);
t-> next = NULL;
return head;
}



node* sort_list(node* head){
	node* t;
	int temp;
	t =head;
	while(t-> next != NULL){
		if (t->data < t->next->data){
			temp = t->data;
			t->data = t->next->data;
			t->next->data = temp;
		}
		t = t->next;
	}
	if(head->data < head->next->data){
		temp = head -> data;
		head->data = head->next->data;
		head->next->data = temp;
	}
	return head;
}


void reverce_print_list(node* head){
	node* tail;
	node * t;
	tail = tail_seek(head);
	t = tail;
	while (t -> prev != NULL){
		printf("%d\n",t -> data);
		t = t -> prev;
	}
	printf("%d\n",t->data);
		printf("\n");
}

node* insert_value(node* head,int insert_after,int new_node_data){
	node* new;
	node* t;
	t = head;

	new = (node*)malloc(sizeof(node));
	if(new == NULL){
	printf("malloc error\n");
 	exit(1);
	}


	new -> data = new_node_data;

	while (t->data != insert_after){
		t = t->next;
	}
	if(t -> next == NULL){
		add_new_tail(head,new_node_data);
		return head;
	}

	new->next = t -> next;
	new -> prev = t;
	t -> next = new;
	return head;
}


node* rm_value(node* head,int rm){
	node* t;
	t = head;
	while(t -> data != rm){
		t = t->next;
	}
	if(t -> prev == NULL){
		rm_head(head);
	}
	if(t -> next == NULL){
		rm_tail(head);
	}
	t->prev->next =t ->next;
	t->next->prev = t -> prev;
	free(t);
	return head;
}


int main(int argc, char const *argv[])
{
	node* ptr = NULL;
	ptr = add_new_head(ptr, 11);
	ptr = add_new_head(ptr, 90);
	ptr = add_new_head(ptr, 80);
	ptr = add_new_head(ptr, 1);
	

	ptr = sort_list(ptr);
	print_list(ptr);
	ptr = rm_value(ptr,11);
	ptr = insert_value(ptr,80,111);
	print_list(ptr);
	return 0;
} 
