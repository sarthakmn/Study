#include<stdio.h>
#include"scll.h"

int main(){
    list_t ls;
    init(&ls);

    add_first(10,&ls);
    add_first(20,&ls);
    add_first(30,&ls);
    add_first(40,&ls);
    add_last(5,&ls);
    add_pos(25,3,&ls);
    display(&ls);
    free_ll(&ls);
    return 0;
}