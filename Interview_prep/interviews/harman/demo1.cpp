// Thread safe singleton design pattern

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
mutex mxt;

class singletone{
    static singletone *sptr;
    singletone(){
        cout << "Single instance" << endl;
    }
    public:
    static singletone* object(){
        if(sptr == nullptr){
            mxt.lock();
            sptr = new singletone;
            mxt.unlock();
        }
        return sptr;
    }
};
singletone* singletone::sptr = nullptr;

int main(void){
    singletone *obj1 = singletone::object();
    singletone *obj2 = singletone::object();

    cout << "OBJ 1 = " << &obj1 << "OBJ 2 = " << &obj2 << endl;
    return 0;
}