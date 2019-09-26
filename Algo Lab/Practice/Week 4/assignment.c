#include<stdio.h>
#include<stdlib.h>

int computeCost(int a[],int mat[][10],int minperm[],int min,int n){
    int cost=0,i;
    for(i=0;i<n;i++){
        cost=cost + mat[i][a[i]-1];
    }
    if(cost<min){
        min=cost;
        for(i=0;i<n;i++)
            minperm[i]=a[i];
    }
    return min;
}

int permute(int a[],int l,int r,int min,int minperm[],int n,int mat[][10]){
    if(l==r){
        min=computeCost(a,mat,minperm,min,n);
    }
    else{
        int i;
        for(i=l;i<=r;i++){
            swap(&a[l],&a[i]);
            min=permute(a,l+1,r,min,minperm,n,mat);
            swap(&a[l],&a[i]);            
        }
    }
    return min;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int i,j,n;
    printf("Enter the number of people\n");
    scanf("%d",&n);
    int mat[10][10];
    int min=10000,minperm[n];
    printf("Enter the cost matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    }
    int a[n];
    for(i=0;i<n;i++)
        a[i]=i+1;
    min=permute(a,0,n-1,min,minperm,n,mat);
    printf("The minimum cost is %d\n",min);
    printf("The minimum cost permutation is \n ");
    for(i=0;i<n;i++)
        printf("%d ",minperm[i]);
    printf("\n");

}