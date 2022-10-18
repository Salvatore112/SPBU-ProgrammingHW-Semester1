#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node 
{
    char* element;
    struct Node *previous;
} Node; // struct that holds the element at the top and the pointer to the element under it

char* push(Node **head, char *element); // Function that adds a new element at the top of the stack

char* pop(Node **head, int *errorCode); // Function that removes a new element at the top of the stack

bool isEmpty(Node *head); // Function that checks if the stack is empty

char* peek(Node *head); // Function that returns the current element at the top of the stack

void clear(Node **head); // Function that removes all the elements from the stack

void displayStack(Node *stack); //Function that displays all the elements of the stack



