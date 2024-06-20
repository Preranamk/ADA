
//Topological sort using Source Removal technique
#include <stdio.h>
#define MAX 100

void topologicalSort(int a[MAX][MAX], int n, int s[MAX]) {
    int indegree[MAX] = {0};
    int top = -1;
    int T[MAX];
    int i, j, sum;

    // Calculate the in-degrees of all vertices
    for (j = 0; j < n; j++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += a[i][j];
        }
        indegree[j] = sum;
    }

    // Find all vertices with in-degree 0 and add them to the stack
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            top++;
            s[top] = i;
        }
    }

    int index = 0;
    // Process the stack
    while (top != -1) {
        int u = s[top];
        top--;
        T[index++] = u;

        // For each vertex v adjacent to u, decrease its in-degree
        for (j = 0; j < n; j++) {
            if (a[u][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    top++;
                    s[top] = j;
                }
            }
        }
    }

    // Output the topological sequence
    printf("Topological Order: ");
    for (i = 0; i < index; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int a[MAX][MAX];
    int s[MAX];

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
    topologicalSort(a, n, s);

    return 0;
}
