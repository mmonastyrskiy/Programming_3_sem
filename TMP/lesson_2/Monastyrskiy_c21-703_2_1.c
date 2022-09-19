#include <stdio.h>
#include<stdlib.h>
long long factorial(long long n){
	if (n == 0){
		return 1;
	}

	n*= factorial(n-1);
	return n;
}

int main(int argc, char *argv[]){
if (argc > 1 ){


long long n;
n = atoi(argv[1]);
printf("%lld\n", factorial(n));
} 
}
