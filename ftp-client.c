#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock;
    struct sockaddr_in server;

    sock=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(sock,(struct sockaddr *)&server,sizeof(server));

    char filename[20],data[300];
    printf("Enter the Filename: ");
    scanf("%s",filename);

    send(sock,filename,strlen(filename),0);
    recv(sock,data,sizeof(data),0);

    printf("Contents: %s",data);
    close(sock);

    return 0;
}