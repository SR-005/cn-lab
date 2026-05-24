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
    listen(serversocket,3);
    socklen_t addresslength=sizeof(client);
    scsocket=accept(serversocket, (struct sockaddr *)&client, &addresslength);

    int size=5;
    int drop=2;
    int frame,i;
    char buffer[1024];
    for(i=0;i<size;i++)
    {
        memset(buffer,0,sizeof(buffer));
        read(scsocket,buffer,sizeof(buffer));

        sscanf(buffer,"%d",&frame);

        if(frame==drop)
            printf("Dropping the Frame %d\n",frame);
        else
            printf("Frame Recieved and Buffered: %d\n",frame);
    }

    printf("Submittion for Re-Transmitting Frame Number %d\n",drop);
    sprintf(buffer,"NAK %d",drop);
    send(scsocket,buffer,strlen(buffer),0);

    memset(buffer,0,sizeof(buffer));
    read(scsocket,buffer,sizeof(buffer));
    sscanf(buffer,"%d",&frame);
    printf("Got the Retrasmitted Frame: %d\n",frame);

    close(serversocket);
    close(scsocket);
}