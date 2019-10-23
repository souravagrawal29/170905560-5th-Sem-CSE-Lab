#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	pid_t fpid;
	fpid = fork();
	if(fpid==0){
		printf("Child to be zombie\n");
		exit(1);
	}
	else{
		printf("Parent without wait()\n");
		for(int i = 0;i<10;i++)
			sleep(1);
	}
}
