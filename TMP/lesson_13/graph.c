#include <stdio.h>
#include <stdlib.h>



typedef struct Node
{ int n,neighbors_counter,capacity;
struct Node* neighbors;

}node;

void expand_array(){



}

void create_new_node(int current_size,int current_count, node* global){

if (current_count == current_size){
	expand_array();
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
neighbors_counter =0;
new.capacity = current_size;
global[current_count] = new;
current_count++;
}


void add_neighbor(node n,node new_nei){
	if(n.current_count ==n.capacity){
		expand_array();
		n.capacity+=1;
	}
	n.neighbors[n.current_count] = new_nei;
	n.current_count+=1;

}



int find_neighbor_ammount(int n){
		FILE* f;
	int node1,node2,a;
	a =0;

	f =fopen(path,'r');
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
return a/2

}


void fill_zeros(int n, int[n][n] nodes){
	int i,j;
	for (i=0;i<n;i++){
		for(j=0,j<n,j++){
			nodes[i][j] = 0;
		}
	}
}
int find_max(const char* path){
	FILE* f;
	int node1,node2,max;
	max = -1;

	f =fopen(path,'r');
	if(f == NULL){
		printf("Error opening file");
		exit(2);
	}
	while(fscanf(f,"%d %d",&node1,&node2)){
		if(node1 > max){max = node1}
		if(node2 > max){max = node2}
	}
fclose(f);
return max
}
void read_adj_matrix(const char* path, int n, int[n][n] nodes){


	FILE* f;
	int node1,node2;

	f =fopen(path,'r');
	if(f == NULL){
		printf("Error opening file");
		exit(2);
	}
	while(fscanf(f,"%d %d",&node1,&node2)){
		nodes[node1-1][node2-1] += 1;
	}
fclose(f);

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
int[n][n] nodes;
fill_zeros(n,nodes);
global = malloc(sizeof(node)*BASIC_SIZE);
if(global == NULL){
	printf("malloc error");
	exit(2);
}

	return 0;
}