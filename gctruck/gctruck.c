#include <malloc.h>

typedef struct trackedptr_node_s {
	void** trackedptr;
	struct trackedptr_node_s* next;
} trackedptr_node_t;

typedef struct allocated_node_s {
	void* data;
	struct allocated_node_s* next;
} allocated_node_t;

trackedptr_node_t* ptrlist;
allocated_node_t* alloclist;