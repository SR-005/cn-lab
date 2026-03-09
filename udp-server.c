#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {

    int sock;
    struct sockaddr_in server, client;
    socklen_t len;

    int a[2][2], b[2][2], result[2][2];

    // Create UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // Server configuration
    server.sin_family = AF_INET;
    server.sin_port = htons(8090);
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to port
    bind(sock, (struct sockaddr*)&server, sizeof(server));

    len = sizeof(client);

    // Receive first matrix
    recvfrom(sock, a, sizeof(a), 0, (struct sockaddr*)&client, &len);

    // Receive second matrix
    recvfrom(sock, b, sizeof(b), 0, (struct sockaddr*)&client, &len);

    // Matrix addition
    printf("Matrix Addition Result (Server Side):\n");

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            result[i][j] = a[i][j] + b[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Send result back to client
    sendto(sock, result, sizeof(result), 0, (struct sockaddr*)&client, len);

    close(sock);

    return 0;
}