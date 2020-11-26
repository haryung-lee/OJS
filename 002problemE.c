#include <stdio.h>

#define MAX_VERTICES 50
#define INF 1000L

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} graphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int getMinVertex (int n) {
    int v, i;
    for (i = 0; i < n; i++)
        if (!selected[i]) {
            v = i;
            break;
        }
    for (i = 0; i < n; i++)
        if (!selected[i] && (distance[i] < distance[v])) v = i;
    return v;
}

void prim(graphType *g, int s) {
    int i, u, v, sum = 0;

    for (u = 0; u < g->n; u++)
        distance[u] = INF;
    distance[s] = 0;
    for (i = 0; i < g->n; i++) {
        u = getMinVertex(g->n);
        selected[u] = 1;
        if (distance[u] == INF) return;
        sum += distance[u];
        for (v = 0; v < g->n; v++)
            if (g->weight[u][v] != INF)
                if (!selected[v] && g->weight[u][v] < distance[v])
                    distance[v] = g->weight[u][v];
    }
    printf("%d", sum);
}

int main() {
    graphType g;

    int v, e;
    scanf("%d %d", &v, &e);

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            g.weight[i][v] = INF;

    for (int i = 0; i < e; i++) {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        g.weight[s-1][e-1] = w;
        g.weight[e-1][s-1] = w;
    }
    g.n = v;
    prim(&g, 0);
    return 0;
}
