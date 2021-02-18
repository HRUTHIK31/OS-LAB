#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
int main()
{pid_t child_pid,wpid;
int status=0,n=2;
printf("Parent code before child process start\n");
for(int id=0;id<n;id++)
{
if((child_pid=fork())==0)
{
printf("Child code starts\n");
exit(0);
}
}
while((wpid=wait(&status))>0)
{
printf("Parent waits for all the child process to complete\n");
}
printf("Parent code after all child process end\n");
}
