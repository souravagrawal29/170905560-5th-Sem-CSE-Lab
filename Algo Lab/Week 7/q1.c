#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST* lchild;
	struct BST *rchild;
};

typedef struct BST *Node;

Node create()
{
	Node temp=NULL;
	int n;
	printf("Enter value\n");
	scanf("%d",&n);
	temp= (Node)malloc(sizeof(struct BST));
	temp->data= n;
	temp->lchild= NULL;
	temp->rchild= NULL;
	return temp;
}

void insert(Node r,Node child)
{
	if(child->data== r->data)
	{
		printf("key found\n");
	}
	else
	{

	if(child->data< r->data)
	{
		if(r->lchild!=NULL)
			insert(r->lchild,child);
		else
			r->lchild= child;
	}
	if(child->data> r->data)
	{
		if(r->rchild!=NULL)
			insert(r->rchild,child);
		else
			r->rchild= child;
	}

	}
}

void preorder(Node r)
{
	if(r!=NULL)
	{
		printf("%d ",r->data);
		balancefact(r);
		preorder(r->lchild);
		preorder(r->rchild);
	}
}

void postorder(Node r)
{
	if(r!=NULL)
	{
		postorder(r->lchild);
		postorder(r->rchild);
		printf("%d ",r->data);
	}
}

void inorder(Node r)
{
	if(r!=NULL)
	{
		inorder(r->lchild);
		printf("%d ",r->data);
		inorder(r->rchild);
	}
}

void balancefact(Node r)
{
	int bf;
	bf= (height(r->lchild)- height(r->rchild));
	printf("balance factor of this Node= %d \n",bf);
}
int max(int a, int b)
{
	if(a>b)
		return a;
	else 
		return b;
}

int height(Node root)
{
	if(root==NULL)
		return 0;
	else
	{
		int h;
		h= (max(height(root->lchild),height(root->rchild))+1);
		return h;
	}

}


int main()
{
	char ch;
	Node root=NULL,temp;

	do
	{
		temp= create();
		if(root==NULL)
		{
			root= temp;
		}
		else
		{
			insert(root,temp);
		}
		printf("want to continue?(y/n)\n");
		getchar();
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');

	printf("preorder traversal:\n");
	preorder(root);

	printf("\npostorder traversal:\n");
	postorder(root);

	printf("\ninorder traversal:\n");
	inorder(root);

	
	return 0;
}