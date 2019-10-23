    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    int main(int argc, char const *argv[]){
     
            int fp1 = open("f1.txt",O_RDWR | O_CREAT | O_APPEND);
        	int fp2 = open("f2.txt",O_RDWR | O_CREAT | O_APPEND);
        	char str1[80],str2[80];
        	//int fcp;
        	//fcp=creat("hello.txt",RD_WR);
        	read(fp1,str1,sizeof(str1));
        	printf("Read:");
        	puts(str1);
        	int i;
        	int k=0;
        	for(i=0;i<strlen(str1);i++)
        	{
             if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u'||str1[i]=='A')
             	 str2[k++]=str1[i];
        	     // write(fp2,str1,strlen(str1));
        	//else continue;
             }
             write(fp2,str2,strlen(str2));
             puts(str2);
            close(fp1);
            close(fp2);
        	return 0;
    }