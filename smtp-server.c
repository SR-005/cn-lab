#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int serversocket,cssocket;
    struct sockaddr_in server,client;
    int length=sizeof(client);

    char hello[100],sender[100],reciever[100],body[200];
    
    //default socket creation
    serversocket=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=INADDR_ANY;

    //bind the socket as server and set it to listen mode
    bind(serversocket,(struct sockaddr *)&server,sizeof(server));  
    listen(serversocket,3);

    //accept incoming request and create new client-server socket
    cssocket=accept(serversocket,(struct sockaddr *)&client, &length);

    //recieve all the contents
    recv(cssocket,hello,100,0);
    recv(cssocket,sender,100,0);
    recv(cssocket,reciever,100,0);
    recv(cssocket,body,200,0);

    //print all the contents
    printf("\nSMTP Mail Received\n");
    printf("Sender: %s",sender);
    printf("Receiver: %s",reciever);
    printf("Message: %s\n",body);

    close(serversocket);

    return 0;
}