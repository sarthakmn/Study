#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int *res = &a;
    cout<<"Value of res : "<<*res<<"\n"; //ponter

    int a1 = 20;
    int &res1 = a1;
    cout<<"Value of res : "<<res1<<"\n"; //referance

    return 0;
}