#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <fcntl.h>
#define BUFFER_SIZE 4096
#define N 10
#define INFlags O_RDONLY
#define OFlags O_WRONLY | O_CREAT
struct Data{
int i;
char c[128];

}data;

typedef struct NodeFull
{
	struct Data data;
	struct NodeFull* next;
	struct NodeFull* prev;
} node;


void gen_rand_str(char* put_into);

void print_list(node* head);

int gen_rand_int();


node* add_new_head(node* head, int new_head_data,char new_head_string[]);

node* tail_seek(node* head);

node* add_new_tail(node* head, int new_tail_data, char new_tail_string[128]);
node* rm_head(node* head);
node* rm_tail(node* head);


size_t read_from_file(node* ptr,const char* path);
size_t dump_to_file(node* ptr,const char* path);


void reverce_print_list(node* head);

node* insert_value(node* head,int insert_after,int new_node_data,char new_node_string[]);


int size_list(node *head);


void swap(node* a, node* b);

node* sort_list(node* head);


node* rm_value(node* head,int rm);
