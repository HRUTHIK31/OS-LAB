#include<stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
#include<stdlib.h>
#include <sys/wait.h>
int main()
{
int pid;
printf("before fork\n");
pid=fork();
if(pid==0)
{
  printf("child has started:%d\n",getpid());
  printf("parent of this child:%d\n",getppid());
  printf("child prints\n");
  sleep(10);
  printf("child prints\n");
}
else
{
  printf("parent has started:%d\n",getpid());
  printf("parent of the parent process:%d\n",getpid());
}
return 0;
}
