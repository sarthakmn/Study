#include"stack.h"
#include<stdio.h>

void init(stack_t *st){
    st->top = -1;
}
int is_empty(stack_t *st){
    return st->top == -1;
}
int is_full(stack_t *st){
    return st->top == SIZE-1;
}
void push(int data,stack_t *st){
    if(is_full(st))
        printf("Stack is Full\n");
    else{
        st->top++;
        st->arr[st->top] = data;
        //printf("%c Pushed\n",data);
    }
}
void pop(stack_t *st){
    if(is_empty(st)){
        return;
    }
    else{
        printf("%c ",st->arr[st->top]);
        st->top--;
    }
    pop(st);
}
char peek(stack_t *st){
    if(is_empty(st))
        printf("Stack is Empty\n");
    else if(is_full(st))
        printf("Stack is Full\n");
    else
        return st->arr[st->top];
}

int symbol(int data){
    if(data >= 97 && data <= 122) // a - z
        return 1;
    else // -43 +45 // *42 /47
        return 2;   
}




