#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
	int ht;
}node;
 
int height(node *root)
{
	int lefth,righth;
	if(root==NULL)
		return(0);
	
	if(root->left==NULL)
		lefth=0;
	else
		lefth=1+root->left->ht;
		
	if(root->right==NULL)
		righth=0;
	else
		righth=1+root->right->ht;
	
	if(lefth>righth)
		return(lefth);
	
	return(righth);
}

node* rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
node* rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht= height(x);
	y->ht= height(y);
	
	return(y);
}
 
node* rightright(node *root)
{
	root=rotateleft(root);
	return root;
}
 
node* leftleft(node *root)
{
	root=rotateright(root);
	return root;
}
 
node* leftright(node *root)
{
	root->left=rotateleft(root->left);
	root=rotateright(root);
	
	return root;
}
 
node* rightleft(node *root)
{
	root->right=rotateright(root->right);
	root= rotateleft(root);
	return root;
}

int balancefact(node *root)
{
	int lefth,righth;
	if(root==NULL)
		return(0);
 
	if(root->left==NULL)
		lefth=0;
	else
		lefth=1+root->left->ht;
 
	if(root->right==NULL)
		righth=0;
	else
		righth=1+root->right->ht;
 
	return(lefth-righth);
}

node* insert(node *root,int x)
{
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->data=x;
		root->left=NULL;
		root->right=NULL;
	}
	else
		if(x > root->data)		// insert in right subtree
		{
			root->right=insert(root->right,x);
			if(balancefact(root)==-2)
				if(x>root->right->data)
					root= rightright(root);
				else
					root= rightleft(root);
		}
		else
			if(x<root->data)
			{
				root->left=insert(root->left,x);
				if(balancefact(root)==2)
					if(x < root->left->data)
						root=leftleft(root);
					else
						root=leftright(root);
			}
		
		root->ht=height(root);
		
		return root;
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d(%d) ",root->data,balancefact(root));
		preorder(root->left);
		preorder(root->right);
	}
}
 
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d(%d) ",root->data,balancefact(root));
		inorder(root->right);
	}
}


int main()
{
	node *root=NULL;
	int x,n,i,op;
	
	do
	{
		printf("1.Create the tree:");
		printf("\t2.Insert a node:");
		printf("\t3.Print the tree:");
		printf("\t4. Exit");
		printf("\nEnter choice:");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1: printf("Enter no. of elements:");
					scanf("%d",&n);
					printf("\nEnter tree data:");
					root=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						root=insert(root,x);
					}
					break;
				
			case 2: printf("\nEnter a data:");
					scanf("%d",&x);
					root=insert(root,x);
					break;
					
					
			case 3: printf("\nPreorder:\n");
					preorder(root);
					printf("\nInorder:\n");
					inorder(root);
					printf("\n");
					break;			
		}
	}while(op!=4);
	
	return 0;
}
