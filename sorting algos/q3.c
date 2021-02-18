#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<pthread.h>
#include <sys/wait.h> 
#include<sys/types.h>
int a[100],n,x;
void *halfsearch(void *param);
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
  printf("Enter the number of elements :");
  scanf("%d",&n);
  printf("Enter the elements : ");
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("Enter the element that has to be searched :");
  scanf("%d",&x);
  int l=1,s=2;
  pthread_t tid;
  pthread_t tid1;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_create(&tid,&attr,halfsearch,(int)l);
  pthread_create(&tid1,&attr,halfsearch,(int)s);
  pthread_join(tid,NULL); 
  pthread_join(tid1,NULL); 
}
void *halfsearch(void *param)
{
    int count=param;
    int beg1,end1,flag=0,mid1,lc,rc,m,p;
    if(count==1)
    {
      m=0;
      p=n/2;
    }
    else
    {
     m=(n/2)+1;
     p=n;
    }
    int k=p-m+1;
    int b[k];
    for(int i=0;i<k;i++)
      b[i]=a[m++];
    sort(b,k);
    beg1=0;
    end1=k;
    mid1=(beg1+end1)/2;
    while(beg1<=end1)
    {
       if(b[mid1]==x)
       {
         flag=1;
         printf("\n");
         printf("---> %d is found at position %d and thread id is %ld\n",x,mid1+1,pthread_self());
         lc=mid1-1;
         rc=mid1+1;
          printf("\n"); 
         for(int i=lc;i>=0;i--)
         {
            if(b[i]<b[mid1])
              break;
            if(b[i]==b[mid1])
           
               printf("---> %d is found at position %d and thread id is %ld\n",b[mid1],i+1,pthread_self());
         }
         for(int i=rc;i<=n/2;i++)
         {
            if(b[i]>b[mid1])
              break;
            if(b[i]==b[mid1])
               printf(">>> %d is found at position %d and thread id is %ld\n",b[mid1],i+1,pthread_self());
         }
         printf("\n");
         break;
       }
       else if(b[mid1]>x)
          end1=mid1-1;
       else
          beg1=mid1+1;
     mid1=(beg1+end1)/2;
    }
   if(flag==0)
      printf(">>> %d is not found in thread with thread id %ld\n",x,pthread_self());
   pthread_exit(0);
}
