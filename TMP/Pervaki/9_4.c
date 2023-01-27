#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#define buffsize 20
int plus(int a, int b, int* status){
	 if (((b > 0) && (a > (INT_MAX - b))) ||
      ((b < 0) && (a < (INT_MIN - b)))) {
    *status = 1;
	return INT_MIN;
  } else {
    return a+b;
  }


}
int minus (int a, int b, int* status){
  if ((b > 0 && a < INT_MIN + b) ||
      (b < 0 && a > INT_MAX + b)) {
  	*status = 2;
  return INT_MIN;

  } else {
  	return a-b;
  }


}
int mult(int a, int b, int* status){
	if (a > 0) {  
    if (b > 0) {  
      if (a > (INT_MAX / b)) {
        *status = 3;
        return INT_MIN;
      }
    } else { 
      if (b < (INT_MIN / a)) {
        *status = 3;
        return INT_MIN;
      }
    } 
  } else {
    if (b > 0) {
      if (a < (INT_MIN / b)) {
        *status = 3;
        return INT_MIN;
      }
    } else {
      if ( (a != 0) && (b < (INT_MAX / a))) {
        *status = 3;
        return INT_MIN;
      }
    } 
  } 
return a*b;
}
int power(int a, int power, int* status){
int counter,cur;
cur = a;
for(counter=1;counter < power;counter++){
	cur = mult(cur,a,status);
	if(*status == 3){
		*status =4;
		return INT_MIN;
	}

}
return cur;
}


int pow(int n,int s)
{
    int res = 1;
    for(int i = 0; i != s; ++i)
        res*=n;
    return res;
}

int checker(char* a ){
	int i;
	for(i=0;i<strlen(a);i++){
		if(i==0 && ((a[i] == '-')||(isdigit(a[i]) != 0))){
			continue;
		}
		else if (isdigit(a[i]) != 0){
			continue;
		}
		else return -1;
	}
	return 0;
}

int translate(int n)
{
	int t;
	if (n <0){
	t = -1;
	n *=-1;
}
    int result = 0;
    for(size_t i = 0; n>=pow(10,i); ++i)
        {
            result += n%pow(10,i+1)/pow(10,i) * pow(6,i);
        }
    if(t == -1){result *=-1;}
    return result;
}
int translate_back(int r){
	int m;
	if (r < 0){m =-1; r*=-1;}
	int result;
	int i,c,t,l;
	char a[20], ra[20];
	i =0;
	t=r;
	l =0;
	while (t> 0){
		a[i] = (t%6)+48;
		l++;
		/*printf("%c",a[i]);*/
		t /=6;
		/*printf("  %d\n",t);*/
		i++;

	}
	c =0;
	for(i=l-1; i>=0; i--){
		ra[i] =a[c];
		c++;
		/*printf("%c",ra[i]);*/
}
/*printf("\n");*/
sscanf(ra, "%d", &result);
if(m==-1){result*=-1;}
return result;
}

 


int calc(char* a_char, char* b_char, int* status){
	int a,b, result;
	int pw,mul1,mul2,min1,min2;
	
	if(checker(a_char) + checker(b_char) != 0){
		/*printf("Error not a number entered\n");*/
		exit(10);
	}
	a = atoi(a_char);
	b = atoi(b_char);
	a = translate(a);
	b = translate(b);
	/*printf("DEBUG %d %d\n", a,b);*/
	pw = power(a,2,status);
	/*printf("pw %d,%d\n",*status,pw);*/
	if(*status != 0) return INT_MIN;

	mul1 = mult(pw,b,status);
	/*printf("mul1 %d,%d\n",*status,mul1);*/
	if(*status != 0) return INT_MIN;

	min1 = minus(b,a,status);
	/*printf("min1 %d,%d\n",*status,min1);*/
	if(*status != 0) return INT_MIN;

	mul2 = mult(b,min1,status);
	/*printf("mul2 %d,%d\n",*status,mul2);*/
	if(*status != 0) return INT_MIN;

	min2 = minus(mul1,mul2,status);
	/*printf("min2 %d,%d\n",*status,min2);*/
	if(*status != 0) return INT_MIN;

	result = plus(min2,b,status);
	/*printf("result %d,%d\n",*status,result);*/
	if(*status != 0) return INT_MIN;





	return translate_back(result);



}

int main(int argc, char const *argv[])
{ 
	char* a_char;
	char* b_char;
	int status;
	int res;
	status = 0;
	a_char = malloc(buffsize * sizeof(char));
	b_char = malloc(buffsize * sizeof(char));
	bzero(a_char,0);
	bzero(b_char,0);
	scanf("%s\n%s\n",a_char,b_char);
	res = calc(a_char,b_char,&status);
	if (status != 0){
		printf("!%d\n",status);
		return status;
	}
	printf("%d\n", res);

	return 0;
}