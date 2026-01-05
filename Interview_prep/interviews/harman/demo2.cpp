// syncronize threads with conditional variables

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

void Producer(){
    while(1){
        cout << "Producer" << endl;
    }
}
void Consumer1(){
    while(1){
        cout << "Consumer1" << endl;
        
    }
}


int main(void){
    thread T1(Producer);
    thread T2(Consumer1);

    T1.join();
    T2.join();
    return 0;
}