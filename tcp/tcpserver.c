#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main()
{
    int serversocket, scsocket;
    struct sockaddr_in server, client;

    serversocket=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=INADDR_ANY;

    bind(serversocket, (struct sockaddr *)&server, sizeof(server));
    listen(serversocket,3);
    socklen_t addresslength = sizeof(client);
    scsocket=accept(serversocket, (struct sockaddr *)&client, &addresslenght);

    //program starts from here
    char string[20];
    recv(scsocket,string,sizeof(string),0);
    int i,j,temp;
    int length=strlen(string);

    for(i=0,j=length-1;i<j;i++,j--)
    {
        temp=string[i];
        string[i]=string[j];
        string[j]=temp;
    }

    send(scsocket,string,sizeof(string),0);
    close(scsocket);
    close(serversocket);
}