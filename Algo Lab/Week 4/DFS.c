#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node Node;

void addEdge(Node* adj[],int x,int y){
	Node* nd1= (Node*)malloc(sizeof(Node));
	nd1->data=y;
	nd1->next=NULL;
	Node* nd2=(Node*) malloc(sizeof(Node));
	nd2->data=x;
	nd2->next=NULL;
	Node* temp1=adj[x];
	if(temp1==NULL)
		temp1=nd1;
	else{
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=nd1;
	}
	Node *temp2=adj[y];
	if(temp2==NULL)
		temp2=nd2;
	else{
		while(temp2->next!=NULL)
			temp2=temp2->next;
		temp2->next=nd2;
	}
}

void printList(Node* adj[],int n){
	int i;
	for(i=1;i<=n;i++){
		printf("%d\t",i);
		Node* temp=adj[i];
		while(temp!=NULL){
			printf("%d ",temp->data );
			temp=temp->next;
		}
		printf("\n");
	}

}

int main(){
	int n,m,x,y;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	Node* adj[n+1];
	printf("Enter number of edges\n");
	scanf("%d",&m);
	while(m-->0){
		scanf("%d",&x);
		scanf("%d",&y);
		addEdge(adj,x,y);
	}
	printList(adj,n);

}