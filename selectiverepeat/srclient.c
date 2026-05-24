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
    int size=5,i;
    char buffer[1024];
    for(i=0;i<size;i++)
    {
        sprintf(buffer,"%d",i);
        send(clientsocket,buffer,strlen(buffer),0);
        usleep(100000);
    }

    int frame;
    char type[10];
    memset(buffer,0,sizeof(buffer));
    read(clientsocket,buffer,sizeof(buffer));

    sscanf(buffer, "%s %d", type, &frame);
    if(strcmp(type,"NAK")==0)
    {
        printf("Got request for resending Frame %d\n",frame);
        sprintf(buffer,"%d",frame);
        send(clientsocket,buffer,strlen(buffer),0);
    }
    close(clientsocket);
}