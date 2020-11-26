#include <stdio.h>
#include <stdlib.h>

typedef struct HeapType {
    int* heap;
    int size;
} heapType;

heapType *create() {
    heapType *new = (heapType *)malloc(sizeof(heapType));
    return new;
}

void initHeap(heapType *h, int n) {
    h->heap = (int *)malloc(sizeof(int) * (n + 1));
    h->size = 0;
}

void insertHeap(heapType *h, int item) {
    int i = ++(h->size);
    while ( (i != 1) && item > h->heap[i / 2]) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

int deleteHeap(heapType *h) {
    if (h->size == 0) return 0;
    int parent, child;
    int item, temp;

    item = h->heap[1];
    temp = h->heap[(h->size)--];
    parent = 1; child = 2;

    while (child <= h->size) {
        if ( (child < h->size) && (h->heap[child] < h->heap[child + 1])) child++;
        if (temp >= h->heap[child]) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main() {
    int n;
    scanf("%d", &n);
    int userInput;
    heapType *heap = create();
    initHeap(heap, n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &userInput);
        if (userInput == 0) {
            printf("%d ", deleteHeap(heap));
        } else {
            insertHeap(heap, userInput);
        }
    }
    return 0;
}
