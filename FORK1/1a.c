# include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main ()
{
pid_t pid; // this is to use the pid data type – relevant headers above
pid = fork();
if (pid == 0)
execl("/bin/ls", "ls", NULL); // child image is now ls command
else
{
wait (NULL); // parent waits for the child to complete execution.
printf("Parent Process gets over the control \n");
printf ("Parent Had been waited for Child to Complete process\n");
}
}
