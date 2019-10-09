#include <malloc.h>

typedef struct observedptr_node_s {
	void** observedptr;
	struct observedptrnode_s* next;
} observedptr_node_t;

typedef struct allocated_node_s {
	void* data;
	struct allocated_node_s* next;
} allocated_node_t;