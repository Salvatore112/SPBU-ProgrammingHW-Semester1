#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node; // struct that holds the element at the top and the pointer to the element under it

int push(Node **head, int element); // Function that adds a new element at the top of the stack

int pop(Node **head, int *errorCode); // Function that removes a new element at the top of the stack

bool isEmpty(Node *head); // Function that checks if the stack is empty

int peek(Node *head); // Function that returns the current element at the top of the stack

void clear(Node **head); // Function that removes all the elements from the stack




