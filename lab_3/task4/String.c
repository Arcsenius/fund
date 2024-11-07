#include "String.h"

#include <stdlib.h>
#include <string.h>
#include <string.h>

String* CreateString(char* data) {
    String* string;
    char* tmp = data;
    int i = 0;
    string->buffer = (char*) malloc(sizeof(data));
    if (string->buffer == NULL) {
        perror("Memory allocation error");
    }
    while (tmp[i] != '\0') {
        string->buffer[i] = tmp[i];
        ++i;
    }
    string->buffer[i] = '\0';

    while (*tmp != '\0') {
        ++tmp;
    }

    string->length = tmp - data;
    return string;
}

void DestroyString(String string) {
    free(string.buffer);
    string.length = 0;
}

int MatchString(String string1, String string2) {
    for (int i = 0; i < string1.length; i++) {
        if (string1.buffer[i] > string2.buffer[i]) {
            return 1;
        } else if (string1.buffer[i] < string2.buffer[i]) {
            return -1;
        }
    }
    return 0;
}
int CompareStrings(String string1, String string2) {
    if (string1.length == string2.length) {
        return MatchString(string1, string2);
    }
    return string1.length > string2.length ? 1 : -1;
}


int CopyToExistingString(String* string, String* newString) {
    if (string->length < newString->length) {
        return 0;
    }
    int i = 0;
    char *tmp = string->buffer;
    while (tmp[i] != '\0') {
        newString->buffer[i] = tmp[i];
        ++i;
    }
    newString->buffer[i] = "\0";
    newString->length = string->length;
    return 1;
}


String* CopyToNewString(String* string) {
    String* newString = (String*) malloc(sizeof(String));
    if (newString != NULL) {
        if (CopyToExistingString(string, newString)) {
            return newString;
        }
    }
return NULL;

    // newString = CreateString(string.buffer);
    //return &newString;
}


void ConcatString(String dest, String src) {
    int newLength = dest.length + src.length;
    dest.buffer = (char*)realloc(dest.buffer, (newLength + 1) * sizeof(char));
    if (dest.buffer != NULL) {
        // perror("Memory allocation error");
    }
    for (int i = 0; i < src.length; i++) {
        dest.buffer[i + dest.length] = src.buffer[i];
    }
    dest.buffer[newLength] = '\0';
    dest.length = newLength;
}













