#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main()
{
    int serversocket;
    struct sockaddr_in server,client;
    socklen_t addresslength = sizeof(client);

    serversocket=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=INADDR_ANY;

    bind(serversocket, (struct sockaddr *)&server, sizeof(server));

    int a[2][2],b[2][2],c[2][2];
    recvfrom(serversocket,a,sizeof(a),0,(struct sockaddr *)&client,&addresslength);
    recvfrom(serversocket,b,sizeof(b),0,(struct sockaddr *)&client,&addresslength);

    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%d", c[i][j]);
        }
        printf("\n");
    }

    sendto(serversocket,c,sizeof(c),0,(struct sockaddr *)&client, addresslength);
    close(serversocket);
}