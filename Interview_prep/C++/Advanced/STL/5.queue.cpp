// FIFO – First In, First Out

#include <iostream>
#include <queue>

using namespace std;

int main(void){
    queue <int> buffer;

    buffer.push(10);
    buffer.push(20);
    buffer.push(30);
    buffer.push(40);

    cout << "Queue : ";
    while (!buffer.empty()) {
        std::cout << buffer.front() << " ";
        buffer.pop();
    }
    
    std::priority_queue<int> pq;    // The largest element comes out first (by default)

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);

    cout << endl <<"Priority Queue : ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}