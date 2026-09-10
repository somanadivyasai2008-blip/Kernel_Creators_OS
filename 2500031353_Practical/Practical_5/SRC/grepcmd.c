#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    pid_t p1, p2;

    pipe(pipefd);

    // First child: ls -l
    p1 = fork();

    if (p1 == 0)
    {
        close(pipefd[0]);

        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        execl("/bin/ls", "ls", "-l", NULL);
    }

    // Second child: grep ".c"
    p2 = fork();

    if (p2 == 0)
    {
        close(pipefd[1]);

        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        execl("/bin/grep", "grep", ".c", NULL);
    }

    // Parent
    close(pipefd[0]);
    close(pipefd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
