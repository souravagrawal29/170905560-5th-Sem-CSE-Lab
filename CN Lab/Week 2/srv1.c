#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10200
int main(){
	int newsockfd;
	newsockfd = createServerSocket();
	
}
void performServerTask(int newsockfd){
	char buf[256];
	read(newsockfd, buf, sizeof(buf));
	printf("Client says:%s\n",buf);
	write(newsockfd, buf, sizeof(buf));
	close(newsockfd);
}
void createServerSocket(){//returns client socket
	int sockfd, newsockfd, portno, clilen, n = 1;
	struct sockaddr_in srvadd, cliadd;
	int i, value;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	srvadd.sin_family = AF_INET;
	srvadd.sin_addr.s_addr = inet_addr("127.0.0.1");
	srvadd.sin_port = htons(PORTNO);

	bind(sockfd, (struct sockaddr *)&srvadd, sizeof(srvadd));
	
	listen(sockfd, 5);

	while(1){
		char buf[256];
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliadd, &clilen);
		
		if(fork()==0){//is child now
			performServerTask(newsockfd);
		}		
		else
			close(newsockfd);
	}
	return ;
}

	