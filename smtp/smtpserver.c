#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main()
{
    int serversocket, scsocket;
    struct sockaddr_in server,client;

    serversocket=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=INADDR_ANY;

    bind(serversocket, (struct sockaddr *)&server, sizeof(server));
    listen(serversocket, 3);
    socklen_t addresslength=sizeof(client);
    scsocket=accept(serversocket, (struct sockaddr *)&client, &addresslength);

    char helo[20],sender[20],recipient[20],body[20];
    recv(scsocket,helo,sizeof(helo),0);
    printf("Helo Packet Successfully Transmitted. It Says: '%s'",helo);

    recv(scsocket,sender,sizeof(sender),0);
    printf("Sender: %s",sender);
    recv(scsocket,recipient,sizeof(recipient),0);
    printf("Recipient: %s",recipient);
    recv(scsocket,body,sizeof(body),0);
    printf("Body: %s",body);

    close(serversocket);
    close(scsocket);
}
