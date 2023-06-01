#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(void){
  FILE *fr=fopen("getline.c","r+");
  if(fr==NULL){
    perror("fopne()");
    exit(-1);
  }
  size_t n=0;
  int num;
  char *string;
  string=NULL;
  while(1){
    if(getline(&string,&n,fr)>0){
      printf("%s",string);
  }else{
    break;
  }
  }
  fclose(fr);
  return 0;
}
