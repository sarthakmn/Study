#include <iostream>
using namespace std;

class Android{
    int version;
    public : 
        Android(int ver):version(ver){}

        friend void show(Android an);                    // friend function declare in class
        friend class Qualcomm;                           // friend class declare in class
};

void show(Android an){
    cout << "Version : " << an.version << endl;           // friend function can access private protected variables of class
}

class Qualcomm{
    public:
        void Qshow(Android ad){
            cout << "Version : " << ad.version << endl;   // friend class can access all private protected var of other class
        }
};

int main(void) {
    Android ad(90.9);
    show(ad);

    Qualcomm Qm;
    Qm.Qshow(ad);

    return 0;
}