/*
Q. meaning of this :
struct A *p;
struct A (*p)[10];

Q. Allocate memory to double pointer
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int Number = 10;
    int *ptr = &Number;

    //int **ptr1 = malloc(sizeof(Number));
    int **ptr2 = &ptr;

    return 0;
}
