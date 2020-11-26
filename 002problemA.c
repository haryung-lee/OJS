#include <stdio.h>
#define MAX_SIZE 51

int map[MAX_SIZE][MAX_SIZE];

typedef struct Axis {
    int x;
    int y;
} axis;

typedef struct QueueType {
    axis queue[10000];
    int front, rear;
} queueType;

void init(queueType *q) {
    q->front = q->rear = -1;
}

int yMove[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int xMove[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void BFS(queueType *q, int targetX, int targetY) {

    int nOfIsland = 0;

    for (int y = 0; y < targetY; y++) {

        // 해당 지점이 바다일 경우
        for (int x = 0; x < targetX; x++) {
            if (map[y][x] == 0) {
                continue;
            }

            // 해당 지점이 육지일 경우
            q->rear++;
            nOfIsland++;
            q->queue[q->rear].x = x, q->queue[q->rear].y = y;
            map[y][x] = 0;

            while (q->front < q->rear) {
                q->front++;
                int x2 = q->queue[q->front].x;
                int y2 = q->queue[q->front].y;

                for (int i = 0; i < 8; i++) {
                    int tempX = xMove[i] + x2;
                    int tempY = yMove[i] + y2;

                    if (tempX < 0 || tempX >= targetX || tempY < 0 || tempY >= targetY)
                        continue; // 해당 좌표계에 없으면 포문으로 continue

                    if (map[tempY][tempX] == 1) { // 지도에 해당 좌표계에 갈수 있으면 enqueue
                        q->queue[++(q->rear)].x = tempX;
                        q->queue[q->rear].y = tempY;
                        map[tempY][tempX] = 0;
                    }
                }
            }
        }
    }
    printf("%d", nOfIsland);
}

int main() {
    int w, h;
    scanf("%d %d", &w, &h);
    queueType q;
    init(&q);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            scanf("%d", &map[i][j]);
    }

    BFS(&q, w, h);

    return 0;
}
