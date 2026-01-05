// Swap 2 Numbers
#include <stdio.h>

int main(void){
    int Number1 = 1;
    int Number2 = 2;

    Number1 = Number1 ^ Number2;
    Number2 = Number1 ^ Number2;
    Number1 = Number1 ^ Number2;

    printf("Number 1 = %d\nNumber 2 = %d\n",Number1,Number2);
    return 0;
}