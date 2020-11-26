#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType {
    int n;
    int adjMax[MAX_VERTICES][MAX_VERTICES];
} graphType;

int visited[MAX_VERTICES];

void initGraph(graphType *g) {
    g->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++)
            g->adjMax[i][j] = 0;
    }
}

void insertVertex(graphType *g, int v) {
    if ((g->n) + 1 > MAX_VERTICES) return;
    g->n++;
}

void insertEdge(graphType *g, int start, int end) {
    if (start >= g->n || end >= g->n) return;
    g->adjMax[start][end] = 1;
    g->adjMax[end][start] = 1;
}

void dfsMat(graphType *g, int v) {
    int w;
    visited[v] = TRUE;
    printf("%d ", v);
    for (w = 0; w < g->n; w++)
        if (g->adjMax[v][w] && !visited[w])
            dfsMat(g, w);
}

int main() {
    graphType *g;
    g = (graphType *)malloc(sizeof(graphType));
    initGraph(g);

    int n, e, s;
    scanf("%d %d %d", &n, &e, &s);

    for (int i = 0; i < n; i++)
        insertVertex(g, i);

    for (int i = 0; i < e; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insertEdge(g, a, b);
    }
    dfsMat(g, s);

    return 0;
}
