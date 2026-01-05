// Double Ended Queue Fast insertion/removal at both front and back
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void){
    deque <int> Buffer = {10,20,30};
    Buffer.push_back(50);
    Buffer.pop_back();
    Buffer.insert(Buffer.begin()+2,25);
    Buffer.erase(Buffer.end());
    
    for(auto i : Buffer){
        cout << "Buffer : " << i << endl;
    }

    return 0;
}