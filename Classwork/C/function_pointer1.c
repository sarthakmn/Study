#include <stdio.h>

int pointer (int num1, int num2, int(*ptr)(int,int)){
    return ptr(num1,num2);
}

int add(int a, int b) {
    return a + b;
}

void main(void){
    int(*ptr)(int,int) = add;
    printf("Addition : %d\n",pointer(20,30,ptr));
}