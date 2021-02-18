#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
 pid_t childpid;
 childpid=fork();
 if(childpid==0)
 {
 printf("child block\n");
 exit(0);
 }
 else if(childpid<0)
 {
 printf("Error\n");
 }
 else
 {
 int returnstatus;
 waitpid(childpid,&returnstatus,0);
 if(returnstatus==0)
 printf("child process terminated normally\n");
 if(returnstatus==1)
 printf("child process terminated with an error");
 }
 return 0;
 }
