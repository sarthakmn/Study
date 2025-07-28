#include<stdio.h>
#include"queue.h"
int main(){
    qu q;
    int choice;
    init(&q);       
    do
    {
        printf("0. Exit\n1. enqueue\n2. dequeue\n3. peek\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* enqueue */
            if(is_full(&q))
                printf("queue is full!!!\n");
            else
            {
                int data;
                printf("Enter data : ");
                scanf("%d", &data);

                enqueue(&q, data);
            }                
            break;

        case 2:
            /* dequeue */
            dequeue(&q);
            break;

        case 3:
            /* peek */
            peek(&q);
            break;
        
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}