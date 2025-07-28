#include <stdio.h>
#pragma pack (1)


struct data{
    char a;
    int b;
    int c; 
    int age: 32;
};

enum color{
    red,
    green
};

void main(void){
    struct data d1;
    printf("size : %ld enum : %d\n", sizeof(d1),red);
}