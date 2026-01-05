/*
list : is Doubly Linked List
forward_list : Singly Linked List
Use vector by default
Use list / forward_list only when you need fast insert/remove in the middle
*/

#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

int main(void){
    list<int> ls = {10,80,30,40};

    ls.push_back(90);
    ls.pop_back();
    ls.remove(40);

    for(int i : ls){
        cout << i << " ";
    }

    forward_list<int> fls = {100,800,300,400};
    fls.push_front(000);                         // for singly linked push_back & pop_back is not possible as back pointer is not present

    return 0;
}
