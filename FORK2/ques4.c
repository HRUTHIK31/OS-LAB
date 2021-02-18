#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

int main()
{
    pid_t pid;
    char history[20][100] = {},command[100];
    int i=0;

    printf("@: ");
    gets(&command);
    strcpy(history[i],command);
        i++;

    while(strcmp(command,"exit") != 0)
    {
        //strcpy(history[i],command);
        //i++;
        pid = vfork();
        if(pid == 0)
        {
            if(command[0] == '!')
            {
                char num[5];
                int j=0;
                for(j=1;command[j]!='\0';j++)
                    num[j-1] = command[j];
                int n = atoi(num);
                if(i<n)
                    n = i;
                printf("Last %d commands: \n",n);
                for(j=n-1;j>=0;j--)
                    printf("%d. %s\n",n-j,history[i-j-1]);
            }
            else
            {
                int j=0,k=0;
                char com[10],ch[50];
                while(command[j] != ' ' && command[j] != '\0')
                {
                    com[j] = command[j];
                    j++;
                }
                j++;
                while(command[j] != '\0')
                {
                    ch[k] = command[j];
                    k++;
                    j++;
                }
                if(ch[0] =='\0')
                    execlp(com,com,NULL);
                else
                    execlp(com,com,ch,NULL);
            }
            exit(0);
        }
        if(pid > 0)
        {
            wait(NULL);
            printf("@: ");
            gets(&command);
            strcpy(history[i],command);
            i++;
        }
    }

    return 0;
}