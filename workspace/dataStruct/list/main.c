#include<stdio.h>
#include"list.h"
int main(void) {
	// elem_t a = 10;
	// elem_t b = 20;
	// elem_t c = 30;
	elem_t a[]={1,4,3,44};

	list_t list;

	list_init(&list);
	for(int i=0;i<sizeof(a)/sizeof(elem_t);i++){
		list_sort_insert(&list, a+i);

	}
	// list_sort_insert(&list, &a);
	// list_sort_insert(&list, &b);
	// list_sort_insert(&list, &c);
	list_print(&list);

	return 0;
}