// set clear toggle check bits 

#include <stdio.h>

void main(void){
    int number = 10;   
    printf("Set 2nd bit : %d\n",(number | ( 1 << 2)));    // 1010 set 2rd bit 1010 & (1 << 2) = 1110
    printf("clear 3rd bit : %d\n",number & (~( 1 << 3))); // 0010
    printf("Toggle Bit 3rd : %d\n",number ^ (1<<3));      // 0010
    printf("Bit at 3rd position is %d\n",(number & (1<<3)) ? 1 : 0);
}