#include <stdio.h>
#include <stdbool.h>

bool test();

int main() {
    if (!test()) {
        return 1;
    }
    
    FILE *file = fopen("file.txt", "r");
    char character;
    
    int amount[1000] = { 0 };
    
    
    while (!feof(file)) {
        character = fgetc(file);
        amount[(int)character]++;
    } 

    for (int i = 0; i < 1000; i++) {
        if (amount[i] > 0) {
            if (i == '\n') {
                printf("\\n appears in the file %d times\n", amount[i]);
            }
            else {
                printf("%c appears in the file %d times\n", i, amount[i]);
            }
        }
    } 
    return 0;
}

bool test() {
    FILE *file1 = fopen("testFile1.txt", "r");
    char character;
    
    int amount[1000] = { 0 };
    
    while (!feof(file1)) {
        character = fgetc(file1);
        amount[(int)character]++;
    } 

    if (amount['b'] != 4 && amount['c'] != 4 && amount['e'] != 6 && amount['f'] != 4 && amount['l'] != 3 && amount['w'] != 3 && amount['z'] != 7){
        printf("Test failed");
        return false;
    } 
    return true;
}