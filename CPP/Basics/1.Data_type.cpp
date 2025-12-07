#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    //bool is one byte data type
    bool a=true;
    bool b=false;
    printf("bool True value = %d\nbool False value = %d\nbool size = %ld\n",a,b,sizeof(a));

    //wchar_t is 2/4 byte data type used for international languages
    wchar_t z=L'A';
    printf("\nchar = %c\nsize of wchar = %ld\n",z,sizeof(z));

    char m = 'm';
    int l = 100;
    short q = 100;
    float o = 12.12F; // or float o = 12.12; or float o = 12.12f
    long n = 12.12;
    double p = 12.12;

    cout<<"m = "<<m<<" size m = "<<sizeof(m)<<endl;
    cout<<"m = "<<q<<" size m = "<<sizeof(q)<<endl;
    cout<<"l = "<<l<<" size l = "<<sizeof(l)<<endl;
    cout<<"o = "<<o<<" size o = "<<sizeof(o)<<endl;
    cout<<"n = "<<n<<" size n = "<<sizeof(n)<<endl;
    cout<<"p = "<<p<<" size p = "<<sizeof(p)<<endl;

    cout<<endl<<"tyepcast p = "<<int(p)<<" size p = "<<sizeof(p)<<endl;

    return 0;
}