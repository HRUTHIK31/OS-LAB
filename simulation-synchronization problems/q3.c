#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
sem_t wrt; 
char search[100];
pthread_mutex_t mutex;
int numreader = 0;
int k=0;
int flag;

typedef struct 
{
	char word[100];
	char primary[1000];
	char secondary[100];
} dict;

dict dictionary[20];
void *writer(void *wno)
{   
    sem_wait(&wrt);
    printf("Enter the word:\t");
    scanf("%s",search);
    int i;
	strcpy(dictionary[k].word,search);
	printf("Enter meaning:\t");
	scanf("%s",dictionary[k].primary);
	printf("Enter secondary meaning:\t");
	scanf("%s",dictionary[k].secondary);
	printf("%s is added to the dictionary.\n\n",dictionary[k].word);
	k++;
    sem_post(&wrt);
}
void *reader(void *rno)
{   
    pthread_mutex_lock(&mutex);
    numreader++;
    if(numreader == 1) {
        sem_wait(&wrt); 
    }
    pthread_mutex_unlock(&mutex);
    int i;
    printf("Enter word to search:\t");
    scanf("%s",search);
 	for(i=0;i<20;i++)
 	{
 		if (strcmp(search,dictionary[i].word)==0)
 		{
 			flag=1;
 			printf("Primary Meaning:\t%s\n", dictionary[i].primary);
 			printf("Secondary Meaning:\t%s\n", dictionary[i].secondary);
        	exit(0);
 		}	
 	}
 	if(flag==0)
 		printf("Given word is not found\n");
    pthread_mutex_lock(&mutex);
    numreader--;
    if(numreader == 0) 
    {
        sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}
int main()
{   
    pthread_t read,write[20];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);
    for(int i = 0; i < 20; i++) 
        pthread_create(&write[i], NULL, (void *)writer, NULL);
    sleep(1);
   	pthread_create(&read, NULL, (void *)reader, NULL);  
    pthread_join(read, NULL);    
    for(int i = 0; i < 20; i++) 
        pthread_join(write[i], NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0; 
}
