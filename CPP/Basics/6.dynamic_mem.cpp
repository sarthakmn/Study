#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    //This memory is allocated at runtime on Hvaleap section of process.
    int * const res = (int*)malloc(4);    //C intiger malloc
    *res = 9;
    cout<<"res = "<<*res<<"\n";
    free(res);

    int * res1 = (int*)calloc(2,4);            //C array[5] calloc
    for(int i=0;i<5;i++){
        res1[i] = i+10;
        cout<<"res1 = "<<res1[i]<<"\n";
    } 
    res1 = (int*)realloc(res1,20);             //C realloc  
        for(int i=0;i<5;i++){
        res1[i] = i+100;
        cout<<"res1.1 = "<<res1[i]<<"\n";
    }     
    free(res1);

    res1 = NULL;  //to avoid dangling pointer 


    int *res2=new int;             //C++ intiger malloc
    *res2 = 15;
    cout<<"res2 = "<<*res1<<"\n";
    delete(res1);

    int *res3 = new int[5];        //C++ array[5] malloc
    for(int i=0;i<5;i++){
        res3[i] = i+16;
        cout<<"res3 = "<<res3[i]<<"\n";
    }
    delete[](res3);

    return 0;
}