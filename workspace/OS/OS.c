#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define LEFT 200
#define RIGHT 400
int main(void){
    int i,j,mark;
    pid_t pid;

    for(i=LEFT;i<=RIGHT;i++){ 
            pid=fork();
            if(pid==0){

                mark=1;      
                for(j=2;j<i/2;j++){
                    if(i%j==0){
                        mark=0;
                        break;
                    }
                }
                if(mark){
                    printf("%d\n",i);
                }
                exit(0);


            } 
            if(pid>0){
               
            }
            
           
          
    }
    return 0;
}