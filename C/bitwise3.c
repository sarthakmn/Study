// print binary of decimal number

#include <stdio.h>

void main(void){
    int number = 10;
    printf("Binary Number : ");
    for (int i = 3; i >= 0; i--)
    {
        if(number&(1<<i)){                            // 1010        1 << 3       0001 1000 & 1010  = 1    
            printf("1");                              // 1010        1 << 2       0001 0000 & 1010  = 0              
        }                                             // 1010        1 << 1       0000 0010 & 1010  = 1
        else{                                         // 1010        1 << 0       0000 0000 & 1010  = 0 
            printf("0");
        }
    }
    printf("\n");
}