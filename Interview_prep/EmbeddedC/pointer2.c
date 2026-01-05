#include <stdio.h>

void Add(int Num1,int Num2){
    printf("Addition : %d\n",Num1+Num2);
}

void buttonPressed(void) {
    printf("Button was pressed\n");  
}
void registerCallback(void(*cb)(void)){
    cb();
}

int main(void){
    int *ptr = NULL;
    int array[] = {10,20,30};
    ptr = array;

    //printf("Pre Increment : %d\n",*++ptr);      // Increments the pointer first
    //printf("Post Increment : %d\n",*ptr++);     // Use the Currunt value and then Increment the pointer

    int **ptr2 = &ptr;
    printf("Double Pointer : %d\n",*(*ptr2+1));   // Double Pointer stores address of pointer

    // Function pointer
    void (*fptr)(int,int);
    fptr = Add;
    fptr(10,30);

    // A callback is a function passed as an argument to another function and executed later using a function pointer.
    registerCallback(buttonPressed);
    
    return 0;
}