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

Node *CreateNode(int value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->link = NULL;
    return p;
}

Node *insert_front(Node *head, int value)
{
    Node *p = CreateNode(value);
    p->link = head;
    return p;
}
//리스트의 중간 부분에 항목을 삽입하는 함수
Node *insert() {}

Node *insert_back(Node *head, int value)
{
    if (head == NULL) {
        return (CreateNode(value));
    }
    Node *curr = head;
    while (curr->link != NULL) {
        curr = curr->link;
    }
    curr->link = CreateNode(value);
    return head;
}

Node *free_node(Node *start)
{
    while (start != NULL) {
        Node *tmp = start;
        start = start->link;
        free(tmp);
    }
    return NULL;
}

// 리스트의 중간 항목을 삭제하는 함수
Node *delete() {}
// 리스트의 첫 번째 항목을 삭제하는 함수
Node *delete_first() {}
// 노드의 개수 반환하는것 / 사이즈를 재는 것
Node *size() {}

int main()
{
    Node *head = NULL; 
    
    head = insert_front(head, 10);
    head = insert_front(head, 20);
    head = insert_front(head, 30);

    head = insert_back(head, 40);

    printList(head);

    free_node(head);
    return 0;
}