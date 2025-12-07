#include <stdio.h>  

int print(int num){
    if (num == 0)
    {
        return 1;
    }
    return num * print(num-1);       // 5 * 4 = 20 * 3 = 60 * 2 = 120 * 1 = 120
}

void main(void)
{
    printf("Factorial : %d\n",print(5));
}