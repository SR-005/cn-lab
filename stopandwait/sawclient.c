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

    int i, n, r;
    char buffer[1024];

    printf("Enter Total Number of Frames to Send: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        snprintf(buffer,sizeof(buffer), "%d", i);
        send(clientsocket,buffer,strlen(buffer),0);

        //wait for Ack
        memset(buffer,0,sizeof(buffer));
        r=read(clientsocket,buffer,sizeof(buffer));
        if(r>0)
            printf("Client got the thing: %s\n",buffer);
    }

    close(clientsocket);

}