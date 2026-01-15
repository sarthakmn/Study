#include <memory>
#include <iostream>
using namespace std;

int main(void){
    unique_ptr<int> uptr1 = make_unique<int>(10);     // memory automatically freed
    //unique_ptr<int> uptr2 = uptr1;                  // not allowed
    unique_ptr<int> uptr2 = move(uptr1);              // allowed to move ownership
    
    shared_ptr<int> sptr1 = make_shared<int>(5);
    cout << "Referance count : " << sptr1.use_count() << endl;

    shared_ptr<int> sptr2 = sptr1;                    // multiple owners
    cout << "Referance count : " << sptr1 << endl;

    return 0;
}
