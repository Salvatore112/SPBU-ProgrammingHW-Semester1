#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "HashTable.h"
#include "linkedList.h"

typedef struct HashTable {
    int size;
    float loadFactor;
    LinkedList** buckets;
} HashTable;

int hash(char* word, int module) {
    int length = strlen(word);
    int result = 0;
    for (int i = 0; i < length; i++) {
        result = (result + word[i]) * 5;
    }
    return result % module;
}


void hashInsertHidden(LinkedList* words[], char* word, int module) {
    int index = hash(word, module);
    if (words[index] == NULL) {
        words[index] = createList();
        listInsertBeginning(word, words[index]);
    }
    else {
        if (isInTheList(words[index], word)) {
            incrementFrequency(words[index], word);
        } else {
            listInsertBeginning(word, words[index]);
        }
    }
}

void hashInsert(HashTable* hashTable, char* word, int module) {
    hashInsertHidden(hashTable->buckets, word, module);
    updateLoadFactor(hashTable);
}

int hashLook(LinkedList* words[], char* word, int module) {
    int index = hash(word, module);
    if(strcmp(getWord(words[index]), word) != 0) {
        LinkedList* tempList = words[index];
        while (strcmp(getWord(words[index]), word) != 0) {
            listTraverse(tempList);
        }
        return getFrequency(tempList);
    } else {
        return getFrequency(words[index]);
    }
}

HashTable* createHashTable(int size) {
    HashTable* newTable = calloc(1, sizeof(HashTable));
    LinkedList** wordss = malloc(sizeof(LinkedList*) * size);
    for (int i = 0; i < size; i++) {
        wordss[i] = NULL;
    }
    newTable->buckets = wordss;
    newTable->size = size;
    return newTable;
}

float updateLoadFactor(HashTable* hashTable) {
    int occupied = 0;
    for (int i = 0; i < hashTable->size; i ++) {
        occupied += listLength(hashTable->buckets[i]);
    }
    hashTable->loadFactor = (float )occupied/(float )hashTable->size;
    return (float )occupied/(float )hashTable->size;
}

float getLoadFactor(HashTable* hashTable) {
    return hashTable->loadFactor;
}

void hashResize(HashTable** oldTable, int *module) {
    int newModule = (*oldTable)->size * 2;
    int oldModule = (*oldTable)->size;
    HashTable* newTable = createHashTable(newModule);
    for (int i = 0; i < oldModule; i++) {
        if (!isEmpty((*oldTable)->buckets[i])) {
            LinkedList* tempList = (*oldTable)->buckets[i];
            bool isNextNull = true;
            do {
                int oldFrequency = getFrequency(tempList);
                hashInsertHidden(newTable->buckets, getWord(tempList), newModule);
                conveyFrequency(newTable->buckets[hash(getWord(tempList), newModule)], getWord(tempList), oldFrequency);
                isNextNull = listTraverse(tempList);
            } while (!isNextNull);
        }

    }
    *module = newModule;
    (*oldTable) = newTable;
}

void printWords(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        if (!isEmpty(hashTable->buckets[i])) {
            LinkedList* tempList = hashTable->buckets[i];
            bool isNextNull = true;
            do {
                printf("%s appears in the file ", getWord(tempList));
                printf("%d times\n", getFrequency(tempList));
                isNextNull = listTraverse(tempList);
            } while (!isNextNull);
        }
    }
}

int findMaxList(HashTable* hashTable) {
    int max = -1;
    for (int i = 0; i < hashTable->size; i++) {
        if (!isEmpty(hashTable->buckets[i])) {
            int length = listLength(hashTable->buckets[i]);
            if (listLength(hashTable->buckets[i]) > max) {
                max = length;
            }
        }
    }
    return max;
}

float findAverageList(HashTable* hashTable) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < hashTable->size; i++) {
        if (!isEmpty(hashTable->buckets[i])) {
            count++;
            sum += listLength(hashTable->buckets[i]);
        }
    }
    return (float )sum/(float )count;
}
