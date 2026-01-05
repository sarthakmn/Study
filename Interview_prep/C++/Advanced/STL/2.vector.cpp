// vector is a dynamic array , allocated memory at run time at heap section

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<int> Table1(5,10);        // 5 elements, all = 10 default set to 0
    vector<int> Table = {10,20,30};

    // Adding elements
    Table.push_back(40);
    Table.insert(Table.begin() + 1, 99);

    // Access element
    cout << "At : " << Table.at(2) << endl;
    cout << "front : " << Table.front() << endl;
    cout << "back : " << Table.back() << endl;

    for (int i : Table){
        cout << "Vector : " << i << endl;
    }

    // remove elements
    //Table.pop_back();        // remove last element
    //Table.clear();           // remove all elements
    Table.erase(Table.begin() + 1);  // removes element at index 1

    Table.size();      // number of elements 
    Table.capacity();  // allocated memory
    return 0;
}