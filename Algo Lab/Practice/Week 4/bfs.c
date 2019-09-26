#include<stdio.h>
#include<stdlib.h>

void bfs(int u,int vis[],int adj[][10],int ord[],int x,int n){
    int q[n],f=0,r=0;
    vis[u]=1;
    q[r++]=u;
    while(f!=r){
        int v=q[f++]; // dequeuing the vertex
        ord[x++]=v;
        int i;
        for(i=1;i<=n;i++){
            if(!vis[i]  && adj[v][i]==1){
                vis[i]=1;
                q[r++]=i; // enqueuing the vertex
            }
        }
    }
}
int main(){
    int n,i,m,j;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int adj[10][10];
    int ord[n],vis[n+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            adj[i][j]=0;
        }
    }
    for(i=0;i<=n;i++)
        vis[i]=0;
    printf("Enter the number of edges \n");
    scanf("%d",&m);
    printf("Enter the edges\n");
    int u,v;
    for(i=0;i<m;i++){
        scanf("%d",&u);
        scanf("%d",&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int x=0;
    for(i=1;i<=n;i++){
        if(!vis[i])
            bfs(i,vis,adj,ord,x,n);
    }
    printf("Printing the order they were enqueued in\n");
    for(i=0;i<n;i++)
        printf("%d ",ord[i]);
    printf("\n");

}