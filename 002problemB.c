#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct QueueType {
    int front, rear;
    int queue[100000];
}queueType;

void initQueue(queueType *q) {
    q->front = q->rear = 0;
}

void enqueue(queueType *q, int a) {
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->queue[q->rear] = a;
}

int dequeue(queueType *q) {
    q->front = (q->front + 1) % MAX_SIZE;
    return q->queue[q->front];
}

int time[100000] = {0};

int findMin(queueType *q, int n, int k) {
    int temp = n;
    int i = 0;
    do {
        time[i] = i++;
        enqueue(q, temp);
        temp *= 2;
    } while (temp < k);

    time[i] = i++;
    enqueue(q, temp);

    for(int j = 0; j < i; j++) {
        int a = dequeue(q);
        if (a < k) time[j] += (k - a);
        else time[j] += (a - k);
    }
    int min = time[0];
    for (int j = 1; j < i; j++)
        if (min > time[j]) min = time[j];
    return min;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    queueType q;
    initQueue(&q);

    if (n > k) printf("%d", n - k);
    else {
        printf("%d", findMin(&q, n ,k));
    }

    return 0;
}
