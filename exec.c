#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void main()
{
    pid_t p;
    p= fork();
    if(p<0)
    {
        printf("chilf creation failed\n");
        exit(EXIT_FAILURE);
    }
    if(p==0)
    {
        printf("the pid of the child process is %d\n",getpid());
        char *args[] = {"ls",NULL};
        execvp(args[0],args);
        printf("error\n");
    }
    if(p>0)
    {
        printf("the parent process id is %d\n",getpid());
        printf("the child process id is %d\n",p);
        wait(NULL);
    }
}