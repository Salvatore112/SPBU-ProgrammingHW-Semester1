#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    char symbol;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinarySearchTree {
    Node *root;
} BinarySearchTree;

//BinarySearchTree data type that is based on binary search tree functions
typedef struct BinarySearchTree BinarySearchTree;

//Inserts value with its data in the BinarySearchTree
void insert(BinarySearchTree* BinarySearchTree, int data, char symbol);

//Checks if a given data is in the BinarySearchTree
bool isDataHere(BinarySearchTree* BinarySearchTree, int data);

//Function that creates a BinarySearchTree
BinarySearchTree* createBinarySearchTree();

//Function that deletes a BinarySearchTree
void deleteBinarySearchTree(BinarySearchTree* BinarySearchTree);

