#include<iostream>
#include<thread>
using namespace std;


class singletone{
    singletone(){
        cout << "Single instance" << endl;
    }
    public:
    static singletone *sptr;
    static singletone* object(){
        if(sptr != nullptr)
        // mutex lock
            sptr = new singletone;
        // mutex unlock
        return sptr;
    }
};
static singletone *sptr = nullptr;

int main(void){
    singletone::object();
    return 0;
}