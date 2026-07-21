#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct queue {
    element data;
    struct queue *link;
} Queue;

struct queue *front, *rear;

void init()
{
    front = NULL;
    rear = NULL;
}

int is_empty()
{
    if (front == NULL) return 1;
    else return 0;
}

void enqueue(element item)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = item;
    q->link = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = q;
    } else {
        rear->link= q;
    }
    rear = q;
}

element dequeue()
{
    element item;

    if (is_empty() == 1) {
        printf("queue empty\n");
        return -1;
    } else {
        Queue *tmp = front;
        item = tmp->data;
        front = front->link;
        free(tmp);
        return item;
    }
}

void print_queue()
{
    if (is_empty() == 1) {
        printf("queue empty\n");
    } else {
        Queue *ptr = front;
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->link;
        }
        printf("NULL\n");
    }
}

void free_all()
{
    if (is_empty() == 1)
        return ;
    while (front != NULL) {
        Queue *ptr = front;
        front = front->link;
        free(ptr);
    }
}

int main()
{
    element item;
    init();
    enqueue(10); print_queue();
    enqueue(20); print_queue();
    enqueue(30); print_queue();
    
    item = dequeue();
    printf("deleted : %d\n", item);
    print_queue();

    free_all();
}