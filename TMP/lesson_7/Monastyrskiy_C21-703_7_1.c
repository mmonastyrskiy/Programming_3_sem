#include <stdio.h>
#include <stdlib.h>
int main(int argc, char  *argv[])
{
	FILE *fi, *fo;
	struct example
	{
		int i;
		char c[100];

		
	} st;

	if(argc < 2) {printf("1\n");exit(1);}
	if((fi =fopen(argv[1],"r"))==NULL){printf("2\n");exit(2);}
	if((fo =fopen(argv[2],"w"))==NULL){printf("3\n");exit(3);}
	while (fscanf(fi,"%d %s",&st.i, st.c) != EOF){	
		fprintf(fo, "%s %d\n",st.c, st.i);
	}
	fclose(fi);
	fclose(fo);

	/* code */
	return 0;
} 
