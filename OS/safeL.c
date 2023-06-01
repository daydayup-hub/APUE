#include<stdio.h>
#include<stdlib.h>
#define FNAME "/tmp/out"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
int daemonize(void);
int main(void){
    FILE *fp;
    int i;
    openlog("mydaemon",LOG_PID,LOG_DAEMON);
    if(daemonize()){
        syslog(LOG_ERR,"daemonsize()failed");
        exit(1);
    }else{
        syslog(LOG_INFO,"daemonsize()success");
    }
    fp=fopen(FNAME,"w");
    if(fp==NULL){
        syslog(LOG_ERR,"fopen:%s",strerror(errno));
        exit(1);
    }
    for(i=0;;i++){
        fprintf(fp,"%d\n",i);
        fflush(fp);
        sleep(1);
    }
    closelog();
	exit(0);
}
int daemonize(void){
    int fd;
    pid_t pid=fork();
    if(pid<0){
        return -1;
    }
    if(pid>0){
        exit(0);
    }
    fd=open("/dev/null",O_RDWR);
    if(fd<0){
        return -1;
    }
    dup2(fd,0);
    dup2(fd,1);
    dup2(fd,2);
    if(fd>2)
        close(fd);
    setsid();
    
    chdir("/");
    umask(0);
    return 0;
}
