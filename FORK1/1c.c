          #include<stdio.h>
         #include <sys/types.h>
         #include <unistd.h>
         #include<stdlib.h>
          #include <sys/wait.h>
          int main()
           {
            pid_t pid;
            pid=fork();
             if(pid==0)
              execlp("ls","ls",NULL);
          else
           {
              wait(NULL);
             printf("Parents process gets the control\n");
             printf("Parent has waited child to complete\n");
            }
            }
