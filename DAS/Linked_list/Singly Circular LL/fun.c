#include<stdio.h>
#include"scll.h"
#include<stdlib.h>
void init(list_t *ls){
    ls->head = NULL;
    ls->tail = NULL;
    ls->count = 0;
}
int is_empty(list_t *ls){
    return ls->head == NULL && ls->tail == NULL;
}
node_t *create(int data){
    node_t *newnode = (node_t*)malloc(sizeof(node_t));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void add_first(int data,list_t *ls){
    node_t *newnode = create(data);
    if(is_empty(ls)){
        ls->head = newnode;
        ls->count++;
        ls->tail = newnode;  
        newnode->next = ls->head; 
    }
    else{
        ls->count++;
        newnode->next = ls->head;
        ls->head = newnode; 
        ls->tail->next = ls->head;
    }   
}

void add_last(int data,list_t *ls){
    node_t *newnode = create(data);
    if(is_empty(ls)){
        ls->head = newnode;
        ls->count++;
        ls->tail = newnode;  
        newnode->next = ls->head; 
    }
    else{
        ls->count++;
        newnode->next = ls->head;
        ls->tail->next = newnode;
        ls->tail = newnode;
    }   
}

void add_pos(int data,int pos,list_t *ls){
    node_t *newnode = create(data);
    if(is_empty(ls)){
        ls->head = newnode;
        ls->count++;
        ls->tail = newnode;  
        newnode->next = ls->head; 
    }
    else{
        int num = 0 ;
        ls->count++;
        node_t *trav = ls->head;
        while(1){
            if(num == pos-1){
                newnode->next = trav->next;
                trav->next = newnode;
                break;
            }
            else{
            num++;
            trav = trav->next;
            }
        }
    } 

}

void display(list_t *ls){
    if(is_empty(ls))
        printf("List is Empty\n");
    else{
        node_t *trav = ls->head;
        printf("List :: ");
        do
        {   
            printf("%d ",trav->data);
            trav = trav->next;
        }
        while (trav != ls->head);
        printf("\n");
    }   
}

void free_ll(list_t *ls){
    if(is_empty(ls))
        printf("List is Empty\n");
    else{
        node_t *trav = ls->head;
        do
        {   
            node_t *temp = trav;
            trav = trav->next;
            free(temp);
        }
        while (trav != ls->head);
        //free(trav);
}
}

void delete_first(list_t *ls){
    if(is_empty(ls)){
        printf("List is Empty\n"); 
    }
    else{
        ls->count--;
        node_t *temp = ls->head;
        ls->head = temp->next;
        ls->tail->next = ls->head;
        free(temp);
    }   
}