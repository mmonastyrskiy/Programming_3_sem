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

void swap(node *a1, node *a2, node *past){
  if(past == NULL){
    a1->next = a2->next;
    a2->next = a1;
  }else{
    past->next = a2;
    a1->next = a2->next;
    a2->next = a1;
  }
}

node* sort_list(node *head){
  int size = size_list(head);
  int i;
  node *a, *b;
  node *past;
  for(i = 0;i<size;i++){
    past = NULL;
    a = head;
    b = a->next;
    while(b != NULL){
      if(a->data > b->data){
        swap(a, b, past);
        if(past == NULL){
          head = b;
        }
        past = b;
        if(a != NULL)
          b = a->next;
      }else{
        past = a;
        a = b;
        b = b->next;
      }
    }
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
	


	/*print_list(ptr);*/

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
