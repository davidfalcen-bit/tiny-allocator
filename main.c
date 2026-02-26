#include <stdio.h>
#include <string.h>

#include "mymalloc.h"


int main(void){
    /* malloc */
    char *p = mymalloc(32);
    if(!p){
        printf("alloc failed\n");
        return 1;
    }
    strcpy(p, "Hello custom malloc");
    printf("p: %s\n", p);
    /* realloc */
    p = myrealloc(p, 64);
    strcat(p, " !!!");
    printf("after realloc: %s\n", p);
    /* calloc */
    int *arr = mycalloc(5, sizeof(int));
    printf("calloc array:\n");
    for(int i = 0; i < 5; i++){
        printf("  arr[%d] = %d\n", i, arr[i]);
    }
    /* free */
    myfree(p);
    myfree(arr);
    return 0;
}
