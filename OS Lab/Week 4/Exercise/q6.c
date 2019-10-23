#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>
void main(){
	int fd = open("file1.txt", O_RDWR);
	char buf[80];
	read(fd, buf, sizeof(buf));
	int i;
	for(i = 0;buf[i]!='\0';i++);

	close(fd);
	fd = open("file2.txt", O_RDWR);
	write(fd, buf, i);
	close(fd);
}
