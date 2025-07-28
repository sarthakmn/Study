//std::vector<std::string> cities = {
//    "Paris", "London", "New York", "Paris", "London", "Paris"
//};
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    string input = "Paris";
    int count;
    map<string,int> mp;
    vector<string> cities = {
   "Paris", "London", "New York", "Paris", "London", "Paris"
    };
    for(string i : cities){
        count = 0;
        for(string j : cities){
            if(i==j){
                count++;
                mp[i] = ; // string = Paris 
                          // int = count
            }
        }
    }
    cout << "Count of " << input << " is " << count << endl;
    return 0;
} 