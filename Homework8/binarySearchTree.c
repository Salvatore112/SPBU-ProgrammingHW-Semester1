#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarySearchTree.h"

typedef struct BstNode {
    int key;
    char* value;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

struct Dictionary {
    BstNode *root;
};

BstNode* getNewNode(int key, char* value) {
    BstNode* newNode = malloc(sizeof(BstNode));
    newNode->key = key;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode* insertRecurion(BstNode** root, int key, char* value) {
    if (*root == NULL) {
        *root = getNewNode(key, value);
    }
    else if (key <= (*root)->key) {
        (*root)->left = insertRecurion(&(*root)->left, key, value);
    }
    else {
        (*root)->right = insertRecurion(&(*root)->right, key, value);
    }
    return *root;
}

void insert(Dictionary* dictionary, int key, char* value) {
    insertRecurion(&(dictionary->root), key, value);
}

bool search(BstNode *root, int key) {
    if (root == NULL) {
        return false;
    }
    else if (root->key == key) {
        return true;
    }
    else if (key <= root->key) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

char* getValueRecursion(BstNode *root, int key) {
    if (root == NULL) {
        return "NULL";
    }
    else if (root->key == key) {
        return root->value;
    }
    else if (key <= root->key) {
        return getValueRecursion(root->left, key);
    }
    else {
        return getValueRecursion(root->right, key);
    }
}

char* getValue(Dictionary* dictionary, int key) {
    return getValueRecursion(dictionary->root, key);
}

bool isKeyHere(Dictionary* dictionary, int key) {
    if (search(dictionary->root, key)) {
        return true;
    }
    return false;
}

struct BstNode* minValueNode(struct BstNode* node) {
    struct BstNode* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

BstNode* deleteRecursion(BstNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    else if (key < root->key) {
        root->left = deleteRecursion(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteRecursion(root->right, key);
    }
    else {
        //case1: No children
        if (root->left == NULL && root->right == NULL) {
            free(root->value);
            free(root);
            root = NULL;
        }
            //case2: One child
        else if (root->left == NULL) {
            BstNode* temp = root;
            root = root->right;
            free(temp->value);
            free(temp);
        }
        else if (root->right == NULL) {
            BstNode* temp = root;
            root = root->left;
            free(temp->value);
            free(temp);
        }
            //case3 : Two children
        else {
            BstNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteRecursion(root->right, key);
        }
        return root;
    }
}

void deleteViaKey(Dictionary* dictionary, int key) {
    deleteRecursion(dictionary->root, key);
}

Dictionary* createDictionary() {
    Dictionary* tree = malloc(sizeof(Dictionary));
    tree->root = NULL;
    return tree;
}

void postorderRecursion(BstNode *root) {
    if (root == NULL) {
        return;
    }
    postorderRecursion(root->left);
    postorderRecursion(root->right);
    free(root->value);
    free(root);
}

void deleteDictionary(Dictionary* dictionary) {
    postorderRecursion(dictionary->root);
}

BstNode* findNodeByKey(BstNode* root, int key) {
    if (root->key == key) {
        return root;
    } else if (key > root->key) {
        return findNodeByKey(root->right, key);
    } else {
        return findNodeByKey(root->left, key);
    }
}

void changeData(Dictionary* dictionary, int key, char* newData) {
    BstNode* temp = findNodeByKey(dictionary->root, key);
    temp->value = newData;
}
