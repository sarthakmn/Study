// map the number counts of cities in the given vector
//std::vector<std::string> cities = {
//    "Paris", "London", "New York", "Paris", "London", "Paris"
//};

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int count;
    map<string,int> mp;
    vector<string> cities = {
   "Paris", "London", "New York", "Paris", "London", "Paris"
    };
    for(string i : cities){
        count = 0;
        for(auto j : cities){
            if(i==j){
                count++;
            }
        }
        mp.insert({i,count});
    }
    for(auto k : mp){
        cout << "city = " << k.first << ", count = " << k.second << endl;
    }
    return 0;
} 