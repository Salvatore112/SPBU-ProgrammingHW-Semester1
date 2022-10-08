#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define testLength 10

bool isSorted(int array[], int length);
void swap(int *oneValue, int *anotherValue);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);
bool qsortTests();
