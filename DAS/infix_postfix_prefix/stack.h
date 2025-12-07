#define SIZE 5

typedef struct stack{
    int arr[SIZE];
    int top;
}stack_t;

void init(stack_t *st);
int is_empty(stack_t *st);
int is_full(stack_t *st);
void push(int data,stack_t *st);
void pop(stack_t *st);
char peek(stack_t *st);
int symbol(int data);