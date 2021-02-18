#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
int start, end, i, temp1, temp2, remainder, n = 0,k;
int fd[2];
if(pipe(fd)==-1)
{
printf("error in the pipe\n");
exit(1);
}
int result[700];
for(k=0;k<=700;k++)
{
result[k]=0;
}

printf("Enter start value and end value : ");
scanf("%d %d", &start, &end);

pid_t pid;
pid=fork();
if(pid>0)
{
for(i = start ; i <= end; ++i)
{
temp2 = i;
temp1 = i;
while (temp1 != 0)
{
temp1 /= 10;
++n;
}
while (temp2 != 0)
{
remainder = temp2 % 10;
result[i] += pow(remainder, n);
temp2 /= 10;
}
n=0;
}
close(fd[0]);
int b[]={1,2,3,4,5};
write(fd[1],&result,sizeof(result));
close(fd[1]);
}

if(pid==0)
{
 int a[700];
 close(fd[1]);
 read(fd[0],&a,sizeof(a));
 close(fd[0]);
 printf("\nArmstrong Number between %d and %d are:\n",start,end);
 for(int y=start;y<=end;y++)
 {
 if(a[y]==y)
 printf("%d\n",y);
 }
}
printf("\n");
}
