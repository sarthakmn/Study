#include <stdio.h>
#include <stdlib.h>

void main(void){
    int *ptr = malloc(sizeof(int));
    free(ptr);
    //*ptr = 10;                 // dangling pointer

    int *ptr2 = malloc(sizeof(int)); // memory leakage not freed
}