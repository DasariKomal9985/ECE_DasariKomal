
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void)
{
    int sock;
    struct sockaddr_in addr;
    char message[] = "Hello from client!";

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1)
    {
        perror("socket");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (connect(sock, (struct sockaddr *)&addr,
                sizeof(addr)) == -1)
    {
        perror("connect");
        close(sock);
        return 1;
    }

    if (send(sock, message, strlen(message), 0) == -1)
        perror("send");
    else
        printf("Message sent successfully!\n");

    close(sock);

    return 0;
}
