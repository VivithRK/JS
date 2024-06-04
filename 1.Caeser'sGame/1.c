#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    int i, n, m, j;

    printf("Enter some text\n");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = 0; // Remove newline character if present

    printf("Enter a string to find\n");
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = 0; // Remove newline character if present

    m = strlen(b);
    n = strlen(a);

    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && b[j] == a[i + j]) {
            j++;
        }
        if (j == m) {
            printf("SUBSTRING FOUND AT LOCATION %d\n", i + 1);
            return 0;
        }
    }

    printf("SUBSTRING NOT FOUND\n");
    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    int i, n, m, j;

    printf("Enter some text\n");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = 0; // Remove newline character if present

    printf("Enter a string to find\n");
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = 0; // Remove newline character if present

    m = strlen(b);
    n = strlen(a);

    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && b[j] == a[i + j]) {
            j++;
        }
        if (j == m) {
            printf("SUBSTRING FOUND AT LOCATION %d\n", i + 1);
            return 0;
        }
    }

    printf("SUBSTRING NOT FOUND\n");
    return 0;
}
