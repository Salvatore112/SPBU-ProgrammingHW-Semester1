#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Dictionary data type that is based on binary search tree functions
typedef struct BinarySearchTree BinarySearchTree;

//Inserts value with its key in the dictionary
void insert(BinarySearchTree* dictionary, int value);

//Function that creates a dictionary
BinarySearchTree* createBinarySearchTree();

//Function that deletes a binary search tree given
void deleteBinarySearchTree(BinarySearchTree* dictionary);

//Sorts an array by building a binary search tree with its elements and rewriting the array by in order traversal
void inOrderSort(int array[], int length);
