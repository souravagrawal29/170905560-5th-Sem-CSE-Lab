#include<stdio.h>
#include<stdlib.h>
int opcount = 0;

void merge(int arr[], int l, int m, int r) {
	int a[100], b[100];
	int n1 = m - l + 1, n2 = r - m;
	for(int i = 0; i < n1; i++)
		a[i] = arr[l + i];
	for(int i = 0; i < n2; i++)
		b[i] = arr[m + i + 1];
	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2) {
		if(a[i] < b[j])
			arr[k++] = a[i++];
		else
			arr[k++] = b[j++];
	}
	while(i < n1)
		arr[k++] = a[i++];
	while(j < n2)
		arr[k++] = b[j++];
}

void mergeSort(int arr[], int l, int r) {
	if(l < r) {
		int m = l + (r - l) / 2;
		opcount++;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main() {
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	int arr[100];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	mergeSort(arr, 0, n);
	printf("Sorted: ");
	for(int i = 0; i < n; i++) 
		printf("%d ", arr[i]);
	printf("\nOpcount: %d\n", opcount);
	return 0;
}