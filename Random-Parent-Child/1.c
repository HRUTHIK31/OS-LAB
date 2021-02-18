#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
void reverse(char str[], int n)
{
	char temp;
	for(int i=0; i<=n/2 ;i++)
	{
		temp = str[i];
		str[i] = str[n-i];
		str[n-i]=temp;
	}
}
int main()
{
	int fd1[2],fd2[2];
	char writestr[20],readstr[20];
	printf("Enter the string :- ");
	gets(writestr);
	pid_t pid;
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
		write(fd1[1], writestr, strlen(writestr)+1);
		read(fd2[0], readstr, sizeof(readstr));
		printf("\nPARENT BLOCK : String after reversing(from child) --> %s\n",readstr);
	}
	else {
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0],readstr, sizeof(readstr));
		printf("\nCHILD BLOCK : String to be reversed(from parent) --> %s \n",readstr);
		reverse(readstr,strlen(readstr)-1);
		write(fd2[1], readstr, strlen((readstr))+1);
		printf("\nCHILD BLOCK : String after reversing --> %s \n",readstr);	
	}	
	return 0;
}
