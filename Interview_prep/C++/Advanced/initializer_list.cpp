#include<iostream>
#include<initializer_list>
using namespace std;

void addition(initializer_list<int> add){
    int total =0;
    initializer_list<int> ::iterator it;

    for(it=add.begin();it!=add.end();it++){
        total += *it;
    }
    cout<<"Addition : "<<total<<endl;
}
int main(void) {
    addition({10,20,30});
    return 0;
}