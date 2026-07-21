#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct queue {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q) {
    if (q->front == q->rear) return 1;
    else return 0;
}

int is_full(Queue *q) {
    if (q->rear == (MAX_QUEUE_SIZE - 1)) return 1;
    else return 0;
}

void enqueue(Queue *q, element item)
{
    if (is_full(q) == 1) {
        printf("queue full\n");
        return ;
    } else {
        (q->rear)++;
        q->data[q->rear] = item;
    }
}

element dequeue(Queue *q)
{
    element item;
    if (is_empty(q) == 1) {
        printf("queue empty\n");
        return -1;
    } else {
        (q->front)++;
        item = q->data[q->front];
        return item;
    }
}

void print_queue(Queue *q)
{
    int i = q->front + 1;
    if (is_empty(q) == 1) {
        printf("queue empty\n");
        return ;
    }
    while (i <= q->rear) {
        printf("%d -> ", q->data[i]);
        i++;
    }
    printf("NULL\n");
}

int main()
{
    Queue queue;
    element item;
    init(&queue);
    enqueue(&queue, 10); print_queue(&queue);
    enqueue(&queue, 20); print_queue(&queue);

    item = dequeue(&queue);
    printf("delete : %d\n", item);
    print_queue(&queue);
}