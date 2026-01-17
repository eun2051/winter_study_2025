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
    if (front == rear && rear == NULL) return 1;
    else return 0;
}

void add_rear(element item)
{
    Queue *node = (Queue *)malloc(sizeof(Queue));
    node->data = item;
    node->link = NULL;
    if (is_empty() == 1) {
        front = rear = node;
        node->link = front;
    } else {
        rear->link = node;
        node->link = front;
        rear = node;
    }
}

element delete_rear()
{
    element item;
    Queue *pre = front;
    if (is_empty() == 1) {
        printf("queue empty\n");
        return -1;
    }
    while (pre->link != rear)
        pre = pre->link;
    Queue *tmp = rear;
    item = tmp->data;
    rear = pre;
    pre->link = front;
    free(tmp);
    return item;
}

void add_front(element item)
{
    Queue *node = (Queue *)malloc(sizeof(Queue));
    node->data = item;
    node->link = NULL;
    if (front == NULL) {
        front = node = node;
    } else {
        node->link = front;
        rear->link = node;
        front = node;
    }
}

element delete_front()
{
    element item;
    Queue *next = front->link;

    if (front == NULL) {
        printf("queue empty\n");
        return -1;
    } else {
        Queue *tmp = front;
        rear->link = next;
        front = next;
        item = tmp->data;
        free(tmp);
        return item;
    }
}

element get_front()
{
    element item;

    if (front == NULL) {
        printf("empty queue\n");
        return -1;
    } else {
        Queue *ptr = front;
        item = ptr->data;
        return item;
    }
}

element get_rear()
{
    element item;

    if (front == NULL) {
        printf("empty queue\n");
        return -1;
    } else {
        Queue *ptr = rear;
        item = ptr->data;
        return item;
    }
}

void print_queue()
{
    Queue *ptr = front->link;
    if (is_empty() == 1) {
        printf("queue empty\n");
        return ;
    }
    printf("%d -> ", front->data);
    while (ptr != front) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void free_all()
{
    if (front == NULL) return ;
    Queue *cur = front->link;
    Queue *start = front;

    while (cur != start) {
        Queue *tmp = cur;
        cur = cur->link;
        free(tmp);
    }
    free(start);
}

int main()
{
    element item;
    init();
    add_rear(10); print_queue();
    add_rear(20); print_queue();
    add_front(30); print_queue();
    add_rear(40); print_queue();

    item = delete_rear();
    printf("rear_deleted : %d\n", item);
    print_queue();
    item = get_front();
    printf("front_peek : %d\n", item);
    print_queue();
    item = delete_front();
    printf("first_delete : %d\n", item);
    print_queue();
    item = get_rear();
    printf("rear_peek : %d\n", item);
    print_queue();

    free_all();
}