#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

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
int pow(int a, int power, int* status){
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
int translate( long int n,int* status) /* 6 -> 10*/
{
	 long int t;
	if (n <0){
	t = -1;
	n *=-1;
}
     long int result = 0;
    for(size_t i = 0; n>=pow(10,i,status); ++i)
        {
            result += n%pow(10,i+1,status)/pow(10,i,status) * pow(6,i,status);
        }
    if(t == -1){result *=-1;}
    return result;
}
int translate_back(int r){ /*10->6*/
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

int main(int argc, char const *argv[])
{		int status;
	 long int a,b,ans1,ans2;
	 status = 0;
	scanf("%ld\n%ld",&a,&b);
	ans1=translate(a,&status);
	ans2=translate_back(b);
	if (status ==0){
	printf("%ld\n%ld\n",ans1,ans2);
}
else{
	printf("%ld\n!\n")
}

	
	return 0;
}