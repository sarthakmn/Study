#include<iostream>
using namespace std;

//fibonaci series
int fun(int num){
    if(num==1)
        return 1;
    if(num==0)
        return 0;
    // 1 1 2 3 5 8 ....
    return fun(num-2) + fun(num-1);
}

//factorial of a number 
int fac(int num){
    if(num<=1)
        return 1;
    // 4! = 4*3*2*1
    return num * fac(num-1);
}

int main(){
    int a = 4;
    cout<<"fibonaci index ["<<a<<"] : "<<fun(a)<<endl;

    cout<<"factorial of "<<a<<"! : "<<fac(a)<<endl;
    return 0;
}
