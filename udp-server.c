#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock;
    struct sockaddr_in server,client;
    socklen_t len;

    int a[2][2],b[2][2],c[2][2];

    sock=socket(AF_INET,SOCK_DGRAM,0);      //socket creation
    server.sin_family=AF_INET;
    server.sin_port=htons(8086)
    server.sin_addr.s_addr=INADDR_ANY;

    bind(sock,(struct sockaddr *)&server, sizeof(server));
    length=sizeof(client);

    recvfrom(sock,a,sizeof(a),(struct sockaddr *)&client, &length);
    recvfrom(sock,b,sizeof(b),(struct sockaddr *)&client, &length);

    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            print("%d",c[i][j]);
        }
        print("\n");
    }

    sendto(sock,c,sizeof(c),(struct sockaddr *)&client, length);
    close(sock)

    return 0;
}
