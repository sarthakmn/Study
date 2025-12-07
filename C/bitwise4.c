// Find number divisible by different number

#include<stdio.h>

void main(void){
    int number = 6;
    // only applicable for even numbers
    printf("Divisible by 2 : %d\n",number&1);       
    printf("Divisible by 4 : %d\n",number&3);  
    printf("Divisible by 8 : %d\n",number&7); 

    // number divisile by 3
    int odd,even = 0;
    while(number){
        if(number & 1){
            odd++;
        }
        number >>= 1;
        
        if(number & 1){
            even++;
        }
        number >>= 1;
    }
    if(!(odd-even)){
        printf("Divisible by 3\n");
    }
}