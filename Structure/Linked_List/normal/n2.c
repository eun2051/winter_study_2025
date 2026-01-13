#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node *CreateNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;     
}

void printList(Node *ptr)
{
    while (ptr != NULL) {
        printf("%d -> ", ptr ->data);
        ptr = ptr->next;
    }
}

void free_all(Node *head)
{
    while (head->next != NULL) {
        Node *ptr = head->next;
        free(head);
        head = ptr;
    }
    if (head->next == NULL)
        free(head); 
}

void insert_front(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void insert_last(Node *head, int value)
{
    Node *ptr = head;
    Node *back_node = (Node *)malloc(sizeof(Node)); 
    while (ptr->next != NULL)
        ptr = ptr->next;
    if (ptr->next == NULL) {
        back_node->data = value;
        back_node->next = NULL;
        ptr->next = back_node;
        // ptr = back_node;
    }
}

void get_size() {}

void search() {}

void first_delete(Node **head)
{
    if (*head == NULL) return ; 
    Node *del = *head;
    *head = (*head)->next;
    free(del);
}

void delete_back(Node **head)
{
    Node *curr = *head;
    Node *pre = NULL;

    if (*head == NULL) return ;
    while (curr->next != NULL) {
        pre = curr;
        curr = curr->next;
    }
    if (pre == NULL) {
        *head = NULL;
    } else {
        pre->next = NULL;
    }
    free(curr);
}

int main()
{
    Node *A = NULL, *B = NULL, *C = NULL;
    Node *head = NULL;

    A = CreateNode(10);
    B = CreateNode(20);
    C = CreateNode(30);
    A->next = B;
    B->next = C;
    C->next = NULL;
    head = A;
    insert_front(&head, 40);
    insert_last(head, 50);

    printList(head);
    first_delete(&head);
    printf("\n");
    printList(head);
    printf("\n");
    delete_back(&head);
    printList(head);
    free_all(head);         
    return 0;
}