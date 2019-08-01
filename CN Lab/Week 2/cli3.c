#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define PORTNO 10202
int main(){
	
	int sockfd;
	sockfd = createClientSocket();
	performClientTask(sockfd);
}

	 void performClientTask(int sockfd){
		printf("Enter array size\n");
		int buf[256];
		scanf("%d", &buf[0]);
		for(int i = 1; i<=buf[0];i++)
			scanf("%d", &buf[i]);
		write(sockfd, buf, sizeof(buf));
		printf("Processed array:\n");
		read(sockfd, buf, sizeof(buf));
		for(int i = 1; i<buf[0]+1;i++){
			printf("%d\t",buf[i]);
		}
		printf("Process id:\n");
		for(int i = 0; i<5;i++)
			printf("%d",buf[200+i]);
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
	


	