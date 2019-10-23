#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
//#include "merge.h"
void swap(int *x,int *y)
{
  int temp=*x;
  *y=*x;
  *x=temp;
}
void bubbleSort(int arrival[], int burst[],int priority[],int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
    {
        for (j = 0; j < n-i-1; j++)
       {
           if (arrival[j] > arrival[j+1])
            { 
             swap(&arrival[j], &arrival[j+1]);
             swap(&burst[j],&burst[j+1]);
             swap(&priority[j],&priority[j+1]);
            }
       }
    } 
}
void fcfs(int arrival[],int burst[],int priority[],int n)
{
  int waiting[n];
  int tat[n];
  int finish[n];
  memset(waiting,0,n*sizeof(int));
  memset(tat,0,n*sizeof(int));
    memset(finish,0,n*sizeof(int));
    int tottime=0;
    for(int i=0;i<n;i++)
    {
      printf("Process [%d] with priority %d is in the queue",i+1,priority[i]);
      if(i==0)
      {
        finish[i]=burst[i];
        tottime+=burst[i];
        waiting[i]=arrival[i];
        tat[i]=burst[i]-arrival[i];
      }
      else
      {
        waiting[i]=tottime-arrival[i];
        tottime+=burst[i];
        finish[i]=tottime;
        tat[i]=burst[i]+waiting[i];
      }
      printf("Waiting time = %d  Finish time = %d  Tat = %d\n",waiting[i],finish[i],tat[i]);
    }
}
int main(int argc, char const *argv[])
{
  int count,i,j;
  int burst[30],wait[30],priority[30],arrival[30];
  int tot;
  printf("Total processes ?\n");
  scanf("%d",&tot);
  printf("Enter burst time followed by arrival time\n");
  for(count=0;count<tot;count++)
  {
      printf("Process [%d]",count+1);
      scanf("%d",&burst[count]);
      scanf("%d",&arrival[count]);
  }
  printf("Enter priority");
  for(count=0;count<tot;count++)
    scanf("%d",&priority[count]);
    
    bubbleSort(arrival,burst,priority,tot);
    fcfs(arrival,burst,priority,tot);
}
