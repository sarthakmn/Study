// Find number is even or odd

#include<stdio.h>

void main(void){
    int number = 6;           //  0110  & 0001   = 0000
    (number&1) ? printf("Number odd\n") : printf("Number even\n");
}