#include<stdio.h>
//冒泡排序
int main(void){
	int a[10]={5,3,6,3,76,2,2,5,3,7};
    int length=sizeof(a)/sizeof(int);
	int i,j,template;
    for(j=0;j<length-1;j++){
        for(i=0;i<length-1-j;i++){
        if(a[i]<a[i+1]){
            //exchange
            template=a[i];
            a[i]=a[i+1];
            a[i+1]=template;
        }
    }


    }
    
    





	int x;
	for(x=0;x<10;x++){
		printf("%d ",a[x]);
	}
	


	return 0;
}
