#include<stdio.h>
#include<unistd.h>
int main()
{
int pid;
pid=fork();
if(pid<0)
printf("fork failed\n");
else if(pid==0)
printf("child block\n");
else if(pid>0)
printf("parent block\n");
return 0;
}
