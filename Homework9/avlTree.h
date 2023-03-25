#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Dictionary Dictionary;

Dictionary* createDictionary();

void deleteViaKey(Dictionary* dictionary, char *key);

bool isKeyHere(Dictionary* dictionary, char* key);

void insert(Dictionary* dictionary, char* key, char* data);

char* getValue(Dictionary* dictionary, char* key);

void deleteDictionary(Dictionary* dictionary);

void changeData(Dictionary* dictionary, char* key, char* newData);
