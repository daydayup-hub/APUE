#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
void daemon_init(void);

int main(){
	//守护进程函数 
	daemon_init();
	
	//打开日志
	openlog("霍博君少爷",LOG_PID,LOG_DAEMON);
	
	int fd=open("1.txt",O_RDWR); 
	if(fd<0){
		syslog(LOG_ERR,"霍博君少爷没饭吃");
		exit(-1);
	}

	char buf[50]="再多看一眼就会爆炸\n";
	while(1){
		sleep(1);
		write(fd,buf,strlen(buf));
		syslog(LOG_INFO,"%s",buf);
	}
	
	return 0;
}
void daemon_init(void){
	//守护进程的制作过程 
	//1>创建子进程，结束父进程 
			//----->为了会话做准备>组长无法成为会话
			if(fork()!=0)
				exit(1);
			
	//2>设置当前子进程为一个会话/终端
			//----->为了摆脱原终端影响
			if(setsid()<0){
				perror("setsid");
				exit(-1);
			}
			
	//3>创建子进程，结束父进程 
			//----->彻底摆脱父子进程间的影响
			if(fork()!=0)
				exit(1);
			
			//---->守护进程雏形建立 
			//以下的操作都是为了完善守护进程
	//4>关闭所有文件描述符----->为了第7步做准备 
			int i;
			for(i=0;i<=sysconf(_SC_OPEN_MAX);i++){
				close(i);
			}
			
	//5>改变执行目录
			chdir("/");
						
	//6>修改权限掩码 
			umask(0);

	//7>文件描述符重定向 
			int fd=open("/dev/null",O_RDWR);
			dup(0);
			dup(0);

}