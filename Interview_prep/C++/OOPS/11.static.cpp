/*
Static variable: A class-level variable shared by all objects.
✔ Declared inside the class
✔ Defined outside the class
✔ Shared by all objects
✔ Initialized only once

Static function: A function that can access only static members of a class.

*/

#include <iostream>
using namespace std;

class Android{
    static int version;
    public :
        static void show(void){
            cout << "Version : " << version << endl;
        }
};

int Android::version = 10;

int main(void){
    Android::show();          // no object needed
    return 0;
}