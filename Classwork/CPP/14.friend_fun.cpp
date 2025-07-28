#include<iostream>
using namespace std;

class myclass{
    int x;

    public:
    friend int fun(int a);              //friend function declare in member fun() 
    void display(){
        cout<<"value of x = "<<x<<"\n";
    }

};

int fun(int a){
    myclass m;
    m.x = a;
    m.display();
    return a;
}

int main(){


    fun(20);    //friend fun is to make friend to user defined fun() with class

    return 0;
}