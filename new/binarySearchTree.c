#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarySearchTree.h"

Node* getNewNode(int data, char symbol);
bool search(Node *root, int data);
Node* deleteRecursion(Node* root, int data);

char* getValueRecursion(Node *root, int data);
void postorderRecursion(Node *root);
//***
Node* parseTreeRecursion(char string[], int *position);

Node* insertRecurion(Node** root, int data, char symbol) {
    if (*root == NULL) {
        *root = getNewNode(data, symbol);
    }
    else if (data <= (*root)->data) {
        (*root)->left = insertRecurion(&(*root)->left, data, symbol);
    }
    else {
        (*root)->right = insertRecurion(&(*root)->right, data, symbol);
    }
    return *root;
}

void insert(BinarySearchTree* BinarySearchTree, int data, char symbol) {
    insertRecurion(&(BinarySearchTree->root), data, symbol);
}

Node* getNewNode(int data, char symbol) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->symbol = symbol;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool search(Node *root, int data) {
    if (root == NULL) {
        return false;
    }
    else if (root->data == data) {
        return true;
    }
    else if (data <= root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

bool isDataHere(BinarySearchTree* BinarySearchTree, int data) {
    if (search(BinarySearchTree->root, data)) {
        return true;
    }
    return false;
}

void delete(BinarySearchTree* BinarySearchTree, int data) {
    deleteRecursion(BinarySearchTree->root, data);
}

Node* deleteRecursion(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    else if (data < root->data) {
        root->left = deleteRecursion(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteRecursion(root->right, data);
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
            root->data = temp->data;
            root->right = deleteRecursion(root->right, data);
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

void postorderRecursion(Node *root) {
    if (root == NULL) {
        return;
    }
    postorderRecursion(root->left);
    postorderRecursion(root->right);
    free(root);
}


