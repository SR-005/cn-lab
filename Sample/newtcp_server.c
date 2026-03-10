#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
    int serversocket, cssocket;
    struct sockaddr_in server, client; 
    char string[20];

    serversocket = socket(AF_INET, SOCKET_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8086);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(serversocket, (struct sockaddr*)&server, sizeof(server));
    listen(serversocket, 3);
    printf("Server waiting for connection");

    int addresslen = sizeof(client);
    cssocket = accept(serversocket (struct sockaddr*)&client, &addresslen);
    recv(cssocket, string, sizeof(string), 0);

    int i, j, temp;
    int length = strlen(string);
    for(i = 0, j = length - 1;i < j; i++, j++){
        temp = string[i];
        string[i] = string [j];
        string[j] = temp;
    }
    send(cssocket, string, sizeof(string), 0);
    close(serversocket);
    close(cssocket);
}