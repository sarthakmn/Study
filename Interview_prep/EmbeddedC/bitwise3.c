// Decimal to Binary
#include <stdio.h>

int main (void) {
    int Number = 10;

    for (int i = 3; i>=0; i--){
        if(Number&(1<<i)){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    return 0;
}