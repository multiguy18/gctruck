#include <malloc.h>

#include "gctruck.h"

typedef struct trackedptr_node_s {
	void** trackedptr;
	struct trackedptr_node_s* next;
} trackedptr_node_t;

typedef struct allocated_node_s {
	void* data;
	struct allocated_node_s* next;
} allocated_node_t;

trackedptr_node_t* ptrlist = NULL;
allocated_node_t* alloclist = NULL;

void* gc_mark(void** ptrtotrack) {
	gc_collect();
	
	trackedptr_node_t *ptrnode = (trackedptr_node_t*)malloc(sizeof(trackedptr_node_t));
	ptrnode->trackedptr = ptrtotrack;

	if (!ptrlist) {
		ptrnode->next = ptrnode;
		ptrlist = ptrnode;
	}
	else {
		trackedptr_node_t* oldnext = ptrlist->next;
		ptrlist->next = ptrnode;
		ptrlist->next->next = oldnext;
		ptrlist = ptrlist->next; 
	}
}

void gc_collect() {
	// TODO
}