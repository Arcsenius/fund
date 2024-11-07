
#include "functions.h"

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>




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
    int flag = 0;
    if (number < 0) {
        number = -number;
        flag = 1;
    } else if (number == 0) {
        printf(" 0 \n");
        *code = kS_OK;
        return NULL;
    }
    unsigned int base = 1 << r;
    unsigned int mask = Decrement(base);
    char* result = (char*)malloc(33);


    if (!result) {
        *code = kE_BAD_ALLOCATION_MEMORY;
        return NULL;
    }
    char* symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    int index = 0;
    while (number) {
        result[index] = symbols[number & mask];
        number >>= r;
        index = Increment(index);
    }

    result[index] = '\0';

    int left = 0, right = Decrement(index);
    char tmp = '\0';
    while(left < right) {

        tmp = result[left];
        result[left] = result[right];
        result[right] = tmp;
        left = Increment(left);
        right = Decrement(right);
    }
    if (flag) {
        printf("-");
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

