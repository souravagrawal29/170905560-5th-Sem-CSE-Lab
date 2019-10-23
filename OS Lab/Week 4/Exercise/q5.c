#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>
void main(){
	int fd = creat("text1.txt", O_RDWR);
	char buf[80]="Hello World \nThis is line 1\nLine 2";
	int bytes = write(fd, buf, sizeof(buf));
	printf("Number of bytes written: %d\n",bytes);
}