#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void add_node_front(int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void add_node_last(int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *trav = head;
    newnode->data = data;
    newnode->next = NULL;
    while(trav->next != NULL){
        trav = trav->next; 
    }
    trav->next = newnode;

}

void traverse(void){
    struct Node *trav = head;
    while(trav != NULL){
        printf("Data : %d\n",trav->data);
        trav= trav->next; 
    }
}

int main() {
    add_node_front(10);
    add_node_front(70);
    add_node_last(100);
    add_node_front(30);
    add_node_front(50);
    traverse();
    return 0;
}