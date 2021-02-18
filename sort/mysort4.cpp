#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
template <class T>
int compare(T * a,T * b)
{
  T k=*a-*b;
  return k;
}
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
template <class T>
void sort(T a[],int m,int opt)
{
  T temp;
  int j,i;
  for(i=0;i<m;i++)
  {
   for(j=0;j<m-i-1;j++)
   {
	if(opt==0)
	{
 	if((compare(&a[j],&a[j+1]))>0)
 	{
  	temp=a[j];
  	a[j]=a[j+1];
  	a[j+1]=temp;
 	}
	}
	else if(opt==1)
	{
 	if((compare(&a[j],&a[j+1]))<0)
 	{
  	temp=a[j];
  	a[j]=a[j+1];
  	a[j+1]=temp;
 	}
	}
   }
  }
  printf("Sorted Array Elements:\t");
  for(j=0;j<m;j++)
 	cout<<a[j]<<" ";
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
	printf("Invalid details provided\n");
	exit(1);
  }
  if(opt>2)
  {
	printf("Invalid sort is provided in details\n");
	exit(1);
  }
  if(type=='i')
  {
	int a[n],i;
	if((argc-n)<4)
   	printf("Less number of arguments are given\n");
	else if((argc-n)>4)
   	printf("More number of arguments are given\n");
   else
   {
	for(i=0;i<n;i++)
	{
  	if(isdigit(argv[4+i][0])==0)
  	{
    	printf("Input is not integer..pls check!!!");
    	exit(1);
  	}
  	a[i]=atoi(argv[4+i]);
	}
	if(opt==1)
   	sort<int>(a,n,opt);
	if(opt==0)
   	sort<int>(a,n,opt);
	}
  }
  else if(type=='f')
  {
	float a[n];
	int i;
	if((argc-n)<4)
   	printf("Less number of arguments are given\n");
	else if((argc-n)>4)
   	printf("More number of arguments are given\n");
   else
   {
	for(i=0;i<n;i++)
	{
  	if(isfloat(argv[4+i])==0)
  	{
    	printf("Input is not of float type..pls check!!!");
    	exit(1);
  	}
  	a[i]=atof(argv[4+i]);
	}
	if(opt==1)
   	sort<float>(a,n,opt);
	if(opt==0)
   	sort<float>(a,n,opt);
	}
  }
  else if(type=='c')
  {
	char a[n];
	int i;
	if((argc-n)<4)
   	printf("Less number of arguments are given\n");
	else if((argc-n)>4)
   	printf("More number of arguments are given\n");
   else
   {
	for(i=0;i<n;i++)
	{
  	a[i]=argv[4+i][0];
  	if(isalpha(a[i])==0)
  	{
    	printf("Input is not character...pls check");
    	exit(1);
  	}
	}
	if(opt==1)
   	sort<char>(a,n,opt);
	if(opt==0)
   	sort<char>(a,n,opt);
	}
  }
  else
  {
	printf("Invalid type is declared\n");
	exit(1);
  }
}
