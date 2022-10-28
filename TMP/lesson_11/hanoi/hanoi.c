#include "stack.h"


void initialize(int n ,int start,stack* l,stack* c,stack* r ){
	int i;
	stack* start_ptr;

	if(start == 1){start_ptr =l;}
	else if(start == 2){start_ptr = c;}
	else{start_ptr = r;}
	for (i = 0; i < n;i++;){
		push(start_ptr,(char)i);
	}
}
void Move(int from,int to,stack* l,stack* c,stack* r){
	stack* start_ptr;
	stack* stop_ptr;
	char tmp;

	if(from == 1){start_ptr =l->next;}
	else if(from == 2){start_ptr = c->next;}
	else{start_ptr = r->next;}

	if(to == 1){stop_ptr =l->next;}
	else if(to == 2){stop_ptr = c->next;}
	else{stop_ptr = r->next;}

tmp = pop(start_ptr);
push(stop_ptr,tmp);
}

void hanoi(int n, int start, int stop,stack* l,stack* c,stack* r){
	int tmp_tower_idx;

	if(n==1){
		printf("Move disk 1 from %d to %d",start,stop);
		Move(start,stop,l,c,r);

	}
	else{
		tmp_tower_idx = = 6 - start - stop;
		hanoi(n-1,start,tmp_tower_idx);
		printf("Move disk %d from %d to %d",i,start,stop);
		Move(start,stop,l,c,r);
		hanoi(n-1,tmp_tower_idx,stop,l,c,r);
	}

}

int main(int argc, char const *argv[])
{
	int start;
	int stop;
	int n;
	stack* head_c = NULL;
	stack* head_l = NULL;
	stack* head_r = NULL;

	stack* head_ptr_c;
	stack* head_ptr_l;
	stack* head_ptr_r;

	head_ptr_c = malloc(sizeof(stack));
    if(head_ptr_c == NULL){
        printf("Malloc error\n");
        exit(1);
    }


	head_ptr_l = malloc(sizeof(stack));
    if(head_ptr_l == NULL){
        printf("Malloc error\n");
        exit(1);
    }


	head_ptr_r = malloc(sizeof(stack));
    if(head_ptr_r == NULL){
        printf("Malloc error\n");
        exit(1);
    }

	if(argc != 4){
		printf("argument error\n");
		exit(1);

	}
	n = atoi(argv[1]);
	start = atoi(argv[2]);
	stop = atoi(argv[3]);

if(((start < 1) ||(start > 3)) || ((end<1) || (end>3)) || (n <= 0)){
	printf("Bad argument");
	exit(1);
}
	initialize(n,start,head_ptr_l->next,head_ptr_c->next,head_ptr_r->next);
	hanoi(n,start,stop);


	return 0;
}