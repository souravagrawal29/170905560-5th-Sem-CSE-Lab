#include<stdio.h>
#include<stdlib.h>
struct Node{
	int val;
	struct Node* next;
};

void printMat(int adj[][10],int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
	return;
}


int main(){
	int n,i,j,x,y;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	int adj[10][10];
	int q;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			adj[i][j]=0;
	
	while(1){
		printf("Enter the two vertices that have an edge or -1 to exit\n");
		scanf("%d",&x);
		if(x==-1)
			break;
		scanf("%d",&y);
		adj[x][y]=1;
		adj[y][x]=1;
		
	}
	printMat(adj,n);

}
