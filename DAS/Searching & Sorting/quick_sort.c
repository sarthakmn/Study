#include<stdio.h>
#include<stdlib.h>

void swap(int *no1,int *no2){
    int temp =  *no1;
    *no1 = *no2;
    *no2 = temp;       
}

int main(){

int arr[] = {66,33,99,11,77,22,55,66,88};
int size = sizeof(arr)/4-1;
int pivot = arr[0];
int i = 0; int j = size;
int left,right;
int count=0;
while(count<6){    
    for(;i<size;i++){
        if(pivot<arr[i]){
            break;      
        }
    } 
    for(;j>0;j--){
        if(pivot>=arr[j]){
            break;
        }
    }
    
    swap(&arr[i],&arr[j]);
    if(i>j){
        swap(&arr[count],&arr[j]);
        count++;
        pivot = arr[count];

        printf("Sorted Array : ");
        for(int i=0;i<size+1;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    }
    
}
    printf("Sorted Array : ");
    for(int i=0;i<size+1;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    return 0;
}
