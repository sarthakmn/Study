/* Print factorial of Number
5! = 5 * 4 * 3 * 2 * 1
*/

#include <stdio.h>

int factorial(int Number){
    if(Number <= 1){
        return 1;
    }
    return Number * factorial(Number-1);
}

int main(void){
    int Number = 5;
    printf("Factorial of %d is %d\n",Number,factorial(Number));
    return 0;
}