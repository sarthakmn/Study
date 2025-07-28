#include<stdio.h>


int main(){
    int arr[] = {11,33,44,66,55,22};
    int size = sizeof(arr)/4;
    int target = 55;
    int flag =0;
    printf("size = %d\n",size);
    for(int i =0 ; i<size ; i++){
        if (arr[i]==target){
            printf("Matched\n");
            printf("arr[%d] = %d\n",i,arr[i]); 
            flag++;
        }
    }
    if(flag==0){
        printf("Target Not Found\n");
    }
    return 0;
}