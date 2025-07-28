// odd and even numbers with different threads
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;
vector<int>odd;
vector<int>even;
mutex mxt;

void odd_even(){
    int start = 0;
    int end = 10;
    mxt.lock();
    for(int i=start;i<=end;i++){
        if(i%2 == 0){
          even.push_back(i);
        }
        else{
           odd.push_back(i); 
    }
    mxt.unlock();
    }
}

int main() {
    thread T1(odd_even);
    thread T2(odd_even);
    T1.join();
    T2.join();
    
    for(int i:odd){
        cout << i << endl;
    }
    
    for(int i:even){
        cout << i << endl;
    }
    return 0;
}