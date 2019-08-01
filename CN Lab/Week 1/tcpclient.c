#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define port 10200
int main(){
	struct sockaddr_in cliaddr;
	int sockfd
	//Creation of Socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		printf("Socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created...\n");

	cliaddr.sin_family = AF_INET;
	cliaddr.sin_port = htons(port);
	cliaddr.sin_addr.s_addr = inet_addr("172.16.57.49");

	if(connect())
}