#include <iostream>
#include <functional>

using namespace std;

int ADD (int A, int B){
    return A+B;
}

int main(void){
    function<int(int,int)> add = ADD;
    ADD(10,20);
    return 0;
}