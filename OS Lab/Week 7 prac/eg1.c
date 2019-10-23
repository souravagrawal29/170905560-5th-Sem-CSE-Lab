#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    int n;
    int fd[2];
    char *data="hello..this is sample data";
    char buff[1025];
    pipe(fd);
    write(fd[1],data,strlen(data));
    if((n=read(fd[0],buff,sizeof(buff)))>=0){
        buff[n]='\0';
        printf("Read %d bytes from the pipe : \"%s\"\n",n,buff);
    }
    else 
        perror("read");
    exit(0);

}