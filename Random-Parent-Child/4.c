#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#define MAX 50
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
	char writestr[MAX],readstr[MAX], result[MAX];
	printf("Enter the string to be reversed : ");
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
		read(fd2[0], readstr, MAX);
		printf("\nPARENT BLOCK: String after reversing  (from child)  --> %s\n\nComparing both and sending back to child\n",readstr);
		/*if(strcmp(writestr,readstr)==0)
			printf("\nYES!, %s is palindrome\n",writestr);
		else
			printf("\nNO!, %s is not a palindrome\n",writestr);*/
		if(strcmp(writestr,readstr)==0)
			strcpy(result, "YES");
		else
			strcpy(result, "NO");
		write(fd1[1], result, strlen(writestr)+1);
	}
	else {
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0],readstr, MAX);
		printf("\nCHILD BLOCK : String to be reversed is (from parent)  %s \n",readstr);
		reverse(readstr,strlen(readstr)-1);
		write(fd2[1], readstr, strlen((readstr))+1);
		read(fd1[0],result, MAX);
		//printf("\n%s",result);
		if(strcmp("YES",result)==0)
			printf("\n%s, %s is palindrome\n",result,writestr);
		else if(strcmp("NO",result)==0)
			printf("\n%s!, %s is not a palindrome\n",result,writestr);
			
	}	
	return 0;
}
