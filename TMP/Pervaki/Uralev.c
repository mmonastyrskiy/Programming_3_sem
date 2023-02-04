#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define N 10
struct lnode {
struct data *p;
struct lnode *next;
};
struct data{
double f;
char s[2];
};
int size_finder(struct lnode* a){
int i;
i =0;
struct lnode* t;
t = a;
while(t != NULL){
t=t->next;
i++;
}
return i;
}

void reverse (struct lnode *a) {
int n;
n = size_finder(a);
struct lnode j;
for (int i = 0; i < n; i++) {
j = *(a + i);
*(a + i) = *(a + n-1 - i);
*(a + n-1 - i) =*a;
}
}
struct lnode* filler(struct lnode* head){
	struct lnode* new;
	struct data* new_data;

	new_data = malloc(sizeof(struct data));
	if(new_data == NULL){
		exit(1);
	}
	new = malloc(sizeof(struct lnode));
	if(new == NULL){
		exit(2);
	}
	new_data->f = rand() %100;
	new_data->s[0] = rand()%255;
	new_data->s[1] = rand()%255;
	new->p = new_data;
	new->next = head;
	return new;

}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	struct lnode* base;
	struct lnode* st1;
	struct lnode* st2;
	struct lnode* st3;
	base = NULL;
	int i;
st1 = filler(base);
st2 = filler(st1);
st3 = filler(st2);
reverse(st3);




	return 0;
}