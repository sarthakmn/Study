#include<iostream>
#include <functional>
using namespace std::placeholders;
using namespace std;

void fun(int a,int b){
    cout<<"sub = "<<a-b<<endl;
}

int main(void) {
    auto c = bind(fun,_1,_2);
    c(4,2);

    auto e = bind(fun,_2,_1);
    e(4,2);

    return 0;
}
