#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarySearchTree.h"

BstNode* getNewNode(int data);
bool search(BstNode *root, int data);
BstNode* deleteRecursion(BstNode* root, int data);
BstNode* insertRecurion(BstNode** root, int data);
char* getValueRecursion(BstNode *root, int data);
void postorderRecursion(BstNode *root);
//***
BstNode* parseTreeRecursion(char string[], int *position);

void insert(BinarySearchTree* BinarySearchTree, int data) {
    insertRecurion(&(BinarySearchTree->root), data);
}

BstNode* insertRecurion(BstNode** root, int data) {
    if (*root == NULL) {
        *root = getNewNode(data);
    }
    else if (data <= (*root)->data) {
        (*root)->left = insertRecurion(&(*root)->left, data);
    }
    else {
        (*root)->right = insertRecurion(&(*root)->right, data);
    }
    return *root;
}

BstNode* getNewNode(int data) {
    BstNode* newNode = malloc(sizeof(BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool search(BstNode *root, int data) {
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

BstNode* deleteRecursion(BstNode* root, int data) {
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
            BstNode* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            BstNode* temp = root;
            root = root->left;
            free(temp);
        }
        //case3 : Two children
        else {
            BstNode* temp = root->right;
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

void postorderRecursion(BstNode *root) {
    if (root == NULL) {
        return;
    }
    postorderRecursion(root->left);
    postorderRecursion(root->right);
    free(root);
}

//***********************************

BinarySearchTree* createParseTree(char string[]) {
    BinarySearchTree* temp = createBinarySearchTree();
    int position = 0;
    temp->root = parseTreeRecursion(string, &position);
    return temp;
}

BstNode* parseTreeRecursion(char string[], int *position) {
    (*position) += 1;
    while (string[*position] == ' ' || string[*position] == '(' || string[*position] == ')') {
        (*position) += 1;
    }
    BstNode *root = malloc(sizeof(BstNode));
    if (root == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    root->data = 24;
    if (string[*position] == '+' || string[*position] == '-' || string[*position] == '*' || string[*position] == '/') {
        root->operation = string[*position];
        root->left = parseTreeRecursion(string, position);
        root->right = parseTreeRecursion(string, position);
    }
    else {
        int value = string[*position] - '0';
        root->data = value;
    }
    return root;
}