#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, type) {type temp = x; x = y; y = temp;}

typedef struct HeapNode {
    int *heap;
    int size;
} heapNode;

void initHeap(heapNode *h, int n) {
    h->heap = (int *)malloc(sizeof(int) * (n+ 1));
    h->size = n;
}

heapNode* create() {
    heapNode* new = (heapNode *)malloc(sizeof(heapNode));
    return new;
}

void insertNode(heapNode *h, int list[]) {
    for (int i = 0; i < h->size; i++)
        h->heap[i + 1] = list[i];
}

int findMin(heapNode *h) {
    int min = h->heap[1];
    for (int i = 2; i <= h->size; i++) {
        if (h->heap[i] == -1) continue;
        if (min > h->heap[i]) SWAP(min, h->heap[i], int);
    }
    return min;
}

int main() {
    int n;
    scanf("%d", &n);
    int list[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    heapNode *heap = create();
    initHeap(heap, n);
    insertNode(heap, list);
    printf("%d", findMin(heap));

    return 0;
}
