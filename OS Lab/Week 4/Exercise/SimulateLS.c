#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(){
	char dirname[20];
	DIR *p;
	struct dirent *d;
	scanf("%s",dirname);
	p = opendir(dirname);
	if(p==NULL){
		printf("No such directory exists.\n");
		exit(1);
	}
	while(d=readdir(p)){
		if((d->d_name)[0]=='.')
			continue;
		printf("%s\n",d->d_name);
	}
}
