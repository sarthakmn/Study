/*
std::map
Keys are stored in sorted order
Implemented as a balanced binary tree (usually a Red–Black Tree)

std::unordered_map
You want fast lookups
Order does not matter
You don’t need range queries
*/

#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int ,string> Student = {{3,"Sarthak"},{2,"satwik"},{1,"Atharv"}};

    Student.insert({0,"Greta"});
    Student.erase(2);
    for (auto it : Student){
        cout << "Roll : " << it.first << " Name : " << it.second << endl;
    }
    return 0;
}