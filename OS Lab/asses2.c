#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>


void* sum(void* param){
    int n=param,s=0;
    while(n>0){
        s=s+ (n%10);
        n=n/10;
    }
    return (void *)s;
}

void* prod(void* param){
    int n=param,p=1;
    while(n>0){
        p=p*(n%10);
        n=n/10;
    }
    return (void *)p;
}


int main(){
    int num,sumd,produ;
    pthread_t thread1,thread2;
    printf("Enter number \n");
    scanf("%d",&num);
    pthread_create(&thread1,0,&sum,num);
    pthread_create(&thread2,0,&prod,num);
    pthread_join(thread1,(void**)&sumd);
    pthread_join(thread2,(void**)&produ);
    printf("The sum is %d \n",sumd);
    printf("The product is %d  \n",produ);
}