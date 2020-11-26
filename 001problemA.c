#include <stdio.h>
#include <stdlib.h>

typedef struct HeapType {
    int *heap;
    int size;
} heapType;

heapType *create() {
    return (heapType *)malloc(sizeof(heapType));
}

void initHeap (heapType *h, int n) {
    h->heap = (int *)malloc(sizeof(int) * (n+1));
    h->size = 0;
}

void insertHeap(heapType *h, int item) {
    int i = ++(h->size);

    while ( (i != 1) && item < h->heap[i / 2]) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

void levelOrder(heapType *h) {
    for (int i = 1; i <= h->size; i++)
        printf("%d ", h->heap[i]);
}

int deleteHeap(heapType *h) {
    int parent, child;
    int item, temp;
    item = h->heap[1];
    temp = h->heap[(h->size)--];
    parent = 1;
    child = 2;
    while (child <= h->size) {
        if ((child < h->size) && (h->heap[child]) > h->heap[child + 1]) child++;
        if (temp <= h->heap[child]) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heapSort(int a[], int n) {
    heapType *h = create();
    initHeap(h, n);
    for (int i = 0; i < n; i++)
        insertHeap(h, a[i]);
    for (int i = 0; i < n; i++)
        a[i] = deleteHeap(h);
    for (int i = 0; i < n; i++)
        insertHeap(h, a[i]);

    for(int i = 1; i <= n; i++)
        printf("%d ", h->heap[i]);
    printf("\n%d", h->heap[n / 2]);
    free(h);
}

int main() {
    int n;
    scanf("%d", &n);

    int userInput[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &userInput[i]);

    heapSort(userInput, n);
    return 0;
}