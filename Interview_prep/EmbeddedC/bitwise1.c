#include <stdio.h>

int main(void){
    int Number = 8;  // 1000
    printf("Set 2nd bit : %d\n",Number | (1<<1));          // 1010 = 10
    printf("clear 4nd bit : %d\n",Number & (~(1<<3)));     // 0000 = 0
    printf("toggle 2nd bit : %d\n",Number ^ ((1<<1)));     // 1010 = 10
    return 0;
}