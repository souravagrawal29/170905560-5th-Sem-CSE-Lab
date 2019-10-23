#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	pid_t fpid;
	fpid = fork();
	if(fpid==0){
		printf("CHILD.\nChild pid: NA\nParent pid: %d\n",getppid());
		printf("Current pid:%d\n",getpid());
	}
	else{
		printf("PARENT.\nChild pid:%d\nParent pid: %d", fpid, getppid());
		printf("Current PID:%d\n",getpid());
	}
}