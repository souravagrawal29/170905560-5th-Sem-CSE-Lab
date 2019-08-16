#include<stdio.h>
#include<stdlib.h>
int count;
int main(){
	int n,m,res,i;
	printf("Enter the first number\n");
	scanf("%d",&m);
	printf("Enter the second number\n");
	scanf("%d",&n);
	res=(m>n)?n:m;
	count=0;
	for(i=res;i>=1;i--){
		count++;
		if(m%i==0 && n%i==0)
			break;
	}
	printf("Number of Steps = %d\n",count);
	printf("GCD is %d\n",i );
}