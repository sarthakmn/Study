#include<stdio.h>
#include"queue.h"
int main(){
    qu queue;
    init(&queue);       
    enqueue(&queue,10);
    enqueue(&queue,20);
    enqueue(&queue,30);
    peek(&queue);
    dequeue(&queue);
    peek(&queue);
    dequeue(&queue);
    peek(&queue);
    

    return 0;
}