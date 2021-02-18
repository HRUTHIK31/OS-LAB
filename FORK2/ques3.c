#include <sys/wait.h>
#include <unistd.h>
#include<stdio.h>
#include <stdlib.h>
int main()
{
   long int count = 0;
   int n = 1000000;
   int i;
   for (i = 0; i < n; i++)
   {
      if (fork() == 0)
          exit(1);
   }
   for (i = 0; i < n; i++)
   {
       int pid;
       wait(&pid);
       pid /= 255;
       count += pid;
   }
   printf("Maximum fork count: %ld\n", count);
   return 0;
}
