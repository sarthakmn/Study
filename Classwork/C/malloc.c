#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int)*2);
    int number = 10;
    *ptr = number;
    *(ptr+1) = 20;
    printf("Number: %d : %d \n", *ptr, *(ptr+1));
    return 0;
}