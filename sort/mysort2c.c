#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


   int compare(int * a,int * b)
    {
       int p=*a-*b;
        return p;
    }


   void sort(int a[],int n,int opt)
    {
      int temp,y,x;
         for(x=0;x<n;x++)
            {
           for(y=0;y<n-x-1;y++)
            {
           if(opt==0)
              {
              if((compare(&a[y],&a[y+1]))<0)
              {
                 temp=a[y];
                 a[y]=a[y+1];
                 a[y+1]=temp;
                }
                }
             else if(opt==1)
                {
                 if((compare(&a[y],&a[y+1]))>0)
                  {
                   temp=a[y];
                       a[y]=a[y+1];
                     a[y+1]=temp;
                   }
                   }
              }
              }
  printf("Sorted Elements:\t");
  for(y=0;y<n;y++)
  {
     printf("%d ",a[y]);
     }
     printf("\n");
}

int main(int argc,char *argv[])
{
  int n,opt;
  opt=atoi(argv[2]);
  if(opt>1)
  {
    printf("\nInvalid option of sorting\n");
    exit(1);
  }
  if(argc<2)
  {
    printf("\nLess no. of arguments are given\n");
    exit(1);
  }
  else
  {
    n=atoi(argv[1]);
    int a[n],i;
    if((argc-n)<3)
       printf("Less no. of arguments are given\n");
    else if((argc-n)>3)
       printf("More no. of arguments are given\n");
   else
   {
    for(i=0;i<n;i++)
    {
      if(isdigit(argv[3+i][0])==0)
      {
        printf("Input is not integer\n");
        exit(1);
      }
      a[i]=atoi(argv[3+i]);
    }
    if(opt==1 || opt==0)
       sort(a,n,opt);
    }
  }
}
