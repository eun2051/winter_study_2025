#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *CreateNode(Node *head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = head;
    return (new_node);
}

void printList(Node *head)
{
    if (head == NULL) {
        printf("NULL\n");
        return ;
    }
    printf("%d -> ", head->data);
    Node *ptr = head->next;
    while (ptr != head) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    if (ptr == head) {
        printf("%d\n", ptr->data);
        return ;
    }
}

void free_all(Node *head)
{
    Node *tmp;
    Node *ptr = head->next;
    if (head == NULL) return ;
    while (ptr != head) {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    free(ptr);
}

int get_size(Node *head)
{
    Node *ptr = head->next;
    int count = 0;
    if (head == NULL) return 0;
    while (ptr != head) {
        count++;
        ptr = ptr->next;
    }
    if (ptr == head) count++;
    return (count);
}

void insert_front(Node **head, int value)
{
    Node *first_node = (Node *)malloc(sizeof(Node));
    first_node->data = value;

    Node *tail = *head;

    if (*head == NULL) {
        *head = first_node;
        first_node->next = *head;
    } else {
        while (tail->next != *head)
            tail = tail->next;
        first_node->next = *head;
        tail->next = first_node;
        *head = first_node;
    }
}

void insert_last(Node **head, int value)
{
    Node *last_node = (Node *)malloc(sizeof(Node));
    last_node->data = value;

    Node *tail = *head;

    if (*head == NULL) {
        *head = last_node;
        last_node->next = *head;
    } else {
        while (tail->next != *head)
            tail = tail->next;
        tail->next = last_node;
        last_node->next = *head;
    }
}

void delete_first(Node **head)
{
    Node *tail = *head;

    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    while (tail->next != *head)
        tail = tail->next;
    Node *del = *head;
    *head = (*head)->next;
    tail->next = *head;
    free(del);
}

void delete_last(Node **head)
{
    if (*head == NULL) return;
    Node *pre = *head;
    Node *curr = (*head)->next;
    if (curr == *head) {
        free(curr);
        *head = NULL;
        return ;
    }
    while (curr->next != *head) {
        pre = pre->next;
        curr = curr->next;
    }
    pre->next = *head;
    free(curr);
}

void delete_value(Node **head, int value)
{
    if (*head == NULL) return;
    Node *pre = *head;
    Node *curr = (*head)->next;

    if (pre->data == value) {
        delete_first(head);
        return ;
    }
    while (curr != *head) {
        if (curr->data == value) {
            pre->next = curr->next;
            free(curr);
            return ;
        }
        pre = pre->next;
        curr = curr->next;
    }
}

Node *search(Node *head, int value)
{
    if (head == NULL) return (NULL);
    Node *ptr = head;

    while (ptr->next != head) {
        if (ptr->data == value)
            return (ptr);
        ptr = ptr->next;
    }
    if (ptr->data == value)
        return (ptr);
    else return (NULL);
}

int main()
{
    Node *head = NULL;
    Node *A = NULL, *B = NULL, *C = NULL;
    
    A = CreateNode(head, 10);
    head = A;
    B = CreateNode(head, 20);
    C = CreateNode(head, 30);
    A->next = B;
    B->next = C;
    insert_front(&head, 40);
    insert_last(&head, 50);

    printList(head);
    printf("%d\n", get_size(head));
    printf("%p\n", search(head, 40));

    delete_first(&head);
    printList(head);
    delete_last(&head);
    printList(head);
    delete_value(&head, 20);
    printList(head);
    delete_value(&head, 10);
    printList(head);
    free_all(head);
    return 0;
}