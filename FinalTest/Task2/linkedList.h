#pragma once
#include <stdbool.h>

// A wrapper for Node.
typedef struct LinkedList LinkedList;

// A function that creates and inserts a new node to the passed linked list.
bool endInsert(char* data, LinkedList *linkedList);

// Function that creates a linked list and returns a pointer to the list thereof.
LinkedList* createList(bool *errorCode);

// A function that deletes the given list.
void deleteList(LinkedList* linkedList);

// The very function from test.
void addAStrings(LinkedList* linkedList);

// Function that checks if the two lists are the same.
bool listsTheSame(LinkedList *linkedList1, LinkedList* linkedList2);

int listLength (LinkedList* linkedList);
