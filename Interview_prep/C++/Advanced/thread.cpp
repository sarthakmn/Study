#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

mutex mxt;
int count = 0;

void logger1(void){
        while(1){
            {
            lock_guard<mutex> lock(mxt);
            count++;
            cout << "Logger1 : " << count << endl;
            }
        sleep(1);
    }
}

void logger2(void){
    while(1){
        {
        lock_guard<mutex> lock(mxt);
        count--;
        cout << "Logger2 : " << count << endl;
        }
        sleep(1);
    }
}

int main(void){
    thread t1(logger1);
    thread t2(logger2);

    t1.join();
    t2.join();
    return 0;
}