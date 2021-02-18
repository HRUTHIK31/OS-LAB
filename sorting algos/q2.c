#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<pthread.h>
#include <sys/wait.h> 
#include<sys/types.h>
int n,a[100],b[100];
void *asc(void *param);
void *dsc(void *param);
int main()
{
  printf("Enter the number of elements :");
  scanf("%d",&n);
  printf("Enter the elements : ");
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  pthread_t tid;
  pthread_t tid1;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_create(&tid,&attr,asc,NULL);
  pthread_join(tid,NULL);
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  pthread_create(&tid1,&attr,dsc,NULL);
  pthread_join(tid1,NULL); 
 for(int i=0;i<n;i++)
   printf("%d ",a[i]);
 printf("\n");
}
void *asc(void *param)
{printf("\n");
  printf("thread 1:\n--------Ascending Order---------\n");
  int temp;
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
       if(a[j]>a[j+1])
       {
         temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;
       }
    }
  }
  pthread_exit(0);
}
void *dsc(void *param)
{
printf("\n");
  printf("thread 2:\n--------Descending Order--------\n");
  int temp1;
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
       if(a[j]<a[j+1])
       {
         temp1=a[j];
         a[j]=a[j+1];
         a[j+1]=temp1;
       }
    }
  }
  pthread_exit(0);
}
