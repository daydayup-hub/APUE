#include <stdio.h>
#include<string.h>
int main(int argc,const char *argv[]){
    
	char buff[100]="";
	FILE* file = fopen(argv[1], "r+");
	FILE* file_copy =fopen(argv[2],"w+");
	if(!file||!file_copy){
	    perror("failed");   	
	    return -1;
	}
	for (;;) {
		bzero(buff,sizeof(buff));
		char *a=fgets(buff,sizeof(buff),file);
		if (a == NULL)
		    break;
		fputs(buff,file_copy);
	}
    
    
    
    return 0;
}
