#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    char* value;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

typedef struct Dictionary {
    Node* root;
} Dictionary;

int max(int oneValue, int anotherValue);

Node* newNode(int key, char* value);

int height(Node* node);

Node* rightRotate(Node* root);

Node* leftRotate(Node* root);

Node* insert(struct Node* root, int key, char* value);

Node* delete(Node* root, int key);

Node* minKeyNode(Node* root);