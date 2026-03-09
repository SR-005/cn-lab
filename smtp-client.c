#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock;
    struct sockaddr_in server;

    char hello[100],sender[100],reciever[100],body[200];

    //default socket creation
    sock=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(sock,(struct sockaddr *)&server,sizeof(server));    //connect the socket with server

    //send hello packet with server
    printf("Enter Hello: ");
    fgets(hello,100,stdin);
    send(sock,hello,100,0);

    //send senders mail to server
    printf("Enter Senders Mail: ");
    fgets(sender,100,stdin);
    send(sock,sender,100,0);

    //send recievers mail to server
    printf("Enter Recievers Mail: ");
    fgets(reciever,100,stdin);
    send(sock,reciever,100,0);

    //send content to server
    printf("Enter Content: ");
    fgets(body,200,stdin);
    send(sock,body,200,0);

    close(sock);
    return 0;
}