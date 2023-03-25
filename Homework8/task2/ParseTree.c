#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ParseTree.h"

typedef struct BstNode {
    int data;
    char operation;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

typedef struct ParseTree {
        BstNode *root;
} ParseTree;

ParseTree* createParseTree() {
    ParseTree* tree = malloc(sizeof(ParseTree));
    if (tree == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    tree->root = NULL;
    return tree;
}

bool nextIsDigit(char string[], int position) {
    return (string[position + 1] != ' ' && string[position + 1] != '+' && string[position + 1] != '*' && string[position + 1] != '/' && string[position + 1] != '(' && string[position + 1] != ')');
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


    if (string[*position] == '+' || string[*position] == '-' || string[*position] == '*' || string[*position] == '/') {
        if (string[*position] == '-' && nextIsDigit(string, *position)) {
            char *number = malloc(sizeof(char) * 8);
            int i = 2;
            number[0] = '-';
            number[1] = string[(*position) + 1];
            (*position) += 1;
            while (nextIsDigit(string, *position)) {
                number[i] = string[(*position) + 1];
                (*position) += 1;
            }
            int intNumber = atoi(number);

            root->data = intNumber;
        }
        else {
            root->operation = string[*position];
            root->right = parseTreeRecursion(string, position);
            root->left = parseTreeRecursion(string, position);
        }
    }

    else {
        char *number = malloc(sizeof(char) * 8);
        if (string[(*position) - 1] == '-') {

        }
        int i = 1;
        number[0] = string[*position];
        while (nextIsDigit(string, *position)) {
            number[i] = string[(*position) + 1];
            (*position) += 1;
        }
        int intNumber = atoi(number);
        root->data = intNumber;
    }
    return root;
}

ParseTree* buildParseTree(char string[]) {
    ParseTree* temp = createParseTree();
    int position = 0;
    temp->root = parseTreeRecursion(string, &position);
    return temp;
}

int calculateExpressionRecursion(BstNode *root) {
    if (root->operation == '+') {
        return calculateExpressionRecursion(root->left) + calculateExpressionRecursion(root->right);
    }
    else if (root->operation == '-') {
        return calculateExpressionRecursion(root->left) - calculateExpressionRecursion(root->right);
    }
    else if (root->operation == '*') {
        return calculateExpressionRecursion(root->left) * calculateExpressionRecursion(root->right);
    }
    else if (root->operation == '/') {
        return calculateExpressionRecursion(root->left) / calculateExpressionRecursion(root->right);
    }
    else {
        return root->data;
    }
}

int calculateExpression(ParseTree* tree) {
    return calculateExpressionRecursion(tree->root);
}

void postorderRecursionDelete(BstNode *root) {
    if (root == NULL) {
        return;
    }
    postorderRecursionDelete(root->left);
    postorderRecursionDelete(root->right);
    free(root);
}

void deleteParseTree(ParseTree* ParseTree) {
    postorderRecursionDelete(ParseTree->root);
}
