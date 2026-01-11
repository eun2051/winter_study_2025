#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} Node;

void printList(Node *ptr)
{
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

Node *CreateNode(Node *head, int value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

int main()
{
    Node *head = NULL; 
    
    head = CreateNode(head, 10);
    head = CreateNode(head, 20);
    head = CreateNode(head, 30);

    printList(head);
    return 0;
}