#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<pthread.h>
#include <sys/wait.h> 
#include<sys/types.h>
int a[100],n;
void *mean(void *param);
void *median(void *param);
void *mode(void *param);
void sort(int b[],int k)
{
 int temp;
 for(int i=0;i<k-1;i++)
 {
   for(int j=0;j<k-i-1;j++)
   {
    if(b[j]>b[j+1])
    {
      temp=b[j];
      b[j]=b[j+1];
      b[j+1]=temp;
    }
   }
  }
}
int main()
{
 printf("\nEnter the number of elements in an array : ");
 scanf("%d",&n);
 printf("\nEnter the elements of array : ");
 for(int i=0;i<n;i++)
   scanf("%d",&a[i]);
 sort(a,n);
 pthread_t tid[3];
 pthread_attr_t attr;
 pthread_attr_init(&attr);
 pthread_create(&tid[0],&attr,mean,NULL);
 pthread_create(&tid[1],&attr,median,NULL); 
 pthread_create(&tid[2],&attr,mode,NULL);
 for(int i=0;i<3;i++)
    pthread_join(tid[i],NULL);
}
void *mean(void *param)
{
  float sum=0;
  float m;
  for(int i=0;i<n;i++)
     sum=sum+a[i];
  m=sum/n;
  printf("\nMean of the elements is : %0.2f\n",m);
}
void *median(void *param)
{
  int m,p;
  if(n%2==0)
  {
    m=n/2;
    p=m-1;
    float median ;
    float k=a[m]+a[p];
    median = k/2;
    printf("\nMedian of the elements is : %0.2f\n",median);
  }
  else
  {
    m=n/2;
    printf("\nMedian of the elements is : %d\n",a[m]);
  }
}
void *mode(void *param)
{
 printf("\nmode among the elements is : ",pthread_self());
 int count[50]={0},freq[100]={0},largest=0,i,c[n],k,j=0;
 for(i=0;i<n;i++)
 {
     int k,f=0;
     for(k=0;k<j;k++)
     {
        if(c[k]==a[i])
            f=1;
     }
     if(f==0)
     {
         c[j]=a[i];
         j++;
     }
  }
  for(i=0;i<j;i++)
  {
    for(k=0;k<n;k++)
     {
       if(a[k] == c[i])
          freq[i]++;
     }
  }
  largest=freq[0];
  for(i=1;i<j;i++)
  {
    if(largest<freq[i])
       largest=freq[i];
  }
  for(i=0;i<j;i++)
  {
     if(freq[i]==largest)
        printf("%d ",c[i]);
  }
 printf("\n");
}
