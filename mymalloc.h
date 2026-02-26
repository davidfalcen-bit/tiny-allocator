#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stddef.h>

void *mymalloc(size_t size);
void myfree(void *ptr);
void *myrealloc(void *ptr, size_t size);
void *mycalloc(size_t nelem, size_t elsize);

#endif // MYMALLOC_H
