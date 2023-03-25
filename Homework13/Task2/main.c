#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int mapping(char character);
void emptyBuffer(char* buffer);
int** createTable(char* fileName, int *errorCode);
char** getComments(char* fileName, int** table, int* errorCode);
void deleteTable(int** table, int strings, int columns);
void deleteComments(char** comments);
bool tests();

int main() {
    if (!tests()) {
        return 1;
    }
    int errorCode = 0;
    int **table = createTable("table.txt", &errorCode);
    if (errorCode < 0) {
        printf("Out of memory\n");
    }
    char** comments = getComments("input.txt", table, &errorCode);
    if (errorCode < 0) {
        printf("Out of memory\n");
    }
    int i = 0;
    while (comments[i] != NULL) {
        printf("%s\n", comments[i]);
        i++;
    }
    deleteTable(table, 4, 3);
    deleteComments(comments);
    return 0;
}

int mapping(char character) {
    if (character == '/') {
        return 0;
    } else if (character == '*') {
        return 1;
    } else {
        return 2;
    }
}

void emptyBuffer(char* buffer) {
    int i = 0;
    while (buffer[i] != '\0') {
        buffer[i] = '\0';
        i++;
    }
}

int** createTable(char* fileName, int *errorCode) {
    FILE* tableFile = fopen(fileName, "r");
    int strings = 0;
    int columns = 0;
    fscanf(tableFile, "%d", &strings);
    fscanf(tableFile, "%d", &columns);

    int** table = malloc(sizeof(int*) *strings);
    if (table == NULL) {
        *errorCode = -1;
        return NULL;
    }
    for (int i = 0; i < strings; i++) {
        table[i] = malloc(sizeof(int*) *columns);
        if (table[i] == NULL) {
            *errorCode = -1;
            return NULL;
        }
    }
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < columns; j++) {
            int state = 0;
            fscanf(tableFile, "%d", &state);
            table[i][j] = state;
        }
    }
    fclose(tableFile);
    return table;
}

char** getComments(char* fileName, int** table, int* errorCode) {
    FILE* file = fopen(fileName, "r");
    int currentState = 0;
    char buffer[100] = { '\0' };

    char** comments = calloc(sizeof(char*), 100);
    if (table == NULL) {
        *errorCode = -1;
        return NULL;
    }

    int i = 0;
    int j = 0;

    while (!feof(file)) {
        char character = '\0';
        fscanf(file, "%c", &character);
        if (character == '\0') {
            break;
        }

        int hash = mapping(character);
        currentState = table[currentState][hash];

        switch (currentState) {
            case 0:
                buffer[i] = character;
                i++;
                if (i <= 3) {
                    i = 0;
                    emptyBuffer(buffer);
                } else if (buffer[i - 1] == '/') {
                    char* newComment = malloc((sizeof(char) * 100));
                    if (newComment == NULL) {
                        *errorCode = -1;
                        return NULL;
                    }
                    strcpy(newComment, buffer);
                    comments[j] = newComment;
                    j++;
                    emptyBuffer(buffer);
                    i = 0;
                }
                break;
            case 1:
                if (i == 0) {
                    buffer[i] = character;
                    i++;
                } else if (buffer[i - 1] == '/') {
                    break;
                }
                break;
            case 2:
            case 3:
                buffer[i] = character;
                i++;
                break;
            default:
                printf("Unexpected error.\n");
                break;
        }
    }
    fclose(file);
    return comments;
}

bool tests() {
    FILE* testFile = fopen("testFile.txt", "r");
    int errorCode = 0;
    int **table = createTable("table.txt", &errorCode);
    if (errorCode < 0) {
        printf("Out of memory\n");
        return false;
    }
    char** comments = getComments("testFile.txt", table, &errorCode);
    if (errorCode < 0) {
        printf("Out of memory\n");
        return false;
    }
    char *expectedComments[5] = {"/*a*/", "/**/", "/*  /*/", "/*comment*/", "/*/*/"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(comments[i], expectedComments[i]) != 0) {
            printf("Tests failed\n");
            return false;
        }
    }
    deleteTable(table, 4, 3);
    deleteComments(comments);
    return true;
}

void deleteTable(int** table, int strings, int columns) {
    for (int i = 0; i < strings; i++) {
        free(table[i]);
    }
}

void deleteComments(char** comments) {
    int i = 0;
    while(comments[i] != NULL) {
        free(comments[i]);
        i++;
    }
}
