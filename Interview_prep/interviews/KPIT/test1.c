// explain callback

#include <stdio.h>

int Addition(int Num1, int Num2){
    return Num1 + Num2;
}

int main(void){
    int (*ptr)(int,int) = Addition;

    printf("Addition callback : %d\n",ptr(10,20));
    return 0;
}