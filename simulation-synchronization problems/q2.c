#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int item;
int flag[2];
int turn;
sem_t empty, full;
void lock_ini()
{
	flag[0] = 0;
	flag[1] = 0;
	turn = 0;
}
void lock(int index)
{
	flag[index] = 1;
	turn = 1 - index;
	while (flag[1 - index] == 1 && turn == 1 - index);
}

void unlock(int index)
{
	flag[index] = 0;
}

void *producer()
{
	int i;
	printf("\nPRODUCER THREAD ID: %ld\n", pthread_self()); 
	for (i = 1; i < 6; i++)
	{
		sem_wait(&empty);		
		lock(0);				//entry-section
		item = i;			    //critical section
		unlock(0);				//critical section
		sem_post(&full);		//exit section
		printf("Produced item: %d\n", item);
	}
}
void *consumer()
{
	int i, total = 0;
	printf("CONSUMER THREAD ID: %ld\n", pthread_self());
	for (i = 1; i < 6; i++)
	{
		sem_wait(&full);		
		lock(1);              //entry-section
		total = total + item; //critical section
		unlock(1);			  //critical section
		sem_post(&empty);     //exit section
		printf("Consumed item: %d\n", item);
	}
}
int main()
{
	pthread_t tid[2];
	lock_ini();
	sem_init(&empty, 0, 1);
	sem_init(&full, 0, 0);
	pthread_create(&tid[0], NULL, producer, NULL);
	pthread_create(&tid[1], NULL, consumer, NULL);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	printf("\n");
}
