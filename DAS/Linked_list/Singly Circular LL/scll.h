typedef struct node
{
    int data;
    struct node *next;
}node_t;

typedef struct list
{
    node_t *tail;
    node_t *head;
    int count;
}list_t;

void init(list_t *ls);
node_t *create(int data);
int is_empty(list_t *ls);
void add_first(int data,list_t *ls);
void add_last(int data,list_t *ls);
void add_pos(int data,int pos,list_t *ls);
void free_ll(list_t *ls);
void display(list_t *ls);