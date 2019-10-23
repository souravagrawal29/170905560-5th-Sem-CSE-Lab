#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a>b)? a: b;
}


int knapsack(int val[],int wt[],int n,int W){
    int K[n+1][W+1];
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0||j==0)
                K[i][j]=0;
            else if(wt[i-1]<=j)
                K[i][j]=max(K[i-1][j],K[i-1][j-wt[i-1]]+val[i-1]);
            else 
                K[i][j]=K[i-1][j];
        }
    }
    return K[n][W];
}

int main(){
    int n,i,W;
    printf("Enter  n\n");
    scanf("%d",&n);
    int val[n],wt[n];
    printf("Enter the elements in vlaues array\n ");
    for(i=0;i<n;i++)
        scanf("%d",&val[i]);
    printf("Enter elements in weight array\n");
    for(i=0;i<n;i++)
        scanf("%d",&wt[i]);
    printf("Enter the maximum value of W\n");
    scanf("%d",&W);
    int maxi=knapsack(val,wt,n,W);
    printf("Max Value Possible %d \n",maxi);
    
}