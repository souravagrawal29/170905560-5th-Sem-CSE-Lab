#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

int isprime(int x){
    if(x==1)
        return 0;
	for(int i=2;i<x;i++)
		if(x%i==0)
			return 0;
return 1;
}

void *prime(void *param){
	//int *ar=(int*)calloc(2,sizeof(int));
	 int *ar=param;
	//int a=(int)ar[0];
	//int b=(int)ar[1];
	//printf("%d",b);
	//int b=(int)*param[1];
	int *arr=(int*)calloc(ar[1]-ar[0]+2,sizeof(int));
	arr[0]=0; //count of primes
	int k=1;
	for(int i=ar[0];i<=ar[1];i++){
	   if(isprime(i)){
	   arr[k++]=i;
	   arr[0]++;
	   }
	}
return (void*)arr;
}


int main(){
	int range[2];
	scanf("%d",&range[0]);
	scanf("%d",&range[1]);
	pthread_t thread;
	pthread_create(&thread,0,&prime,(void *)range);
	int * res;
	pthread_join(thread,(void**)&res);
	int sz=res[0];
	int arr[sz];
	for(int i=1;i<=res[0];i++)
		printf("%d ",res[i]);

}

