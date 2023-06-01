#include <stdio.h>

int main(int argc,const char *argv[]){
    //标准IO实现文件的复制
	int a;
	FILE* file = fopen(argv[1], "r+");
	FILE* file_copy =fopen(argv[2],"w+");
	if(!file||!file_copy){
	    perror("failed");   	
	    return -1;
	}
	for (;;) {
		a = fgetc(file);
		if (a == EOF)
		    break;
		//printf("%c", a);
		fputc(a,file_copy);
	}
    
    
    
    return 0;
}
