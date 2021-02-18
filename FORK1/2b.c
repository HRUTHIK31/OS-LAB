#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
 int i,j,k;
  int n=10;
  int sum1=0;
  int sum2=0;
  pid_t pid;
  pid=fork();
  if(pid==0)
  {
 	printf("Child:-\n");
	for(i=2; i<=n; i+=2)
	{
    	/* Add current even number to sum */
    	sum1 += i;
	}
	printf("sum(even)=%d",sum1);
	printf("\n");
  }
  if(pid>0)
  {
   printf("parent:-\n");
   for(j=1; j<=n; j+=2)
	{
    	/* Add current odd number to sum */
    	sum2 += j;
}
	printf("sum(odd)=%d",sum2);
	printf("\n");
  }
  return 0;
 }
