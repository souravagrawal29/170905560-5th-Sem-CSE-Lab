#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>

struct packet{
	pid_t server_pid;
	char response[100];
};

int main(){

	int sockfd;
	struct packet pack;
	struct sockaddr_in seraddr;

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	if(sockfd<0){
		printf("Socket not created\n" );
		exit(0);
	}
	else
		printf("Socket created\n");

	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(9999);
	seraddr.sin_addr.s_addr=inet_addr("172.16.57.195");

	if(connect(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))==-1){
		printf("Connection failed\n");
		exit(0);
	}

	char ch;
	printf("Enter character\n");
	scanf("%c",&ch);
	int n=write(sockfd,&ch,sizeof(ch));
	n=read(sockfd,&pack,sizeof(struct packet));
	printf("Process id: %d\n",pack.server_pid);
	printf("Response: %s\n",pack.response);
}