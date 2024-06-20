//Topological sort using DFA

#include <stdio.h>
#define MAX 100

int s[MAX];      // Array to keep track of visited nodes
int res[MAX];    // Array to store the topological order
int j;           // Index for the result array

// DFS function
void DFS(int u, int n, int a[MAX][MAX]) {
    s[u] = 1;  // Mark the current node as visited

    // Traverse all adjacent vertices
    for (int v = 0; v < n; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            DFS(v, n, a);
        }
    }

    // Store the completely explored vertex
    res[j] = u;
    j++;
}

// Function to perform topological sort
void topological_order(int n, int a[MAX][MAX]) {
    // Initialize visited array to 0
    for (int i = 0; i < n; i++) {
        s[i] = 0;
    }

    j = 0;  // Initialize index for result array

    // Process each vertex in the graph
    for (int u = 0; u < n; u++) {
        if (s[u] == 0) {
            DFS(u, n, a);
        }
    }

    // Output the topological sequence in reverse order
    printf("Topological Order: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int a[MAX][MAX];

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Perform topological sort
    topological_order(n, a);

    return 0;
}
