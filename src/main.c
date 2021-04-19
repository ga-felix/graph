#include <stdio.h>
#include "graph.h"

/* Code test of graph library */

int main() {
    Graph graph;
    int verticeNumber = 5;

    initialize(&graph, verticeNumber);
    addEdge(&graph, 1, 5, 3);
    addEdge(&graph, 3, 2, 7);
    addEdge(&graph, 3, 5, 4);
    print(&graph);
}