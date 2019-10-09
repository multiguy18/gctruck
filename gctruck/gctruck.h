#ifndef GCTRUCK
#define GCTRUCK

void* gc_mark(void** ptrtotrack);

#define GCMARK(ptr) gc_mark(&(void*)ptr)

#define GCNEW(ptrname, type) type ## * ptrname = (type ## *)malloc(sizeof type); \
gc_mark(&(void*)ptrname)

#endif