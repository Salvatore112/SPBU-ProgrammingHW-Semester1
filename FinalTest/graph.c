#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"


typedef struct Graph  {
    int numNodes;
    bool** edges;
} Graph;

Graph* createGraph(int numNodes) {
    Graph *graph = malloc(sizeof(Graph));
    if (graph == NULL) {
        return NULL;
    }

    graph->numNodes = numNodes;

    graph->edges = calloc(sizeof(bool*), graph->numNodes);
    if (graph->edges == NULL) {
        free(graph);
        return NULL;
    }

    for (int i = 0; i < graph->numNodes; i++) {
        graph->edges[i] = calloc(sizeof(bool), graph->numNodes);
        if (graph->edges[i] == NULL) {
            deleteGraph(graph);
            return NULL;
        }
    }

    for (int i = 0; i < numNodes; i++) {
        graph->edges[i][i] = true;
    }

    return graph;
}

void deleteGraph(Graph* graph) {
    if (graph->edges == NULL) {
        return;
    }
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->edges[i] != NULL) {
            free(graph->edges[i]);
        }
    }
    free(graph->edges);
    free(graph);
}

void printGraph(Graph* graph) {
    printf("digraph { \n");

    for (int from = 0; from < graph->numNodes; from++) {
        for (int to = 0; to < graph->numNodes; to++) {
            if (graph->edges[from][to]) {
                printf("    %d -> %d;\n", from, to);
            }
        }
    }
    printf("}\n");
}

bool addEdge(Graph* graph, int fromNode, int toNode) {
    if (hasEdge(graph, fromNode, toNode)) {
        return false;
    }
    graph->edges[fromNode][toNode] = true;
    return true;
}

bool hasEdge(Graph* graph, int fromNode, int toNode) {
    return graph->edges[fromNode][toNode];
}

const bool* findNodes(Graph* graph, int numberOfNodes) {
    bool *bitScale = calloc(numberOfNodes, sizeof( bool ));
    for (int i = 0; i < numberOfNodes; i++) {
        bool badNode = false;
        for (int j = 0; j < numberOfNodes; j++) {
            if (graph->edges[i][j] != true && i != j) {
                bitScale[i] = false;
                badNode = true;
                break;
            }
        }
        if (!badNode) {
            bitScale[i] = true;
        } else {
            bitScale[i] = false;
        }
    }
    return bitScale;
}