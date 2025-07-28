#include<stdio.h>

void add(int a=0,int b=0){  // declare argument = 0 to make it default
    printf("Addition : %d\n",a+b);
}
int main(){

    add(10); // passed only 1 arg
    add(20,70);
    return 0;
}