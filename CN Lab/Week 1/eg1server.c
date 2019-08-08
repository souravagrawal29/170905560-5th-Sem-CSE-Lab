#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#define PORT 8080
int main(){

	int sockfd,clilen,client_sockfd,msglen;
	struct sockaddr_in seraddr,cliaddr;
	//Creation of an unnamed socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		printf("Socket Creation failed...\n");
		exit(0);
	}
	else 
		printf("Socket successfully created...\n");

	//Naming the socket and defining the interface
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(PORT);
	seraddr.sin_addr.s_addr = inet_addr("172.16.57.97");

	if(bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))==-1){
		printf("Socket bind failed...\n");
		exit(0);
	}
	else 
		printf("Socket bound successfully...\n");

	if(listen(sockfd,5)==-1){
		printf("Server Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening...\n");

	while(1){
		char buff[256];
		clilen = sizeof(cliaddr);
		client_sockfd = accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
		if(client_sockfd<0){
			printf("Server accept failed...\n");
			exit(0);
		}
		msglen=read(client_sockfd,buff,sizeof(buff));
		printf("Message from client: %s\n",buff);
		msglen=write(client_sockfd,buff,sizeof(buff));
	}
}