/*
Short, local logic fast → lambda
Complex, reusable logic slow → function
*/

#include <iostream>
using namespace std;

int main(void){
    int x = 10;
    auto lamba = [&x](auto Num1) -> int{          // "&x" is parameter "-> int" is return type
        return Num1 + x;
    };

    cout << lamba(20);
    return 0;
}