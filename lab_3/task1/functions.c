
#include "functions.h"

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

// int DecimalToBaseR(int number, int r, char* result, kState* code){
//
//     unsigned int base = 1 << r;
//     unsigned int mask =
//
// }


unsigned int Increment(unsigned int number) {
    unsigned int mask = 1;

    while (number & mask) {
        number ^= mask;
        mask <<= 1;
    }
    number ^= mask;
    return number;
}


unsigned int Decrement(unsigned int number) {
    unsigned int mask = 1;

    while (!(number & mask)) {
        number ^= mask;
        mask <<= 1;
    }

    number ^= mask;
    return number;

}


char* DecimalToBaseR(int number, int r, kState* code) {

    if (r < 1 || r > 5) {
        *code = kE_INVALID_ARGUMENT;
        return NULL;
    }
    unsigned int base = 1 << r;
    unsigned int mask = Decrement(base);
    char* result = (char*)malloc(65);


    if (!result) {
        *code = kE_BAD_ALLOCATION_MEMORY;
        return NULL;
    }
    char* symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    int index = 0;
    while (number) {
        result[index] = symbols[number & mask];
        // printf("%c", result[index]);
        number >>= r;
        index = Increment(index);
    }

    result[index] = '\0';

    int left = 0, right = Decrement(index);
    char tmp = "";
    while(left < right) {

        tmp = result[left];
        result[left] = result[right];
        result[right] = tmp;
        left = Increment(left);
        right = Decrement(right);
    }
    *code = kS_OK;
    return result;
}



void LogErrors(kState code) {
    switch (code) {
        case kS_OK: {
            printf("Success!\n");
            break;
        }
        case kE_BAD_ALLOCATION_MEMORY: {
            printf("ERROR: BAD ALLOCATION\n");
            break;
        }
        case kE_INVALID_ARGUMENT: {
            printf("ERROR: INVALID ARGUMENT");
            break;
        }
        default: {
            printf("UNKNOWN ERROR CODE\n");
            break;
        }
    }
}

