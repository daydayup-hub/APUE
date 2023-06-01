#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define THRNUM 3
void * func(void *c);
static int next(n);
pthread_mutex_t mutex[3];
int main()
{   int i,err;
    pthread_t tid[THRNUM];
    for(i=0;i<THRNUM;i++){
        pthread_mutex_init(mutex+i,NULL);
        pthread_mutex_lock(mutex+i);
        err=pthread_create(&tid[i],NULL,func,(void*)i);
        if(err){
            fprintf(stderr,"pthread_create():%s\n",strerror(err));
            exit(1);
        }
        pthread_mutex_unlock(mutex+0);
    }
    alarm(1);
   
    for(i=0;i<THRNUM;i++){
        pthread_join(tid[i],NULL);
    }
    exit(0);
   
}
void * func(void *p){
    int n=(int)p;
    char c='a'+n;
    while(1){
        pthread_mutex_lock(mutex+(int)p);
        write(1,&c,1);
        pthread_mutex_unlock(mutex+next(n));
    }

    pthread_exit(NULL);
    return NULL;
}
static int next(n){
    return (n+1)%3;    
}


