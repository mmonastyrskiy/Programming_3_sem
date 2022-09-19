#include <stdio.h>
void st(char a[], int n){
	int i;
	for (i = 0; i < n; i++)
	{
		printf("[%x]\n",a[i]);
	}
	i = 0;
	while (a[i] != '\0'){
		printf("[%x]%c\n",a[i],a[i]);
		i++;
	}
}



int length(char a[]){
	int l = 0;
	int i = 0;
	while (a[i] != '\0'){
		i++;
	}
	return i;
}

int  main(int argc, char  *argv[])
{
	char c1[] = {'q','w','e',0};
	char c2[] = "asdf";
	char c;
	printf("1[%s]\n",c1);
	printf("2[%s]\n",c2);
	/*st(c1,4); */
	while((c = getc(stdin)) != EOF){
		switch (c){
			case '\n':printf("\\n\n"); break;
			case 'q':return 1;
			case 'Q' : printf("QQQ\n");		}
	}
	if(argc > 1){
		printf("length: %d\n",length(argv[1]));
	}
	return 0;
}