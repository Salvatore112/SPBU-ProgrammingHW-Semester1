#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph Graph;

Graph* createGraph(int numNodes);

void deleteGraph(Graph* graph);

void printGraph(Graph* graph);

bool addEdge(Graph* graph, int fromNode, int toNode);

bool hasEdge(Graph* graph, int fromNode, int toNode);

void codeGraph(FILE* file, Graph* graph);