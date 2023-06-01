#include<stdio.h>
//直接插入排序
int main(void){
	int a[10]={5,3,6,3,76,2,2,5,3,7};
	int i,j;
	int template;
	for(i=1;i<10;i++){
		j=i;
		template=a[j];
		while(1){
			if(template<a[j-1]){
				a[j]=a[j-1];
				j--;
			}
			else
				break;
		}
		a[j]=template;
	}
	int x;
	for(x=0;x<10;x++){
		printf("%d ",a[x]);
	}
	


	return 0;
}
