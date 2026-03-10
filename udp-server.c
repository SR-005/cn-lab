#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock;
    struct sockaddr_in server,client;

    int a[2][2],b[2][2],c[2][2];

    sock=socket(AF_INET,SOCK_DGRAM,0);      //socket creation
    server.sin_family=AF_INET;              //specifies IPv4
    server.sin_port=htons(8090);                //server port number = 8086: htons converts port num to network byte order
    server.sin_addr.s_addr=INADDR_ANY;          //accepts connection from any IPv4 Addresses

    bind(sock,(struct sockaddr *)&server, sizeof(server));       //bind sockets with IP Address and Port

    recvfrom(sock,a,sizeof(a),0,(struct sockaddr *)&client, sizeof(client));      //recieve matrix a from client
    recvfrom(sock,b,sizeof(b),0,(struct sockaddr *)&client, sizeof(client));       //recieve matrix b from client

    //add matrix a and b
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    sendto(sock,c,sizeof(c),0,(struct sockaddr *)&client, sizeof(client));      //send matrix c to client
    close(sock);

    return 0;
}
