/*
Object slicing happens when a derived class object is copied into a base class object by value.
Because C++ copies objects by value.
Base ad = Qm; → copy constructor of Base
Base does not know about Derived members
So extra data is lost
SOLUTION : Pointers/references prevent slicing, but virtual enables polymorphism.
*/

#include <iostream>
using namespace std;

class Android {
    public : 
        virtual void show(){
            cout << "Andorid show()" << endl;
        }

};

class Qualcomm : public Android{
    public :
        void show(){
            cout << "Qualcomm show()" << endl;
        }
};

int main (void){
    Qualcomm Qm;
    Android ad = Qm;
    ad.show();                           // object slicing happend

    Android *adn = new Qualcomm();
    adn->show();
    return 0;
}