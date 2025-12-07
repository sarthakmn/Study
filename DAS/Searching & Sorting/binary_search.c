#include<stdio.h>


int main(){
    int arr[] = {11,22,33,44,55,66};
    int size = sizeof(arr)/4-1;
    int target = 66;
    int flag =0;
    int left = 0;
    int right = size;
    int mid;    

    for(int i =0 ; i<size+1 ; i++){
        mid = (left+right)/2;

        if(arr[mid]>target){
            left = 0;
            right = mid-1;
        }    
        else{
            left = size;
            right = mid+1; 
        }
        if(arr[mid]==target){
            flag++;
            printf("Target matched at arr[%d] location\n",mid);
            break;
        }
    }
    if(flag==0){
        printf("Target Not Found\n");
    }
    return 0;
}