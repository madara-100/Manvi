#include <stdio.h>
#include <stdlib.h>


void createGraph(int graph[100][100], int vertices) {
    int i, j, edges, src, dest;

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source and destination):\n");
    for (i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);

        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            graph[src][dest] = 1; // For directed graph
            graph[dest][src] = 1; // For undirected graph
        } else {
            printf("Invalid edge! Please enter valid vertices.\n");
            i--; // Retry the current edge
        }
    }
}


void dfs(int graph[100][100], int visited[100], int start, int vertices) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, vertices);
        }
    }
}

int main() {
    int graph[100][100] = {0};
    int visited[100] = {0};
    int vertices, start;
    int choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Create the graph
    createGraph(graph, vertices);

    do {
        printf("\nMenu:\n");
        printf("1. Perform DFS\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Reset visited array for each DFS call
                for (int i = 0; i < vertices; i++) {
                    visited[i] = 0;
                }

                printf("Enter the starting vertex (0 to %d): ", vertices - 1);
                scanf("%d", &start);

                if (start >= 0 && start < vertices) {
                    printf("DFS Traversal starting from vertex %d: ", start);
                    dfs(graph, visited, start, vertices);
                    printf("\n");
                } else {
                    printf("Invalid starting vertex!\n");
                }
                break;

            case 2:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}
