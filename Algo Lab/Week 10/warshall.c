#include<stdio.h> 
#include<stdlib.h>
#include<string.h>


void print(int v,int possible[][v]) 
{ 
	printf ("Transitive Closure\n"); 
	for (int i = 0; i < v; i++) 
	{ 
		for (int j = 0; j < v; j++) 
			printf ("%d ", possible[i][j]); 
		printf("\n"); 
	} 
} 

void transitiveClosure(int v,int graph[][v]){ 
	
	int possible[v][v], i, j, k; 

	for (i = 0; i < v; i++) 
		for (j = 0; j < v; j++) 
			possible[i][j] = graph[i][j]; 

	for (k = 0; k < v; k++){ 
		for (i = 0; i < v; i++){
			for (j = 0; j < v; j++) 
				possible[i][j] = possible[i][j] || (possible[i][k] && possible[k][j]); 
		}
	} 

	print(v,possible); 
} 


int main() 
{ 
	int v=4;
	int graph[v][v];
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			scanf("%d",&graph[i][j]);

	transitiveClosure(v,graph); 
	return 0; 
} 
