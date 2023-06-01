#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <strings.h>
#include<pthread.h>

void *receiveHander (void *p);
void *sendHander (void *p);
pthread_mutex_t mutex;
struct sockaddr_in addr,client;
socklen_t addrlen;

                    //     struct sockaddr_in {
                    //        sa_family_t    sin_family; /* address family: AF_INET */
                    //        in_port_t      sin_port;   /* port in network byte order */
                    //        struct in_addr sin_addr;   /* internet address */
                    //    };       
int main(void){
    pthread_mutex_init(&mutex,NULL);
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        perror("socket():\n");
        exit(-1);
    }
    //绑定IP和端口号
    addr.sin_family=AF_INET;
    addr.sin_port=htons(12340);
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
	


    //创建一个线程，进行数据的接受
    pthread_t tid_receive,tid_send;
    int receive= pthread_create(&tid_receive, NULL,receiveHander, (void *)fd);
	//接收操作
	// while(1){
	// bzero(buf,sizeof(buf));
	// recv(fd,buf,sizeof(buf),0);
	// printf("客户端:%s\n",buf);
	// }
	 int send= pthread_create(&tid_send, NULL,sendHander, (void *)sockfd);

    
    
    
    
    while(1);
    return 0;
}
//接收数据
void *receiveHander (void *p){
    while(1){
        pthread_mutex_lock(&mutex);
        int fd=(int)p;
        // printf("%d\n",fd);
        char buf[50];
        bzero(buf,sizeof(buf));
        recv(fd,buf,sizeof(buf),0);
        printf("客户端:%s\n",buf);
        pthread_mutex_unlock(&mutex);
    }
   
}

//发送数据
void *sendHander (void *p){
    while(1){
        pthread_mutex_lock(&mutex);

        int fd=(int)p;
        // printf("%d\n",fd);
        char buf[50];
        bzero(buf,sizeof(buf));
        send(fd,buf,sizeof(buf),0);
        printf("客户端:%s\n",buf);
        pthread_mutex_unlock(&mutex);


    }
   
}