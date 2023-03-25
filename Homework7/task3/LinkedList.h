#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//struct that holds values and a link to another struct (next element of the list) /
typedef struct Node Node;

//a wrapper for Node /
typedef struct LinkedList LinkedList;

//function that inserts an element at any position of the array /
void insert(int value, char *name, int index, LinkedList *linkedList);

//function that prints all the elements of the list /
void printList(LinkedList *linkedList);

//function that creates a linked list /
LinkedList* createList();

//a wrapper that launches the first recursion of merge sort /
void mergeSort(LinkedList *linkedList, bool byName);

//function that splits a linked list into two parts /
void split(Node *head, Node **front, Node **back);

//merge sort itself /
void mergeSortRecursion(Node **head, bool byName);

//function that checks if a linkedList is sorted /
bool isSorted(LinkedList *linkedList, bool byName);

//function that takes two sorted linked lists and merges them into a whole one /
Node* mergeSortedLists(Node *front, Node *back, bool byName);

// function that deletes a linked list freeing memory /
void deleteList(LinkedList *list);
