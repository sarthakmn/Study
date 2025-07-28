#include<iostream>
using namespace std;

class time{
    int a=0;
    int const b=0;
    int mutable c=0;

    public:
    void print() const{
        c=10;             // mutable is to modifty data in constant member fun()
        a = 30;           // not modificable in const fun()
        b = 20;           // not modificable becoz it is const
    }
};

int main(){

    return 0;
}