#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
int main()
{
    char text[100];
    printf("Enter text: ");
    gets(&text);
    int len = strlen(text);
    char c[50];
    int count[50],freq[100]={0};
    int i,j=0;
    for(i=0;i<50;i++)
        count[i] = 0;
    for(i=0;i<len;i++)
    {
        int k,f=0;
        for(k=0;k<j;k++)
        {
            if(c[k] == text[i])
                f = 1;
        }
        if(f == 0)
        {
            c[j] = text[i];
            j++;
        }
    }
    for(i=0;i<j;i++)
    {
        pid_t pid;
        pid = vfork();
        if(pid == 0)
        {
            int k;
            for(k=0;k<len;k++)
            {
                if(text[k] == c[i])
                    freq[i]++;
            }
            exit(0);
        }
    }
    printf("\nCHARACTERS\tCODE\n-----------------------\n");
    for(i=0;i<j;i++)
       printf("%c\t\t%d\n",c[i],freq[i]);
    return 0;
}
