#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
 int i;
 int n=5;
 pid_t childpid,wpid;
 int status=0;
 for(int id=0;i<n;i++)
 {
 if((childpid=fork())==0)
 {
 printf("child block %d\n",i);
 exit(0);
 }
 }
 while((wpid=wait(&status))>0);
 printf("parent block\n");
 return 0;
 }
 
