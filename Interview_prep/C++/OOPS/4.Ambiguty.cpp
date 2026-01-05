#include <iostream>
using namespace std;

class Android{
    public:
        void show(){
            cout << "Class Android" << endl;
        }
};

class Qualcomm{
    public:
        void show(){
            cout << "Class Qualcomm" << endl;
        }
};

class Samsung : public Android, public Qualcomm{

};


int main(void){
    Samsung sm;
    sm.Qualcomm::show();    // To avoid Ambiguity
    return 0;
}