#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

    int sock;
    struct sockaddr_in server;
    socklen_t len;

    int a[2][2], b[2][2], result[2][2];

    // Create UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8090);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    len = sizeof(server);

    // Input first matrix
    printf("Enter first matrix:\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&a[i][j]);

    // Send first matrix
    sendto(sock, a, sizeof(a), 0, (struct sockaddr*)&server, len);

    // Input second matrix
    printf("Enter second matrix:\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&b[i][j]);

    // Send second matrix
    sendto(sock, b, sizeof(b), 0, (struct sockaddr*)&server, len);

    // Receive result
    recvfrom(sock, result, sizeof(result), 0, (struct sockaddr*)&server, &len);

    printf("Result matrix:\n");

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    close(sock);

    return 0;
}