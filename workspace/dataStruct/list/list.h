#ifndef LIST_H
#define LIST_H
typedef int elem_t;
typedef struct node {
	elem_t data;
	struct node *next, * prev;
}node_t;
typedef struct {
	node_t head;
	int length;
}list_t;

int list_init(list_t *list);
int list_sort_insert(list_t *list,elem_t *pe);
int list_insert(list_t* list, elem_t *pe);
int list_tail_insert(list_t* list, elem_t* pe);
int list_delete(list_t* list);
int list_tail_delete(list_t* list);
int list_search(list_t* list, elem_t* pe);
int list_sort(list_t* list);
int list_print(list_t* list);

#endif
