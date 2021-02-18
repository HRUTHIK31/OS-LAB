#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
   int n;
   printf("Enter n value\n");
   scanf("%d",&n);
  pid_t pid;
  pid=fork();
  int i,j;
  if(pid==0)
  {
 	printf("Child:-\n");
 	for(i=0;i<=n;i++)
 	{
    	if(i%2==0)
    	printf("%d\t",i);
   	 
 	}
	printf("\n\n");
  }
  if(pid>0)
  {
 
   printf("parent:-\n");
 	for(j=0;j<n;j++)
 	{
    	if(j%2!=0)
    	printf("%d\t",j);
   	 
 	}
 	printf("\n\n");
  }
  return 0; 
 }
