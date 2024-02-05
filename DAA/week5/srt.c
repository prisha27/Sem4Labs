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

void topological_sort_source_removal(struct Graph* graph) {
    int in_degree[MAX_VERTICES] = {0};

    for (int v = 0; v < graph->vertices; ++v) {
        struct Node* temp = graph->adj_list[v];
        while (temp) {
            int adj_vertex = temp->data;
            in_degree[adj_vertex]++;
            temp = temp->next;
        }
    }

    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    for (int i = 0; i < graph->vertices; ++i) {
        if (in_degree[i] == 0) {
            queue[++rear] = i;
        }
    }

    printf("Topological Sort (Source Removal): ");
    while (front <= rear) {
        int u = queue[front++];
        printf("%d ", u);

        struct Node* temp = graph->adj_list[u];
        while (temp) {
            int adj_vertex = temp->data;
            in_degree[adj_vertex]--;
            if (in_degree[adj_vertex] == 0) {
                queue[++rear] = adj_vertex;
            }
            temp = temp->next;
        }
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

    topological_sort_source_removal(graph);

    return 0;
}
