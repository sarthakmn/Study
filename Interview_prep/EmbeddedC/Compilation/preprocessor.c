#include <stdio.h>         // usr/include/
#include "preprocessor.h"  // local

int main(void) {
    function();
    printf("Pi = %f\n",PI);
    printf("Square = %d\n",SQUARE(10));
    printf("Max = %d\n",MAX(10,20));

#if DEBUG == 0
    printf("Conditional compilation\n");
#endif

#ifdef DEBUG
    printf("If defined\n");
#elif 
    printf("If not defined\n");
#endif

    return 0;
}

inline void function(){
    printf("Macro: \nA preprocessor directive (#define) that performs text substitution before compilation.\nInline Function: \nA function with the inline keyword that suggests the compiler to replace the function call with its body at compile time.\n\n");
}