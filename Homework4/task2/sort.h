#pragma once

#include <stdbool.h>
#define TEST_LENGTH 10

// quick sort
void quickSort(int array[], int low, int high);

// Function that runs several tests on the quickSort function.
bool qsortTests();
