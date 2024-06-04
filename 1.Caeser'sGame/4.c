#include <stdio.h>
#define INFINITY 999

int prim(int cost[10][10], int source, int n) {
    int i, j, sum = 0, visited[10];
    int distance[10], vertex[10];
    int min, u, v;

    for (i = 1; i <= n; i++) {
        vertex[i] = source;
        visited[i] = 0;
        distance[i] = cost[source][i];
    }
    visited[source] = 1;

    for (i = 1; i < n; i++) {
        min = INFINITY;
        for (j = 1; j <= n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }
        visited[u] = 1;
        sum += distance[u];
        printf("\n%d -> %d", vertex[u], u);

        for (v = 1; v <= n; v++) {
            if (!visited[v] && cost[u][v] < distance[v]) {
                distance[v] = cost[u][v];
                vertex[v] = u;
            }
        }
    }
    return sum;
}

void main() {
    int a[10][10], n, i, j, m, source;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter the cost matrix (0 for self-loop and 999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter the source:\n");
    scanf("%d", &source);
    m = prim(a, source, n);
    printf("\nThe cost of the spanning tree = %d\n", m);
}
