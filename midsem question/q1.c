#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int c;
int *charCount;
FILE *file;

FILE *openFile(char *filename) // open a file in read mode and return the pointer
{
    FILE *file;
    file = fopen(filename, "r");

    if (!file)
    {
        printf("Error!\n");
        return NULL;
    }

    return file;
}

void *runner(void *param)
{

    int i = *((int *)param);
    while ((c = tolower(fgetc(file))) != EOF)
    {
        if (i == 26 && (c < 97 || c > 122))
            charCount[c]++; // Count other char
        else if (c == i + 97)
            charCount[i + 97] += 1; // Count letters
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]) //command line arguments
{


    if (argc != 2)
    {
        printf("Syntax: ./a.out <filename>\n");
        return 1;
    }

    char *filename = argv[1];

    if ((file = openFile(filename)) == NULL)
        return 1;

    pthread_t tid;
    pthread_attr_t attr;

    charCount = mmap(NULL, 128 * sizeof(*charCount), PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    for (int i = 0; i < 27; i++)
    {

        file = openFile(filename);
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        rewind(file);
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, arg);
        pthread_join(tid, NULL);
    }
    for (int i = 97; i < 123; i++)
    {
        printf("|   %c    |  %0d ", i, charCount[i]);
        printf("\n");
    }

    if (fclose(file) != 0)
    {
        printf("Error closing file!\n");
        return 1;
    }

    return 0;
}
