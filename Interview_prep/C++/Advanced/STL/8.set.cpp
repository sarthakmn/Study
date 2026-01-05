/*
In C++, std::set and std::unordered_set store unique elements, but they differ in ordering, performance, and internal implementation.
*/
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main(void){
    set<int> Version = {10,40,5,30};
    Version.insert(20);

    unordered_set<int> Ver = {10,40,5,30};
    Ver.insert(20);

    for(auto it : Version){
        cout << "Set : " << it << endl;
    }
    return 0;
}