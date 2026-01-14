#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *llink;
    struct node *rlink;
} Node;
// Node *head = NULL;
// Node *tail = NULL;

Node *CreateNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    new_node->data = value;
    new_node->llink = new_node;
    new_node->rlink = new_node;
    return (new_node);
}

Node *insert_front(Node **head, int value)
{
    if (*head == NULL) {
        *head = CreateNode(value);
        return (*head);
    } else {
        Node *new = CreateNode(value);
        Node *tail = (*head)->llink;
        tail->rlink = new;
        (*head)->llink = new;
        new->llink = tail;
        new->rlink = *head;
        *head = new;
    }
    return (NULL);
}

// Node *insert() {}

Node *insert_last(Node **head, int value)
{
    if (*head == NULL) {
        *head = CreateNode(value);
        return (*head);
    } else {
        Node *back = CreateNode(value);
        Node *tail = (*head)->llink;
        tail->rlink = back;
        back->llink = tail;
        (*head)->llink = back;
        back->rlink = (*head);
    }
    return (NULL);
}

Node *delete_front(Node **head)
{
    if (*head == NULL) return (NULL);
    else if (*head == (*head)->rlink) {
        free(*head);
        *head = NULL;
        return (NULL);
    } else {
        Node *del = (*head);
        Node *tail = (*head)->llink;
        Node *next = (*head)->rlink;
        tail->rlink = next;
        next->llink = tail;
        (*head) = next;
        free(del);
    }
    return (NULL);
}

// Node *delete() {}
Node *delete_last(Node **head)
{
    if (*head == NULL) return (NULL);
    else if (*head == (*head)->rlink) {
        free(*head);
        *head = NULL;
        return (NULL);
    } else {
        Node *tail = (*head)->llink;
        Node *pre = tail->llink;
        pre->rlink = *head;
        (*head)->llink = pre;
        free(tail);
    }
    return (NULL);
}
// Node *delete_target() {}

void printForward(Node *head)
{
    if (head == NULL) return ;
    printf("%d -> ", head->data);
    Node *ptr = head->rlink;
    while (ptr != head) {
        printf("%d -> ", ptr->data);
        ptr = ptr->rlink;
    }
    printf("\n");
}

void printBackward(Node *head)
{
    if (head == NULL) return ;
    Node *ptr = head->llink;
    while (ptr != head) {
        printf("%d <- ", ptr->data);
        ptr = ptr->llink;
    }
    printf("%d\n", head->data);
}

void free_all(Node *head)
{
    if (head == NULL) return ;
    Node *ptr = head->rlink;
    while (ptr != head) {
        Node *tmp = ptr;
        ptr = ptr->rlink;
        free(tmp);
    }
    free(ptr);
}

// 값을 바꾸지 말고 포인터를 맞바꾸어 리스트의 방향 뒤집기
void reverse(Node **head)
{
    if (*head == NULL) return ;
    Node *ptr = *head;
    Node *next = ptr->rlink;

    ptr->rlink = ptr->llink;
    ptr->llink = next;
    ptr = next;
    while (ptr != *head) {
        next = ptr->rlink;
        ptr->rlink = ptr->llink;
        ptr->llink = next;
        ptr = next;
    }
    *head = (*head)->rlink;
}

int main()
{
    Node *head = NULL;
    Node *A = NULL, *B = NULL, *C = NULL;

    A = CreateNode(10);
    head = A;
    B = CreateNode(20);
    A->rlink = B;
    B->llink = A;
    C = CreateNode(30);
    C->llink = B;
    C->rlink = A;
    A->llink = C;
    B->rlink = C;
    insert_front(&head, 40);
    insert_last(&head, 50);

    printForward(head);
    // printBackward(head);
    delete_front(&head);
    printForward(head);
    delete_last(&head);
    printForward(head);
    
    reverse(&head);
    printForward(head);
    free_all(head);
    return 0;
}