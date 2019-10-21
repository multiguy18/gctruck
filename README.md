# gctruck
A implementation of a (sort of) reference counting garbage collector in c

This project is completly self-educational and not intended for use in a productive enviroment, at least for now...

## Theory

If a pointer will be marked by GCNEW or GCMARK, a pointer to this pointer will be added to a list. A copy of the marked pointer will be also stored in a seperate list if the adress doesn't exist there yet. The purpose of the pointer-to-pointer list is to provide a reference to the pointers on the stack created by a varaiable declaration in a certain scope, and to check if the pointers are still valid.

When we leave a scope in c, we have no way of being notified which variables are out of scope. But we know that they are overwritten when a scope on the same level is introduced later. TODO...

Pointers to tracked pointers are stored in a endless single-linked list. This will be useful to implement a limit of how many pointers will be scanned when the GC is triggered by GCNEW, GCMARK and gc_collect(), and allows every pointer to be scanned even when the GCs scanning count will be limited.
