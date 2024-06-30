#include <stdio.h>
#define INFINITY 999
#define MAX 100

int parent[MAX], cost[MAX][MAX], t[MAX][2];

int find(int v) {
    while (parent[v]) {
        v = parent[v];
    }
    return v;
}

void union1(int i, int j) {
    parent[j] = i;
}

void kruskal(int n) {
    int i, j, k, u, v, mincost, res1, res2, sum = 0;
    for (k = 1; k < n; k++) {
        mincost = INFINITY;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i == j) continue;
                if (cost[i][j] < mincost) {
                    u = find(i);
                    v = find(j);
                    if (u != v) {
                        res1 = i;
                        res2 = j;
                        mincost = cost[i][j];
                    }
                }
            }
        }
        union1(find(res1), find(res2));
        t[k][0] = res1;
        t[k][1] = res2;
        sum += mincost;
    }
    printf("\nCost of spanning tree is %d\n", sum);
    printf("\nEdges of spanning tree are\n");
    for (i = 1; i < n; i++)
        printf("%d -> %d\n", t[i][0], t[i][1]);
}

int main() {
    int i, j, n;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        parent[i] = 0;
    printf("\nEnter the cost adjacency matrix (0 for self edge and 999 if no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    kruskal(n);
    return 0;
}
