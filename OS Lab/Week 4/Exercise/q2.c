#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	pid = fork();
	if(pid==0){
		printf("This is child in Q2\n");
		execlp("/home/student/Desktop/170905374/OS/w4/q1", "q1", NULL);
	}
	else{
		printf("This is parent in Q2, waiting.\n");
		wait(NULL);
		printf("Child complete.\n");
	}
}

