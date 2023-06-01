#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>
#include<pthread.h>
pthread_mutex_t mutex;
void *receiveHander (void *p);
void *sendHander (void *p);
struct sockaddr_in server;
socklen_t addrlen;                
int main(void){
    pthread_mutex_init(&mutex,NULL);
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        perror("socket():\n");
        exit(-1);
    }
    //与服务器建立连接
    server.sin_family=AF_INET;
    server.sin_port=htons(12340);
    server.sin_addr.s_addr=inet_addr("192.168.50.102");
    socklen_t addrlen;
    addrlen=sizeof(server);
    if(connect(sockfd,(struct sockaddr*)&server,addrlen)){
        perror("failed\n");
        exit(0);
    }
    printf("connect success!\n");

    //创建一个线程负责数据的接受
    
    // char buf[100];
    // while(1){
    //     bzero(buf,sizeof(buf));
    //     scanf("%s",buf);
    //     send(sockfd,buf, strlen(buf), 0);
    // }

    pthread_t tid_receive,tid_send;
    //    int receive= pthread_create(&tid_receive, NULL,receiveHander, (void *)fd);
	
	 int send= pthread_create(&tid_send, NULL,sendHander, (void *)sockfd);
  



    
    
    
    
    while(1);
    return 0;
}

//发送数据
void *sendHander (void *p){
    while(1){
        pthread_mutex_lock(&mutex);

        int fd=(int)p;
        // printf("%d\n",fd);
       char buf[100];
    // while(1){
        bzero(buf,sizeof(buf));
        scanf("%s",buf);
        send(fd,buf, strlen(buf), 0);
    // }
        pthread_mutex_unlock(&mutex);


    }
   
}