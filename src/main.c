#include <stdio.h>
#include "graph.h"

/* Code test of graph library */

int main() {
    Graph graph;
    int verticeNumber = 5;

    initialize(&graph, verticeNumber);
    addNode(&graph);
    addNode(&graph);
    addNode(&graph);
    addEdge(&graph, 1, 8);
    addEdge(&graph, 5, 5);
    addEdge(&graph, 3, 2);
    print(&graph);
}