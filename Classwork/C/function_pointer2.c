#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int (*ISR)(int,int);

void main(void){
    ISR = add;
    printf("Addition : %d\n",ISR(20,100));
}