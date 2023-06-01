#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO
				(Linux-specific) */
};
int main(void){
	  int vala,valb,valc;
	  struct sembuf sops={0,-1,0};
	  key_t key= ftok("OS.c", 2);
	  int semid=semget( key, 3, IPC_CREAT|0666);
	  vala=semctl(semid,0,GETVAL,NULL);
	  printf("deng:%d\n",vala);


      semop( semid, &sops, 1);
        vala=semctl(semid,0,GETVAL,NULL);
	  printf("deng:%d\n",vala);
	  



	
	
	
	
	return 0;
}