#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarySearchTree.h"

#define DICTIONARY_SIZE 256

int main() {
    BinarySearchTree *tree = createBinarySearchTree();
    
    char expression[100] = "wafgsexcxgf";
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
        }
    }

    

}