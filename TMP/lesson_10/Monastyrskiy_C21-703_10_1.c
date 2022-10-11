#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Data{
int i;
char c[128];

}	;

typedef struct NodeFull
{
	struct Data data;
	struct NodeFull* next;
	struct NodeFull* prev;
} node;


void gen_rand_str(char* put_into){
	char ret[128];
	int i;
	for (i=0;i<128;i++){
		ret[i] = (char)(65 +rand()%26);
		/*printf("%c",ret[i]);*/
	}
	ret[127] = '\0';
	memcpy(put_into,ret,sizeof(char) * 128);

}

void print_list(node* head){
	int i;
	if (head -> next != NULL){
		printf("I =%d ",head -> data.i);
		printf("C = ");
	for(i=0;i<128;i++){
		printf("%c",head->data.c[i]);
	}
	printf("\n");
		print_list(head -> next);
	}
	else{
		printf("I =%d ",head -> data.i);
		printf("C = ");
	for(i=0;i<128;i++){
		printf("%c",head->data.c[i]);
	}
	}
	printf("\n");
}




node* add_new_head(node* head, int new_head_data,char new_head_string[]){
	node* new;
		new = malloc(sizeof(node));
		if(new == NULL){
			printf("Malloc failed\n");
			exit(1);
		}
		
		new -> next = head;
		new -> data.i = new_head_data;
		memcpy(new->data.c,new_head_string,sizeof(char) * 128);
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

node* add_new_tail(node* head, int new_tail_data, char new_tail_string[128]){
node* tail;
node* new;

new = (node*)malloc(sizeof(node));
if(new == NULL){
printf("malloc error\n");
 exit(1);
}
new -> data.i = new_tail_data;
memcpy(new->data.c,new_tail_string,sizeof(char) * 128);
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
	int i;
	tail = tail_seek(head);
	t = tail;
	while (t -> prev != NULL){
		printf("I=%d\n",t -> data.i);
		for(i=0;i< 128;i++){
			printf("%c",t->data.c[i]);
		}
		t = t -> prev;
	}
	printf("%d\n",t->data.i);
		for(i=0;i< 128;i++){
			printf("%c",t->data.c[i]);
		}
		printf("\n");
}

node* insert_value(node* head,int insert_after,int new_node_data,char new_node_string[]){
	node* new;
	node* t;
	t = head;

	new = (node*)malloc(sizeof(node));
	if(new == NULL){
	printf("malloc error\n");
 	exit(1);
	}


	new -> data.i = new_node_data;
	memcpy(new->data.c,new_node_string,sizeof(char) * 128);


	while (t->data.i != insert_after){
		t = t->next;
	}
	if(t -> next == NULL){
		add_new_tail(head,new_node_data,new_node_string);
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


/*a b null*/

node* sort_list(node* head){
	node* t;
  	int i;
  	int size = size_list(head);
  	for(i=0;i<size;i++){
  		  	t = head;
	while(t->next != NULL){
		if(t->data.i < t-> next->data.i){
			if(t -> prev == NULL){
				head = t->next;
			}
			swap(t, t->next);
		}
		else{t = t-> next;}
	}
}

	printf("\n\n");
	return head;
	}


node* rm_value(node* head,int rm){
	node* t;
	t = head;
	while(t -> data.i != rm){
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
	char* p;
	p=malloc(sizeof(char)* 128);
	if(p==NULL){
		printf("malloc error\n");
		exit(2);
	}



	srand(time(NULL));
	gen_rand_str(p);
	ptr = add_new_head(ptr, 11,p);
	gen_rand_str(p);
	ptr = add_new_head(ptr, 90,p);
	gen_rand_str(p);
	ptr = add_new_head(ptr, 80,p);
	gen_rand_str(p);
	ptr = add_new_head(ptr, 1,p);
	
	print_list(ptr);

	ptr = sort_list(ptr);
	print_list(ptr);
	return 0;
} 
