#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarySearchTree.h"

#define DICTIONARY_SIZE 256

void insertionSort(int array[], int length);


typedef struct PrefixCode {
    bool code[DICTIONARY_SIZE];
    int codeLength;
} PrefixCode ;

void postorderRecursion(Node *root, PrefixCode dictionary[], bool currentCode[], int codeLength) {
    if (root->right == NULL && root->left == NULL) {
        dictionary[root->symbol].codeLength = codeLength;
        for (int i = 0; i < codeLength; i++) {
            dictionary[root->symbol].code[i] = currentCode[i];

        }
        return;
    }
    currentCode[codeLength] = 0;
    postorderRecursion(root->left, dictionary, currentCode, codeLength + 1);
    currentCode[codeLength] = 1;
    postorderRecursion(root->right, dictionary, currentCode, codeLength + 1);

}

int main() {
    BinarySearchTree *tree = createBinarySearchTree();

    char expression[100] = "waaaafgsecxgf";
    int dictionary[DICTIONARY_SIZE] = { 0 };
    int lengthExpression = strlen(expression);
    for (int i = 0; i < lengthExpression; i++) {
        dictionary[expression[i]]++;
    }

    BinarySearchTree *trees[DICTIONARY_SIZE] = {NULL};

    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (dictionary[i] != 0) {
            BinarySearchTree *tempTree = createBinarySearchTree();
            insert(tempTree, dictionary[i], (char)i);
            trees[i] = tempTree;
        }
    }

    for(int i = 1; i < DICTIONARY_SIZE; i++) {
        int key = trees[i] == NULL ? -1 : trees[i]->root->frequency;
        BinarySearchTree *tempTree = trees[i];
        int j = i - 1;

        while (j >= 0 && (trees[j] == NULL || trees[j]->root->frequency <= key)) {
            trees[j + 1] = trees[j];
            j--;
        }
        trees[j + 1] = tempTree;
    }

    int lastPosition = 0;
    while (trees[lastPosition] != NULL) {
        lastPosition++;
    };

    printf("%c -- %d\n", trees[0]->root->symbol, trees[0]->root->frequency);

    for (int i = lastPosition - 1; i > 0; i--) {
        BinarySearchTree* tempTree = createBinarySearchTree();
        insert(tempTree, trees[i]->root->frequency + trees[i - 1]->root->frequency, '\0');
        tempTree->root->left = trees[i - 1]->root;
        tempTree->root->right = trees[i]->root;
        trees[i] = NULL;
        trees[i - 1] = tempTree;
        int j = i - 2;
        while (j >= 0 && (trees[j]->root->frequency < tempTree->root->frequency)) {
            trees[j + 1] = trees[j];
            j--;
        }
        trees[j + 1] = tempTree;
        printf("");
    }
    printf("%d\n", strlen(expression));
    printf("%d", trees[0]->root->frequency);


    PrefixCode codes[DICTIONARY_SIZE];
    bool currentCode[DICTIONARY_SIZE] = {0};
    postorderRecursion(trees[0]->root, codes, currentCode, 0);
    printf("%d",codes['e'].codeLength);

    FILE *codeFile = fopen("code.huff", "w");
    int length = strlen(expression);
    bool buffer[8];
    int currentPosition = 0;
    for (int i = 0; i < length; i++) {
        int currentLetter = codes[expression[i]].codeLength;
        for (int i = 0; i < currentLetter; i++) {
            buffer[currentPosition] = codes[expression[i]].code[i];
            currentPosition++;
            if (currentPosition >= 8) {
                char output = 0;
                for (int i = 0; i < 8; i++) {
                    if (buffer[i]) {
                        output += 1;
                    }
                    output <<= 1;
                }
                putc(output, codeFile);
                currentPosition = 0;
            }
        }
    }

}

//char expression[100] = "waaaafgsecxgf";

