#include<stdio.h>

#define SIZE 5

typedef struct stack{
    int arr[SIZE];
    int top;
}stack_t;

void init(stack_t *st);
int is_empty(stack_t *st);
int is_full(stack_t *st);
void push(int data,stack_t *st);
void pop(stack_t *st);
void peek(stack_t *st);


int main(){
    stack_t st;
    init(&st);

    return 0;
}

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
        printf("%d Pushed\n",data);
    }
}
void pop(stack_t *st){
    if(is_empty(st)){
        printf("Stack is Empty\n");
        return;
    }
    else{
        st->top--;
        printf("%d poped\n",st->arr[st->top]);
    }
}
void peek(stack_t *st){
    if(is_empty(st))
        printf("Stack is Empty\n");
    else if(is_full(st))
        printf("Stack is Full\n");
    else
        printf("Stack Top element : %d\n",st->arr[st->top]);
}