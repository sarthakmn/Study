#include <iostream>
#include <string>

using namespace std;

int main(void){
    
    char data[] = {0,1,1,0,0};

    for(int i=0;i<=sizeof(data);i++){
        cout << "data : " << data[i] << endl;
    }
    return 0;
}