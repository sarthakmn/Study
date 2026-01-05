#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    vector<int> Table(5);
    Table = {50,30,4,80,20};

    Table.insert(Table.begin(),10);

    sort(Table.begin(),Table.end());
    
    auto it  = find(Table.begin(),Table.end(),20);
    cout << "Find : " << (it != Table.end()) << endl;

    for(auto i : Table){
        cout << "Vector : " << i << endl;
    }

    return 0;
}