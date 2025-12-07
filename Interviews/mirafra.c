// prime numbers in 1-10
// add node in doubly linkedlist
// second biggest element in array
#include <stdio.h>

int main() {
    // Write C code here
    int arr[] = {7,100,50,35,20,300};
    int biggest=0,second_biggest=0;
    
    for(int i=0;i<sizeof(arr)/4;i++){
        if(arr[i]>biggest){
            biggest = arr[i];
        }
    }
    for(int i=0;i<sizeof(arr)/4;i++){
        if(arr[i]>second_biggest && arr[i] != biggest){
            second_biggest = arr[i];
        }
    }
    printf("\nBiggest : %d",biggest);
    printf("\nSecond Biggest : %d",second_biggest);
    return 0;
}