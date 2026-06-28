#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next;
    struct Node *prev;
    int data;
}node_t;

struct Node *head = NULL;

void add_node_first(int data){
    node_t *newnode = (node_t*)malloc(sizeof(node_t));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void add_node_last(int data){
    node_t *newnode = (node_t*)malloc(sizeof(node_t));
    node_t *trav = head;

    while(trav->next != NULL){
        trav = trav;
    }
    newnode->prev = trav;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}
void traverse(void){
    node_t *trav = head;
    while(trav != NULL){
        printf("Data : %d\n",trav->data);
        trav = trav->next;
    }
}

int main(void){
    add_node_first(10);
    add_node_first(80);
    add_node_first(40);
    add_node_last(90);
    add_node_first(20);
    traverse();
    return 0;
}