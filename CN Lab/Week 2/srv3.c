#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10202
int main(){
	int newsockfd;
	newsockfd = createServerSocket();
	
}
void performServerTask(int newsockfd){
	int buf[256];
	read(newsockfd, buf, sizeof(buf));
	//buf[0] should store length of int array to be sorted
	QSort(buf, 1, buf[0]);
	buf[200] = getpid();
	write(newsockfd, buf, sizeof(buf));
	close(newsockfd);

}
void QSort(int arr[], int l, int r){
	if(l<r){
		int p = partition(arr, l, r);
		QSort(arr, l, p-1);
		QSort(arr, p+1, r);
	}

}
int partition(int arr[], int l, int r){
	int p = arr[l];
	int i = l;
	int j = r;
	while(i<j){
		while(arr[i]<=p&&i<r) i++;
		while(arr[j]>p&&j>=l) j--;
		swap(&arr[i], &arr[j]);
	}
	swap(&arr[i], &arr[j]);
	swap(&arr[l], &arr[j]);
	return j;
}
void swap(int *a, int*b){
	int c= *a;
	*a = *b;
	*b = c;
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

	