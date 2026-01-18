#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
    int size;
    int heap[MAX_ELEMENT];
} Heap;

Heap *createHeap(Heap *h)
{
    h = (Heap *)malloc(sizeof(Heap));
    h->size = 0;
    return h;
}

void insert_Minheap(Heap *h, int data)
{
    (h->size)++;
    h->heap[h->size] = data;

    int child = h->size;
    int parent = (h->size) / 2;

    while (parent > 0) {
        if (h->heap[parent] > h->heap[child]) {
            int tmp = h->heap[parent];
            h->heap[parent] = h->heap[child];
            h->heap[child] = tmp;

            child = parent;
            parent /= 2;
        } else 
            break;
    }
    return ;
}

int delete_Minheap(Heap *h)
{
    int item = h->heap[1];
    h->heap[1] = h->heap[h->size];
    h->size = h->size - 1;

    int parent = 1;
    int child = 2;

    while (child <= h->size) {
        if (child + 1 <= h->size && h->heap[child] > h->heap[child + 1]) {
            child += 1;
        }
        if (h->heap[parent] > h->heap[child]) {
            int tmp = h->heap[child];
            h->heap[child] = h->heap[parent];
            h->heap[parent] = tmp;

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
    printf("\n");
}

int main()
{
    Heap *h = createHeap(h);
    insert_Minheap(h, 3);
    insert_Minheap(h, 5);
    insert_Minheap(h, 1);
    insert_Minheap(h, 23);
    insert_Minheap(h, 9);

    printHeap(h);
    delete_Minheap(h);
    printHeap(h);

    free(h);
    return 0;
}