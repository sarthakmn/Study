#define SIZE 5

typedef struct queue{
    int arr[SIZE];
    int front,rear;
}qu;

void init(qu *queue);
int is_empty(qu *queue);
int is_full(qu *queue);
void enqueue(qu *queue,int data);
void dequeue(qu *queue);
int peek(qu *queue);