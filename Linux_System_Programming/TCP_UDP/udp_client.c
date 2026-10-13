
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void)
{
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock == -1) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8081);

    if (inet_pton(AF_INET, "127.0.0.1",
                  &server_addr.sin_addr) != 1) {
        fprintf(stderr, "Invalid server address\n");
        close(sock);
        return 1;
    }

    const char *message = "Hello from UDP client!";

    if (sendto(sock, message, strlen(message), 0,
               (struct sockaddr *)&server_addr,
               sizeof(server_addr)) == -1) {
        perror("sendto");
        close(sock);
        return 1;
    }

    struct sockaddr_in reply_addr;
    socklen_t reply_len = sizeof(reply_addr);

    ssize_t n = recvfrom(sock, buffer, sizeof(buffer) - 1,
                         0, (struct sockaddr *)&reply_addr,
                         &reply_len);

    if (n > 0) {
        buffer[n] = '\0';
        printf("Server: %s\n", buffer);
    } else if (n == -1) {
        perror("recvfrom");
    }

    close(sock);
    return 0;
}

