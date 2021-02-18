#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

//void multiply(int a[][20],int b[][20],int m1,int n1,int m2,int n2);
//void print(int a[][20],int m,int n);

int main()
{
    int m1,n1,m2,n2;
    printf("Enter order of first matrix(m1xn1): ");
    scanf("%d%d",&m1,&n1);
    printf("Enter order of second matrix(m2xn2): ");
    scanf("%d%d",&m2,&n2);
    if(m2 == n1 || m1 == n2)
    {
        int a[m1][n1],b[m2][n2],i,j;
        printf("Enter values for first array: ");
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
                scanf("%d",&a[i][j]);
        }
        printf("Enter values for second array: ");
        for(i=0;i<m2;i++)
        {
            for(j=0;j<n2;j++)
                scanf("%d",&b[i][j]);
        }
        if(n1 == m2)
        {
            int p[m1][n2];

            for(i=0;i<m1;i++)
                for(j=0;j<n2;j++)
                    p[i][j] = 0;

            for(i=0;i<m1;i++)
            {
                for(j=0;j<n2;j++)
                {
                    pid_t pid;
                    pid = vfork();
                    if(pid == 0)
                    {
                        int k;
                        for(k=0;k<n1;k++)
                            p[i][j] += a[i][k]*b[k][j];
                    exit(0);
                    }
                    else if(pid > 0)
                    {
                        wait(NULL);
                    }
                }
            }
            printf("\nProduct:\n");
            for(i=0;i<m1;i++)
            {
                for(j=0;j<n2;j++)
                    printf("%d\t",p[i][j]);
                printf("\n");
            }
            printf("\n");
        }
        else
        {
            int p[m2][n1];

            for(i=0;i<m2;i++)
                for(j=0;j<n1;j++)
                    p[i][j] = 0;

            for(i=0;i<m2;i++)
            {
                for(j=0;j<n1;j++)
                {
                    pid_t pid;
                    pid = vfork();
                    if(pid == 0)
                    {
                        int k;
                        for(k=0;k<n2;k++)
                            p[i][j] += b[i][k]*a[k][j];
                    exit(0);
                    }
                    else if(pid > 0)
                    {
                        wait(NULL);
                    }
                }
            }
            printf("\nProduct:\n");
            for(i=0;i<m2;i++)
            {
                for(j=0;j<n1;j++)
                    printf("%d\t",p[i][j]);
                printf("\n");
            }
            printf("\n");
        }
    }
    else
    {
        printf("These two matrices cannot be multiplied\n");
        return 0;
    }

    return 0;
}

/*void multiply(int a[][20],int b[][20],int m1,int n1,int m2,int n2)
{
    int i,j,p[m1][n2];

    for(i=0;i<m1;i++)
        for(j=0;j<n2;j++)
            p[i][j] = 0;
    
    for(i=0;i<m1;i++)
           {
                for(j=0;j<n1;j++)
                    printf("%d ",a[i][j]);
                printf("\n");
           }

            for(i=0;i<m2;i++)
           {
                for(j=0;j<n2;j++)
                    printf("%d ",b[i][j]);
                printf("\n");
           }

    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            pid_t pid;
            pid = vfork();
            if(pid == 0)
            {
                int k;
                for(k=0;k<n1;k++)
                    p[i][j] += a[i][k]*b[k][j];
                exit(0);
            }
            else if(pid > 0)
            {
                wait(NULL);
            }
        }
    }
    printf("Product:\n\n");
    print(p,m1,n2);
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
            printf("%d ",p[i][j]);
        printf("\n");
    }
    printf("\n");
    
}

void print(int a[][20],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}*/