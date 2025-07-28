#include <iostream>
#include <vector>

int main(void){
    std::vector <int> array = {10,20,30,40};
    array.insert(array.begin()+1,15);
    array.push_back(70);
    array.pop_back();
    array.reserve(array.size());
    for (int i = 0; i<array.size();i++){   
        printf("List : %d\n",array[i]);
    }

    return 0;
}