#include <stdio.h>
#include "avlTree.h"

void options();

int main() {
    Dictionary* new = createDictionary();

    insert(new, 9, "g");
    insert(new, 5, "j");
    insert(new, 10, "k");
    insert(new, 0, "h");
    insert(new, 6, "h");
    insert(new, 11, "k");
    insert(new, -1, "p");
    insert(new, 1, "j");
    insert(new, 2, "i");

    Dictionary* dictionary = createDictionary();

    int choice = 0;
    char valueBuffer[256];
    int key = 0;
    do {
        options();
        scanf("%d", &choice);
    } while (choice != 0);

    return 0;
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