#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BstNode {
    int data;
    char operation;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

typedef struct BinarySearchTree {
    BstNode *root;
} BinarySearchTree;

//BinarySearchTree data type that is based on binary search tree functions
typedef struct BinarySearchTree BinarySearchTree;

//Inserts value with its data in the BinarySearchTree
void insert(BinarySearchTree* BinarySearchTree, int data);

//Deletes value of the given data
void delete(BinarySearchTree* BinarySearchTree, int data);

//Checks if a given data is in the BinarySearchTree
bool isDataHere(BinarySearchTree* BinarySearchTree, int data);

//Function that creates a BinarySearchTree
BinarySearchTree* createBinarySearchTree();

//Function that deletes a BinarySearchTree
void deleteBinarySearchTree(BinarySearchTree* BinarySearchTree);

//*********************************8

BstNode* parseTreeRecursion(char string[], int *position);

BinarySearchTree* createParseTree(char string[]);