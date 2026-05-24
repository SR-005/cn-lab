#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<fcntl.h>

int main()
{
    int serversocket, scsocket;
    struct sockaddr_in server,client;

    serversocket=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(8086);
    server.sin_addr.s_addr=INADDR_ANY;

    bind(serversocket, (struct sockaddr *)&server, sizeof(server));
    listen(serversocket, 3);
    socklen_t addresslength=sizeof(client);
    scsocket=accept(serversocket,(struct sockaddr *)&client, &addresslength);

    char filename[30], data[100];
    int file, n;
    n=recv(scsocket,filename,sizeof(filename),0);
    filename[n]='\0';

    file=open(filename,O_RDONLY);
    if(file<0)
    {
        strcpy(data,"No Contents Found");
    }
    else
    {
        n=read(file,data,sizeof(data));
        data[n]='\0';
    }
    close(file);

    send(scsocket,data,sizeof(data),0);
    close(serversocket);
    close(scsocket);
}