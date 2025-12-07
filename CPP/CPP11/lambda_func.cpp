#include <stdio.h>
#include<iostream>

int main(){ 
    auto num = [](int a){std::cout<<"Printed num : "<<a<<std::endl;};
    num(10);
    return 0;
}