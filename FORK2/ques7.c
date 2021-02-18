#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
    int n,i,j,x=0;
    printf("Enter order of matrix: ");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter elements of matrix: ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    
    int sum=0,s=0;
    for(i=0;i<n;i++)
        sum += a[i][i];
    for(i=0,j=n-1;i<n;i++,j--)
        s += a[i][j];

    if(s != sum)
    {
        printf("The given matrix is not a magic square.\n");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        pid_t pid;
        pid = vfork();
        if(pid == 0)
        {
            int k,s1=0,s2=0;
            for(k=0;k<n;k++)
            {
                s1 += a[i][k];
                s2 += a[k][i];
            }
            if(s1 != sum && s2 != sum)
                x = 1;
            exit(0);
        }
        else if(pid > 0)
        {
            wait(NULL);
        }
    }

    if(x == 1)
        printf("The given matrix is not a magic square.\n");
    else
        printf("The given matrix is a magic square.\n");

    return 0;
}