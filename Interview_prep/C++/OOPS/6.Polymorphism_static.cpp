/*
Compile-Time Polymorphism
(also called Static Polymorphism)
Achieved using:
1. Function Overloading
2. Operator Overloading
*/
#include <iostream>
using namespace std;

class Base{
    int Number1;
    int Number2;
    public:
        Base(int Num1,int Num2):Number1(Num1),Number2(Num2){};

        void show(void){}
        void show(int a){}   // function overloading

        Base operator + (Base obj){               // operator overloadng
            obj.Number1 = Number1 + obj.Number1; 
            obj.Number2 = Number2 + obj.Number2; 
            return obj;
        }

        bool operator == (Base obj){
            return ((obj.Number1 == Number1 && obj.Number2 == Number2));
        }

        void print(void){
            cout << "Number1 : " << Number1 << " Number2 : " << Number2 << endl;
        }
};

int main(void){
    Base B1(10,20);
    Base B2(40,30);

    Base B3 = B1+B2;
    B3.print();

    Base B4(50,60);
    Base B5(50,60);
    bool isEqual = B4 == B5;
    
    if(isEqual){
        cout << "Is Equal" << endl;
    }

    return 0;
}