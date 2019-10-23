#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30

struct edge
{
	int u,v,w;
};
 
struct adj
{
	struct edge data[MAX];
	int v;
};

struct adj elist;
int wt[MAX][MAX],v;
struct adj track;
 
void out();
void kruskal();
int find(int belongs[],int Vno);
void union_(int belongs[],int child1,int child2);


void sort(){
	int i,j;
	struct edge temp;
	
	for(i=1;i<elist.v;i++)
		for(j=0;j<elist.v-1;j++)
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
			}
}

void kruskal()
{
	int belongs[MAX],i,j,childno1,childno2;
	elist.v=0;
 
	for(i=1;i<v;i++)
		for(j=0;j<i;j++)
		{
			if(wt[i][j]!=0)
			{
				elist.data[elist.v].u=i;
				elist.data[elist.v].v=j;
				elist.data[elist.v].w=wt[i][j];
				elist.v++;
			}
		}
 
	sort();
	
	for(i=0;i<v;i++)
		belongs[i]=i;
	
	track.v=0;
	//DSU 
	for(i=0;i<elist.v;i++){
		childno1=find(belongs,elist.data[i].u);
		childno2=find(belongs,elist.data[i].v);
		
		if(childno1!=childno2){
			track.data[track.v]=elist.data[i];
			track.v=track.v+1;
			union_(belongs,childno1,childno2);
		}
	}
}

void union_(int belongs[],int child1,int child2){
	int i;
	for(i=0;i<v;i++)
		if(belongs[i]==child2)
			belongs[i]=child1;
}
int find(int belongs[],int Vno){
	return(belongs[Vno]);
}

 

 
void out()
{
	int i,cost=0;
	
	for(i=0;i<track.v;i++)
	{
		printf("\n%d-->%d\t,Edge cost:%d",track.data[i].u,track.data[i].v,track.data[i].w);
		cost=cost+track.data[i].w;
	}
    printf("\n");
	printf("Total Cost of the spanning wt=%d\n",cost);
}

int main()
{
	int i,j,v_cost;
	printf("Enter the number of vertices?\n");
    scanf("%d",&v);
	printf("Enter graph:");
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			scanf("%d",&wt[i][j]);
	kruskal();
	out();
}
 

 


