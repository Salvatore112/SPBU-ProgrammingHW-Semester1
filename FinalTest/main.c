#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

#define NUMBER_OF_NODES 5

bool tests();
bool areTheSameArrays(bool array1[], bool array2[], int length);

int main(void) {
    if (!tests()) {
        return 1;
    }
    Graph* graph = createGraph(NUMBER_OF_NODES);
    addEdge(graph, 0 ,1);
    addEdge(graph, 0 ,2);
    addEdge(graph, 0 ,3);
    addEdge(graph, 0 ,4);
    printGraph(graph);

    bool* soughtNodes = findNodes(graph, NUMBER_OF_NODES);

    for (int i = 0; i < NUMBER_OF_NODES; i++) {
        if (soughtNodes[i] == true) {
            printf("%d is a sought node\n", i);
        }
    }

    deleteGraph(graph);
    return 0;
}

bool tests() {
    Graph* testGraph1 = createGraph(6);
    addEdge(testGraph1, 0 ,1);
    addEdge(testGraph1, 0 ,2);
    addEdge(testGraph1, 0 ,3);
    addEdge(testGraph1, 0 ,4);
    addEdge(testGraph1, 0 ,5);

    addEdge(testGraph1, 4 ,0);
    addEdge(testGraph1, 4 ,2);
    addEdge(testGraph1, 4 ,3);
    addEdge(testGraph1, 4 ,1);
    addEdge(testGraph1, 4 ,5);

    bool *soughtNodes1 = findNodes(testGraph1, 6);

    bool expectedScale[6] = {1, 0, 0, 0, 1, 0};

    if (!areTheSameArrays(soughtNodes1, expectedScale, 6)) {
        printf("Test failed\n");
        deleteGraph(testGraph1);
        return false;
    }
    deleteGraph(testGraph1);
    return true;
}

bool areTheSameArrays(bool array1[], bool array2[], int length) {
    for (int i = 0; i < length; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}