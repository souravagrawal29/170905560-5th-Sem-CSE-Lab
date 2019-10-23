#include<string.h>
#include<stdio.h>
#define noofchars 256

int flag=0,op=0;

int max(int a,int b){
	return (a>b)?a:b;
}

void badTable(char str[],int m,int bad[noofchars]){
	int i;
	for(i=0;i<noofchars;i++)
		bad[i]=-1;

	for(i=0;i<m;i++)
		bad[(int)str[i]]=i;
}

void search(char text[],char patt[]){

	int m=strlen(patt);
	int n=strlen(text);

	int bad[noofchars];

	badTable(patt,m,bad);

	int s=0;
	while(s<=(n-m)){
		int j=m-1;
		while(j>=0 && ++op && patt[j]==text[s+j])
			j--;
		if(j<0){
			printf("Pattern found at %d with %d operations\n",s+1,op);
			flag=1;
			s+=(s+m<n)?m-bad[text[s+m]]:1;
		}
		else
			s+=max(1,j-bad[text[s+j]]);
	}
}

int main(){
	char text[100],patt[100];
	printf("enter text\n");
	gets(text);
	printf("enter pattern\n");
	gets(patt);
	search(text,patt);
	if(flag==0){
		printf("pattern not found\n");
	}
	printf("Total character comparisons %d\n",op);
}


//"ABAAABCD"; 
//"ABC"