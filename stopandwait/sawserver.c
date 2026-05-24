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

    char buffer[1024],ack[50];
    int n,frame;
    while(1)
    {
        memset(buffer,0,sizeof(buffer));
        n=read(scsocket,buffer,sizeof(buffer));
        if(n<=0)
        {
            printf("Disconnected");
            break;
        }

        sscanf(buffer,"%d",&frame);
        printf("Frame Recieved: %d\n",frame);
        sleep(1);

        snprintf(ack,sizeof(ack),"ACK %d",frame);
        send(scsocket,ack,strlen(ack),0);
    }
    close(serversocket);
    close(scsocket);
}