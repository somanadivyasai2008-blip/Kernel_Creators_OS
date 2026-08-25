#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main()
{
    char buffer[100];
    int index;
    char ch;
    struct termios oldt, newt;

    while (1)
    {
        printf("myshell> ");
        fflush(stdout);

        index = 0;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        while (1)
        {
            ch = getchar();

            if (ch == '\n')
            {
                buffer[index] = '\0';
                break;
            }

            if (ch == 127 && index > 0)
            {
                index--;
                printf("\b \b");
                fflush(stdout);
            }
            else if (index < 99)
            {
                buffer[index++] = ch;
                putchar(ch);
                fflush(stdout);
            }
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        printf("\n");

        if (index == 4 &&
            buffer[0] == 'e' &&
            buffer[1] == 'x' &&
            buffer[2] == 'i' &&
            buffer[3] == 't')
        {
            printf("Shell exiting...\n");
            break;
        }

        printf("You entered: %s\n", buffer);
    }

    return 0;
}
