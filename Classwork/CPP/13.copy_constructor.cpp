#include<iostream>
using namespace std;

class myclass{
    int x;

    public:
    myclass(){}

    myclass(int a){
        x = a;
    }

    myclass(myclass &a){   // copy constructor 
        x = a.x;
        cout<<"My copy constructor\n";
    }

    void display(){
        cout<<"value of x = "<<x<<"\n";
    }

    ~myclass(){
        cout<<"Destructor Called\n";
    }
};

int main(){


    myclass m(10),o; // no copy constructor called
    m.display();

    //copy constructor used to create copy of member  of a other object of same class 
    myclass n(m);    // my copy constructor called / If created or default called
    n.display();

    o = m;          // default copy constructor 
    o.display();

    myclass i = m; // my copy constructor called  / If created or default called
    i.display();

    return 0;
}