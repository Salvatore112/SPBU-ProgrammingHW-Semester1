#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//a wrapper for Node /
typedef struct LinkedList LinkedList;

//function that inserts an element at any 
void insert(int value, LinkedList *linkedList);

//inserts the a value right before the bigger man
void orderInsert(int value, LinkedList *linkedList);

//function that prints all the elements of the list / 
void printList(LinkedList *linkedList);

//function that creates a linked list /
LinkedList* createList();

//function that allows you to access a linked list elements via their index /
int accessElement(int index, LinkedList *linkedList);

int listLength(LinkedList* linkedList);