#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "avlTree.h"

int max(int oneValue, int anotherValue) {
    return (oneValue > anotherValue) ? oneValue : anotherValue;
}

Node* newNode(int key, char* value) {
    Node* temp = malloc(sizeof(Node));
    temp->key = key;
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

Node* rightRotate(Node* root) {
    Node* leftSubtree = root->left;
    Node* leftSubtreeRightSubtree = leftSubtree->right;

    leftSubtree->right = root;
    root->left = leftSubtreeRightSubtree;

    leftSubtree->height = max(height(leftSubtree->left), height(leftSubtree->right)) + 1;
    root->height = max(height(root->left), height(root->right)) + 1;

    return leftSubtree;
}

Node* leftRotate(Node* root) {
    Node* rightSubtree = root->right;
    Node* rightSubtreeLeftSubtree = rightSubtree->left;

    rightSubtree->left = root;
    root->right = rightSubtreeLeftSubtree;

    rightSubtree->height = max(height(rightSubtree->left), height(rightSubtree->right)) + 1;
    root->height = max(height(root->left), height(root->right)) + 1;

    return rightSubtree;
}

int getBalance(struct Node *root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

Node* insertRecursion(struct Node* root, int key, char* value) {
    if (root == NULL)
        return newNode(key, value);

    if (key < root->key)
        root->left = insertRecursion(root->left, key, value);
    else if (key > root->key)
        root->right = insertRecursion(root->right, key, value);
    else {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    //LL
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);
    //RR
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);
    //LR
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //RL
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void insert(Dictionary* dictionary, int key, char* value) {
    dictionary->root = insertRecursion(dictionary->root, key, value);
}

Node* minKeyNode(Node* root) {
    Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* deleteRecursion(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteRecursion(root->left, key);
    } else if (key > root->key) {
        root->right = deleteRecursion(root->right, key);
    } else {
        //case1: No children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
            //case2: One child
        else if (root->left == NULL) {
            Node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
            //case3 : Two children
        else {
            Node *temp = minKeyNode(root->right);
            root->key = temp->key;
            root->right = deleteRecursion(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void delete(Dictionary* dictionary, int key) {
    deleteRecursion(dictionary->root, key);
}

Dictionary* createDictionary() {
    Dictionary* temp = malloc(sizeof(Dictionary));
    if (temp == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    temp->root = NULL;
    return temp;
}