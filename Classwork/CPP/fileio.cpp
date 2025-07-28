#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    ofstream fout;
    char *name = "sarthak";
    fout.open("sample.txt");
    fout.write(name,sizeof(name));
    fout.close();
    return 0;   
}