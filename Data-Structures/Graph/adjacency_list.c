#include <stdio.h>
#include <stdlib.h>

/* =========================================================
 * DATA STRUCTURES
 * ========================================================= */

// Edge structure (Linked list node)
typedef struct EdgeNode {
    int destination;
    struct EdgeNode* next;
} EdgeNode;

// Graph structure (Control Panel)
typedef struct Graph {
    int numVertices;
    EdgeNode** adjLists; // Dynamic array of pointers to the lists
} Graph;

/* =========================================================
 * CREATION AND INSERTION FUNCTIONS
 * ========================================================= */

// Initializes the graph in RAM in O(V) time
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    
    // calloc ensures all pointers are initialized to NULL
    graph->adjLists = (EdgeNode**)calloc(numVertices, sizeof(EdgeNode*));
    
    return graph;
}

// Adds a directed edge (source -> destination) in O(1) time
void addEdge(Graph* graph, int source, int destination) {
    EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
    newEdge->destination = destination;
    
    // Inserts the new node at the BEGINNING of the list to guarantee O(1)
    newEdge->next = graph->adjLists[source];
    graph->adjLists[source] = newEdge;
}

/* =========================================================
 * EXECUTION TEST
 * ========================================================= */
int main() {
    // 1. Define the graph size (e.g., 5 vertices, IDs from 0 to 4)
    int numVertices = 5;
    Graph* myGraph = createGraph(numVertices);

    // 2. Add the connections (Source -> Destination)
    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 4);
    
    // Vertex 1 will point to 2 and then to 3
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 1, 3); 
    
    addEdge(myGraph, 3, 4);

    // 3. Visual memory validation
    printf("Graph initialized with %d vertices.\n", myGraph->numVertices);
    
    // Let's check who is at the top of Vertex 1's list.
    // Since insertion is O(1) (always pushes to the head), 
    // the LAST one added (3) must be the FIRST in the queue.
    if (myGraph->adjLists[1] != NULL) {
        printf("The first connection of Vertex 1 points to Vertex: %d\n", myGraph->adjLists[1]->destination);
    }

    return 0;
}
