#include<iostream>
using namespace std;
#pragma pack(1)

//structure and union are linear data type which is use to store the data contiguosly of different data type
// enum used to make the code readable and it assign the value to variables like index
struct str{
    int a = 20;  //4
    char b = 's'; //1 
    int age : 7;        // bit fields use to assign value in effecient way to save memory
    //size = 4+1+1 = 6  //but in c compiler add slack bytes in divisible of 4 hence size = 8 
                        //to turn off this feature use #pragma pack(1)
};

union uni{    //All members of union share same memory space i.e. modification of an member can affect others too.
    int c  ;  //4   
    char d ; //1 
    //size = 4
};

// enum en{        //cannot able to decalre in global space
//     red,
//     blue,
//     black,
// };

int main(){
    str st; 
    cout<<"structure member : "<<st.a<<"  "<<st.b<<endl;
    cout<<"structure size : "<<sizeof(st)<<endl;
    
    uni u;
    u.c = 40 ,u.d = 'a';     // so here u.c init first then u.d will replace the 4 byte
                              // memory with his value hence value of u.c gets overwrite 
    cout<<"union member     : "<<u.c<<"  "<<u.d<<endl;

    enum en{         
    red,blue,black,
    };
    cout<<"enum member     : "<<red<<"  "<<blue<<"  "<<black<<endl;
    return 0;
}
