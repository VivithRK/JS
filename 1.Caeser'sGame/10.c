#include <stdio.h>

void counting_sort(int a[], int k, int n) {
    int i, j;
    int b[n], c[k + 1];

    // Initialize count array
    for (i = 0; i <= k; i++)
        c[i] = 0;

    // Store the count of each element in the count array
    for (j = 0; j < n; j++)
        c[a[j]] = c[a[j]] + 1;

    // Modify the count array to store the cumulative count of elements
    for (i = 1; i <= k; i++)
        c[i] = c[i] + c[i - 1];

    // Build the output array
    for (j = n - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }

    // Copy the sorted elements back to the original array
    for (i = 0; i < n; i++)
        a[i] = b[i];

    // Print the sorted array
    printf("The Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, k = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > k) {
            k = a[i]; // Find the maximum value in the array to set the range of the count array
        }
    }
    counting_sort(a, k, n);
    return 0;
}
