#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>
void *runner(void *param);
int n;
int main(int argc, int *argv[])
{
	if(argc!=2)
	{
		printf("Invalid number of commands passed, please pass only 2\nExiting...\n");
		exit(0);
	}
	n = atoi(argv[1]);
	printf("Prime numbers upto %d\n \n",n);
	pthread_t tid[n-2];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=2; i<=n; i++)
	{
		pthread_create(&tid[i-2], &attr, runner, i);
	}
	for(int i=2; i<=n; i++)
	{
		pthread_join(tid[i-2], NULL);
	}
	printf("\n");
	return 0;
}
void *runner(void *param)
{
	int x = (int)param;
	int flag = 0;
	for(int i=2; i<= sqrt(x); i++)
	{
		if(x%i==0)
		{
			flag = 1;
			break;
		}
	}
	if(flag==0)
		printf("%d  ",x);
	pthread_exit(0);
}
