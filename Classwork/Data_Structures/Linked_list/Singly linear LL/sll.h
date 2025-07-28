#ifndef __SLL_H
#define __SLL_H


typedef struct node
{
    int data;
    struct node *next;
}node_t;

void init();
node_t *create(int data);
int is_empty();
void free_ll();
void add_first(int data);
void add_pos(int data,int pos);
void add_last(int data);
void delete_first();
void delete_last();
void delete_pos(int pos);
void display();
#endif