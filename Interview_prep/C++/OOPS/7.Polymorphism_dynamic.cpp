/*
Run-Time Polymorphism
(also called Dynamic Polymorphism)
Achieved using: Inheritance & Virtual functions & Base class pointer
*/

#include <iostream>
using namespace std;

class Telechips{
    public :
        virtual void show(void){                     // Virtual Function
            cout << "Show from Telechips" << endl;
        }
};

class Qualcomm : public Telechips{                   // Inheritance
    public :
        void show(void){
            cout << "Show from Qualcomm" << endl;
        }
};
int main(void){
    Telechips *tl = new Qualcomm();                  // Base class pointer
    tl->show();
    return 0;
}
