#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fd1[2], fd2[2];
	pid_t pid;
	char str1[20], str2[20],readstr[20];
	printf("Enter string 1 : ");
	gets(str1);
	printf("Enter string 2 : ");
	gets(str2);
	if(pipe(fd1)==-1)
	{
		fprintf(stderr, "Pipe 1 failed");
		return 1;
	}
	if(pipe(fd2)==-1)
	{
		fprintf(stderr, "Pipe 2 failed");
		return 1;
	}
	pid = fork();
	if(pid==-1)
	{
		printf("Fork failed");
		return 1;
	}
	else if(pid>0)
	{	
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0], readstr, sizeof(readstr));
		printf("\nPARENT BLOCK: Concatenating the two strings '%s' and '%s'(received from child)\n", str1, readstr);
		strcat(str1, readstr);
		write(fd2[1], str1, strlen(str1)+1);
	}
	else {
		close(fd1[0]);
		close(fd2[1]);
		write(fd1[1], str2, strlen(str2)+1);
		read(fd2[0], readstr, sizeof(readstr));
		printf("\nCHILD BLOCK: received concatenated string from parent : %s\n",readstr);
	}
}
