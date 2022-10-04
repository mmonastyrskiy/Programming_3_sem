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


int size_list(node *head){
  node *tmp = NULL;
  int size = 0;
  if(head == NULL) return 0;
  tmp = head;
  while(tmp!= NULL){
    size++;
    tmp = tmp->next;
  }
  return size;
}


void swap(node* a, node* b){
	node* next;
	node* prev;
	if(!(a->prev == NULL)){
		prev = a->prev;

	}
	else{prev=NULL;}
	if(!(b->next == NULL)){
		next = b->next;

	}
	else{next=NULL;}

	if(!(prev == NULL)){
	prev -> next =b;
	}
	if(!(next == NULL)){
	next -> prev = a;
}
	b->next = a;
	a->prev =b;
	a->next =next;
	b->prev = prev;
}




node* sort_list(node* head){
	node* t;
  	int i;
  	int size = size_list(head);
  	t = head;
  	for(i=0;i<size;i++){
	while(t->next != NULL){
		/*printf("%d :: %d\n", t->data,t->next->data);*/
		if(t->data < t-> next->data){
			if(t -> prev == NULL){
				head = t->next;
			}
			printf("t=%d ::: t-> next=%d\n",t->data,t->next->data);
			swap(t, t->next);
			printf("t=%d ::: t-> next=%d\n",t->data,t->next->data);
		}
	}
	t = t->next;
	printf("\n\n");
	}
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
	

	print_list(ptr);

	ptr = sort_list(ptr);
	print_list(ptr);
	/*ptr = rm_value(ptr,11);
	ptr = insert_value(ptr,80,111);
	print_list(ptr);*/
	return 0;
} 
