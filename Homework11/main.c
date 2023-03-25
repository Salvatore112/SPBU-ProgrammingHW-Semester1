#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "linkedList.h"

void printMatrix(int** matrix, int cities);
bool allConquered(bool conquered[], int length);
void conquer(LinkedList* state, int** matrix,bool conquered[], int cities);

int main() {
    FILE* file = fopen("input.txt", "r");
    int cities = 0;
    fscanf(file, "%d", &cities);
    int roads = 0;
    fscanf(file, "%d", &roads);
    int** matrix = calloc(cities, sizeof(int*));
    if (matrix == NULL) {
        printf("Out of memory\n");
        return 1;
    }
    for (int i = 0; i < cities; i++) {
        matrix[i] = calloc(cities, sizeof(int*));
    }
    for (int i = 0; i < roads; i++) {
        int row = 0;
        int column = 0;
        int length = 0;
        fscanf(file, "%d", &row);
        fscanf(file, "%d", &column);
        fscanf(file, "%d", &length);
        matrix[row][column] = matrix[column][row] = length;
    }
    int capitalsAmount = 0;
    fscanf(file, "%d", &capitalsAmount);
    LinkedList** capitalsScale = calloc(cities, sizeof(LinkedList*));
    if (capitalsScale == NULL) {
        printf("Out of memory\n");
        return 1;
    }
    bool* conquered = calloc(cities, sizeof(bool));
    if (conquered == NULL) {
        printf("Out of memory\n");
        return 1;
    }
    for (int i = 0; i < capitalsAmount; i++) {
        int capital = 0;
        fscanf(file, "%d", &capital);
        capitalsScale[capital] = createList();
        insert(capital, capitalsScale[capital]);
        conquered[capital] = true;
    }
    int i = 0;
    while (!allConquered(conquered, cities)) {
        while (capitalsScale[i] == NULL) {
            i++;
        }
        conquer(capitalsScale[i], matrix, conquered, cities);
        i++;
        if (i >= cities) {
            i = 0;
        }
    }
    printMatrix(matrix, cities);
    for (int i = 0; i < cities; i++) {
        if (capitalsScale[i] != NULL) {
            printList(capitalsScale[i]);
        }
    }
    free(conquered);
    free(matrix );
    return 0;
}

void printMatrix(int** matrix, int cities) {
    printf(" ");
    for(int i = 0; i < cities; i++) {
        printf(" %d", i);
    }
    printf("\n");
    for (int i = 0; i < cities; i++) {
        printf("%d|", i);
        for (int j = 0; j < cities; j ++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool allConquered(bool conquered[], int length) {
    for (int i = 0; i < length; i++) {
        if (conquered[i] == false) {
            return false;
        }
    }
    return true;
}

void conquer(LinkedList* state, int** matrix, bool conquered[], int cities) {
    int nearestDistance = INT_MAX;
    int nearestCity = -1;
    int length = listLength(state);
    for (int i = 0; i < length; i++) {
        int stateCity = accessElement(i, state);
        for (int j = 0; j < cities; j++) {
            int matrixElement = matrix[stateCity][j];
            if (matrixElement != 0 && conquered[j] != true) {
                if (nearestDistance > matrix[stateCity][j]) {
                    nearestDistance = matrix[stateCity][j];
                    nearestCity = j;
                }
            }
        }
    }
    if (nearestCity != -1) {
        insert(nearestCity, state);
        conquered[nearestCity] = true;
    }
}
