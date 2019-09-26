#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *NODE;
void create(NODE *root,int val)
{
	if(*root == NULL)
	{
		NODE temp = (NODE)malloc(sizeof(struct node));
		temp->data = val;
		temp->left = temp->right = NULL;
		*root = temp;
	}
	else if(val<(*root)->data)
		create(&((*root)->left),val);
	else
		create(&((*root)->right),val);
}

void inorder(NODE root) {
	if(root) {
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

int nodes(NODE root) 
{ 
    if (root == NULL) 
       return 0;    
    int ans = 1;
    ans = ans + nodes(root->left);
    ans = ans + nodes(root->right);
    return ans;
} 


int main()
{
	int n,x,ch,i;
	NODE root;
	root=NULL;
	printf("1.Insert\n2.Total Nodes\n3.Exit\n");
	do
	{		
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter a node\n");
			scanf("%d",&x);
			create(&root,x);
			break;
			
			case 2:
			x = nodes(root);
			printf("Number of nodes are: %d\n",x);
			break;
			case 3:
			exit(0);
			default:
			break;
		}
	}while(ch!=3);
}
