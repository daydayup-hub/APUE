#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
int main(){
    int pipefd[2];
    int ret=pipe(pipefd);
    printf("pipefd[0]=%d\n",pipefd[0]);
	printf("pipefd[1]=%d\n",pipefd[1]);
   
    if(ret<0){
		perror("pipe");
		return -1;
	}
	 pid_t pid=fork();
    if(pid>0){
    char buf[50];

        while(1){
            scanf("%s",buf);
            write(pipefd[1],buf,strlen(buf));
        }
    }else if(pid==0){
        char buf[50];
        while(1){
            bzero(buf,sizeof(buf));
            read(pipefd[0],buf,sizeof(buf));
            printf("father's data is%s",buf);
        }
        
    }    



    return 0;
}