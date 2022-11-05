#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//ParseTree data type that is based on binary search tree functions
typedef struct ParseTree ParseTree;

//builds parse tree of a given expression
ParseTree* buildParseTree(char string[]);

//traverses a parse tree and calculates the expression
int calculateExpression(ParseTree* tree);

//deletes a parse tree
void deleteParseTree(ParseTree* ParseTree);