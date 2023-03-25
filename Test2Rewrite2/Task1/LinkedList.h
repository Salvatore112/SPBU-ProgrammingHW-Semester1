#pragma once
#include <stdbool.h>

// A wrapper for Node.
typedef struct LinkedList LinkedList;

// A function that creates and inserts a new node to the passed linked list.
bool endInsert(int data, LinkedList *linkedList);

// Function that creates a linked list and returns a pointer to the list thereof.
LinkedList* createList(bool *errorCode);

// A function that prints elements of a given linked list to a given file.
void printToFile(LinkedList* linkedList, FILE* file);

void deleteList(LinkedList* linkedList);
