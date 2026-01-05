#include <stdio.h>

typedef union{
    __uint32_t value;  // Access whole register
    struct {           // Access individual bits
        __uint32_t mode   : 4;
        __uint32_t status : 4;
        __uint32_t reserved : 24;
    } bits;
}ampli;

int main(void){

    ampli am;
    am.value = 0;         // Clear all bits of register
    am.bits.mode = 0xF;   // Set all mode bits of register
    return 0;
}