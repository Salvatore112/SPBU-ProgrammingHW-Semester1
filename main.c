#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarySearchTree.h"

int main() {
    FILE *file = fopen("file.txt", "r");
    char buffer[100];
    fscanf(file, "%[^\n]", buffer);
    

    BinarySearchTree *tree = createParseTree(buffer);
    printf("%d", tree->root->left->left->data);
    
    return 0;
}