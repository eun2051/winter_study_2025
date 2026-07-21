#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
// 배열 안에 들어오는 값의 타입을 element로 한번에 지정
typedef struct stack {
    int top;
    element data[MAX_STACK_SIZE];
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int is_full(Stack *s)
{
    if (s->top == MAX_STACK_SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(Stack *s)
{
    if (s->top == -1)
        return 1;
    else return 0;
}

void push(Stack *s, element item)
{
    if (is_full(s) == 1) {
        printf("stack full\n");
    } else {
        (s->top)++;
        s->data[s->top] = item;
    }
}

element pop(Stack *s)
{
    if (is_empty(s) == 1)
        return -1;
    else {
        element d = s->data[s->top];
        (s->top)--;
        return d;
    }
}

void peek(Stack *s)
{
    if (is_empty(s) == 1) {
        printf("stack empty\n");
        return ;
    } else {
        element d = s->data[s->top];
        printf("%c\n", d);
    }
}

void print(Stack *s)
{
    if (s->top == -1) {
        printf("stack empty\n");
        return ;
    }
    int i = s->top;
    while (i != -1) {
        printf("%c " , s->data[i]);
        (i)--;
    }
    printf("\n");
}

int main()
{
    Stack p;
    init(&p);

    push(&p, 'a');
    push(&p, 'b');
    push(&p, 'c');
    print(&p);

    peek(&p);
    pop(&p);
    print(&p);
    return 0;
}
