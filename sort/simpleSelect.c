#include<stdio.h>
int main(void){
	int a[5]={7,4,6,3,9};
    int length=sizeof(a)/sizeof(int);
	int index,j,MAX,template,mem;
    for(index=length-1;index>0;index--){
        MAX=a[0];
        for(j=0;j<=index;j++){
            if(MAX<=a[j]){
                MAX=a[j];
                template=j;
            }                
        }
        //exchange
        //index是最大值的位置
        a[template]=a[index];
        a[index]=MAX;
    }
    for(int x=0;x<length;x++){
        printf("%d ",a[x]);
    }

	return 0;
}
