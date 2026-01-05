/*
An abstract class is a class that cannot be instantiated (object cannot be created).
It is used as a base class and contains at least one pure virtual function.
*/
#include <iostream>
using namespace std;

class Android{
    public :
        Android(){cout << "Android Constructor" << endl;}
        virtual ~Android(){cout << "Android Destructor" << endl;}      // Virtual Destructor defined for safe cleanup of derived class
                                                                       // If removed then ~Telechips() will not get called leading to memory leakage

        virtual void show(void) = 0;
};

class Telechips : public Android{
    public : 
        Telechips(){cout << "Telechips Constructor" << endl;}
        ~Telechips(){cout << "Telechips Destructor" << endl;}

        void show(void) override{
            cout << "Telechips show() " << endl;
        }
};
int main(void){
    Android *ad = new Telechips();
    ad->show();
    
    delete(ad);
    return 0;
}


