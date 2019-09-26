#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *NODE;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int height(NODE root)
{
	if(root == NULL)
		return 0;
	return (1+max(height(root->left),height(root->right)));
}
int diameter(NODE root)
{
	if(root == NULL)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);

	int ld = diameter(root->left);
	int rd = diameter(root->right);

	return max(1+lh+rh,max(ld,rd));
}
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
int main()
{
	int n,x,ch,i;
	NODE root;
	root=NULL;
	printf("1.Insert\n2.Diameter\n3.Exit\n");
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
			x = diameter(root);
			printf("Diameter is: %d\n",x);
			break;
			case 3:
			exit(0);
			default:
			break;
		}
	}while(ch!=3);
}
