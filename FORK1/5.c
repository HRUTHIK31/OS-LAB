#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
int arr[10],n;
int main(void)
{
  int pid;
  int i,j;
  printf("\nEnter the no of numbers:");
  scanf("%d",&n);
  printf("\nEnter the Number:");
  for(i=0;i<n;i++)
  	scanf("%d",&arr[i]);
  pid=fork();
  if(pid==0)
  {
   int i,j,k,temp;
  for(i=0;i<n;i++)
  {
    	for(j=i+1;j<n;j++)
    	{
            	if(arr[i]<arr[j])
            	{
                    	temp=arr[i];
                    	arr[i]=arr[j];
                    	arr[j]=temp;
            	}
    	}
   }
	printf("\nDescending order sort within child are:\n");
    	for(i=0;i<n;i++)
        	printf("%d\t",arr[i]);
    	printf("\n");
	}  
   else
   {
  int i,j,k,temp;
  for(i=0;i<n;i++)
  {
	for(j=i+1;j<n;j++)
	{
    	if(arr[i]>arr[j])
    	{
        	temp=arr[i];
        	arr[i]=arr[j];
        	arr[j]=temp;  
    	}
	}
   }
 	printf("\nAscending order within the parent are:\n");
     	for(i=0;i<n;i++)
            	printf("%d\t",arr[i]);
}
	return 0;
}
