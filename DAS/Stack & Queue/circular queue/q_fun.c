#include"queue.h"
#include<stdio.h>

void init(qu *queue){
    queue->front = queue->rear = -1;
}

int is_empty(qu *queue){
    return queue->rear == queue->front && queue->rear == -1 || (queue->front == queue->rear != -1);
}

int is_full(qu *queue){
   return SIZE == queue->rear - queue->front || (queue->rear - queue->front == 0 && queue->rear != -1);
}

void enqueue(qu *queue,int data){
    if(is_full(queue)){
        printf("Queue is Full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear]=data;

}

void dequeue(qu *queue){
    if(is_empty(queue)){
        printf("Queue is empty\n");
        return;
    }
    queue->front++;
}

int peek(qu *queue){
    return queue->arr[queue->front+1];
}