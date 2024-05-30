#include <stdio.h>
#include <stdlib.h>

#define MAX 64  

void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}


void subtract(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][j] * B[i][j];
            }
        }
    }
}

void divideAndConquer(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int halfSize = size / 2;

    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    int temp1[MAX][MAX], temp2[MAX][MAX];

    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }

    divideAndConquer(A11, B11, temp1, halfSize);
    divideAndConquer(A12, B21, temp2, halfSize);
    add(temp1, temp2, C11, halfSize);

    divideAndConquer(A11, B12, temp1, halfSize);
    divideAndConquer(A12, B22, temp2, halfSize);
    add(temp1, temp2, C12, halfSize);

    divideAndConquer(A21, B11, temp1, halfSize);
    divideAndConquer(A22, B21, temp2, halfSize);
    add(temp1, temp2, C21, halfSize);

    divideAndConquer(A21, B12, temp1, halfSize);
    divideAndConquer(A22, B22, temp2, halfSize);
    add(temp1, temp2, C22, halfSize);

    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + halfSize] = C12[i][j];
            C[i + halfSize][j] = C21[i][j];
            C[i + halfSize][j + halfSize] = C22[i][j];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the matrices (must be a power of 2): ");
    scanf("%d", &size);

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    divideAndConquer(A, B, C, size);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
