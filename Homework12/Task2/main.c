#include <stdio.h>
#include "graph.h"

int main() {
    FILE* file = fopen("graph.dot", "w");

    Graph* graph = createGraph(5);
    addEdge(graph, 4, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    printGraph(graph);
    codeGraph(file, graph);
    system("script.bat");
    deleteGraph(graph);
    return 0;
}
