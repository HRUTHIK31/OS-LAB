#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>#include<stdlib.h>
#include <sys/wait.h>
int main()
{
pid_t pid;
pid=fork();
char *cmd[]={"ls","-l",NULL};
if(pid==0)
execv("/bin/ls",cmd);
else
{
wait(NULL);
printf("Parents process gets the control\n");
printf("Parent has waited child to complete\n");
}
}
