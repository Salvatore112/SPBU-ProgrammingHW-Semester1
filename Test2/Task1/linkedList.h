#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//a wrapper for Node /
typedef struct LinkedList LinkedList;

//function that inserts an element at any
void insert(int value, int index, LinkedList *linkedList);

//function that creates a linked list /
LinkedList* createList();

//function that allows you to access a linked list elements via their index /
int accessElement(int index, LinkedList *linkedList);

//function that checks if the given list is symmetrical (returns true if it's symmetrical)
bool isSymmetrical(LinkedList* linkedList);

//return a length of the linked list given
int listLength(LinkedList* linkedList);

void deleteList(LinkedList* linkedList);
