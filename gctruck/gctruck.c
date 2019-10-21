#include <malloc.h>
#include <stdbool.h>

#include "gctruck.h"

bool gccollectfullcycle = false;
bool gcnomemory = false;

typedef struct trackedptr_node_s {
	void** trackedptr;
	struct trackedptr_node_s* next;
} trackedptr_node_t;

typedef struct allocated_node_s {
	void* data;
	trackedptr_node_t* ptrlist;
	struct allocated_node_s* next;
} allocated_node_t;

allocated_node_t* alloclist = NULL;

void gc_mark(void** ptrtotrack) {
	gcnomemory = false;

	gc_collect();
	
	allocated_node_t* allocnode = (allocated_node_t*)malloc(sizeof(allocated_node_t));

	if (allocnode == NULL) {
		gccollectfullcycle = true;
		gc_collect();
		gccollectfullcycle = false;

		allocnode = (allocated_node_t*)malloc(sizeof(allocated_node_t));
		if (allocnode == NULL) {
			gcnomemory = true;
		}
	}

	allocnode->data = *ptrtotrack;

	if (!alloclist) {
		allocnode->next = allocnode;
		alloclist = allocnode;
	}
	else {
		allocated_node_t* oldnext = alloclist->next;
		alloclist->next = allocnode;
		alloclist->next->next = oldnext;
		alloclist = alloclist->next;
	}

	//TODO: ptrlist

	//trackedptr_node_t* ptrnode = (trackedptr_node_t*)malloc(sizeof(trackedptr_node_t));
	//ptrnode->trackedptr = ptrtotrack;
}

void gc_collect() {
	// TODO
}