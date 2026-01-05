#include <stdio.h>
#include <stdlib.h>

int main(void){
    int number = 10;
    int *mptr = (int*)malloc(sizeof(number));
    mptr = &number;
    
    int *cptr = (int*)calloc(1,sizeof(number));
    cptr = (int*)realloc(cptr,sizeof(number)*2);

    printf("Malloc Number : %d\n",*mptr);
    printf("Calloc Number : %d\n",*cptr);
    
    return 0;
}