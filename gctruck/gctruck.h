#ifndef GCTRUCK
#define GCTRUCK

#include <stdbool.h>

extern bool gccollectfullcycle;
extern bool gcnomemory;

void gc_mark(void** ptrtotrack);
void gc_collect();

#define GCMARK(ptr) gc_mark(&(void*)ptr)

#define GCNEW(ptrname, type) type ## * ptrname = (type ## *)malloc(sizeof(type)); \
gc_mark(&(void*)ptrname)

#endif
