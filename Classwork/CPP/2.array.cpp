#include<iostream>
using namespace std;

//linear data type which is use to store the data contiguosly of same data type
int main(){
    int arr[] = {10,20,30,40};
    for (int i = 0; i < 4; i++)
    {
       cout<<"arr : "<<arr[i]<<endl; 
    }
    cout<<"address arr : "<<arr<<endl; 
    cout<<endl; 

    int *p = arr;

        for (int i = 0; i < 4; i++)
    {
       //cout<<"p : "<<p[i]<<endl;       or
       //cout<<"++p : "<<*(++p)<<endl;   or
       cout<<"p : "<<*(p+i)<<endl; 
    }
    cout<<"address arr : "<<*p<<endl; 

    //2-D array is collection of 1-D arrays in contiguous memory locations.
    int arr2[3][2]={{11,22},{33,44},{55,66}};
    //or int arr2[][2]={{11,22},{33,44},{55,66}};
    cout<<arr2[2][0]<<endl; 

    int (*ptr)[2] = arr2;
    cout<<ptr[2][1]<<endl; 
    
    return 0;
}
