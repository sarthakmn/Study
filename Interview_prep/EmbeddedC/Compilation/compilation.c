/*
preprocessor : gcc -E compilation.c -o compilation.i         // Replace preprocessor directives 
compiler :     gcc -S compilation.c -o compilation.s         // .c -> .asm , error check
assambler :    gcc -c compilation.c -o compilation.o         // .asm -> .o (machine code)
linker :       link .a .so                                   // link the static & dynamic libraries
executable :   gcc compilation.o -o compilation              // make executable
*/

/*
Static linking
gcc -c libmath.c
ar rcs libmath.a libmath.o
gcc compilation.c -L. -lmath -o Static

Dynamic linking
gcc -fPIC -c mathlib.c
gcc -shared -o libmathlib.so libmath.o 
gcc compilation.c -L. -lmath -o Dynamic
*/

#include <stdio.h>
#include "preprocessor.h"

int main(void){
    printPI();
    return 0;
}