#include <stdio.h>
#define MAX 100
#define INF 9999

void prims(int n, int cost[MAX][MAX]) {
    int i, j;
    int min, source;
    int s[MAX], d[MAX], p[MAX];
    int T[MAX][2]; // To store the edges of MST
    int sum = 0, k = 0;

    // Step 1: Find the source vertex with the minimum edge going out of it
    min = INF;
    source = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] < min) {
                min = cost[i][j];
                source = i;
            }
        }
    }

    // Step 2: Initialization
    for (i = 0; i < n; i++) {
        s[i] = 0;
        d[i] = cost[source][i];
        p[i] = source;
    }

    // Step 3: Add source to s
    s[source] = 1;

    // Step 4: Find the Minimum Spanning Tree if exists
    sum = 0;
    k = 0;
    for (i = 1; i < n; i++) {
        // Find u such that d[u] is minimum and u belongs to (V - s)
        min = INF;
        int u = -1;
        for (j = 0; j < n; j++) {
            if (s[j] == 0 && d[j] <= min) {
                min = d[j];
                u = j;
            }
        }

        // Select an edge with the least cost
        T[k][0] = u;
        T[k][1] = p[u];
        k++;

        // Add the cost associated with the edge to get total cost of MST
        sum += cost[u][p[u]];

        // Add u to s
        s[u] = 1;

        // Update d[] and p[] for vertices adjacent to u and not yet in s
        for (int v = 0; v < n; v++) {
            if (s[v] == 0 && cost[u][v] < d[v]) {
                d[v] = cost[u][v];
                p[v] = u;
            }
        }
    }

    // Step 5: Check for the existence of spanning tree
    if (sum >= INF) {
        printf("Spanning tree does not exist\n");
    } else {
        printf("Spanning tree exists and MST is:\n");
        for (i = 0; i < n - 1; i++) {
            printf("(%d, %d)\n", T[i][0], T[i][1]);
        }
        printf("The cost of the spanning tree (MST) is: %d\n", sum);
    }
}

int main() {
    int n, i, j;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (enter 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(n, cost);

    return 0;
}
