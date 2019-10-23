#include<stdlib.h>
#include<limits.h> 
#include<stdio.h> 

int minDistance(int V,int dist[],int Queue[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (Queue[v] == 0 && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  

int out(int V,int dist[]) 
{   
    printf("\nSource is vertex [0]\n"); 
    printf("V | D\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d | %d\n", i, dist[i]); 
} 
  

void dijkstra(int V,int graph[V][V], int src) 
{ 
    int dist[V]; 
    
  
    int Queue[V]; 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, Queue[i] = 0; 
 
    dist[src] = 0; 
  
    for (int count = 0; count < V - 1; count++) { 
        
        int u = minDistance(V,dist, Queue); 
  
        
        Queue[u] = 1; 
  
        
        for (int v = 0; v < V; v++) 
            if (!Queue[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
   
    out(V,dist); 
} 
  

int main() 
{
    int V;
    printf("\nEnter the number of vertices:\n");
    scanf("%d",&V);

    int graph[V][V];

    printf("\nEnter the adj graph:\n");
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
  
    dijkstra(V,graph, 0); 
  
    return 0; 
} 
