#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
int list_init(list_t* list) {
	if (!list)
		return -1;
	list->length = 0;
	list->head.next = &(list->head);
	list->head.prev = &(list->head);
	return 0;
}

int list_insert(list_t* list, elem_t* pe) {
	node_t *pnode,*pnew;
	if (!list || !pe)
		return -1;
	//
	pnode = list->head.next;
	pnew = malloc(sizeof(node_t));
	if (!pnew)
		return -1;
	memcpy(&pnew->data, pe, sizeof(elem_t));
	//insert from head
	pnew->prev = &list->head;
	list->head.next = pnew;
	pnew->next = pnode;
	pnode->prev = pnew;
	list->length++;
	return 0;
}



int list_sort_insert(list_t* list, elem_t* pe) {
	node_t *pnode,*pnew,*pnext;
	if (!list || !pe)
		return -1;
	//
	pnode = &list->head;
	pnew = malloc(sizeof(node_t));
	if (!pnew){
		printf("failed");
		return -1;

	}
	memcpy(&pnew->data, pe, sizeof(elem_t));


	//locate
	while(pnode->next!=&list->head){
		if(*pe<pnode->data&&*pe>=pnode->next->data)
			break;
		pnode=pnode->next;
	}
	//tail or location
	if(pnode->next==&list->head){
		//insert into tail
		pnew->next = &list->head;
		list->head.prev = pnew;
		pnode->next = pnew;
		pnew->prev = pnode;
		list->length++;
		return 0;
	}


	//insert into pnode
	pnext=pnode->next;
	pnode->next=pnew;
	pnew->prev=pnode;
	pnew->next=pnext;
	pnext->prev=pnew;

	list->length++;
	return 0;
}


list_delete(list_t* list){
	node_t *pdel,*pnode;
	if(!list)
		return -1;
	pdel=list->head.next;
	if(pdel==&list->head){
		printf("list is null\n");
		return -1;
	}
	pnode=pdel->next;
	list->head.next=pnode;
	pnode->prev=&list->head;
	return 0;
}
int list_tail_insert(list_t* list, elem_t* pe) {
	node_t *pnode,*pnew;
	if (!list || !pe)
		return -1;
	//
	pnode = list->head.prev;
	pnew = malloc(sizeof(node_t));
	if (!pnew)
		return -1;
	memcpy(&pnew->data, pe, sizeof(elem_t));
	//insert from head
	pnew->next = &list->head;
	list->head.prev = pnew;
	pnode->next = pnew;
	pnew->prev = pnode;
	list->length++;
	return 0;
}
int list_tail_delete(list_t* list){
	node_t *pdel,*pnode;
	if(!list)
		return -1;
	pdel=list->head.prev;
	if(pdel==&list->head){
		printf("list is null\n");
		return -1;
	}
	pnode=pdel->prev;
	list->head.prev=pnode;
	pnode->next=&list->head;
	return 0;
}
int list_search(list_t* list, elem_t* pe) {
	node_t *pnode,*pnew;
	if (!list || !pe)
		return -1;
	pnode = list->head.next;
	if(pnode==&list->head){
		printf("list is null");
		return -1;
	}
	while(pnode!=&list->head){
		if(pnode->data==*pe){
			printf("the match's next is:%d\n",pnode->next->data);
			printf("the match's prev is:%d\n",pnode->prev->data);
		}
		pnode=pnode->next;
	}

	return 0;
}
// int list_sort(list_t* list){
// 	if(!list)
// 		return -1;
// 	node_t *pnode;
// 	pnode=list->head.next;
// 	if(pnode==&list->head){
// 		printf("list is null");
// 		return -1;
// 	}
// 	int index=list->length;
// 	int template=pnode->data;
// 	while(--index){
// 		pnode=pnode->next;
		
// 		while(1){
			
// 		}
// 	}
		

	
// }

int list_print(list_t* list) {
	if (!list)
		return -1;
	node_t *pnode;
	pnode = list->head.next;
	while (pnode!=&list->head) {
		printf("%d\n", pnode->data);
		pnode = pnode->next;
	}


}


