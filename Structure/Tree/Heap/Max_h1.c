#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
    int heap[MAX_ELEMENT];
    int size;
} Heap;

Heap *createHeap(Heap *h)
{
    h = (Heap *)malloc(sizeof(Heap));
    h->size = 0;
    return h;
}

void insertHeap(Heap *h, int data)
{
    (h->size)++;
    h->heap[h->size] = data;

    int curr = h->size;
    int parent = (h->size) / 2;

    while (parent > 0) {
        if (h->heap[parent] < h->heap[curr]) {
            int tmp = h->heap[parent];
            h->heap[parent] = h->heap[curr];
            h->heap[curr] = tmp;

            curr = parent;
            parent /= 2;
        } else
            break;
    }
    return ;
}

int deleteHeap(Heap *h)
{
    int item = h->heap[1];
    h->heap[1] = h->heap[h->size];
    h->size = h->size - 1;

    int parent = 1;
    int child = 2;
    while (child <= h->size) {
        //오른쪽 자식의 인덱스 번호가 힙 크기 이하이면서 왼쪽 자식보다 더 큰 경우
        if (child + 1 <= h->size && h->heap[child] < h->heap[child + 1]) {
            child += 1;
            // 비교할 자식의 인덱스 -> 오른쪽으로 바꿔줌
        }
        if (h->heap[parent] < h->heap[child]) {
            int tmp = h->heap[parent];
            h->heap[parent] = h->heap[child];
            h->heap[child] = tmp;

            parent = child;
            child = parent * 2;
        } else
            break;
    }
    return item;
}

void printHeap(Heap *h)
{
    int i = 1;
    while (i <= h->size) {
        printf("%d ", h->heap[i]);
        i++;
    }
}

int main()
{
    Heap *h = createHeap(h);
    insertHeap(h, 3);
    insertHeap(h, 5);
    insertHeap(h, 1);
    insertHeap(h, 23);
    insertHeap(h, 9);

    printHeap(h);
    printf("\n");
    deleteHeap(h);
    printHeap(h);

    free(h);
    return 0;
}