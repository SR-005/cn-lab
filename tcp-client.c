#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock;
    struct sockaddr_in server;        //for storing server address details
    char string[20];                    //array for storing string

    sock=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;                      //specifies IPv4
    server.sin_port=htons(8086);                    //server port number = 8086: htons converts port num to network byte order
    server.sin_addr.s_addr=inet_addr("127.0.0.1");  //sets localhost "127.0.0.1"
    
    connect(sock,(struct sockaddr *)&server, sizeof(server));   //connecting to a server

    //prompt the string
    printf("Enter a string: ");
    scanf("%s",string);

    send(sock,string,strlen(string),0);         //send the string to client
    recv(sock,string,strlen(string),0);         //recieve the reversed string from client

    printf("Reversed String: %s",string);   
    close(sock);                //close the socket


    return 0;
}