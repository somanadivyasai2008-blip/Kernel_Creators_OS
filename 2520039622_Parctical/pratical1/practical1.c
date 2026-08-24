#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char command[100];
    pid_t pid;

    printf("Enter Linux command: ");
    scanf("%99s", command);

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());
        printf("Executing command: %s\n", command);

        execlp(command, command, (char *)NULL);

        perror("exec failed");
        exit(1);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        wait(NULL);

        printf("Child process completed.\n");
    }

    return 0;
}