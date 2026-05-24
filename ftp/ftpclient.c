#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<fcntl.h>

int main()
{
    int clientsocket;
    struct sockaddr_in server;

    clientsocket=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(clientsocket, (struct sockaddr *)&server, sizeof(server));

    char filename[50],data[100];
    printf("Enter the Filename: ");
    scanf("%s",filename);

    send(clientsocket,filename,strlen(filename),0);
    recv(clientsocket,data,sizeof(data),0);

    printf("Conents: %s",data);
    close(clientsocket);
}