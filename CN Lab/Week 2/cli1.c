#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define PORTNO 10201
int main(){
	
	int sockfd;
	sockfd = createClientSocket();
	performClientTask(sockfd);
}

	 void performClientTask(int sockfd){
		char ch[256], buf[256];
		printf("\nEnter string\t");
		gets(ch);
		ch[strlen(ch)]='\0';
		write(sockfd, ch, strlen(ch));
		printf("String sent back from server is \n");
		int n = 1;
		while(n){
			n = read(sockfd, buf, sizeof(buf));
			puts(buf);
		}
	}

	 int createClientSocket(){
		int len, result, sockfd, n = 1;

		struct sockaddr_in address;
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = inet_addr("127.0.0.1");
		address.sin_port = htons(PORTNO);
		len = sizeof(address);
		result = connect(sockfd, (struct sockaddr *)&address, len);

		if(result==-1){
			perror("\nCLIENT ERROR");
			exit(1);
		}
		return sockfd;
	}
	


	