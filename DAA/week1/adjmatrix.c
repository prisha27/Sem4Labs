#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int v;
    int e;
    int** adj;
};

struct Graph* adjmatrix() {
    int u, v1, i;
    struct Graph* G = (struct Graph*)malloc(sizeof(struct Graph));
    printf("\nEnter number of vertices: ");
    scanf("%d", &G->v);
    printf("Enter number of edges: ");
    scanf("%d", &G->e);

    // Allocate memory for adjacency matrix
    G->adj = (int**)malloc(G->v * sizeof(int*));
    for (u = 0; u < G->v; u++) {
        G->adj[u] = (int*)malloc(G->v * sizeof(int));
        for (v1 = 0; v1 < G->v; v1++) {
            G->adj[u][v1] = 0; // Initialize all elements to 0
        }
    }

    printf("\nEnter pairs of edges:\n");
    for (i = 0; i < G->e; i++) {
        scanf("%d %d", &u, &v1);
        G->adj[u][v1] = 1;
        G->adj[v1][u] = 1; // For undirected graph, consider both directions
    }

    return G;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < graph->v; i++) {
        for (int j = 0; j < graph->v; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = adjmatrix();
    printGraph(graph);

    // Free allocated memory
    //for (int i = 0; i < graph->v; i++) {
       // free(graph->adj[i]);
    //}
   // free(graph->adj);
    //free(graph);

    return 0;
}
