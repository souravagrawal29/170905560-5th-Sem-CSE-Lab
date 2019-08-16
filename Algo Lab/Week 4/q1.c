#include <stdio.h>
#include <stdlib.h>

int mini = 1000007;
int mat[10][10];
int n;

void computeCost(int arr[]) {
	int cost = 0,i;
	for(i=0; i<n; i++) {
		cost = cost + mat[i][arr[i]-1];
	}
	if(cost < mini)
		mini = cost;
	return;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int arr[], int start, int end)
{
    if(start==end) {
        computeCost(arr);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap(&arr[i], &arr[start]);
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end);
        //restore swap
        swap(&arr[i], &arr[start]);
    }
}

int main() {
	int i,j;
	printf("Enter number of people: \n");
	scanf("%d",&n);

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
}