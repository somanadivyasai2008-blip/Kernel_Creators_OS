#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
char message[100];
mkfifo("client_fifo", 0666);
mkfifo("server_fifo", 0666);
printf("Server waiting for message...\n");
int fd1 = open("client_fifo", O_RDONLY);
int fd2 = open("server_fifo", O_WRONLY);
read(fd1, message, sizeof(message));
printf("Client says: %s\n", message);
char response[] = "Message received by server";
write(fd2, response, strlen(response) + 1);
close(fd1);
close(fd2);
return 0;
}
