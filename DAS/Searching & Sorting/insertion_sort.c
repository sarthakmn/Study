#include<stdio.h>


int main(){
    int arr[] = {66,44,33,22,11};
    int size = sizeof(arr)/4;

    int k=0;
    while (k<size)
    {
    for(int i=1;i < size;i++){
        int temp = arr[i];
        int j;
        for(j = i-1;j >= 0 && arr[j]>arr[i];j--){
        
                arr[j+1] = arr[j];
               
   
                } arr[j+1] = temp;
        }k++;
    }
    
    printf("Sorted Array : ");
    for(int i=0;i<size;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    return 0;
}
