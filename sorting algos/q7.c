#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<time.h>
#include<pthread.h>
#include <sys/wait.h> 
#include<sys/types.h>
void *estimate(void *param);
int interval,circle_points = 0, square_points = 0,n,s;
double pi; 
int main() 
{  
  int i; 
  printf("Enter the interval and number of threads:");
  scanf("%d%d",&interval,&n); 
  srand(time(NULL));
  s = (interval*interval)/n; 
  pthread_t tid[n];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  for(i=0;i<n;i++) 
      pthread_create(&tid[i],&attr,estimate,NULL);  
  for(i=0;i<n;i++) 
      pthread_join(tid[i],NULL);
  pi=(double)(4*circle_points)/square_points; 
  printf("final => %lf\n",pi);  
  return 0; 
} 
void *estimate(void *param)
{
 for(int i=0;i<s;i++)
 {
   double rand_x, rand_y, origin_dist;
   rand_x=(double)(rand() % (interval + 1)) / interval; 
   rand_y=(double)(rand() % (interval + 1)) / interval; 
   origin_dist = rand_x * rand_x + rand_y * rand_y;
   if(origin_dist<=1)		  
      circle_points++; 
   square_points++; 
 }
 pthread_exit(0); 
}
