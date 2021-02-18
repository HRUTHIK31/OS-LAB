#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
typedef struct Merge_sort
{
	int left;
	int right;
}M;
void Merge();  
void *Mergesort(void * Par); 
int arr[100];
int main()
{
	M *A=(M*)malloc(sizeof(M));
	int size,i;
	printf("Enter the size of the array:\n" );
	scanf("%d",&size);
	printf("Enter the array elements:\n" );
	for (i = 0; i < size; ++i)
	{
		scanf("%d",&arr[i]);
	}
	A->left=0,A->right=size-1;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,Mergesort,(void *)A); 
	pthread_join(tid,NULL); 
	printf("Sorted Array:\n" );
	for (i = 0; i < size; ++i)
	{
		printf("%d ",arr[i]);
	}
	return(0);
}
	
void Merge(int left , int m , int right)
{
	int i, j, k; 
    int n1 = m - left + 1; 
    int n2 =  right - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void *Mergesort(void * Par)
{
	M * A= (M*) Par;
	int i;

	M *As=(M*)malloc(sizeof(M));
	if(A->left<A->right)
	{
	int m=A->left+ (A->right-A->left)/2;	
	 pthread_t tid[2];
         pthread_attr_t attr;
         pthread_attr_init(&attr); 
         As->left=A->left,As->right=m;
		 M *As1=(M*)malloc(sizeof(M));
		 
		 As1->left = m+1;  As1->right = A->right;
         pthread_create(&tid[0],&attr,Mergesort,(void *)As);
         pthread_create(&tid[1],&attr,Mergesort,(void *)As1);
         pthread_join(tid[0],NULL);
         pthread_join(tid[1],NULL);

		Merge(As->left,m,A->right);
	}
	free(As);
}
