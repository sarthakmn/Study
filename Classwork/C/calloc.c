#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr = NULL;
    ptr = calloc(111,sizeof(int));
    printf("Number: %d \n", *ptr);
    return 0;
}