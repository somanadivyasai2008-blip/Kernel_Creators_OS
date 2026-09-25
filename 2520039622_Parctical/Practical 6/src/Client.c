#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
char message[100];
char response[100];

printf("Enter message: ");
fgets(message, sizeof(message), stdin);

int fd1 = open("client_fifo", O_WRONLY);
int fd2 = open("server_fifo", O_RDONLY);

write(fd1, message, strlen(message) + 1);

read(fd2, response, sizeof(response));

printf("Server says: %s\n", response);

close(fd1);
close(fd2);

return 0;
}