#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct queue {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} Queue;

void init(Queue *p)
{
    p->front = -1;
    p->rear = -1;
}

int is_full(Queue *p)
{
    if (p->rear == MAX_QUEUE_SIZE -1) {
        printf("Queue full\n");
        return 1;
    } else return 0;
}
int is_empty(Queue *p)
{
    if (p->rear == -1) {
        printf("Queue empty\n");
        return 1;
    } else return 0;
}

void enqueue(Queue *p, element item)
{
    if (is_full(p) == 1) {
        printf("queue full\n");
        return ;
    } else {
        (p->rear)++;
        p->data[p->rear] = item;
    }
}

element dequeue(Queue *p)
{
    element item;
    int delete = (p->front) + 1;

    if (is_empty(p) == 1) {
        printf("queue empty\n");
        return -1;
    } else {
        item = p->data[delete];
        p->front = delete;
        return item;
    }
}

element peek(Queue *p)
{
    element item;
    int peek = (p->front) + 1;

    if (is_empty(p) == 1) {
        printf("queue empty\n");
        return -1;
    } else {
        item = p->data[peek];
        return (item);
    }
}

void printQueue(Queue *p)
{
    int i = (p->front) + 1;
    if (is_empty(p)) {
        printf("queue empty\n");
        return ;
    }
    while (i <= p->rear) {
        printf("%d -> ", p->data[i]);
        i++;
    }
    printf("NULL\n");
}

int main()
{
    Queue array;
    element item;
    init(&array);

    enqueue(&array, 10); printQueue(&array);
    enqueue(&array, 20); printQueue(&array);
    enqueue(&array, 30); printQueue(&array);

    item = dequeue(&array);
    printf("deleted : %d\n", item);
    printQueue(&array);
    item = peek(&array);
    printf("peek : %d\n", item);
    printQueue(&array);
}