#include <iostream>

using namespace std;

template <typename I, typename... F>
I add(I Num1, F... Num2) {
    return (Num1 + ... + Num2);
}

template <typename A>
class Add{
    A Number1;
    A Number2;
    A Addition;
    public :
        Add(A Number1,A Number2){
            this->Number1 = Number1;
            this->Number2 = Number2;
        }
        void add(void){
            Addition = Number1+Number2;
        }
        void show(void){
            cout << "Addition : " << Addition << endl;
        }
};

int main(void){
    cout << add<int>(10,11.9) << endl;

    Add A(20,30);
    A.add();
    A.show();
    return 0;
}