#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "stringLexer.h"

enum states{startState, firstClosureCharacter, readAtCharacter, secondClosureCharacter, readDot ,errorSate};

bool fromFirstClosure(char character) {
    return ((character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9')
            || character == '.' || character == '_' ||
            character == '%' || character == '+' || character == '-');
}

bool fromSecondClosure(char character) {
    return ((character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9') ||
            character == '-');
}

bool isValidString(char* string) {
    unsigned long long stringLength = strlen(string);
    int state = startState;
    for (int i = 0; i < stringLength; i++) {
        char character = string[i];
        switch (state) {
            case startState:
                if (fromFirstClosure(character)) {
                    state = firstClosureCharacter;
                } else {
                    state = errorSate;
                }
                break;
            case firstClosureCharacter:
                if (fromFirstClosure(character)) {
                    state = firstClosureCharacter;
                } else if (character == '@') {
                    state = readAtCharacter;
                } else {
                    state = errorSate;
                }
                break;
            case readAtCharacter:
                if (fromSecondClosure(character)) {
                    state = secondClosureCharacter;
                } else {
                    state = errorSate;
                }
                break;
            case secondClosureCharacter:
                if (fromSecondClosure(character)) {
                    state = secondClosureCharacter;
                } else if (character == '.') {
                    state = readDot;
                } else {
                    state = errorSate;
                }
                break;
            case readDot: {
                if (fromSecondClosure(character)) {
                    state = secondClosureCharacter;
                } else {
                    state = errorSate;
                }
                break;
            }
            case errorSate:
                break;
            default:
                printf("Unexpected error: state not found\n");
                return false;
                break;
        }
    }
    return state == readDot;
}