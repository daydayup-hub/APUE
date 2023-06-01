#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 1024
int fr,fw,ret,len,pos;
char *buf[SIZE] ={};
int main(int argc, char *argv[]){
    fr=open("read.c",O_RDONLY);
	fw=open("tem.c",O_WRONLY|O_CREAT|O_TRUNC,0666);
	while(1){
		len=read(fr,buf,SIZE);
		if(len<0){
			perror("read()");
			break;
		}
		if(len==0){
			break;
		}
		pos=0;
		while(len>0){

			ret=write(fw,buf+pos,len);
			if(ret<0){
				perror("write()");
				exit(1);
			}
			//从上次写入的地方继续写
			pos+=ret;
			//检查是否全部写入
			len-=ret;

		}
		
	}

	close(fr);
	close(fw); 
    return 0;
}

