#include<iostream>
using namespace std;

namespace a{         //if we want to assign as simillar names in code
    int shubham = 10;
}

namespace b{         
    int shubham = 20;
}

int main()
{
    cout<<"value of shubham a = "<<a::shubham<<"\n";
    cout<<"value of shubham b = "<<b::shubham<<"\n";
    return 0;
}