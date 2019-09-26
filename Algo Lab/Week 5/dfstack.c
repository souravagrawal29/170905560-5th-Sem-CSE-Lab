#include <stdio.h>
#include <stdlib.h>

int g[101][101];
int V,E;
int visited[101] = {0};
int stack[101],top=0;
int order[101],len=0;

void push(int v) {
	stack[top] = v;
	top++;
}

int pop() {
	if(top == 0)
		return -1;
	top--;
	return stack[top];
}

void dfsv(int v) {
	visited[v] = 1;
	printf("Visiting..%d\n", v);
	push(v);

	while(1) {
		int vert = pop();
		if(vert == -1)
			break;
		order[len++] = vert;
		if(!visited[vert]) {
			printf("Visiting..%d\n", vert);
			visited[vert] = 1;
		}

		for(int i=1; i<=V; i++) {
			if(!visited[i] && g[vert][i] == 1) {
				push(i);
			}
		}
	}
}

void dfs() {
	for(int i=1; i<=V; i++) {
		if(!visited[i])
			dfsv(i);
	}
}

int main() {
	printf("Enter number of vetices:\n");
	scanf("%d",&V);
	printf("Enter num of edges: \n");
	scanf("%d",&E);
	int i,x,y;
	for(i=0; i<E; i++) {
		scanf("%d%d",&x,&y);
		g[x][y] = 1;
	}

	dfs();

	for(i=len-1; i>=0; i--) {
		printf("%d\t", order[i]);
	}

	printf("\n");
}
