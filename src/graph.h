#include <stdbool.h>

#define SIZE 50 + 1 /* Avoids '0' nodes value: vertices range 1 to SIZE */
#define EMPTY_EDGE -1 /* Signs an empty edge
#define EMPTY_NODE -1 /* Signs an empty node

/* Avoids variable types replacement */

typedef int Weight;

/* Defines graph structure, as well it's attributes */

typedef struct {
    Weight adjacencyList[SIZE][SIZE];
    int nodesNumber;
    int edgesNumber;
} Graph;

/* Initializes a new graph */

bool initialize(Graph *graph, int nodesNumber);

/* Prints a graph structure */

bool print(Graph *graph);

/* Checks if node value validity */

bool nodeExists(Graph *graph, int node);

/* Checks if there's an edge between two nodes */

bool isConnected(Graph *graph, int fromNode, int toNode);

/* Inserts a node */

bool addNode(Graph *graph);

/* Inserts an edge */

bool addEdge(Graph *graph, int firstNode, int secondNode);

/* Removes a node */

bool removeNode(Graph *graph);

/* Removes an edge */

bool removeEdge(Graph *graph, int firstNode, int secondNode);

/* Reinitializes an existent graph */

bool reinitialize(Graph *graph);

/* Checks if there's a path between two nodes */

bool isReachable(Graph *graph, int fromNode, int toNode);

/* Checks if graph has cycles */

bool hasCycles(Graph *graph);

/* Returns node degree */

int nodeDegree(Graph* graph, int node);

/* Returns entry degree of node */

int entryDegree(Graph* graph, int node);

/* Returns exit degree of node */

int exitDegree(Graph* graph, int node);

/* Finds the shortest path between two nodes */

bool shortestPath(Graph* graph, int fromNode, int toNode);

/* Finds the minimum cost path between two nodes */

bool minimumPath(Graph* graph, int fromNode, int toNode);