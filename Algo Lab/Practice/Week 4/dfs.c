#include<stdio.h>
#include<stdlib.h>
int x=0,y=0;

void dfs(int u,int adj[][10],int push[],int pop[],int vis[],int n){
    vis[u]=1;
    push[x++]=u;
    int i;
    for(i=1;i<=n;i++){
        if(!vis[i] && adj[u][i]==1)
            dfs(i,adj,push,pop,vis,n);
    }
    pop[y++]=u;

}

int main(){
    int n,m,i,j;
    printf("Enter the number of vertices and edges\n");
    scanf("%d",&n);
    scanf("%d",&m);
    int vis[n+1],push[n],pop[n];
    for(i=0;i<=n;i++)
        vis[i]=0;
    int adj[10][10],u,v;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++)
            adj[i][j]=0;
    }
    printf("Enter u and v that share an edge\n");
    for(i=0;i<m;i++){
        scanf("%d",&u);
        scanf("%d",&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    printf("The matrix is as follows \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
    for(i=1;i<=n;i++){
        if(!vis[i])
            dfs(i,adj,push,pop,vis,n);
    }
    printf("The push and pop order are as follows\n");
    for(i=0;i<n;i++)
        printf("%d ",push[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",pop[i]);
    printf("\n");
}