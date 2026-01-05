#include <stdio.h>

int main(void){
    volatile int Flag = 1;

    printf("Waiting for event\n");

    while(Flag){}                       // In case of normat int Flag compiler treats this code as while(1){Infinite loop}

    printf("Event Detected\n");
    return 0;
}