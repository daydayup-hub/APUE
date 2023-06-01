#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <strings.h>



struct sockaddr_in addr,client;
socklen_t addrlen;

                    //     struct sockaddr_in {
                    //        sa_family_t    sin_family; /* address family: AF_INET */
                    //        in_port_t      sin_port;   /* port in network byte order */
                    //        struct in_addr sin_addr;   /* internet address */
                    //    };       
int main(void){
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        perror("socket():\n");
        exit(-1);
    }
    printf("%d\n",sockfd);
    //绑定IP和端口号
    addr.sin_family=AF_INET;
    addr.sin_port=htons(12345);
    addr.sin_addr.s_addr=inet_addr("192.168.50.102");
    addrlen=sizeof(addr);
   if( bind(sockfd, (struct sockaddr*)&addr,addrlen)){
    perror("failed\n");
   } 
   printf("serve open success\n");
   //监听
   listen(sockfd,8);
   int len=sizeof(client);
   //等待连接，client的数据会回填
   int fd=accept(sockfd, (struct sockaddr*)&client, &len);
   if(fd<0){
        perror("accept");
        return -1;
        }
	printf("客户%d连接成功\n",fd);
    char buf[50];
	
	//接收操作
	while(1){
	bzero(buf,sizeof(buf));
	recv(fd,buf,sizeof(buf),0);
	printf("客户端:%s\n",buf);
	}
	

    
    
    
    
    
    return 0;
}