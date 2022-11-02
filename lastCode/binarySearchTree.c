#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarySearchTree.h"

Node* getNewNode(int frequency, char symbol);
bool search(Node *root, int frequency);
Node* deleteRecursion(Node* root, int frequency);

char* getValueRecursion(Node *root, int frequency);
void postorderRecursion(Node *root);
//***
Node* parseTreeRecursion(char string[], int *position);

Node* insertRecurion(Node** root, int frequency, char symbol) {
    if (*root == NULL) {
        *root = getNewNode(frequency, symbol);
    }
    else if (frequency <= (*root)->frequency) {
        (*root)->left = insertRecurion(&(*root)->left, frequency, symbol);
    }
    else {
        (*root)->right = insertRecurion(&(*root)->right, frequency, symbol);
    }
    return *root;
}

void insert(BinarySearchTree* BinarySearchTree, int frequency, char symbol) {
    insertRecurion(&(BinarySearchTree->root), frequency, symbol);
}

Node* getNewNode(int frequency, char symbol) {
    Node* newNode = malloc(sizeof(Node));
    newNode->frequency = frequency;
    newNode->symbol = symbol;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool search(Node *root, int frequency) {
    if (root == NULL) {
        return false;
    }
    else if (root->frequency == frequency) {
        return true;
    }
    else if (frequency <= root->frequency) {
        return search(root->left, frequency);
    }
    else {
        return search(root->right, frequency);
    }
}

bool isfrequencyHere(BinarySearchTree* BinarySearchTree, int frequency) {
    if (search(BinarySearchTree->root, frequency)) {
        return true;
    }
    return false;
}

void delete(BinarySearchTree* BinarySearchTree, int frequency) {
    deleteRecursion(BinarySearchTree->root, frequency);
}

Node* deleteRecursion(Node* root, int frequency) {
    if (root == NULL) {
        return NULL;
    }
    else if (frequency < root->frequency) {
        root->left = deleteRecursion(root->left, frequency);
    }
    else if (frequency > root->frequency) {
        root->right = deleteRecursion(root->right, frequency);
    }
    else {
        //case1: No children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
            //case2: One child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
            //case3 : Two children
        else {
            Node* temp = root->right;
            root->frequency = temp->frequency;
            root->right = deleteRecursion(root->right, frequency);
        }
        return root;
    }
}

BinarySearchTree* createBinarySearchTree() {
    BinarySearchTree* tree = malloc(sizeof(BinarySearchTree));
    if (tree == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    tree->root = NULL;
    return tree;
}

void deleteBinarySearchTree(BinarySearchTree* BinarySearchTree) {
    postorderRecursion(BinarySearchTree->root);
}



