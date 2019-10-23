//IPC_msgq_rcv.c

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE  128

int ispalin(char str[]) 
{ 
    int lo = 0; 
    int hi= strlen(str) - 1; 
  
    while (hi > lo) 
    { 
        if (str[lo++] != str[hi--]) 
        { 
            printf("%sBhak", str); 
            return -1; 
        } 
    } 
 return 1; 
} 
void die(char *s)
{
  perror(s);
  exit(1);
}

typedef struct msgbuf
{
    long    mtype;
    char    mtext[MAXSIZE];
} ;


main()
{
    int msqid;
    key_t key;
    struct msgbuf rcvbuffer;

    key = 1234;

    if ((msqid = msgget(key, 0666)) < 0)
      die("msgget()");


     //Receive an answer of message type 1.
    if (msgrcv(msqid, &rcvbuffer, MAXSIZE, 1, 0) < 0)
      die("msgrcv");

    if(ispalin(rcvbuffer.mtext)==1)
         printf("%s Is a pal", rcvbuffer.mtext);

    printf("%s\n", rcvbuffer.mtext);
    exit(0);
}
