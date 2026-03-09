#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int serversocket,cssocket;      //server only socket, server+client socket
    struct sockaddr_in server,client;   //to store server and client address
    char string[20];                    //to store string

    serversocket=socket(AF_INET,SOCK_STREAM,0);     //create server socket

    server.sin_family=AF_INET;                  //specifies IPv4
    server.sin_port=htons(8086);                //server port number = 8086: htons converts port num to network byte order
    server.sin_addr.s_addr=INADDR_ANY;          //accepts connection from any IPv4 Addresses

    bind(serversocket,(struct sockaddr *)&server,sizeof(server));       //bind sockets with IP Address and Port
    listen(serversocket,3);                     //server waits for client connection, 3 -> max no. of queued connection
    printf("Server waiting for connection...\n");

    int addresslength=sizeof(client);          

    //accept incoming client connection and create new socket
    cssocket=accept(serversocket,(struct sockaddr *)&client,(socklen_t*)&addresslength); 

    //recieve string from server
    recv(cssocket,string,sizeof(string),0);
    int i,j,temp;
    int length=strlen(string);

    for(i=0,j=length-1; i<j; i++,j--)
    {
        temp=string[i];
        string[i]=string[j];
        string[j]=temp;
    }

    //sends the reversed string to server
    send(cssocket,string,sizeof(string),0);
    close(serversocket);

    return 0;
}