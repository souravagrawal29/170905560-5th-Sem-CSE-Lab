#include <stdio.h>
#include <stdlib.h>

int g[101][101];

int V,E;

int visited[101] = {0};

void printmat() {
	for(int i =1; i<=V; i++) {
		for(int j=1; j<=V; j++) {
			printf("%d\t",g[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}

int check() {
	int i,j;

	for(i=1; i<=V; i++) {
		for(j=1; j<=V; j++) {
			if(g[j][i] == 1) 
				break;			
		}
		if(j == V+1) {
			if(!visited[i]) {
				visited[i] = 1;
				return i;
			}			
		}			
	}
	return -1;
}

void sourcerem() {
	while(1) {
		int p = check();
		if(p == -1)
			break;
		printf("%d ", p);
	
		for(int i=1; i<=V; i++)
			g[p][i] = 0;
	
	}
	
}

int main () {
	printf("Enter no of vertices: ");
	scanf("%d", &V);
	int i, j, a, b;
	printf("Enter number of edges: ");
	scanf("%d",&E);
	printf("Enter the edges: \n");
	for(i=0; i<E; i++) {
		scanf("%d%d",&a,&b);
		g[a][b] = 1;
	}
	printf("The topological sort is as follows:\n");
	sourcerem();
	printf("\n");
	return 0;
}
