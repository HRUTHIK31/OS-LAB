#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
int main()
{
  pid_t pid;
  int n,mid,x;
  printf("Enter number of elements:\t");
  scanf("%d",&n);
  mid=(0+n)/2;
  int a[n];
  printf("\nEnter array elements:\n");
  for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
  printf("Enter element to be searched :\t ");
  scanf("%d",&x);
  pid=fork();
  if(pid<0)
  {
   printf(" forking error\n");
   exit(1);
  }
  else if(pid>0)
  {
	int beg=0,mid1,end=mid,temp,flag=0,lc,rc,m=0;
	for(int i=beg;i<end-1;i++)
	{
  	for(int j=beg;j<end-m-1;j++)
  	{
   	if(a[j]>a[j+1])
   	{
     	temp=a[j];
     	a[j]=a[j+1];
     	a[j+1]=temp;
   	}
  	}
  	m++;
	}
   printf("\nSorted elements in parent block are: ");
   for(int i=beg;i<end;i++)
  	printf("%d\t ",a[i]);
   printf("\n\n");
	mid1=(beg+end)/2;
	while(beg<=end)
	{
   	if(a[mid1]==x)
   	{
     	flag=1;
     	printf("--->Number %d is found in parent block at position %d\n",x,mid1+1);
     	lc=mid1-1;
     	rc=mid1+1;
     	for(int i=lc;i>=0;i--)
     	{
        	if(a[i]<a[mid1])
          	break;
        	if(a[i]==a[mid1])
           	printf("--->Number %d is found in parent block at position %d\n",a[mid1],i+1);
     	}
     	for(int i=rc;i<=n/2;i++)
     	{
        	if(a[i]>a[mid1])
          	break;
        	if(a[i]==a[mid1])
           	printf("--->Number %d is found in parent block at position %d\n",a[mid1],i+1);
     	}
     	printf("\n");
     	break;
   	}
   	else if(a[mid1]>x)
      	end=mid1-1;
   	else
      	beg=mid1+1;
 	mid1=(beg+end)/2;
	}
   if(flag==0)
  	printf("--->Number %d is not found in parent block\n\n",x);
  }
  else
  {
	int beg=mid,mid2,end=n,temp,m=0,flag=0,lc,rc;
   for(int i=beg;i<end-1;i++)
	{
  	for(int j=beg;j<end-m-1;j++)
  	{
   	if(a[j]>a[j+1])
   	{
     	temp=a[j];
     	a[j]=a[j+1];
     	a[j+1]=temp;
   	}
  	}
  	m++;
	}
   printf("Sorted Elements in child block are : ");
   for(int i=beg;i<end;i++)
  	printf("%d ",a[i]);
   printf("\n\n");
	mid2=(beg+end)/2;
	while(beg<=end)
	{
   	if(a[mid2]==x)
   	{
     	flag=1;
     	printf("--->Number %d is found in child block at position %d\n",x,mid2+1);
    	lc=mid2-1;
    	rc=mid2+1;
    	for(int i=lc;i>=(n/2);i--)
     	{
        	if(a[i]<a[mid2])
          	break;
        	if(a[i]==a[mid2])
           	printf("--->Number %d is found in child block at position %d\n",a[mid2],i+1);
     	}
     	for(int i=rc;i<n;i++)
     	{
        	if(a[i]>a[mid2])
          	break;
        	if(a[i]==a[mid2])
           	printf("--->Number %d is found in child block at position %d\n",a[mid2],i+1);
     	}
     	printf("\n");
     	break;
   	}
   	else if(a[mid2]>x)
      	end=mid2-1;
   	else
      	beg=mid2+1;
 	mid2=(beg+end)/2;
	}
	if(flag==0)
  	printf("--->Number %d is not found in child block\n",x);
  }
  return 0;
}
