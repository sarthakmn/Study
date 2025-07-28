// input : arr[] = {1,2,3,4,5,6,7} k=3
// output : arr[] = {4,5,6,7,1,2,3}

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int k=3; 
    int flag = 0;
    int tmp[7];
    for(int i=0;i<sizeof(arr)/4;i++){
        if(i == sizeof(arr)/4-k){
            flag = (flag+k)-6;
            
        }
        else{
            tmp[(flag+k)-6] = arr[i];
        }
        // 5+2 = 7 = 6 0+2 = 2-6 = -4
        cout << flag << endl;
        flag++;
    }
    
    for(int i=0;i<sizeof(arr)/4;i++){
        cout << tmp[i];
    }
    return 0;
}