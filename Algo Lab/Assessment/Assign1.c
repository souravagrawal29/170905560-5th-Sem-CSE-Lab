// Knapsack recursive brute force solution

#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int max(int a,int b){
	return a>b?a:b;
}

int knapsack(int a[],int w[],int W,int n){
	if(n==0||W==0)
		return 0; 
	if(w[n-1]>W)
		return knapsack(a,w,W,n-1) ;

	return max(a[n-1]+knapsack(a,w,W-w[n-1],n-1),knapsack(a,w,W,n-1));
}

int main(){
	int n,i,W;
	printf("Enter n \n");
	scanf("%d",&n);
	printf("Enter the values\n");
	int a[n],w[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the weights\n");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Enter the max capacity\n");
	scanf("%d",&W);
	printf("%d\n", knapsack(a,w,W,n));

}