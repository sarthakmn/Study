/*
A virtual table pointer (vptr) is a hidden pointer added by the compiler to objects of classes that use virtual functions.
It helps C++ achieve runtime polymorphism.
When a base-class pointer points to a derived-class object, C++ must decide at runtime which function to call.

✔ vptr is automatically added by compiler
✔ Exists only if at least one virtual function is present
✔ Each object has one vptr (typically)
✔ vtable is shared among all objects of the same class
✔ vptr increases object size slightly


        vptr	         |          vtable
Pointer inside object	 |   Table of function addresses
One per object	         |  One per class
Points to vtable	     |  Stores virtual functions

*/

#include <iostream>
using namespace std;

class Android{
    public : 
        int version;
};

class Samsung : public Android{

};

int main(void){
    Android *Ad =  new Samsung();
    

    return 0;
}