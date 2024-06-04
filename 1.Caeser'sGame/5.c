#include <stdio.h>
#define INFINITY 999

void dijkstra(int cost[10][10], int n, int source, int distance[10]) {
    int visited[10], min, u;
    int i, j;

    // Initialize distances and visited array
    for (i = 1; i <= n; i++) {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }
    visited[source] = 1;
    distance[source] = 0;

    // Dijkstra's algorithm
    for (i = 1; i < n; i++) { // Run n-1 times
        min = INFINITY;
        for (j = 1; j <= n; j++) {
            if (visited[j] == 0 && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }
        visited[u] = 1;

        for (j = 1; j <= n; j++) {
            if (visited[j] == 0 && cost[u][j] != INFINITY && (distance[u] + cost[u][j] < distance[j])) {
                distance[j] = distance[u] + cost[u][j];
            }
        }
    }
}

int main() {
    int n, cost[10][10], distance[10];
    int i, j, source;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Cost Matrix\nEnter 999 for no edge\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstra(cost, n, source, distance);

    printf("\nShortest Distances from source node %d:\n", source);
    for (i = 1; i <= n; i++) {
        if (distance[i] == INFINITY) {
            printf("Node %d is unreachable from source node %d\n", i, source);
        } else {
            printf("Shortest distance to node %d is %d\n", i, distance[i]);
        }
    }

    return 0;
}
