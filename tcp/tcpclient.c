#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main()
{
    int clientsocket;
    struct sockaddr_in server;
    
    clientsocket=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(clientsocket,(struct sockaddr *)&server, sizeof(server));
    
    char string[20];
    printf("Enter the String: ");
    scanf("%s",string);
    printf("\nOriginal: %s",string);

    send(clientsocket,string,strlen(string),0);
    recv(clientsocket,string,strlen(string),0);

    printf("\nReverse: %s",string);
}