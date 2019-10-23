#include<stdio.h>
#include<stdlib.h>

void search(int mat[][10],int fromR, int toR, int fromC,int toC,int key){
    int i=(toR-fromR)/2;
    int j=(toC-fromC)/2;
    if(mat[i][j]==key){
        printf("Element found at %d %d \n",i,j);
    }
    else{
        if(i!=toR || j!= fromC)
            search(mat,fromR,i,j,toC,key);
        if(mat[i][j]<key){
            if(i+1<=toR)
                search(mat,i+1,toR,fromC,toC,key);
        }
        else{
            if(j-1>=fromC)
                search(mat,fromr,toR,fromC,j-1,key);
        }
    }
}