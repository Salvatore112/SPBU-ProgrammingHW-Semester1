#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//a wrapper for Node
typedef struct LinkedList LinkedList;

//function that creates a linked list
LinkedList* createList();

//inserts a new element to the beginning of the list
void listInsertBeginning(char* word, LinkedList *linkedList);

//returns the value of the frequency field
int getFrequency(LinkedList* linkedList);

//returns the value of the word field
const char* getWord(LinkedList* linkedList);

//moves head forward by one element
bool listTraverse(LinkedList* linkedList);

//cheeks to see if the word is in the list
bool isInTheList(LinkedList* linkedList, char* word);

//increments a frequency by 1
void incrementFrequency(LinkedList* linkedList, char* word);

//returns the length of the list
int listLength(LinkedList* linkedList);

//sets "newFrequency" elements with the "word" field
void conveyFrequency(LinkedList* linkedList, char* word, int newFrequency);

//checks to see if the head points to NULL
bool isEmpty(LinkedList* linkedList);
