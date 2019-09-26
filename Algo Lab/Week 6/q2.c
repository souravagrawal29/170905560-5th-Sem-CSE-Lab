#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int r) {
	int p = arr[l];
	int i = l;
	int j = r+1;
	while(1) {
		while(1) {
			i = i + 1;
			if(arr[i]>=p)
				break;
		}

		while(1) {
			j = j - 1;
			if(arr[j]<=p)
				break;
		}

		swap(&arr[i],&arr[j]);

		if(i>=j)
			break;
	}
	swap(&arr[i],&arr[j]);
	swap(&arr[l],&arr[j]);

	return j;
}

void quicksort(int arr[],int l,int r) {
	if(l<r) {
		int s = partition(arr,l,r);
		quicksort(arr,l,s-1);
		quicksort(arr,s+1,r);
	}
}

int main() {
	int n;
	printf("Enter number of elements: \n");
	scanf("%d",&n);
	int arr[n],i;
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}
