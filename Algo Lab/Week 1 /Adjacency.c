#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};

typedef struct Node Node;

struct Node* ad[11];

void addEdge(int adj[][11],int x,int y){

	adj[x][y]=1;
	adj[y][x]=1;
	Node *nd=(Node *)malloc(sizeof(Node));
	nd->data=y;
	nd->next=NULL;
	Node* nd2=(Node*)malloc(sizeof(Node));
	nd2->data=x;
	nd2->next=NULL;
	Node *temp=ad[x];
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=nd;
	Node *temp2=ad[y];
	while(temp2->next!=NULL)
		temp2=temp2->next;
	temp2->next=nd2;

}

void printMat(int adj[][11],int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
	return;
}

void printList(int n){
	int i;
	for(i=1;i<=n;i++){
		Node *temp=ad[i];
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main(){
	int n,i,j,x,y;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	int adj[11][11];
	int q;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			adj[i][j]=0;

	for(i=1; i<=n; i++) {
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->data = i;
		temp->next = NULL;
		ad[i] = temp;
	}
	
	while(1){
		printf("Enter the two vertices that have an edge or -1 to exit\n");
		scanf("%d",&x);
		if(x==-1)
			break;
		scanf("%d",&y);
		addEdge(adj,x,y);
	}
	printf("\n\n");
	printList(n);
	printf("\n\n");
	printMat(adj,n);

}
