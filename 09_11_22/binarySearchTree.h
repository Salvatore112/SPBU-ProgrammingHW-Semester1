#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int frequency;
    char symbol;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinarySearchTree {
    Node *root;
} BinarySearchTree;

//BinarySearchTree frequency type that is based on binary search tree functions
typedef struct BinarySearchTree BinarySearchTree;

//Inserts value with its frequency in the BinarySearchTree
void insert(BinarySearchTree* BinarySearchTree, int frequency, char symbol);

//Checks if a given frequency is in the BinarySearchTree
bool isfrequencyHere(BinarySearchTree* BinarySearchTree, int frequency);

//Function that creates a BinarySearchTree
BinarySearchTree* createBinarySearchTree();

//Function that deletes a BinarySearchTree
void deleteBinarySearchTree(BinarySearchTree* BinarySearchTree);

