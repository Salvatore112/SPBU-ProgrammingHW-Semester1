#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//struct that holds the element at the top and the pointer to the element under it
typedef struct Node {
    int element;
    struct Node *previous;
} Node; 

// Function that adds a new element at the top of the stack.
void push(Node **head, int element, int *errorCode);

// Function that removes a new element at the top of the stack.
int pop(Node **head, int *errorCode);

// Function that checks if the stack is empty.
bool isEmpty(Node *head);

// Function that returns the current element at the top of the stack.
int peek(Node *head, int *errorCode);

// Function that removes all the elements from the stack.
void clear(Node **head); 

// Function that displays all the elements of the stack.
void displayStack(Node *stack); 



