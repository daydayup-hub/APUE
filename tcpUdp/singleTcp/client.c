#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>


struct sockaddr_in server;
socklen_t addrlen;                
int main(void){
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        perror("socket():\n");
        exit(-1);
    }
    printf("%d\n",sockfd);
    //与服务器建立连接
    server.sin_family=AF_INET;
    server.sin_port=htons(12345);
    server.sin_addr.s_addr=inet_addr("192.168.50.102");
    socklen_t addrlen;
    addrlen=sizeof(server);
    if(connect(sockfd,(struct sockaddr*)&server,addrlen)){
        perror("failed\n");
        exit(0);
    }
    printf("connect success!\n");
    char buf[100];
    while(1){
        bzero(buf,sizeof(buf));
        scanf("%s",buf);
        send(sockfd,buf, strlen(buf), 0);

    }



  



    
    
    
    
    
    return 0;
}