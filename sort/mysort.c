#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
 
#define BUFF_SIZE 1024
 
int main(int argc, char* argv[])
{

        if(  argv[1] == "-help")
        {
        
            printf("Enter numbers to sort\n");
            exit(EXIT_FAILURE);
	}
	
	int n,ch,a[50],x,dup,y,f;
	char *buff[BUFF_SIZE];
	f=0;
	
	n=atoi(argv[1]);
	ch=atoi(argv[2]);
	
	for(x=0;x<n;x++)
	{
	
	   a[x]=atoi(argv[x+3]);
	   f++;
	   
	 }
	 
	 
	 
	 if(n!=f)
	 {
	 printf("No. of numbers are less or more");
	 }
	 
	 
	else
	{
	
	 if(ch == 1)
	 {
	   
	   for(x=0;x<n;x++)
	   {
	    for(y=0;y< n-x-1;y++)
	     {
	     if(a[y]>a[y+1])
	     {
	       dup=a[y];
	       a[y]=a[y+1];
	       a[y+1]=dup;
	       
	       }
	       }
	 }
	 for(x=0;x<n;x++)
	 {
	 
	   printf("%d\t",a[x]);
	  
	   
	   }
	 }
	 
	 
	   
	 else if(ch == 0)
	 {
	   
	   for(x=0;x<n;x++)
	   {
	    for(y=0;y< n-x-1;y++)
	     {
	     if(a[y]<a[y+1])
	     {
	       dup=a[y];
	       a[y]=a[y+1];
	       a[y+1]=dup;
	       
	       }
	       }
	 }
	 for(x=0;x<n;x++)
	 {
	 
	   printf("%d\t",a[x]);
	  
	   
	   }
	 }
	 
	 else if(ch<0 || ch>1)
	 {
	 printf("Enter correct mode for sorting(ONLY 0 and 1 are accepted)");
	 }
	 }
	 
	 

	printf("\n");
	
	
	
	
	
	
	exit(EXIT_SUCCESS);
}
	
	
	
	
	

