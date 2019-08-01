#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 10200
int main(){
	int sockfd, client_sockfd,clilen;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	//Creation of an unnamed socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		printf("Socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created...\n");

	// Naming the socket
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(PORT);
	seraddr.sin_addr.s_addr=inet_addr("172.16.57.49");

	if(bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))==-1){
		printf("Socket bind failed ...\n");
		exit(0);
	}
	else{
		printf("Socket successfully bound... \n");
	}

	if(listen(sockfd,5)!=0){
		printf("Listen failed ...\n");
		exit(0);
	}
	else 
		printf("Server listening ...\n");

	while(1){
		char buff[256];
		printf("Server waiting..\n");
		clilen = sizeof(cliaddr);
		client_sockfd = accept(sockfd,(struct sockaddr*)&cliaddr, &clilen);
		if(client_sockfd <0){
			printf("Server accept failed...\n");
			exit(0);
		}
		int message_len;
		message_len = read(client_sockfd, buff,sizeof(buff));
		printf("Message from Client %s\n",buff);
		printf("Enter message for client\n");
		scanf("%s",buff);
		if(strcmp(buff,"exit")==0){
			printf("Server exit ...\n");
			break;
		}
		message_len = write(client_sockfd,buff,sizeof(buff));
	}
	return 0;

}