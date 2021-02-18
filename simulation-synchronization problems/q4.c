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
	char primary[100];
	char secondary[100];
} dict;

dict dictionary[20];
void *writer(void *wno)
{   
    sem_wait(&wrt);
    flag=1;
    printf("Enter word:\t");
    scanf("%s",search);
    int i;
    for(i=0;i<20;i++)//duplicates
    {
    	if(strcmp(dictionary[i].word,search)==0)
    	{
    		printf("WORD ALREADY EXISTS\n");
    		flag=0;
    		break;
    	}
    }
    if(flag==1)
    {
		strcpy(dictionary[k].word,search);
		printf("Enter primary meaning:\t");
		scanf("%s",dictionary[k].primary);
		printf("Enter secondary meaning:\t");
		scanf("%s",dictionary[k].secondary);
		printf("%s is added to the dictionary.\n\n",dictionary[k].word);
		k++;
	}
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
    int i,flag=0,low=0,high=19;
    printf("Enter word to search:\t");
    scanf("%s",search);
 	while(low<=high)
 	{
 		int mid=(low+high)/2;
 		if (strcmp(search,dictionary[mid].word)==0)
 		{
 			printf("Primary Meaning: %s\n", dictionary[mid].primary);
 			printf("Secondary Meaning: %s\n", dictionary[mid].secondary);
        	exit(0);
 		}
 		else if(strcmp(search,dictionary[mid].word)>0)
 		{
 			high=high;
 			low=mid+1;
 		}
 		else
 		{
 			low=low;
 			high=mid-1;
 		}
 	}
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
