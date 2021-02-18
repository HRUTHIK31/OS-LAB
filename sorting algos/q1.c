#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
void *runner(void *param);
int main(int argc, char *argv[])
{
	int a,b,value,sum=0,j=0;
	printf("Enter the Range:");
	scanf("%d %d",&a,&b);
	//a = atoi(argv[1]);
	//b = atoi(argv[2]);
	printf("\nArmstrong numbers between %d and %d are\n\n",a,b);
	pthread_t tid[b-a+1];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=a; i<=b; i++)			
		pthread_create(&tid[j++], &attr, runner, i);
	for(int i=0; i<=b-a; i++)
		pthread_join(tid[i], NULL);	
	printf("\n");	
	return 0;
}	
void *runner(void *param)
{
	int n,c=0,r,sum=0;
	int i = (int)param;
	n = i;
	while(n>0)
	{
		n=n/10;
		c++;
	}
	n=i;
	sum = 0;
	while(n>0)
	{
		r=n%10;
		sum+= pow(r,c);
		n=n/10;
	}
	if(sum==i)
		printf("%d\n",i);
	pthread_exit(0);
}
