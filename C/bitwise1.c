
// set all even bits
// Input : 20 
// Output : 30
// Binary representation of 20 is
// 10100. After setting
// even bits, we get 11110

//Input : 10
//Output : 10

#include <stdio.h>

void main(void){

    int number = 20;                        // 0010  
    printf("Number : %d\n",number|0xA);     // 1010

}