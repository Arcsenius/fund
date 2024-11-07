

#ifndef STRING_H
#define STRING_H


typedef struct {
    char* buffer;
    int length;
} String;

typedef enum {
    kS_OK,
    kE_INVALID_ALLOCATION_MEMORY
} kState;

String* CreateString(char* data);
int CompareStrings(String string1, String string2);
int MatchString(String string1, String string2);
int CopyToExistingString(String* string, String* newString);
String* CopyToNewString(String* string);
void ConcatString(String dest, String src);
#endif //STRING_H
