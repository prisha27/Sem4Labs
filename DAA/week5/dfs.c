#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adj_list;
};

struct Graph* create_graph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adj_list = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; ++i) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

void add_edge(struct Graph* graph, int u, int v) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = v;
    new_node->next = graph->adj_list[u];
    graph->adj_list[u] = new_node;
}

void topological_sort_dfs_util(struct Graph* graph, int v, int visited[MAX_VERTICES], int* stack, int* stack_index) {
    visited[v] = 1;

    struct Node* temp = graph->adj_list[v];
    while (temp) {
        int adj_vertex = temp->data;
        if (!visited[adj_vertex]) {
            topological_sort_dfs_util(graph, adj_vertex, visited, stack, stack_index);
        }
        temp = temp->next;
    }

    stack[(*stack_index)++] = v;
}

void topological_sort_dfs(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int stack_index = 0;

    for (int i = 0; i < graph->vertices; ++i) {
        if (!visited[i]) {
            topological_sort_dfs_util(graph, i, visited, stack, &stack_index);
        }
    }

    printf("Topological Sort (DFS): ");
    for (int i = stack_index - 1; i >= 0; --i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = create_graph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(graph, u, v);
    }

    topological_sort_dfs(graph);

    return 0;
}

/* 
// Function to print the graph:

void print_graph(struct Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        struct Node* current = graph->adj_list[i];
        printf("Vertex %d: ", i);
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}
*/