#include"queue.h"
#include<stdio.h>

void init(qu *queue){
    queue->front = queue->rear = -1;
}

int is_empty(qu *queue){
    return queue->front == queue->rear;
}

int is_full(qu *queue){
    return queue->rear == SIZE-1;
}

void enqueue(qu *queue,int data){
    queue->rear++;
    queue->arr[queue->rear] = data;
}

void dequeue(qu *queue){
    queue->front++;
}

int peek(qu *queue){
    printf("peeked element : %d\n",queue->arr[queue->front+1]);
    return queue->front+1;
}