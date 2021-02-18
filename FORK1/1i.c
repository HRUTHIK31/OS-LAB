#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
int main()
{
pid_t pid;
pid=fork();
char *cmd[]={"ls","-aF","/",0};
char *env[]={0};
if(pid==0)
execve("/bin/ls",cmd,env);
else
{
wait(NULL);
printf("Parents process gets the control\n");
printf("Parent has waited child to complete\n");
}
}
