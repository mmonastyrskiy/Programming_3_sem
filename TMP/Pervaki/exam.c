#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	unsigned long int p = 7;
	int N;
	float sum;
	int i,power;
	 unsigned long long int  tmp;
	sum = 0;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		tmp = p;
		for(power=1;power<i;power++){
			tmp *=p;

		}
		sum += (float)i/(float)tmp;

	}
	printf("%.4f\n",sum);
	return 0;
}