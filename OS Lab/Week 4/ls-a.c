#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
	char dir[10];
	DIR *p;
	struct dirent *d;
	printf("Enter directory name\n");
	scanf("%s",dir);
	p=opendir(dir);
	if(!p){
		printf("Cannot find directory\n");
		exit(-1);
	}
	while(d=readdir(p)){
		printf("%s\t",d->d_name);
		printf("%c\n",d->d_type);
	}
	return 0;
}