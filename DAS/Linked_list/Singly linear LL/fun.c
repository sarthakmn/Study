#include"sll.h"
#include<stdio.h>
#include<stdlib.h>

node_t *head;

void init(){
    head = NULL;
}

int is_empty(){
    return head == NULL;
}

node_t *create(int data){
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}


void free_ll(){
    if(is_empty())
        printf("List is Empty\n");
    else{
    node_t *trav = head;
    while (trav != NULL)
    {   node_t *temp = trav;
        trav = trav->next;
        free(temp);
    }
}
}

void add_first(int data){
    node_t *newnode = create(data);
    if(is_empty())
        head = newnode;
    else{
        newnode->next = head;
        head = newnode;
    }
}

void add_pos(int data,int pos){
    node_t *newnode = create(data);
    if(is_empty())
        head= newnode;
    else if(pos == 1){
        free(newnode);
        add_first(data);
        return;
    }
    else{
    int count = 0;
    node_t *trav = head;
    node_t *temp;
    while (1)
    {   temp = trav;
        count++;
        if(count == pos-1){
            trav = trav->next;
            break;
        }
        trav = trav->next;
    }
    newnode->next = trav;
    temp->next = newnode;
    }
}

void add_last(int data){
    node_t *newnode = create(data);
    if(is_empty())
        head= newnode;
    else{
    node_t *trav = head;
    while (trav->next != NULL)
    {   
        trav = trav->next;
    }
    trav->next = newnode;
    }
}

void delete_first(){
    if(is_empty())
        printf("List is Empty\n");
    else{
        node_t *trav = head;
        trav = trav->next;
        free(head);
        head = trav;

    }
}

void delete_last(){
    if(is_empty()){
        printf("List is empty\n");
    }
    else{
        node_t *trav = head;
       
        while(trav != NULL){
            if(trav->next->next == NULL)
                trav->next = NULL;
            trav = trav->next;

        }
        free(trav);
    }
}

void delete_pos(int pos){
if(is_empty())
        printf("List is empty\n");
    else if(pos == 1){
        delete_first();
        return;
    }
    else{
    int count = 0;
    node_t *trav = head;
    node_t *temp;
    while (1)
    {   
        count++;
        if(count == pos-1){
            temp = trav;
            trav = trav->next;
            break;
        }        
        trav = trav->next;
    }
    temp->next = trav->next;
    free(trav);
    }
}


void display(){
    node_t *trav = head;
    printf("List : ");
    if(is_empty())
        printf("List is Empty\n");
    else{
    while (trav != NULL)
    {   
        printf("%d ",trav->data);
        trav =trav->next;
    }
    printf("\n");
}
}



