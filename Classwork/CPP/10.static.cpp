#include<iostream>
using namespace std;

class complex
{
    private:
        int real;
        int imag;
        static int count;        //saving the count value for each object 

    public:
    complex(int r=0,int i=0)
    {
        count++;
        this->real=r;
        this->imag=i;
    }
    void printComplexNumber()
    {
        cout<<"\ncomplex number="<<real<<"+j"<<imag;
    }  
    static void printCount()
    {
        cout<<"count="<<count<<"\naddress of count="<<&count<<"\n";
    } 
};//end of class
int complex::count=0;
int main()
{
    complex c1(11,22);
    complex c2(1,2);
    complex c3(1,2);

    complex::printCount();

    return 0;
}