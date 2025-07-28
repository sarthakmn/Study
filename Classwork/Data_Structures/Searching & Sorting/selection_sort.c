#include<stdio.h>

void swap(int *no1,int *no2){
    int temp =  *no1;
    *no1 = *no2;
    *no2 = temp;       
}

int main(){
    int arr[] = {11,44,33,22,66,55};
    int size = sizeof(arr)/4-1;

    for(int i=0;i<size+1;i++){
        for(int j=i+1; j<size+1;j++){
            if(arr[i]>arr[j])
            swap(&arr[i],&arr[j]);
        } 
    }       
    printf("Sorted Array : ");
    for(int i=0;i<size+1;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    return 0;
}
