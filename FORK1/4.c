#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
  int x=0,y=1,nextterm=x+y;
  int i,j,fact;
  int low,flag;
  int n;
  printf("enter number:");
  scanf("%d",&n);
  pid_t pid ;
  pid=fork();
  if(pid == 0)
  {
 printf("Child prints prime numbers:\n ");

   // iteration until low is not equal to high
   while (low < n) {
  	flag = 0;
  	// ignore numbers less than 2
  	if (low <= 1) {
     	++low;
     	continue;
  	}
  	// if low is a non-prime number, flag will be 1
  	for (i = 2; i <= low / 2; ++i) {

     	if (low % i == 0) {
        	flag = 1;
        	break;
     	}
  	}
  	if (flag == 0)
     	printf("%d ", low);
  	// to check prime for the next number
  	// increase low by 1
  	++low;
   }
   printf("\n");
   
   
  }
  if (pid > 0)
  {
  printf("parent is generating fibinacci series:\n");
  while (n>0)
  {
  nextterm=x+y;
  printf("%d ",nextterm);
  x=y;
  y=nextterm;
  n--;
  }
  printf("\n");
  }
  return 0;
  }
