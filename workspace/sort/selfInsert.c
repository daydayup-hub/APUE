#include<stdio.h>
//折半插入查找
int main(void){
	int number;
	printf("insert th number:\n");
	scanf("%d",&number);
	int a[]={1,2,4,7,34,66,77,88};
	int length=sizeof(a)/sizeof(int);
	int start=0,
		end=length-1,
		half;
	while(start<=end){
		half=(start+end)/2;
		if(number<a[half])
			end=half-1;
		if(number>a[half])
			start=half+1;
		if(number==a[half]){
			printf("index:%d\n",half);
			return 0;
		}
		
	}
	printf("not found\n");



	return 0;
}
