#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "avlTree.h"

typedef struct Node {
    char* key;
    char* data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

typedef struct Dictionary {
    Node* root;
};

int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int oneValue, int anotherValue) {
    return (oneValue > anotherValue) ? oneValue : anotherValue;
}

Node* newNode(char* key, char* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->left   = NULL;
    newNode->right  = NULL;
    newNode->height = 1;
    return(newNode);
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

struct Node* insertRecursion(struct Node* node, char* key, char* data) {
    if (node == NULL) {
        return (newNode(key, data));
    }
    if (strcmp(key, node->key) < 0) {
        node->left = insertRecursion(node->left, key, data);
    }
    else if (strcmp(key, node->key) > 0) {
        node->right = insertRecursion(node->right, key, data);
    }
    else {
        return node;
    }

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key) {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNodeRecursion(Node* root, char* key) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(key, root->key) < 0) {
        root->left = deleteNodeRecursion(root->left, key);
    } else if(strcmp(key, root->key) > 0) {
        root->right = deleteNodeRecursion(root->right, key);
    } else {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNodeRecursion(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Dictionary* createDictionary() {
    Dictionary* dictionary = malloc(sizeof(Dictionary));
    dictionary->root = NULL;
    return dictionary;
}

void deleteViaKey(Dictionary* dictionary, char *key) {
    dictionary->root = deleteNodeRecursion(dictionary->root, key);
}

Node* findNodeByKey(Node* root, char* key) {
    if (root->key == key) {
        return root;
    } else if (strcmp(key, root->key) > 0) {
        return findNodeByKey(root->right, key);
    } else {
        return findNodeByKey(root->left, key);
    }
}

bool isKeyHereRecursion(Node* root, char* key) {
    if (root == NULL) {
        return false;
    }
    else if (root->key == key) {
        return true;
    }
    else if (key <= root->key) {
        return isKeyHereRecursion(root->left, key);
    }
    else {
        return isKeyHereRecursion(root->right, key);
    }
}

bool isKeyHere(Dictionary* dictionary, char* key) {
    return isKeyHereRecursion(dictionary->root, key);
}

void insert(Dictionary* dictionary, char* key, char* data) {
    dictionary->root = insertRecursion(dictionary->root, key, data);
}

char* getValueRecursion(Node *root, char *key) {
    if (root == NULL) {
        return "NULL";
    }
    else if (root->key == key) {
        return root->data;
    }
    else if (key <= root->key) {
        return getValueRecursion(root->left, key);
    }
    else {
        return getValueRecursion(root->right, key);
    }
}

char* getValue(Dictionary* dictionary, char* key) {
    return getValueRecursion(dictionary->root, key);
}

void postorderRecursion(Node *root) {
    if (root == NULL) {
        return;
    }
    postorderRecursion(root->left);
    postorderRecursion(root->right);
    free(root);
}

void deleteDictionary(Dictionary* dictionary) {
    postorderRecursion(dictionary->root);
}

void changeData(Dictionary* dictionary, char* key, char* newData) {
    Node* temp = findNodeByKey(dictionary->root, key);
    temp->data = newData;
}

