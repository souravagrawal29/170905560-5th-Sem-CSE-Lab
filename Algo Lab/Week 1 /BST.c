#include<stdio.h>
#include<stdlib.h>
struct Node{
	int val;
	struct Node* left;
	struct Node* right;
};

typedef struct Node Node;

Node* newNode(int x){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->val=x;
	temp->left=temp->right=NULL;
	return temp;
}
void insert(Node** root, int x){
	if(*root==NULL)
		*root=newNode(x);
	else if((*root)->val==x){
		printf("Key Found\n");
		return;
	}
	else if(x<(*root)->val)
		insert(&((*root)->left),x);
	else if(x>(*root)->val)
		insert(&((*root)->right),x);
}
void inorder(Node* root){
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}
void preorder(Node* root){
	if(root==NULL)
		return;
	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}

int main(){
	int x;
	Node* root=NULL;
	while(1){
		printf("Enter a key to insert or -1 to exit the loop\n");
		scanf("%d",&x);
		if(x==-1)
			break;
		insert(&root,x);
	}
	printf("Inorder\n");
	inorder(root);
	printf("\n");
	printf("Preorder\n");
	preorder(root);
	printf("\n");
	printf("Postorder\n");
	postorder(root);

	printf("\n");
}