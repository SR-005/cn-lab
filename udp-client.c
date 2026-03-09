#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sock;
    struct sockaddr_in server;
    socklen_t length;

    int a[2][2],b[2][2],c[2][2];

    sock=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;          //specifies IPv4
    server.sin_port=htons(8090);                //server port number = 8086: htons converts port num to network byte order
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    length=sizeof(server);          //get the length of server address

    //prompt matrix a
    int i,j;
    printf("Enter first matrix:\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&a[i][j]);
    sendto(sock, a, sizeof(a), 0, (struct sockaddr*)&server, length);       //send matrix a to server

    //prompt matrix a
    printf("Enter second matrix:\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&b[i][j]);
    sendto(sock, b, sizeof(b), 0, (struct sockaddr*)&server, length);       //send matrix b to server

    recvfrom(sock,c,sizeof(c),0,(struct sockaddr *)&server, &length);       //recieve added matrix c from server

    //print matrix c
    printf("Result matrix:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    close(sock);
    return 0;
}