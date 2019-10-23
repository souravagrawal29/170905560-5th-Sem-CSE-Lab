#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
int main(){
	DIR *p;
	char dir[10];
	struct dirent *d;
	printf("Enter the directory name\n");
	scanf("%s",dir);
	p=opendir(dir);
	if(!p){
		printf("Cannot find directory\n");
		exit(-1);
	}
	while(d=readdir(p)){
		if(strcmp(d->d_name,".")==0||strcmp(d->d_name,"..")==0)
			continue;
		printf("%s\n",d->d_name);
	}
	return 0;

}