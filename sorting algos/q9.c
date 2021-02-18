#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<pthread.h>
#include <sys/wait.h> 
#include<sys/types.h>
int n;
void *fib(void *param);
int main()
{
  printf("Enter the number of elements in fibnocci series to be printed: ");
  scanf("%d",&n);
  pthread_t tid[n];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  printf("fibanocci series :\n");
  for(int i=0;i<n;i++)
  {
     pthread_create(&tid[i],&attr,fib,i);
     pthread_join(tid[i],NULL);
  }
  printf("\n");
}
void *fib(void *param)
{
  long long int fib = (long long int) param; 
  fib = (pow((1 + sqrt(5)), fib) -pow((1 - sqrt(5)), fib)) /  (pow(2, fib) * sqrt(5)); 
  printf("%d  ",fib);
  pthread_exit(0);           
}
