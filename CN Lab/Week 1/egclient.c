#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#define PORT 8080
int main(){

	struct sockaddr_in seraddr;
	int sockfd
	//Creating a socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		printf("Socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created...\n");

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(PORT);
	seraddr.sin_addr.s_addr = inet_addr("172.16.57.97");

	if(connect(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))==-1){
		printf("Connection failed...\n");
		exit(0);
	}
	else 
		printf("Connected successfully..\n");

	while(1){
		char buff[256];
		memset(buff,0,sizeof(buff));
		printf("Enter message:\n");
		gets(buff);
		buff[strlen(buff)-1]='\0';
		msglen=write(sockfd,buff,sizeof(buff));
		msglen=read(sockfd,buff,sizeof(buff));
		printf("Message from Server:\n");
		puts(buff);
		if(strcmp(buff,"exit")==0){
			printf("Client Exit...\n");
			exit(0);
		}

	}
	

}