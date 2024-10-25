#include <stdio.h>
#include "functions.h"

int main() {
    kState code;
    Vector* lines = CreateVector(2, &code);
    if (code != kS_OK) {
        logErrors(code);
        return code;
    }

    Vector* chars = CreateVector(2, &code);
    if (code != kS_OK) {
        logErrors(code);
        return code;
    }

    Vector* fileIds = CreateVector(2, &code);
    if (code != kS_OK) {
        logErrors(code);
        return code;
    }

    code = FindEnterancesInFiles(lines, chars, fileIds, "zovzovzovzovzovsvosvosvosvo", 1, "./input_1.txt");
    if (code != kS_OK) {
        logErrors(code);
        return code;
    }

    for (int i = 0; i < lines->len; i++) {
        printf("Found substring enterance in file with id: %d, on position: line: %d, char: %d\n", fileIds->buffer[i],
               lines->buffer[i], chars->buffer[i]);
    }

    DestroyVector(lines);
    DestroyVector(chars);
    DestroyVector(fileIds);
    return kS_OK;
}