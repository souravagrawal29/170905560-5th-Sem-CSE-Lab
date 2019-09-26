#include <stdio.h>
#include <stdlib.h>

int mini = 1000007;
int mat[10][10];
int n;
int minperm[10];

void computeCost(int arr[]) {
	int cost = 0,i;
	for(i=0; i<n; i++) {
		cost = cost + mat[i][arr[i]-1];
	}
	if(cost < mini) {
		mini = cost;
		for(i=0; i<n; i++)
			minperm[i] = arr[i];
	}
	return;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int arr[], int start, int end) {
    if(start == end) {
        computeCost(arr);
        return;
    }    
    for(int i=start; i<=end; i++)
    {        
        swap(&arr[i], &arr[start]);
        permutation(arr, start+1, end);        
        swap(&arr[i], &arr[start]);
    }
}

int main() {
	int i,j;
	printf("Enter number of people: \n");
	scanf("%d",&n);
	printf("Enter the cost matrix: \n");
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&mat[i][j]);
		}
	}

	int arr[n];
	for(i=0; i<n; i++) {
		arr[i] = i+1;
	}

	permutation(arr,0,n-1);

	printf("The minimum cost is %d\n", mini);
	printf("The permutation is: \n");
	for(i=0; i<n; i++) {
		printf("Person %d gets job %d\n", i+1, minperm[i]);
	}
	printf("\n");

	/*
	Sample input
	25 40 35
	40 60 35
	20 40 25
	ans = 95
	2 3 1
    */
}