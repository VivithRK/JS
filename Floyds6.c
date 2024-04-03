#include <stdio.h>
#include <omp.h>

#define INFINITY 999

int min(int i, int j) {
    return (i < j) ? i : j;
}

void floyd(int n, int p[10][10]) {
    int i, j, k;
    #pragma omp parallel for private(i, j, k) shared(p)
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
            }
        }
    }
}

int main() {
    int i, j, n, a[10][10];
    double starttime, endtime;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    starttime = omp_get_wtime();
    floyd(n, a);
    endtime = omp_get_wtime();

    printf("\nThe distance matrix is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\nThe time taken is %0.9f seconds.\n", (endtime - starttime));

    return 0;
}
