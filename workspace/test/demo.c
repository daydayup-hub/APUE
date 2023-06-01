#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
    pid_t pid,child;
    pid=fork();
    if(pid==0){
        printf("%d:i am child\n",getpid());
        exit(0);

    }
    if(pid>0){
        printf("%d:i am father\n",getpid());

        exit(0);
    }
    
    
    
    
    while(1);
    exit(0);
}