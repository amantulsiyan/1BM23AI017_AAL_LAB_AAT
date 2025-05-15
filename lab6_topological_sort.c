#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;  // Number of vertices

void dfs(int v) {
    visited[v] = 1;

    // Visit all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    // Push current vertex to stack after visiting its neighbors
    stack[++top] = v;
}

void topologicalSort() {
    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Call DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print vertices in topological order
    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    // Example graph (DAG) with 6 vertices
    n = 6;
    int exampleGraph[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    // Copy example graph to global graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = exampleGraph[i][j];

    topologicalSort();

    return 0;
}
