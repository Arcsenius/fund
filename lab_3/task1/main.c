#include <stdio.h>
#include "functions.h"

int main() {
    kState code = kS_OK;
    int number = 64;
    unsigned int r = 4;

    char* result = DecimalToBaseR(number, r, &code);

    if (code != kS_OK) {
        LogErrors(code);
        return 1;
    }

    printf("%s\n", result);


    return 0;
}
