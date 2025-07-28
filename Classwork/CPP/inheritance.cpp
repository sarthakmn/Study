#include <iostream>

using namespace std;

class pet{
    public:
        int cost;
        string name;
};

class dog : public pet{
    private:
        int a;
        public:
            void set(int m_cost){
                cost = m_cost;
            }
            void Display(){
                cout<< "cost of dog : "<<cost<<endl;
            }
};

int main(void){
    //pet p1;
    dog d1;
    d1.set(200);
    d1.Display();
    return 0;
}