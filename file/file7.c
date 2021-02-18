#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int pid_t,pid0,pid1,pid2,pid3;
pid0=fork();//1-->2
if(pid0==0)
{
pid2=fork();//2-->4
if(pid2==0)
{
fork();//4-->8
}
else if(pid2>0)
{
pid3=fork();//2-->5
if(pid3==0)
fork();//5-->9
else if(pid3>0)
fork();//2-->6
}
}
else if(pid0>0)
{
pid1=fork();//1-->3
if(pid1==0)
fork();//3-->7
}
printf("OS\n");
return 0;
}
