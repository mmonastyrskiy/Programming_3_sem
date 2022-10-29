#include "stack.h"
#include <stdlib.h>






void display(stack* l,stack* c, stack* r){
		stack* lp;
		stack* cp;
		stack* rp;

		lp = l;
		cp =c;
		rp = r;

	while (!((lp-> next == NULL)&& (cp->next == NULL)&& (rp->next == NULL)))
	{		printf("%d|%d|%d\n",lp->i,cp->i,rp->i);
		lp = lp->next;
		cp = cp->next;
		rp = rp->next;
	}

}

void initialize(int n ,int start,stack* l,stack* c,stack* r ){
	int i;
	stack* start_ptr;

	if(start == 1){start_ptr =l;}
	else if(start == 2){start_ptr = c;}
	else{start_ptr = r;}
	for (i = 0; i < n;i++){
		push(start_ptr,(char)(i+48));
	}
}
void Move(int from,int to,stack* l,stack* c,stack* r){
	stack* start_ptr;
	stack* stop_ptr;
	char tmp;
	if(from == 1){start_ptr =l;}
	else if(from == 2){start_ptr = c;}
	else{start_ptr = r;}

	if(to == 1){stop_ptr =l;}
	else if(to == 2){stop_ptr = c;}
	else{stop_ptr = r;}

tmp = pop(start_ptr);
push(stop_ptr,tmp);
}

void hanoi(int n, int start, int stop,stack* l,stack* c,stack* r){
	int tmp_tower_idx;

	if(n==1){
		printf("Move disk 1 from %d to %d\n",start,stop);
		Move(start,stop,l,c,r);
		/*display(l,c,r);*/

	}
	else{
		tmp_tower_idx = 6 - start - stop;
		hanoi(n-1,start,tmp_tower_idx,l,c,r);
		printf("Move disk %d from %d to %d\n",n,start,stop);
		Move(start,stop,l,c,r);
		/*display(l,c,r);*/
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


    head_ptr_r-> next = head_r;
    head_ptr_c-> next = head_c;
    head_ptr_l -> next = head_l;

	scanf("%d%d%d",&n, &start,&stop);

if(((start < 1) ||(start > 3)) || ((stop<1) || (stop>3)) || (n <= 0)){
	printf("Bad argument");
	exit(1);
}

	initialize(n,start,head_ptr_l,head_ptr_c,head_ptr_r);
	hanoi(n,start,stop,head_ptr_l,head_ptr_c,head_ptr_r);


	return 0;
}