#include<stdio.h>
#include<stdlib.h>
#include"sll.h"

int main(){
    init();
    add_last(20);
    add_last(30);
    add_last(40);
    add_first(10);
    add_pos(5,1);
    delete_first();
    delete_last();
    delete_pos(2);
    display();
    free_ll();
    return 0;
}