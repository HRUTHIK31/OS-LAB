#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
typedef struct Pars
{
	int low;
	int high;
}pars;

void * Quick_Sort(void * Par);
int partition ( int low, int high) ;
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int arr[100];

int main(int argc, char const *argv[])
{
	int n,i;
	printf("Enter the size of the array:\n" );
	scanf("%d",&n);
	printf("Enter the array elements:\n" );


	for (i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}

	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);

	pars * Ps=(pars *)malloc(sizeof(pars));
	Ps->low=0,Ps->high=n-1;

	pthread_create(&tid,&attr,Quick_Sort,(void*)Ps); 

	pthread_join(tid,NULL); 

	printf("sorted Array:\n" );
	for (i = 0; i < n; ++i)
	{
		printf("%d  ",arr[i]);
	}

	return 0;
}



void * Quick_Sort(void *Par)
{
                int i;
		pars * P=(pars * )Par;

		pars * Ps=(pars *)malloc(sizeof(pars));
		if(P->low<P->high)
		{
			pthread_t tid[2];
			pthread_attr_t attr;
                        pthread_attr_init(&attr);
			int pi=partition(P->low,P->high);
                        Ps->low=P->low,Ps->high=pi-1;
                        P->low=pi+1;

			pthread_create(&tid[0],&attr,Quick_Sort,(void*)Ps);
			pthread_create(&tid[1],&attr,Quick_Sort,(void*)P);
                        for (i = 0; i < 2; ++i)
			{
				pthread_join(tid[i],NULL);
			}

		}
		free(Ps);
}


int partition ( int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1),j;  
  
    for (j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

