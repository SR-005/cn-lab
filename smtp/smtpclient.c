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

    connect(clientsocket, (struct sockaddr *)&server, sizeof(server));

    char helo[50],sender[50],recipient[50],body[50];
    
    printf("Enter the Helo Packet: ");
    fgets(helo,20,stdin);
    send(clientsocket,helo,strlen(helo),0);
    printf("Helo Packet Send!!");

    printf("\nEnter the sender Packet: ");
    fgets(sender,20,stdin);

    printf("\nEnter the recipient Packet: ");
    fgets(recipient,20,stdin);

    printf("\nEnter the body Packet: ");
    fgets(body,20,stdin);

    send(clientsocket,sender,strlen(sender),0);
    send(clientsocket,recipient,strlen(recipient),0);
    send(clientsocket,body,strlen(body),0);
}
