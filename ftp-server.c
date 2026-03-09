#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main()
{
    int sock,scsock;
    struct sockaddr_in server,client;
    int length=sizeof(client);

    sock=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=INADDR_ANY;

    bind(sock,(struct sockaddr *)&server,sizeof(server));
    listen(sock,3);
    scsock=accept(sock,(struct sockaddr *)&client,&length);

    char filename[20],data[300],file,n;
    n=recv(scsock,filename,sizeof(filename),0);
    filename[n]='\0';

    file=open(filename,O_RDONLY);

    if(file<0)
    {
        strcpy(data,"File Not Found");
    }
    else
    {
        n=read(file,data,sizeof(data));
        data[n]='\0';
        close(file);
    }

    send(scsock,data,sizeof(data),0);
    close(sock);
    close(scsock);
}