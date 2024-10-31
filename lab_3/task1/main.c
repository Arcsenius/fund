#include <stdio.h>
#include "functions.h"

int main() {
    kState code = kS_OK;
    unsigned int number = 12;
    unsigned int r = 1;

    char* result = DecimalToBaseR(number, r, &code);

    if (code != kS_OK) {
        LogErrors(code);
        return 1;
    }

    printf("%s\n", result);


    return 0;
}
