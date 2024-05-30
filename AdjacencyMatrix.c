#include <stdio.h>
#include <stdlib.h>

// Function to initialize the adjacency matrix with zeros
void initializeMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

// Function to print the adjacency matrix
void printMatrix(int n, int matrix[n][n]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, e;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Create an adjacency matrix
    int adjMatrix[n][n];
    initializeMatrix(n, adjMatrix);

    // Input edges and their weights
    printf("Enter the edges and their weights (format: start_vertex end_vertex weight):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // For undirected graph
    }

    // Print the adjacency matrix
    printMatrix(n, adjMatrix);

    return 0;
}
