#include "mymalloc.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    size_t size;
    int occup;
    struct node *next;
} block_meta_t;
#define META_SIZE sizeof(block_meta_t)
void *global_base = NULL;


block_meta_t *find_free_block(block_meta_t **last, size_t size){
    block_meta_t *curr = global_base;
    *last = NULL;
    while(curr){
        if(curr->occup == 0 && curr->size >= size)
            return curr;

        *last = curr;
        curr = curr->next;
    }

    return NULL;
}


block_meta_t *request_space(block_meta_t *last, size_t size){
    void *allocated = sbrk(META_SIZE + size);
    if(allocated == (void *)-1){
        perror("sbrk");
        return NULL;
    }

    block_meta_t *block = allocated;
    block->next  = NULL;
    block->occup = 1;
    block->size  = size;

    if(last == NULL){
        global_base = block;
    }else{
        last->next = block;
    }
    return block;
}


void *get_block_ptr(void *ptr){
    return ((block_meta_t *)ptr) - 1;
}



void *mymalloc(size_t size){
    if(size <= 0) return NULL;
    block_meta_t *block = NULL;
    if(global_base == NULL){
        block = request_space(NULL, size);
        if(!block) return NULL;
        return block + 1;
    }else{
        block_meta_t *last;
        block = find_free_block(&last, size);

        if(block != NULL){
            block->occup = 1;
            return block + 1;
        }else{
            block = request_space(last, size);
            if(!block) return NULL;

            return block + 1;
        }
    }
}


void myfree(void *ptr){
    if(ptr == NULL) return;
    block_meta_t *block = get_block_ptr(ptr);
    block->occup = 0;
}


void *myrealloc(void *ptr, size_t size){
    if(ptr == NULL)
        return mymalloc(size);
    if(size == 0){
        myfree(ptr);
        return NULL;
    }
    block_meta_t *block = get_block_ptr(ptr);
    if(block->size >= size){
        return ptr;
    }else{
        void *nptr = mymalloc(size);
        if(!nptr) return NULL;
        size_t nsize = block->size;
        if(nsize > size)
            nsize = size;
        memmove(nptr, ptr, nsize);
        myfree(ptr);
        return nptr;
    }
}


void *mycalloc(size_t nelem, size_t elsize){
    if(elsize <= 0) return NULL;
    void *ptr = mymalloc(nelem * elsize);
    if(!ptr) return NULL;
    memset(ptr, 0, nelem * elsize);
    return ptr;
}
