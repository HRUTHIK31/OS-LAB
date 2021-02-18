#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int isfloat(char ch[])
{
	int flag=0,i=0,length;
	length=strlen(ch);
	while(ch[i++]!='\0')
	{
  	if(ch[i]=='.')
  	{
    	flag=1;
    	break;
  	}
	}
   return flag;
}
void ascsort(int a[],int m)
{
  int temp,j,i;
  for(i=0;i<m;i++)
  {
   for(j=0;j<m-i-1;j++)
   {
	if(a[j]>a[j+1])
	{
  	temp=a[j];
  	a[j]=a[j+1];
  	a[j+1]=temp;
	}
   }
  }
  printf("Sorted Array Elements:\t");
  for(j=0;j<m;j++)
 	printf("%d ",a[j]);
}
void ascsort(float a[],int m)
{
  int j,i;
   float temp;
  for(i=0;i<m;i++)
  {
   for(j=0;j<m-i-1;j++)
   {
	if(a[j]>a[j+1])
	{
  	temp=a[j];
  	a[j]=a[j+1];
  	a[j+1]=temp;
	}
   }
  }
  printf("Sorted Array values:\t");
  for(j=0;j<m;j++)
 	cout<<a[j]<<" ";
}
void ascsort(char a[],int m)
{
  int temp,j,i;
  for(i=0;i<m;i++)
  {
   for(j=0;j<m-i-1;j++)
   {
	if(a[j]>a[j+1])
	{
  	temp=a[j];
  	a[j]=a[j+1];
  	a[j+1]=temp;
	}
   }
  }
  printf("Sorted Array values:\t");
  for(j=0;j<m;j++)
 	printf("%c ",a[j]);
}
void dscsort(int a[],int m)
{
  int temp,j,i;
  for(i=0;i<m;i++)
  {
   for(j=0;j<m-i-1;j++)
   {
	if(a[j]<a[j+1])
	{
  	temp=a[j];
  	a[j]=a[j+1];
  	a[j+1]=temp;
	}
   }
  }
  printf("Sorted Array values:\t");
  for(j=0;j<m;j++)
 	printf("%d ",a[j]);
}
void dscsort(float a[],int m)
{
  int j,i;
  float temp;
  for(i=0;i<m;i++)
  {
   for(j=0;j<m-i-1;j++)
   {
	if(a[j]<a[j+1])
	{
  	temp=a[j];
  	a[j]=a[j+1];
  	a[j+1]=temp;
	}
   }
  }
  printf("Sorted Array values:\t");
  for(j=0;j<m;j++)
 	cout<<a[j]<<" ";
}
void dscsort(char a[],int m)
{
  int temp,j,i;
  for(i=0;i<m;i++)
  {
   for(j=0;j<m-i-1;j++)
   {
	if(a[j]<a[j+1])
	{
  	temp=a[j];
  	a[j]=a[j+1];
  	a[j+1]=temp;
	}
   }
  }
  printf("Sorted Array values:\t");
  for(j=0;j<m;j++)
 	printf("%c ",a[j]);
}
int main(int argc,char *argv[])
{
  int n,opt;
  char type;
  n=atoi(argv[1]);
  type=argv[2][0];
  opt=atoi(argv[3]);
  if(argc<3)
  {
	printf("Invalid details given\n");
	exit(1);
  }
  if(opt>2)
  {
	printf("Invalid sort in details\n");
	exit(1);
  }
  if(type=='i')
  {
	int a[n],i;
	if((argc-n)<4)
   	printf("Less arguments are given\n");
	else if((argc-n)>4)
   	printf("More arguments are given\n");
   else
   {
	for(i=0;i<n;i++)
	{
  	if(isdigit(argv[4+i][0])==0)
  	{
    	printf("plss check input is not charcter!!!");
    	exit(1);
  	}
  	a[i]=atoi(argv[4+i]);
	}
	if(opt==1)
   	ascsort(a,n);
	if(opt==0)
   	dscsort(a,n);
	}
  }
  else if(type=='f')
  {
	float a[n];
	int i;
	if((argc-n)<4)
   	printf("Less arguments are given\n");
	else if((argc-n)>4)
   	printf("More arguments are given\n");
   else
   {
	for(i=0;i<n;i++)
	{
  	if(isfloat(argv[4+i])==0)
  	{
    	printf("plss check input is not float type!!!");
    	exit(1);
  	}
  	a[i]=atof(argv[4+i]);
	}
	if(opt==1)
   	ascsort(a,n);
	if(opt==0)
   	dscsort(a,n);
	}
  }
  else if(type=='c')
  {
	char a[n];
	int i;
	if((argc-n)<4)
   	printf("Less arguments are given\n");
	else if((argc-n)>4)
   	printf("More arguments are given\n");
   else
   {
	for(i=0;i<n;i++)
	{
  	a[i]=argv[4+i][0];
  	if(isalpha(a[i])==0)
  	{
    	printf("plss check input is not character");
    	exit(1);
  	}
	}
	if(opt==1)
   	ascsort(a,n);
	if(opt==0)
   	dscsort(a,n);
	}
  }
  else
  {
	printf("Invalid type\n");
	exit(1);
  }
}
