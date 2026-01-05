#include <stdio.h>
#include <string.h>

int main(void) {
    int array1[] = {10,20,30};
    int array2[] = {100,200,300};

    memcpy(array1,array2,sizeof(array1));
    memmove(array1,array2,sizeof(array1));
    memset(array1,0,sizeof(array1));
    
    for (size_t i = 0; i < 3; i++)
    {
        printf("Array : %d\n",array1[i]);
    }
    
    return 0;
}