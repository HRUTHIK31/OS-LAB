#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#define MAX 50
int main()
{
	int fd1[2], fd2[2];
	pid_t pid;
	char str[MAX], substr[MAX], readstr[MAX];
	int start,end;
	printf("Enter the string : ");
	gets(str);
	if(pipe(fd1)==-1) {
		fprintf(stderr, "Pipe 1 failed");
		return 1;
	}
	if(pipe(fd2)==-1) {
		fprintf(stderr, "Pipe 2 failed");
		return 1;
	}
	pid = fork();
	if(pid==-1)
	{
		printf("Fork failed");
		return 1;
	}
	if(pid>0)
	{
		close(fd1[0]);
		close(fd2[1]);
		
		write(fd1[1], str, strlen(str)+1);	
		read(fd2[0], readstr, MAX);
		
		if(strlen(readstr)!=1)
			printf("\nPARENT BLOCK: Substring received (from child) --> %s\n",readstr);
	}
	else
	{
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0], readstr, MAX);
		printf("\nCHILD BLOCK: String received (from parent) --> %s\n",readstr);
		printf("\nEnter the start and end index of the substring : ");
		scanf("%d %d",&start,&end);
		if(start>=0 && start<strlen(readstr) && end>=0 && end<strlen(readstr))
		{
			int j=0;
			for(int i=start; i<=end; i++)
				substr[j++] = str[i];
			printf("\nIn child : Substring generated is %s\n",substr);
			write(fd2[1], substr, strlen(substr)+1);
		}
		else {
			printf("Index out of range, exiting\n");
			exit(1);	
	}
	return 0;
	}
}	
