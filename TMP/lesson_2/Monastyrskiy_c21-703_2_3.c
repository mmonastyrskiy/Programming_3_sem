#include <stdio.h>


int length(char a[]){
	int l = 0;
	int i = 0;
	while (a[i] != '\0'){
		i++;
	}
	return i;
}
int my_strcmp(char a[], char b[]){
	int len_a,len_b,i;
	len_a = length(a);
	len_b = length(b);
	if (len_a == len_b){
		for(i =0;i <len_a;i++){
			if(a[i] != b[i]) 
				{
					return 2;
				}

		}
	return 0;

	}
	if (len_a > len_b){return -1;}
	else{return 1;}
}
int  main(int argc, char  *argv[])
{
char c1[] = "asdf";
char c2[] = "aqdf";
printf("%d\n",my_strcmp(c1,c2) );
	return 0;
}