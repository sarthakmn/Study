// virtual function , table vpointer
#include <iostream>
using namespace std;

class base{
    public:
        virtual void show(void){
            cout << "Show from the base class" << endl;
        } 
};

class derived:public base{
    public:
    void show(void) override {
        cout << "Show from the derived class" << endl;
    }
};

int main() {
    base b1;
    derived d1;
    b1.show();
    d1.show();
    return 0;
}