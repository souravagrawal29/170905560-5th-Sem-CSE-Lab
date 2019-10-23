#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define INT_MAX 9999
int min(int a,int b){
	return a < b ? a : b;
}
void print(int v,int dist[][4]) 
{ 
	for (int i = 0; i < v; i++) 
	{ 
		for (int j = 0; j < v; j++) 
		{ 
			if (dist[i][j] == INT_MAX) 
				printf("X\t"); 
			else
				printf ("%d\t", dist[i][j]); 
		} 
		printf("\n"); 
	} 
}

void floyd(int v,int adj[][4]) { 
	int dist[v][v], i, j, k; 
	for (i = 0; i < v; i++) 
		for (j = 0; j < v; j++) 
			dist[i][j] = adj[i][j];
	for (k = 0; k < v ; k++) { 
		for (i = 0; i< v; i++) { 
			for (j=0; j<v; j++) 
				dist[i][j] = min((dist[i][k]+ dist[k][j]),dist[i][j]); 
		} 
	}
	printf("The distance matrix is as follows \n");
	print(v,dist); 
} 
int main() {
	int v;
	int i ,j;
	printf("Enter the value of v\n");
	scanf("%d",&v);
	int adj[v][v];
	printf("Enter the adjacency matrix and 9999 for nodes that cannot be reached\n");
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			scanf("%d",&adj[i][j]);
	floyd(v,adj); 
	return 0; 
} 
/* 	{0, 5, INF, 10}, 
	{INF, 0, 3, INF}, 
	{INF, INF, 0, 1}, 
	{INF, INF, INF, 0} */
/*{ 
		{	   0, INT_MAX,	  -2, INT_MAX },
		{	   4,	   0,	   3, INT_MAX },
		{ INT_MAX, INT_MAX,	   0,	   2 },
		{ INT_MAX,	  -1, INT_MAX,	   0 } 
	};*/