#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;

typedef struct bst{
    node_t *root;
}bst_t;

void init(bst_t *bst);
node_t *create(int data);
int is_empty(bst_t *bst);
void add(int data,bst_t *bst);
void preorder(node_t *node);
void inorder(node_t *node);
void postorder(node_t *node);
void free_t(node_t *node);
int dfs(int data,bst_t *bt);

int main (){
    bst_t t1;
    init(&t1);
    add(50,&t1);
    add(30,&t1);
    add(60,&t1);
    add(40,&t1);

    printf("Preorder  : ");
    preorder(t1.root);
    printf("\n");

    printf("Inorder   : ");
    inorder(t1.root);
    printf("\n");

    printf("Postorder : ");
    postorder(t1.root);
    printf("\n");

    dfs(50,&t1);

    free_t(t1.root);

    return 0;
}

void init(bst_t *bst){
    bst->root = NULL;
}
node_t *create(int data){
    node_t *newnode = (node_t*)malloc(sizeof(node_t));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}   
int is_empty(bst_t *bst){
    return bst->root == NULL;
}
void add(int data,bst_t *bst){
    node_t *newnode = create(data);
    if(is_empty(bst))
        bst->root = newnode;
    else{
        node_t *trav = bst->root;
        while(1){
        if(trav->data > data){
            if(trav->left == NULL){
                trav->left = newnode;
                break;
            }
            trav = trav->left;
        }
        else{
            if(trav->right == NULL){
                trav->right = newnode;
                break;
            }
            trav = trav->right;
        }
        }
    }
}
void preorder(node_t *node){
    if(node == NULL){
        return;
    }
    printf(" %d",node->data);
    preorder(node->left);
    preorder(node->right);
}
void inorder(node_t *node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    printf(" %d",node->data);
    inorder(node->right);
}
void postorder(node_t *node){
    if(node == NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf(" %d",node->data);   
}
void free_t(node_t *node){


        if(node == NULL){
        return;
    }
    free_t(node->left);
    free_t(node->right);
    free(node);
}
int dfs(int data,bst_t *bt){
    printf("\n");
    node_t *trav = bt->root;
    while(trav != NULL){
        if(trav->data == data){
            printf("target found : %d \n",data);
            return 1;
        }
        if(is_empty(bt)){
            printf("tree is empty\n");
            return 0;
        }
        if(trav->data > data) {
            trav = trav->left;
        }
        else {
            trav = trav->right;
        }
    }
    printf("Target not found : %d \n",data);
    return 2;
}
