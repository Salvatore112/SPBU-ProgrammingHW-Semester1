#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//a wraper for Node
typedef struct LinkedList LinkedList;

//function that creates a linked list used in creating circular linked list/
LinkedList* createList();

//creates a circular list with elements 1...n;
LinkedList* createCircle(int n);

// Josephus count
int count(LinkedList *circularList, int m );


