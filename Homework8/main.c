#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarySearchTree.h"

void options();
bool tests();

int main() {
    if (!tests()) {
        return 1;
    }

    Dictionary* dictionary = createDictionary();

    int choice = 0;
    char valueBuffer[256];
    int key = 0;
    do {
        options();
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            break;
        case 1:
            printf("Enter a key: ");
            scanf("%d", &key);
            if (isKeyHere(dictionary, key)) {
                deleteViaKey(dictionary, key);
            }
            printf("Enter a value: ");
            scanf("%s", &valueBuffer);
            char *value = malloc(sizeof(char) * 256);
            strcpy(value, valueBuffer);
            insert(dictionary, key, value);
            break;
        case 2:
            printf("Enter a key: ");
            scanf("%d", &key);
            printf("The value is %s\n", getValue(dictionary, key));
            break;
        case 3:
            printf("Enter a key: ");
            scanf("%d", &key);
            if (isKeyHere(dictionary, key)) {
                printf("There is such a key in the dictionary\n");
            }
            else {
                printf("There is no such a key in the dictionary\n");
            }
            break;
        case 4:
            printf("Enter a key: ");
            scanf("%d", &key);
            if (isKeyHere(dictionary, key)) {
                deleteViaKey(dictionary, key);
            }
        default:
            printf("Invalid input\n");
            break;
        }
    } while (choice != 0);

    deleteDictionary(dictionary);
}

void options() {
    printf("Binary search tree based Dictionary\n");
    printf("Options\n");
    printf("0 - Exit\n");
    printf("1 - Add a value with a correlating key\n");
    printf("2 - Get a value via a key\n");
    printf("3 - Check to see if there's a key in the dictionary\n");
    printf("4 - Delete a key and acorrelating value\n");
    printf("Enter a corresponding digit to choose an option: ");
}

bool tests() {
    Dictionary *testDictionary1 = createDictionary();
    insert(testDictionary1, 100, "123");
    insert(testDictionary1, 200, "145");
    insert(testDictionary1, 300, "600");
    if (!isKeyHere(testDictionary1, 100)) {
        printf("Insert failed\n");
        return false;
    }
    if (isKeyHere(testDictionary1, 1)) {
        printf("Insert failed on finding a nonexistent key in the dictionary\n");
        return false;
    }
    if (getValue(testDictionary1, 100) != "123") {
        printf("Get value function failed\n");
        return false;
    }
    if (strcmp(getValue(testDictionary1, 500), "NULL") != 0) {
        printf("Get value function failed on trying to get a value of a nonexistent key\n");
        return false;
    }
    return true;
}