#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 5	
#define BUFFERSIZE 2 

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BUFFERSIZE];
pthread_mutex_t mutex;
void *producer(void *param)
{
	int item;
	for (int i = 0; i < MAX; i++)
	{
		item = rand() % 100; 
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = item;
		printf("Producer produces Item %d at position : %d\n", buffer[in], in);
		in = (in + 1) % BUFFERSIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}
void *consumer(void *param)
{
	for (int i = 0; i < MAX; i++)
	{
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[out];
		printf("Consumer consumes Item %d at position : %d\n",  item, out);
		out = (out + 1) % BUFFERSIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

int main()
{
	pthread_t tid[2];
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, BUFFERSIZE);
	sem_init(&full, 0, 0);
    pthread_create(&tid[0], NULL, producer, NULL);
	pthread_create(&tid[1], NULL, consumer, NULL);
	pthread_join(tid[0], NULL);	
	pthread_join(tid[1], NULL);	
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	return 0;
}
