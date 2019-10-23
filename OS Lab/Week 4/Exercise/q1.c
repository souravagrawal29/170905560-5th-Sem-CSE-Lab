#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
	int status;
	pid_t pid;
	pid = fork();
	if(pid==0){
		for(int i =0;i<10;i++){
			printf("This is child @%d\n",i);
			sleep(1);
		}
	}
	else{
		printf("\nParent blocked.\n");
		wait(&status);
		printf("This is parent, child returned %d\n",status);

	}
}