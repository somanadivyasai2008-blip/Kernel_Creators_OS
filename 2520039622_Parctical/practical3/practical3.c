#include <unistd.h>
#include <stdio.h>

int main()
{
    int pid;

    pid = fork();

    if(pid == 0)
    {
        printf("Child process\n");
        printf("PID: %d\n", getpid());

        sleep(10);

        printf("Child process completed\n");
    }
    else
    {
        printf("Parent process\n");
        printf("PID: %d\n", getpid());
        sleep(10);
    }

    return 0;
}





