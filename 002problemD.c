#include <stdio.h>
#define MAX_SIZE 21

int map[MAX_SIZE][MAX_SIZE];

typedef struct Axis {
    int x;
    int y;
    int t;
} axis;

typedef struct QueueType {
    axis queue[10000];
    int front, rear;
} queueType;

void init(queueType *q) {
    q->front = q->rear = -1;
}

int yMove[4] = {0, 1, 0, -1};
int xMove[4] = {1, 0, -1, 0};

void BFS(queueType *q, int targetX, int targetY) {
    q->rear++;
    q->queue[q->rear].x = 0, q->queue[q->rear].y = 0;
    q->queue[q->rear].t = 1; // 출발지점도 횟수로 포함되니까 !
    map[0][0] = 0;

    while (q->front < q->rear) { // 큐에 아무것도 없을때까지 반복
        q->front++;
        int x = q->queue[q->front].x;
        int y = q->queue[q->front].y;

        if (x == targetX - 1 && y == targetY - 1) {
            printf("%d", q->queue[q->front].t);
            return;
        }

        for (int i =0; i < 4; i++) { // dequeue한 좌표에서 오,아래,왼,위 좌표 계산
            int tempX = xMove[i] + x;
            int tempY = yMove[i] + y;

            if (tempX < 0 || tempX >= targetX || tempY < 0 || tempY >= targetY) continue; // 해당 좌표계에 없으면 포문으로 continue
            if (map[tempY][tempX] == 1) { // 지도에 해당 좌표계에 갈수 있으면 enqueue
                q->queue[++(q->rear)].x = tempX;
                q->queue[q->rear].y = tempY;
                q->queue[q->rear].t = q->queue[q->front].t + 1;
            }
        }
    }
}

int main() {
    int y, x;
    scanf("%d %d", &y, &x);
    queueType q;
    init(&q);
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++)
            scanf("%1d", &map[i][j]);
    }

    BFS(&q, x, y);

    return 0;
}
