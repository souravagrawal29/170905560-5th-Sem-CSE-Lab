#include<stdio.h>
#include<stdlib.h>

int adj[11][11] = {};
typedef struct Node {
	int data;
	struct Node *next;
}Node;

Node *arr[11];

void addEdge(int a,int b) {
	if(a>10 || b>10) {
		printf("Vertex should be less than 10\n");
		return;
	}
	adj[a][b] = 1;
	adj[b][a] = 1;
	printf("Added to matrix\n");
	int i;
	for(i=0; i<11; i++) {
		if(a == i) {
			Node *temp = arr[i];
			Node *nd = (Node *)malloc(sizeof(Node));
			nd->data = b;
			temp->next = nd;
		}
	}

	for(i=0; i<11; i++) {
		if(b == i) {
			Node *temp = arr[i];
			Node *nd = (Node *)malloc(sizeof(Node));
			nd->data = a;
			temp->next = nd;
			nd->next = NULL;
		}
	}

	printf("Added to list\n");
}

void printMatrix() {
	int i,j;
	printf("\t");
	for(i=0; i<11; i++)
		printf("%d\t",i);
	printf("\n\n");
	for(i=0; i<11; i++) {
		printf("%d\t", i);
		for(j=0; j<11; j++) {
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
}

void printList() {
	int i;

	for(i=0; i<11; i++) {
		Node *temp = arr[i];
		while(temp!=NULL) {
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	int choice,a,b,i;

	for(i=0; i<11; i++) {
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->data = i;
		temp->next = NULL;
		arr[i] = temp;
	}

	do {
		printf("1. Add an edge\n");
		printf("2. Print adjacency matrix\n");
		printf("3. Print adjacency list\n");
		printf("4. Exit\n");
		printf("Enter choice: \n");
		scanf("%d",&choice);

		switch(choice) {
			case 1: printf("Enter first vertex: \n");
			        scanf("%d",&a);
			        printf("Enter second vertex: \n");
			        scanf("%d",&b);
			        addEdge(a,b);
			        break;
			case 2: printMatrix();
			        break;
			case 3: printList();
			        break;
			case 4: break;
			default: printf("Wrong choice\n");
		}
	}
	while(choice!=4);
}