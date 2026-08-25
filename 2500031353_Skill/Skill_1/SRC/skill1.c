#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    printf("Skill-1: Process Demonstration\n");
    printf("Parent PID: %d\n", getpid());

    pid = fork();

    if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());
        execlp("ls", "ls", NULL);
    }
    else
    {
        wait(NULL);
        printf("Parent: Child completed\n");
    }

    return 0;
}
