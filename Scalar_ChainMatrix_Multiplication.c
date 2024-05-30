#include <stdio.h>
#include <limits.h>

int MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int arr_size;
    printf("Enter the number of matrices: ");
    scanf("%d", &arr_size);

    if (arr_size < 2) {
        printf("Number of matrices should be at least 2.\n");
        return 1;
    }

    int arr[arr_size];
    printf("Enter the dimensions of the matrices (as a sequence of integers): ");
    for (int i = 0; i < arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Minimum number of multiplications required for the matrices multiplication is %d ", MatrixChainOrder(arr, arr_size));

    return 0;
}