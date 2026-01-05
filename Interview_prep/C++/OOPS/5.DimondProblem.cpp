#include <iostream>
using namespace std;

class Android{
    public:
        int Brand;
};

class Telechips : public virtual Android{          // inherit virtual base class in hybrid inheritance to avoid ambiguous error

};

class Qulcomm : public virtual Android{

};

class Forvia : public Telechips, public Qulcomm{

};

int main(void){
    Forvia fce;
    fce.Brand = 0;
    return 0;
}