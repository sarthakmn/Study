#include<stdio.h>
#define PRINT(var) printf(#var " = %d\n", var)       //user defined constants #macro
#define VAR(a,b) printf("var : %d\n",a##b)           // token pasting operator ##
#define ADD(a, b) printf("addition : %d\n",(a + b));
int main(){
    PRINT(12);
    VAR(12,40);
    ADD(10,20);
    printf("Time : %s \nDate : %s\n",__TIME__,__DATE__); //predefined constants
    return 0;
}

// conditional compilation done to check some condition in preprocessor level before compilation.
// #define VER 1
// int main() {
// #ifndef VER
// #error "VER not defined"
// #endif
// #if VER == 1
// printf("This is Version 1.\n");
// #elif VER == 2
// printf("This is Version 2.\n");
// #else
// printf("This is 3+ Version.\n");
// #endif
// return 0;
// }