#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
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
		return new;

}

node* tail_seek(node* head){
	node* t;
	node* res;
	t = head;
	if (t -> next != NULL){
		printf("%d\n",t->data);
		tail_seek(t -> next);
	}
	if(t-> next ==NULL){

	res = t;
}
	return res;
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
new -> next = NULL;
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
t-> next = NULL;
free(t-> next);
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


int main(int argc, char const *argv[])
{
	node* ptr = NULL;
	ptr = add_new_head(ptr, 11);
	ptr = add_new_head(ptr, 90);
	ptr = add_new_head(ptr, 80);
	ptr = add_new_head(ptr, 1);
	


	print_list(ptr);

	/*ptr = rm_head(ptr);
	print_list(ptr);
	printf("\n\n");
	ptr = rm_tail(ptr);
	ptr = add_new_tail(ptr,1001);
	print_list(ptr);*/
	sort_list(ptr);
	print_list(ptr);

	return 0;
} 
