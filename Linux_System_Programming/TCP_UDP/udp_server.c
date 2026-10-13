
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void)
{
    int sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024];

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock == -1) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8081);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&server_addr,
             sizeof(server_addr)) == -1) {
        perror("bind");
        close(sock);
        return 1;
    }

    printf("UDP server waiting on port 8081...\n");

    ssize_t n = recvfrom(sock, buffer, sizeof(buffer) - 1,
                         0, (struct sockaddr *)&client_addr,
                         &client_len);

    if (n == -1) {
        perror("recvfrom");
        close(sock);
        return 1;
    }

    buffer[n] = '\0';
    printf("Client: %s\n", buffer);

    const char *reply = "Hello from UDP server!";

    if (sendto(sock, reply, strlen(reply), 0,
               (struct sockaddr *)&client_addr,
               client_len) == -1) {
        perror("sendto");
    }

    close(sock);
    return 0;
}

