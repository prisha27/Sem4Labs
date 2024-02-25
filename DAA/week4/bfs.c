#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Structure for queue
struct Queue {
    int front;
    int rear;
    int size;
    int* arr;
};

// Function to create a new node in the adjacency list
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to create a queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->arr = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int item) {
    queue->arr[++queue->rear] = item;
    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    queue->size--;
    return queue->arr[queue->front++];
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue(graph->numVertices);
    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    // Free allocated memory for the queue
    free(queue->arr);
    free(queue);
}

int main() {
    int v, e;
    printf("\nEnter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    struct Graph* graph = createGraph(v);
    int i, s, d;

    // Add edges
    for (i = 0; i < e; i++) {
        printf("\nEnter source and destination for adding edges\n");
        scanf("%d %d", &s, &d);

        if (s < v && d < v)
            addEdge(graph, s, d);
    }
    printf("\nAdjacency List of the Graph:\n");
    printGraph(graph);
    printf("\nBFS Traversal of the Graph:\n");
    BFS(graph, 0); // Start BFS traversal from vertex 0

    return 0;
}

