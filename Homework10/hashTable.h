#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

//A struct that contains buckets, load factor and the size (amount of buckets)
typedef struct HashTable HashTable;

//hash function that takes a word, module and returns hash devided by that module
int hash(char* word, int module);

//inserts a word into a hash table or update the word's frequency if the word is already there
void hashInsert(HashTable* hashTable, char* word, int module);

//creates and returns a hashTable struct
HashTable* createHashTable(int size);

//function that recounts the load factor of the hash table
float updateLoadFactor(HashTable* hashTable);

//return the load factor of the hash table
float getLoadFactor(HashTable* hashTable);

//creates a brand-new hash table double the size of the previous and returns it
void hashResize(HashTable** oldTable,int *module);

//prints the words along with their frequencies
void printWords(HashTable* hashTable);

//looks for the longest list of the table and returns it
int findMaxList(HashTable* hashTable);

//looks for the average list of the table and returns it
float findAverageList(HashTable* hashTable);

void deleteTable(HashTable* hashTable);