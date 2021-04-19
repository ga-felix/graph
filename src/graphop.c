#include <stdio.h>
#include "graph.h"

/* Initializes a new graph, setting all fields to empty default value */

bool initialize(Graph *graph, int nodesNumber) {

    if(!nodeExists(nodesNumber)) {
        fprintf(stderr, "[ERROR] nodes number is invalid %d\n", nodesNumber);
        return false;
    }
    graph->nodesNumber = nodesNumber; // Signs the number of nodes
    graph->edgesNumber = 0;

    for(int line = 0; line < graph->nodesNumber; line++) { // Initialize matrix structure
        for(int column = 0; column < graph->nodesNumber; column++) {
            graph->adjacencyList[line][column] = EMPTY_EDGE;
        }
    }
    return true;
}

/* Prints a graph structure, going through each valid/existent edge
value. */

bool print(Graph *graph) {

    if(graph->nodesNumber == 0) {
        fprintf(stderr, "[ERROR] Cannot print an empty graph\n");
        return false;
    }

    for(int line = 1; line <= graph->nodesNumber; line++) {
        fprintf(stdout, "[PRINT] Node %d\nConnections: ", line);
        for(int column = 1; column <= graph->nodesNumber; column++) {
            if(isConnected(line, column)) {
                fprintf(stdout, "%d, ", column);
            }
        }
        fprintf(stdout, "\n");
    }

    return true;
}

/* Adds a node incrementing graph nodesNumber attribute. It's a property
of this adjancency matrix incremental model (which is simple) */

bool addNode(Graph *graph) {

    if(graph->nodesNumber == SIZE) {
        fprintf(stderr, "[ERROR] Cannot insert new node: graph is full\n");
        return false;
    }

    graph->nodesNumber += 1;

    fprintf(stdout, "[INSERT-NODE] Node %d inserted\n", graph->nodesNumber);
    return true;
}

/* Checks node value validity (if it's inbounds) */

bool nodeExists(Graph* graph, int node) {
    return (node <= graph->nodesNumber && node > 0);
}

/* Checks if there's an edge of any weight between two nodes */

bool isConnected(Graph* graph, int fromNode, int toNode) {
    return (graph->adjacencyList[fromNode][toNode] != EMPTY_EDGE);
}

/* Creates an edge between two given nodes. If it already exists,
increments weight value */

bool addEdge(Graph *graph, int fromNode, int toNode, Weight weight) {

    if(!nodeExists(graph, fromNode) || !nodeExists(graph, toNode)) {
        fprintf(stderr, "[ERROR] Cannot insert new edge: node %d or %d value(s) out of bounds\n", fromNode, toNode);
        return false;
    }

    if(isConnected(graph, fromNode, toNode)) {
        graph->adjacencyList[fromNode][toNode] = weight;
        // graph->adjacencyList[toNode][fromNode] = weight; // Uncomment to generate a digraph
    }
    
    fprintf(stdout, "[INSERT-EDGE] Edge inserted between %d and %d of weight %d\n", fromNode, toNode, graph->adjacencyList[fromNode][toNode]);
    return true;
    
}

/* Removes a node. Reverse logic of addNode function */ 

bool removeNode(Graph *graph) {

    if(graph->nodesNumber == 0) {
        fprintf(stderr, "[ERROR] Cannot remove node because graph is empty\n");
        return false;
    }

    graph->nodesNumber -= 1;

    fprintf(stdout, "[REMOVE-NODE] Node %d removed\n", graph->nodesNumber + 1);
}

/* Removes an edge between two given nodes */

bool removeEdge(Graph *graph, int fromNode, int toNode) {

    if(!nodeExists(graph, fromNode) || !nodeExists(graph, toNode)) {
        fprintf(stderr, "[ERROR] Cannot remove edge: node %d or %d value(s) out of bounds\n", fromNode, toNode);
        return false;
    }

    if(!isConnected(graph, fromNode, toNode)) {
        fprintf(stderr, "[ERROR] Cannot remove edge: nodes %d and %d edge not found\n", fromNode, toNode);
        return false;
    }

    graph->adjacencyList[fromNode][toNode] = EMPTY_EDGE;
    // graph->adjacencyList[toNode][fromNode] = EMPTY_EDGE; // Uncomment if you want a digraph
    
    fprintf(stdout, "[REMOVE-EDGE] Edge removed between %d and %d\n", fromNode, toNode);
    return true;
    
}

/* Checks if an edge has neighbors */

bool noNeighbors(Graph *graph, int node) {
    
    if(!nodeExists(graph, node)) {
        fprintf(stderr, "[ERROR] Cannot check if node has neighbors: value %d out of bounds\n", node)
        return false;
    }

    for(int column = 1; column <= graph->nodesNumber; column++) {
        if(isConnected(node, column)) {
            return false;
        }
    }

    return true;

}

/* Returns next neighbor to a node */

int nextNeighbor(Graph *graph, int node, int adjacentNode) {

    if(!nodeExists(graph, node) || !nodeExists(graph, adjacentNode)) {
        fprintf(stderr, "[ERROR] Cannot check next neighbor: node %d or %d value(s) out of bounds\n", node, adjacentNode);
        return EMPTY_NODE;
    }

    for(int column = adjacentNode + 1; column <= graph->nodesNumber; column++) {
        if(isConnected(graph, node, column)) {
            return graph->adjacencyList[node][column];
        }
    }

    return EMPTY_NODE;
}