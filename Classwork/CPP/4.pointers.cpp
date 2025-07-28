#include<iostream>
using namespace std;


void swap(int *a , int *b)
{   
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//use to store the adderess of any variable
int main(){
    int a = 10;
    int *b = &a;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"b = "<<*b<<endl;
    cout<<"b = "<<&b<<endl;
    cout<<endl;

    int **c = &b;
    cout<<"c = "<<c<<endl;
    cout<<"c = "<<*c<<endl;
    cout<<"c = "<<**c<<endl;
    cout<<"c = "<<&c<<endl;

    int a1= 20;
    cout<<"before : "<<a<<" "<<a1<<endl;
    swap(&a,&a1);
    cout<<"after : "<<a<<" "<<a1<<endl;
    
    
    
    return 0;
}



