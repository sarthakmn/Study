#include <stdio.h>
#include <stdlib.h>

int main(void){
    int Number = 10;
    
    void *vd = &Number;  // Void pointer can store address of any type
    printf("Void Pointer : %d\n",*(int *)vd);

    int *wd;             // ❌ Wild pointer (uninitialized)
    int *np = NULL;      // ✅ Null pointer Points to nothing *np ~ 0
    
    int *dg = malloc(sizeof(int));
    free(dg);
    // dg still holds old address → dangling pointer
    dg = NULL; // ✅ Safe practice

    const int *ptr;          // value constant
    int *const ptr;          // pointer constant
    const int *const ptr;    // both constant

    return 0;
}