#include<stdio.h>

//inline keyword replace the function body with call when we call it 
//hence speed increase no stack is used for function activation record

inline void printvalue(){  
    printf("Value is Printed \n");
}
int main(){

    printvalue(); // call
    return 0;
}