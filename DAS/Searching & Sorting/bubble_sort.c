#include<stdio.h>

void swap(int *no1,int *no2){
    int temp =  *no1;
    *no1 = *no2;
    *no2 = temp;       
}

int main(){
    int arr[] = {66,55,44,33,22,11};
    int size = sizeof(arr)/4-1;

    for(int i=0;i<size+1;i++){
        for(int j=0;j<size+2;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
    }
    }      
    printf("Sorted Array : ");
    for(int i=0;i<size+1;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    return 0;
}
