#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{ int n,neighbors_counter,capacity;
struct Node* neighbors;

}node;


void expand_array(node* n , int c){
n = realloc(n,sizeof(node)*c+1);
}


void create_new_node(int current_size,int current_count, node* global){

if (current_count == current_size){
	expand_array(global,current_size);
	current_size+=1;

}
node new;
node* a;
new.n = current_count+1;
a = malloc(sizeof(node)*current_size);
if(a == NULL){
	printf("malloc error");
	exit(2);
}
new.neighbors = a;
new.neighbors_counter =0;
new.capacity = current_size;
global[current_count] = new;
current_count++;
}



void expand_arrayS(node* n){


n->neighbors = realloc(n->neighbors,sizeof(node)*n->capacity+1);
}


char IsInList(node* global, int search,int max){
	int i;
	for(i=0;i<max;i++){
		if((global+i)->n == search){
			return '0';
		}
	}
return '1';
}


node NodeFinder(int n,int max, node* nodes){
	int i;
	for(i=0;i<max;i++){
		if(nodes[i].n == max){
			return nodes[i];
		}
		printf("Error");
		exit(3);
	}
}


void add_neighbor(node n,node new_nei){
	if(n.neighbors_counter ==n.capacity){
		expand_arrayS(&n);
		n.capacity+=1;
	}
	n.neighbors[n.neighbors_counter] = new_nei;
	n.neighbors_counter+=1;

}


void GraphLoader(const char* path, int max, node* global, int* gl_ptr){
	FILE* f;
	int node1, node2;
	f =fopen(path,"r");
	if(f == NULL){
		printf("Error opening file");
		exit(2);
	}
	while(fscanf(f,"%d %d",&node1,&node2)!=EOF){
		if(IsInList(global,node1,max)=='1'){
			create_new_node(max,*gl_ptr,global);
		}
		else if (IsInList(global,node2,max)=='1'){
			create_new_node(max,*gl_ptr,global);

		}
		else if(IsInList(global,node1,max) == '0' && IsInList(NodeFinder(node1,max,global).neighbors
																	,node2,max) == '1')
		{
			add_neighbor(NodeFinder(node1,max,global),NodeFinder(node2,max,global));
		}
		else if (IsInList(global,node2,max) == '0' && IsInList(NodeFinder(node2,max,global).neighbors,
			node1,max) == '1')
		{
			add_neighbor(NodeFinder(node2,max,global),NodeFinder(node1,max,global));
		}






	}
fclose(f);


}













int find_neighbor_ammount(int n,const char* path){
		FILE* f;
	int node1,node2,a;
	a =0;

	f =fopen(path,"r");
	if(f == NULL){
		printf("Error opening file");
		exit(2);
	}
	while(fscanf(f,"%d %d",&node1,&node2)){
		if(node1 == n || node2 == n){
			a+=1;
		}
	}
fclose(f);
return a/2;

}


void fill_zeros(int n, int nodes[n][n]){
	int i,j;
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			nodes[i][j] = 0;
		}
	}
}
int find_max(const char* path){
	FILE* f;
	int node1,node2,max;
	max = -1;

	f =fopen(path,"r");
	if(f == NULL){
		printf("Error opening file");
		exit(2);
	}
	while(fscanf(f,"%d %d",&node1,&node2)!=EOF){
		printf("%d %d", node1, node2);
		if(node1 > max){max = node1;}
		if(node2 > max){max = node2;}
	}
fclose(f);
return max;
}
void read_adj_matrix(const char* path, int n, int nodes[n][n]){


	FILE* f;
	int node1,node2;

	f =fopen(path,"r");
	if(f == NULL){
		printf("Error opening file");
		exit(2);
	}
	while(fscanf(f,"%d %d\n",&node1,&node2)!=EOF){
		nodes[node1-1][node2-1] += 1;
	}
fclose(f);



}



void print_matrix(int n, int nodes[n][n]){
	int i,j;

for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		printf(" %d ",nodes[i][j]);
	}
	printf("\n");
}

}










int Deijktsra(int n, int nodes[n][n],int start, int end, int counter){

	int i,counter;
	int copy[n][n];
	counter =0;
	memcpy(copy,nodes,sizeof(int*)*n+sizeof(int)*n);
	if(nodes[start-1][end-1] != 0){
		return counter
	}
	for(i=0;i<n;i++){
		if(nodes[start-1][n] != 0){
			counter++;
			Deijktsra(n,nodes,n+1,end,counter);
		}

	}


}



int main(int argc, char const *argv[])
{	
	int BASIC_SIZE = 10;
	int gl_ptr = 0;
	node* global;
	const char* path;
	int n;
	if(argc != 2 ){
		printf("Argument error\n");
		exit(1);

	}
path = argv[1];
n = find_max(path);
printf("\n%d\n",n);

int nodes[n][n];

fill_zeros(n,nodes);

read_adj_matrix(path,n,nodes);
print_matrix(n,nodes);




global = malloc(sizeof(node)*BASIC_SIZE);
if(global == NULL){
	printf("malloc error");
	exit(2);
}
GraphLoader(path,BASIC_SIZE,global,&gl_ptr);

	return 0;
}