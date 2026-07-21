#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct stack {
    element data;
    struct stack *link;
} Stack;

struct stack *top = NULL;

void push(element item)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = item;
    s->link = top;
    top = s;
}

element pop()
{
    element item;
    struct stack *tmp = top;
    if (top == NULL) {
        printf("stack empty\n");
    } else {
        item = tmp->data;
        top = tmp->link;
        free(tmp);
        return item;
    }
}

void free_all()
{
    Stack *tmp = top;

    if (top == NULL) {
        return ;
    } else {
        while (tmp != NULL) {
            top = tmp->link;
            free(tmp);
            tmp = top;
        }
    }
}

element peek()
{
    element item;
    struct stack *tmp = top;

    if (top == NULL) {
        printf("stack empty, NULL\n");
    } else {
        item = tmp->data;
        return item;
    }
}

void printStack()
{
    struct stack *ptr = top;
    
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("NULL\n");
    }
}

int main()
{
    element item;
    printStack();
    push(10); printStack();
    push(20); printStack();
    push(30); printStack();

    pop(); printStack();
    item = peek();
    printf("%d\n", item);
    printStack();

    free_all();
}