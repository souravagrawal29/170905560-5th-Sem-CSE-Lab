// Knapsack brute force iterative(generating subsets)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int max=0;


void knapsack(int a[],int w[],int W,int n){

	unsigned int pow_n = pow(2, n); 
    int i, j,tempc,tempw; 
 
    for(i = 1; i <= pow_n; i++) {
    	tempc = 0,tempw=0;     
	    for(j = 0; j < n; j++) {  
	        if(i & (1 << j)) {
	            tempc = tempc + a[j];
	            tempw = tempw + w[j];
	        }
	    }
	    if(tempc>max && tempw<=W){
	    	max=tempc;
	    }
    } 
}

int main(){
	int n,i;
	printf("Enter n \n");
	scanf("%d",&n);
	printf("Enter the values\n");
	int a[n],w[n],W;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the weights\n");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Enter the max capacity\n");
	scanf("%d",&W);
	knapsack(a,w,W,n);
	printf("Answer is %d\n", max);
}