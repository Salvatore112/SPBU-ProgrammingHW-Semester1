#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Dictionary data type that is based on binary search tree functions
typedef struct Dictionary Dictionary;

//Inserts value with its key in the dictionary
void insert(Dictionary* dictionary, int key, char* value);

//Deletes value of the given key
void deleteViaKey(Dictionary* dictionary, int key);

//Checks if a given key is in the dictionary
bool isKeyHere(Dictionary* dictionary, int key);

//Returns a value of a given key
char* getValue(Dictionary* dictionary, int key);

//Function that creates a dictionary
Dictionary* createDictionary();

//Function that deletes a dictionary
void deleteDictionary(Dictionary* dictionary);