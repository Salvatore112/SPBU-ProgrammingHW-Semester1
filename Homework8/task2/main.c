#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ParseTree.h"

bool tests();

int main() {
    if(!tests()) {
        return 1;
    };

    FILE *file = fopen("D:\\file.txt", "r");
    if (file == NULL) {
        printf("File not found");
        return 1;
    }
    char buffer[100];
    fscanf(file, "%[^\n]", buffer);

    ParseTree *tree = buildParseTree(buffer);

    printf("%d ", calculateExpression(tree));

    fclose(file);
    deleteParseTree(tree);
    return 0;
}

bool tests() {
    char testExpression1[] = "( * ( + 1 1 ) 2 ) ";
    int expectedResult1 = 4;
    ParseTree *testTree1 = buildParseTree(testExpression1);
    if (expectedResult1 != calculateExpression(testTree1)) {
        printf("Tests failed on the example expression");
        return false;
    }

    char testExpression2[] = "( * ( + 13 15 ) 74 ) ";
    int expectedResult2 = 2072;
    ParseTree *testTree2 = buildParseTree(testExpression2);
    if (expectedResult2 != calculateExpression(testTree2)) {
        printf("Tests failed when expression contains numbers (not digits)");
        return false;
    }

    char testExpression3[] = "( * -2 -3)";
    int expectedResult3 = 6;
    ParseTree *testTree3 = buildParseTree(testExpression3);
    if (expectedResult3 != calculateExpression(testTree3)) {
        printf("Tests failed when expression contains negative numbers (not digits)");
        return false;
    }
    return true;
}