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

#define SIZE 5

typedef struct stack{
    node_t *arr[SIZE];
    int top;
}stack_t;

void stack_init(stack_t *st);
int stack_is_empty(stack_t *st);
int is_full(stack_t *st);
void push(node_t *data,stack_t *st);
node_t *pop(stack_t *st);
void peek(stack_t *st);



