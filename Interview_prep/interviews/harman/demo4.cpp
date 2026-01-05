#include <iostream>
#include<stdio.h>
using namespace std;
#define SIZE 5

void show(int *arr){
    for (int i = 0; i < SIZE; i++)
    {
        printf("Arr[%d] = %d\n",i,arr[i]);
    }
}

int main(void) {
    int arr[SIZE] = {10,20,30,40,50};         // shift array by 3
    int temp[SIZE];
    int k = 4;
    int flag = 0; int i = 0;

    while(flag <= SIZE-1){

        if(i == SIZE-k){
            i = 0;
            k = 0;
        }
        temp[i+k] = arr[flag];
        flag++;
        i++;
    }
    show(temp);
    return 0;
}
