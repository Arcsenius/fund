#include <stdio.h>
#include <stdlib.h>

#include "String.h"

int main() {
    String *s1, *s2;
    s1 = CreateString("Hello c");
    s2 = CreateString("Hello World");
    CopyToExistingString(s1, s2);
    // String* s3 = CopyToNewString(s2);
    // printf("%s\n%s", s1.buffer, s2.buffer);
// printf("%s\n", s3->buffer);


    // ConcatString(s1, s2);
    // printf("%s\n", s1.buffer);
free(&s1);
    // free(s3);
    free(&s2);
}