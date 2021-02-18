#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
pid_t pid;
int n,i;
printf("Enter total elements in array :\n ");
scanf("%d",&n);
int a[n];
printf("Enter array elements : \n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
pid=fork();
int temp,j,m=n/2,k,p=0;
if(pid<0)
exit(0);
else if(pid==0)
{
for(i=0;i<m;i++)
{
for(j=0;j<m-i-1;j++)
{
if(a[j]>a[j+1]){
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("\nChild: first-half sorted in ascending order \n");
for(j=0;j<m;j++)
printf("%d ",a[j]);
printf("\n");
}
else
{
wait(NULL);
for(i=m;i<n;i++)
{
for(k=m;k<n-p-1;k++)
{
if(a[k]<a[k+1])
{
temp=a[k];
a[k]=a[k+1];
a[k+1]=temp;
}
}
p=p+1;
}
printf("\nParent: Sorted second-half in descending order \n");
for(j=m;j<n;j++)
printf("%d ",a[j]);
printf("\n");
}
}
