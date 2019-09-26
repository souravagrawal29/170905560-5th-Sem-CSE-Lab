#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int h[],int n)
{
	int i,k,v,heapify,j;
	for(i=n/2;i>=1;i--)
	{
		k=i;v=h[k];heapify=0;
		while(heapify==0 && 2*k<=n)
		{
			j=2*k;
			if(j<n)
				if(h[j]<h[j+1])
					j++;
			if(v>=h[j])
				heapify=1;
			else
			{
				h[k]=h[j];
				k=j;
			}
		}
		h[k]=v;
	}
	return;
}
void heapsort(int h[],int n)
{
	for(int i=n;i>0;i--)
	{
		swap(&h[i],&h[1]);
		printf("%d ",h[i]);
		heapify(h,--n);
	}
}
void main()
{
	int h[20],i,n;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	heapify(h,n);
	printf("Heap:\n");
	for(int i=1;i<=n;i++)
		printf("%d ",h[i]);
	printf("\n");
	printf("Heapsort:\n");
	heapsort(h,n);
	printf("\n");
}