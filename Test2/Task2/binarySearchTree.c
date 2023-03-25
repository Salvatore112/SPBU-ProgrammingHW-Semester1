#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarySearchTree.h"

typedef struct BstNode {
    int value;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

typedef struct BinarySearchTree {
    BstNode *root;
} BinarySearchTree;

BstNode* getNewNode(int value) {
    BstNode* newNode = malloc(sizeof(BstNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode* insertRecurion(BstNode** root, int value) {
    if (*root == NULL) {
        *root = getNewNode(value);
    }
    else if (value <= (*root)->value) {
        (*root)->left = insertRecurion(&(*root)->left, value);
    }
    else {
        (*root)->right = insertRecurion(&(*root)->right, value);
    }
    return *root;
}

void insert(BinarySearchTree* dictionary, int value) {
    insertRecurion(&(dictionary->root), value);
}

BinarySearchTree* createBinarySearchTree() {
    BinarySearchTree* tree = malloc(sizeof(BinarySearchTree));
    tree->root = NULL;
    return tree;
}

void deleteRecursion(BstNode *root) {
    if (root == NULL) {
        return;
    }
    deleteRecursion(root->left);
    deleteRecursion(root->right);
    free(root);
}

void deleteBinarySearchTree(BinarySearchTree* dictionary) {
    deleteRecursion(dictionary->root);
}

void inOrderTraversal(BstNode* root, int array[], int *index) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left, array, index);
    array[*index] = root->value;
    (*index)++;
    inOrderTraversal(root->right, array, index);

}

void inOrderSort(int array[], int length) {
    BinarySearchTree* tree = createBinarySearchTree();
    for (int i = 0; i < length; i++) {
        insert(tree, array[i]);
    }
    int index = 0;
    inOrderTraversal(tree->root, array, &index);
    deleteRecursion(tree->root);
}