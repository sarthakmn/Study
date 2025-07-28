#include<iostream>
using namespace std;

class complex{
    int i;
    int r;

    public:
    //complex():i(0),r(0){  }

    void My_take(){
        cout<<"Enter Number i,r: ";
        cin>>i>>r;
    }
    void My_print(){
        cout<<"Enter Number i,r: "<<i<<","<<r<<"\n";
    }
    void edit_i(int i){
        this->i = i;
    }
    void edit_j(int r){
        this->r = r;
    }
    ~complex(){
        cout<<"Destructor is called\n";
    }
 };

int main(){
    complex cp;
    cp.My_take();
    cp.My_print();
    cp.edit_i(20);
    cp.My_print();
    return 0;
}