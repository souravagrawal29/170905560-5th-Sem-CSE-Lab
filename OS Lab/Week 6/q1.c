#include<stdio.h>
#include<stdlib.h>

void sort(int arr[],int burst[],int prior[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				temp=burst[j];
				burst[j]=burst[j+1];
				burst[j+1]=temp;
				temp=prior[j];
				prior[j]=prior[j+1];
				prior[j+1]=temp;
			}
		}
	}
}

void fcfs(int arr[],int prior[],int burst[],int n){

	int turn[n],fin[n],wait[n],i;
	printf("Performing FCFS...\n");
	fin[0]=burst[0];
	wait[0]=0;turn[0]=burst[0];
	for(i=1;i<n;i++){
		fin[i]=fin[i-1]+burst[i];
		turn[i]=fin[i]-arr[i];
		wait[i]=turn[i]-burst[i];
	}
	int totwait=0,totturn=0;
	double awt,aturnt;
	printf("\n");
	for(i=0;i<n;i++){
		printf("Process %d with priority %d is executig\n",(i+1),prior[i]);
		printf("Finish time = %d  Turnaround time = %d  Waiting time = %d\n\n",fin[i],turn[i],wait[i]);
		totwait+=wait[i];
		totturn+=turn[i];
	}
	awt=totwait/(double)n;
	aturnt=totturn/(double)n;
	printf("Total Turnaround time = %d\nTotal Waiting time %d\n",totturn,totwait);
	printf("Average Turnaround time = %lf\nAverage Waiting time %lf\n",aturnt,awt);

}

int main(){
	int i,n;
	char ch;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	int arr[n],burst[n],prior[n],turn[n],fin[n],wait[n];
	printf("Enter the arrival time, burst time and priority of %d processes respectively\n", n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		scanf("%d",&burst[i]);
		scanf("%d",&prior[i]);
	}
	printf("Sorting based on arrival time\n");
	sort(arr,burst,prior,n);
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\n",arr[i],burst[i],prior[i]);
	}
	fcfs(arr,prior,burst,n);
}