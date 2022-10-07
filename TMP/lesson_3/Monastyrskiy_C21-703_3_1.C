#include <stdio.h> 
void readstr(char b[], int size){
	char c;
	int pointer;
	pointer = 0;
	while(1){
		c = getc(stdin);
		if(c == '\n') break;
		if(pointer == size-2){
			break;
		}
		b[pointer] = c;
		pointer++;


	}
	b[pointer] = '\0';
}


int copy_str(char src[], char dest[]){
	int i;
	i = 0;
	while(src[i] != '\0'){
		if(i >= 254){return -1;}
		dest[i] = src[i];
		i++;
	}
dest[i] = '\0';
i++;
return i;
}


void out(char buffer[]){
		int i;
	i = 0;
	while(buffer[i] != '\0'){
		printf("a[%d]= %c\n",i,buffer[i]);
		i++;
	}
}

int main(){
	char buffer[256];
	char buffer_2[256];
	readstr(buffer,256);
	copy_str(buffer,buffer_2);
	int i;
	i = 0;
	while(buffer[i] != '\0'){
		printf("a[%d]= %c\n",i,buffer[i]);
		i++;
	}
	printf("\n");
	i =0;

		while(buffer_2[i] != '\0'){
		printf("b[%d]%c\n",i,buffer_2[i]);
		i++;
	}

	return 0;

} 
