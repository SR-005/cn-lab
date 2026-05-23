#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main()
{
    int clientsocket;
    struct sockaddr_in server;
    socklen_t addresslength = sizeof(server);

    clientsocket=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    int i,j;
    int a[2][2],b[2][2],c[2][2];
    printf("Enter Matrix A: ");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Enter A[%d][%d]: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter Matrix B: ");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Enter B[%d][%d]: ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }

    sendto(clientsocket,a,sizeof(a),0,(struct sockaddr *)&server, addresslength);
    sendto(clientsocket,b,sizeof(b),0,(struct sockaddr *)&server, addresslength);

    recvfrom(clientsocket,c,sizeof(c),0,(struct sockaddr *)&server, &addresslength);
    printf("Result: ");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d",c[i][j]);
        }
        printf("\n");
    }
    close(clientsocket);

}