#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int h[], int n, int i) 
{ 
    int l = i * 2; 
    int r = i * 2 + 1; 
    int largest = i; 
    if (l <= n && h[l] > h[i]) 
        largest = l; 
    if (r <= n && h[r] > h[largest]) 
        largest = r;
    if (largest != i) 
    { 
        swap(&h[i], &h[largest]); 
        heapify(h, n, largest); 
    } 
}

int main()
{
	int arr[20];
	int n;
	printf("Enter no of elements: ");
	scanf("%d\n",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i); 
		printf("Heap: ");
		for(int j=1; j <= n; j++)
			printf("%d ",arr[j]);
		printf("\n");
	}
}